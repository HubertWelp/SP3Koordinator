#ifndef ROBOTER_H
#define ROBOTER_H

#include "../src/Subjekt.h"
#include "../src/rosnode.h"
class Roboter : public Subjekt, public ROSNode
{
public:
    Roboter(int argc, char **argv);
    void setStatus(string status);
    string getStatus();
    /**
     * @brief setZiel
     * @param x    Koordinate im Raum
     * @param y    Koordinate im Raum
     * @param phi  Drehung um die z Achse in Radien
     *
     * Sendet Position und Orientierung an den RosNode
     */
    void greife(float x, float y, float z, float phi, float breite);
private:
//    void msgReceivedCallback(const std_msgs::String::ConstPtr& msg);
    void msgReceivedCallback(const std_msgs::String::ConstPtr &msg);
    string m_status;
    ROSNode *rtst;

};

#endif // ROBOTER_H
