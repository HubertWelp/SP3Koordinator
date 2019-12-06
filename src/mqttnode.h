/**
  @brief

  @version 2
  - Implementierung des Singleton-Musters
*/
#ifndef MQTTNODE_H
#define MQTTNODE_H

#include "/opt/paho.mqtt.c-master/src/MQTTClient.h"
#include "../src/Subjekt.h"

//#define ADDRESS     "tcp://192.168.77.253:1883"
#define ADDRESS     "tcp://127.0.0.1:1883"
#define CLIENTID    "SCRS"
#define TOPIC       "test"
#define PAYLOAD     "TestTest"
#define QOS         1
#define TIMEOUT     10000L

class MQTTNode
{

public:
    MQTTNode(char* sURI=ADDRESS, char* cID=CLIENTID);
    virtual ~MQTTNode();
    void subscribe(char* topic, int qos=0);
    void unsubscribe(char* topic);
    void publish(char* topic, char* message, int len, int qos=0);


protected:
    virtual void onMessageReceived(char* t, char* m);
private:
    static void delivered(void *context, MQTTClient_deliveryToken dt);
    static int msgarrvd(void *context, char *topicName, int topicLen, MQTTClient_message *message);
    static void connlost(void *context, char *cause);

    MQTTClient client;
    char serverURI[500];
    char clientID[500];
    static MQTTNode* m_instanz;
};

#endif // MQTTNODE_H
