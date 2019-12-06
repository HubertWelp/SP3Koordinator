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
    void setZiel(double x, double y);
private:
//    void msgReceivedCallback(const std_msgs::String::ConstPtr& msg);
    void msgReceivedCallback(const move_base_msgs::MoveBaseActionResult::ConstPtr &msg);
    string m_status;

};

#endif // ROBOTER_H
