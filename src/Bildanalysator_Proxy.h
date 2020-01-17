#ifndef Bildanalysator_Proxy_H
#define Bildanalysator_Proxy_H
/** @class SCRS
 * @brief Abstraktion eines Smart Connected RFID Sensors.
 *
 * Die Klasse SCRS stellt eine Abstraktion bzw. einen Proxy fuer einen realen Smart Connected RFID Sensor (SCRS) dar.
 * Der SCRS ist ein Telemetrie-Geraet, welches ueber MQTT/WLAN seine Sensordaten (Inhalt eines 15693-RFID-Transponders) versendet.
 * Die Klasse stellt dem Nutzer alle von einem realen SCRS gesendeten Informationen ueber entsprechende getter-Methoden zur Verfuegung.
 * Ferner lassen ueber die Klasse Einstellungen an dem realen Geraet vornehmen. Dies wird realisiert ueber das Empfangen und Versenden
 * von MQTT-Nachrichten. Hierfuer muss die SCRS-Klasse als MQTT-Knoten fungieren und leitet sich entsprechend von der Klasse MQTTNode ab.
 * Da sich der Zustand von Objekten dieser Klasse asynchron von extern (dem realen SCRS) aendern laesst, muessen nutzende Objekte ueber eine
 * solche Zustandsaenderung informiert werden. Die Klasse nimmt entsprechend die Rolle des Subjekts im Observer-Pattern an und leitet sich von
 * der Klasse Subjekt ab.
 *
 * @author Dr. Hubert Welp
 *
 */

#include "../src/Subjekt.h"
#include "udpnode.hpp"



class Bildanalysator_Proxy : public Subjekt, public UDPNode
{
public:
    enum ObjektTyp {Snickers,MilkyWay,Maoam,Schokoriegel};
    Bildanalysator_Proxy ();/* verhindert, dass ein Objekt von außerhalb von N erzeugt wird. */
                  // protected, wenn man von der Klasse noch erben möchte

    static int hexStringToByteStream(unsigned char* byte, const char* hex, int len);
    static void byteStreamToHexString(char* hex, const unsigned char* byte, int len);


    int bildanalyseStarten(ObjektTyp suessigkeit);
    void getObjektPosition(int* px, int* py, int* pz);
    float getObjektOrientierung();
    int getObjektBreite();


private:
    /** @brief setTagConent
    *
    * Mit der Methode wird der Inhalt der empfangenen Tag-Nachricht gespeichert. Da SCRC ein ein beobachtetes Subjekt ist,
    * ruft sie die geerbte Methode benachrichte() auf.
    * @param [in] content Buffer des byteweisen Inhalt eines 15693-RFID-Tag inklusive RFID-Unique Identifier
    * @param [in] len Laenge des Buffers in Byte
    */
//    void setTagContent(const unsigned char* content, int len);
    bool error = false;
    float phi;
    int x, y, z;
    int breite;



    // UDPNode interface
protected:
    void messageReceived(string msg);
};

#endif // SCRS
