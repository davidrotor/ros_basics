#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include <iostream>

void cuenta_cb(const std_msgs::Int32::ConstPtr& msg){
        ROS_INFO("Recieved [%d]",msg->data);
}
int main(int argc, char **argv){
        ros::init(argc,argv,"demo_topic_subscriber");
        ros::NodeHandle node;
        ros::Subscriber conteo=node.subscribe("/valor",10,cuenta_cb);
        ros::spin();
        return 0;
}