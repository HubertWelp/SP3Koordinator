#include "rosnode.h"
#include <iostream>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>

ROSNode::ROSNode(int argc, char **argv,  const string nodeName)
    : m_pStringTopic(PS_TOPIC)
    , m_pPoseTopic(PP_TOPIC)
    , m_sTopic(S_TOPIC)
{
    ros::init(argc,argv,nodeName);
    if ( ! ros::master::check() ) {
        ROS_INFO("connection to ROS-Master could not be established\n");
    }
    ros::start();
    changeStringPublisherTopic(m_pStringTopic);
    changePosePublisherTopic(m_pPoseTopic);
    changeSubscriberTopic(m_sTopic);
    th=thread(&ROSNode::threadMethod,this);
    cout << "thread started for spinning\n";

}

ROSNode::~ROSNode()
{
    ros::shutdown();
}

void ROSNode::changeSubscriberTopic(const string &topic)
{
    ros::NodeHandle nh;
    m_subscriber = nh.subscribe(topic, 1000, &ROSNode::msgReceivedCallback,this);

}

void ROSNode::changeStringPublisherTopic(const string &topic)
{
    ros::NodeHandle nh;
    m_stringPublisher = nh.advertise<std_msgs::String>(topic,1000);
}

void ROSNode::changePosePublisherTopic(const string &topic)
{
    ros::NodeHandle nh;
    m_posePublisher = nh.advertise<geometry_msgs::PoseStamped>(topic,1000);
}

void ROSNode::publish(const string msg)
{
    std_msgs::String rosMsg;
    rosMsg.data = msg;
    m_stringPublisher.publish(rosMsg);
}

void ROSNode::publish(const double x, const double y, const double z, const double phi) // Fuer Drehung muss w = 1 und phi ein radiant
{
    geometry_msgs::PoseStamped rosMsg;
    rosMsg.header.frame_id = "map";
    rosMsg.pose.position.x = x;
    rosMsg.pose.position.y = y;
    rosMsg.pose.position.z = z;

    /** Die drehung wird durch radianten angegeben zbsp.: 180° = pi **/
    /*** hier Wird die Quanternion Darstellung für eine Drehumg um die z Achse berechnet *******/
    tf2::Quaternion qtemp;
    geometry_msgs::Quaternion qmsgtemp;
    qtemp.setRPY(0,0,phi);
    qmsgtemp = tf2::toMsg(qtemp);
    /******************************************************************************************/

    rosMsg.pose.orientation.x = qmsgtemp.x;//Drehung um x Achse
    rosMsg.pose.orientation.y = qmsgtemp.y;//Drehung um y Achse
    rosMsg.pose.orientation.z = qmsgtemp.z;//Drehung um z Achse*/
    rosMsg.pose.orientation.w = qmsgtemp.w;//Drehung um w Achse
    m_posePublisher.publish(rosMsg);
}


//void ROSNode::msgReceivedCallback(const std_msgs::String::ConstPtr &msg)
//{
////    ROS_INFO("Ich hoerte: [%s]", msg->data.c_str());
//}
void ROSNode::msgReceivedCallback(const std_msgs::String::ConstPtr &msg)
{
//    ROS_INFO("Ich hoerte: [%s]", msg->data.c_str());
    ROS_INFO("Ich hoerte: [%s]", msg->data.c_str());
    printf("ich hoerte: %s\n",msg->data.c_str());

}

void ROSNode::threadMethod()
{
    ros::Rate rate(10);
    while(ros::ok())
    {
//        cout << "ROS spinning \n";
        ros::spinOnce();
        rate.sleep();
//        ros::spin();
    }
}

