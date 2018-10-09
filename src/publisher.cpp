#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include <iostream>

int main(int argc, char **argv){
    ros::init(argc,argv,"demo_topic_publisher");
    ros::NodeHandle node;
    ros::Publisher contador= node.advertise<std_msgs::Int32>("/valor",10);
    ros::Rate loop(10);
    int cuenta=0;
    while(ros::ok()){
        std_msgs::Int32 msg;
        msg.data=cuenta;
        ROS_INFO("%d",msg.data);
        contador.publish(msg);
        ros::spinOnce();
        loop.sleep();
        ++cuenta;
        
    }
    return 0;
}