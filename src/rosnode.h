#ifndef ROSNODE_H
#define ROSNODE_H
#include <string>
#include <thread>
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <geometry_msgs/PoseStamped.h>
#include <move_base_msgs/MoveBaseActionResult.h>

using namespace std;

//#define ROS_MASTER_URI     "http://192.168.1.105:11311"
#define ROS_MASTER_URI     "http://localhost:11311"
#define NODENAME    "sp3"
#define PP_TOPIC    "robot/pose"
#define PS_TOPIC    "robot/status"
#define S_TOPIC     "robot/status"
//#define S_TOPIC     "move_base/result"
#define S_TOPIC     "rueckmeldung"

class ROSNode
{
public:
    ROSNode(int argc, char **argv, const string nodeName=NODENAME);
    virtual ~ROSNode();
    void changeSubscriberTopic(const string& topic);
    void changeStringPublisherTopic(const string& topic);
    void changePosePublisherTopic(const string& topic);
    void publish(const string msg);
    /**
     * @brief publish
     * @param x
     * @param y
     * @param z
     * @param w
     * @param phi
     * Diese Funktion sendet sowohl Positionsdaten(x,y,z) als auch die Orientierung im Raum.
     * Dabei ist die Orientierung auf die Drehung um die z-Achse beschränkt.
     * Um diese Drehung zu senden muss w = 1
     */
    void publish(const double x, const double y, const double z=0.0, const double phi=0.0);
//    virtual void msgReceivedCallback(const std_msgs::String::ConstPtr& msg);
    virtual void msgReceivedCallback(const std_msgs::String::ConstPtr &msg);

private:
    ros::Publisher m_stringPublisher;
    ros::Publisher m_posePublisher;
    ros::Subscriber m_subscriber;
    string m_pStringTopic;
    string m_pPoseTopic;
    string m_sTopic;
    void threadMethod();
    std::thread th;


};

#endif // ROSNODE_H
