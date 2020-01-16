#include "roboter.h"
#include <iostream>
using namespace std;

Roboter::Roboter(int argc, char **argv)
    :ROSNode(argc,argv)
{

}

void Roboter::setStatus(string status)
{
    m_status = status;
//    cout << "Status: " << status << endl;
    benachrichtige();
}

string Roboter::getStatus()
{
    return m_status;
}

void Roboter::setZiel(double x, double y,double phi)
{
    // hier Message an echten Roboter ueber ROSNode senden
    ROSNode::publish(x,y,0,phi);

}

//void Roboter::msgReceivedCallback(const std_msgs::String::ConstPtr &msg)
//{
//    string status = string(msg->data.c_str());
//    setStatus(status);
//}
void Roboter::msgReceivedCallback(const move_base_msgs::MoveBaseActionResult::ConstPtr &msg)
{
    printf("ich hoerte: %i\n",msg->status.status);

    string status;

    status = to_string(msg->status.status);
    cout << "als string " << status << endl;
    setStatus(status);
}
