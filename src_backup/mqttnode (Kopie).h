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

class MQTTNode : public Subjekt
{

public:
    MQTTNode(char* sURI=ADDRESS, char* cID=CLIENTID);
    ~MQTTNode();
    void subscribe(char* topic, int qos=0);
    void unsubscribe(char* topic);
    void publish(char* topic, char* message, int len, int qos=0);
    char* getLastMessageReceived(char* m);
    char* getLastTopicReceived(char* t);
    static MQTTNode* getInstanz();

private:
    static void delivered(void *context, MQTTClient_deliveryToken dt);
    static int msgarrvd(void *context, char *topicName, int topicLen, MQTTClient_message *message);
    static void connlost(void *context, char *cause);
    void setLastMessage(char* t, char* m);
//    MQTTNode ();/* verhindert, dass ein Objekt von außerhalb von N erzeugt wird. */
                  // protected, wenn man von der Klasse noch erben möchte
    MQTTNode( const MQTTNode& ){}; /* verhindert, dass eine weitere Instanz via
     Kopie-Konstruktor erstellt werden kann */

    MQTTClient client;
    char serverURI[500];
    char clientID[500];
    char m_lastMessageReceived[10000];
    char m_lastTopicReceived[1000];
    static MQTTNode* m_instanz;
};

#endif // MQTTNODE_H
