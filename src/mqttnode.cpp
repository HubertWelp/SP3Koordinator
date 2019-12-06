#include "../src/mqttnode.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


MQTTNode* MQTTNode::m_instanz=NULL;
volatile MQTTClient_deliveryToken deliveredtoken;


MQTTNode::MQTTNode(char* sURI, char* cID )
{
    strcpy(serverURI,sURI);
    strcpy(clientID,cID);


    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
    int rc;
    int ch;

    MQTTClient_create(&client, serverURI, clientID,MQTTCLIENT_PERSISTENCE_NONE, nullptr);
    conn_opts.keepAliveInterval = 20;
    conn_opts.cleansession = 1;

    MQTTClient_setCallbacks(client, nullptr, connlost, msgarrvd, delivered);

    printf("Connect to MQTT server ...\n");
    if ((rc = MQTTClient_connect(client, &conn_opts)) != MQTTCLIENT_SUCCESS)
    {
        printf("Failed to connect, return code %d\n", rc);
        exit(EXIT_FAILURE);
    }

    m_instanz = this;

}

MQTTNode::~MQTTNode()
{
    MQTTClient_disconnect(client, 10000);
    MQTTClient_destroy(&client);
}

void MQTTNode::delivered(void *context, MQTTClient_deliveryToken dt)
{
    printf("Message with token value %d delivery confirmed\n", dt);
    deliveredtoken = dt;
}

int MQTTNode::msgarrvd(void *context, char *topicName, int topicLen, MQTTClient_message *message)
{
    int i;
    char* payloadptr;
    char* payloadbuffer;

//    printf("Message arrived\n");
//    printf("     topic: %s\n", topicName);
//    printf("   message: ");

    payloadbuffer = payloadptr = (char*)message->payload;
//    for(i=0; i<message->payloadlen; i++)
//    {
//        putchar(*payloadptr++);
//    }
//    putchar('\n');
//    FILE* file = fopen( "d:/temp/test.jpg", "wb" );
//    fwrite( message->payload, 1, message->payloadlen, file );
//    fclose(file);

    // Call the user-defined call-back function
    payloadbuffer = new char[message->payloadlen+1];
    strncpy(payloadbuffer,(char*)message->payload,message->payloadlen);
    payloadbuffer[message->payloadlen]=0;
    if(m_instanz)
    {
        m_instanz->onMessageReceived(topicName,payloadbuffer);
    }
//    printf("%s\n",payloadbuffer);
    delete payloadbuffer;
    MQTTClient_freeMessage(&message);
    MQTTClient_free(topicName);
    return 1;
}

void MQTTNode::connlost(void *context, char *cause)
{
    printf("\nConnection lost\n");
    printf("     cause: %s\n", cause);
    if(m_instanz)
    {
        MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
        int rc;
        int ch;

//        MQTTClient_create(&(m_instanz->client), m_instanz->serverURI, m_instanz->clientID,MQTTCLIENT_PERSISTENCE_NONE, nullptr);
        conn_opts.keepAliveInterval = 20;
        conn_opts.cleansession = 1;


        printf("Re-connect to MQTT server ...\n");
        if ((rc = MQTTClient_connect(m_instanz->client, &conn_opts)) != MQTTCLIENT_SUCCESS)
        {
            printf("Failed to connect, return code %d\n", rc);
            exit(EXIT_FAILURE);
        }

    }
}



void MQTTNode::subscribe(char* topic, int qos)
{
    printf("Subscribing to topic %s\nfor client %s using QoS%d\n\n", topic, clientID, qos);
    MQTTClient_subscribe(client, topic, qos);
}

void MQTTNode::unsubscribe(char* topic)
{
    printf("Unsubscribing to topic %s\nfor client %s\n\n", topic, clientID);
    MQTTClient_unsubscribe(client, topic);
}

void MQTTNode::publish(char* topic, char* message, int len, int qos)
{
    int rc;
    MQTTClient_message pubmsg = MQTTClient_message_initializer;
    MQTTClient_deliveryToken token;

    pubmsg.payload = (void*)message;
    pubmsg.payloadlen = len;

    pubmsg.qos = qos;
    pubmsg.retained = 0;
    MQTTClient_publishMessage(client, topic, &pubmsg, &token);
    printf("Waiting for up to %d seconds for publication of %s\n"
            "on topic %s for client with ClientID: %s\n",
            (int)(TIMEOUT/1000), (char*)pubmsg.payload, topic, clientID);
    rc = MQTTClient_waitForCompletion(client, token, TIMEOUT);
    printf("Message with delivery token %d delivered\n", token);
}


void MQTTNode::onMessageReceived(char *t, char *m)
{
    printf("MQTTNode: t=%s m=%s\n",t,m);
}

