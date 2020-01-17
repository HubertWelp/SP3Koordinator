#ifndef ROBOTER_H
#define ROBOTER_H

#include "../src/Subjekt.h"
#include "../src/rosnode.h"
#include "raum.h"
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
    void greife(double x, double y, double z, double phi,double breite);
private:
//    void msgReceivedCallback(const std_msgs::String::ConstPtr& msg);
    void msgReceivedCallback(const move_base_msgs::MoveBaseActionResult::ConstPtr &msg);
    string m_status;
    ROSNode *rtst;

};

#endif // ROBOTER_H
