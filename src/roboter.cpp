#include "roboter.h"
#include <iostream>
using namespace std;

Roboter::Roboter(int argc, char **argv)
    :ROSNode(argc,argv)
{
    rtst = new ROSNode(argc,argv);
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

void Roboter::greife(float x, float y,float z,float phi,float breite)
{
    // hier Message an echten Roboter ueber ROSNode senden
    printf("\n greife Objekt  %.1f %.1f %.1f %f %.1f \n",x,y,z,phi,breite);

    rtst->publish(x,y,z,phi/180.0*3.1415926535);
    string str;
    str=to_string(breite);
    rtst->publish(str);

}

//void Roboter::msgReceivedCallback(const std_msgs::String::ConstPtr &msg)
//{
//    string status = string(msg->data.c_str());
//    setStatus(status);
//}
void Roboter::msgReceivedCallback(const std_msgs::String::ConstPtr &msg)
{
    printf("ich hoerte: %s\n",msg->data.c_str());

    string status;

    status = msg->data.c_str();
    cout << "als string " << status << endl;
    setStatus(status);
}
