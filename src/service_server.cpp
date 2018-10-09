#include "ros/ros.h"
#include "ros_basics/demo_srv.h"
#include <iostream>
#include <sstream>

using namespace std;

bool service_cb(ros_basics::demo_srv::Request &req, ros_basics::demo_srv::Response &res){
    std::stringstream ss;
    ss<<"Recieved Here";
    res.out=ss.str();
    ROS_INFO("From Client [%s], Server says [%s]",req.in.c_str(),res.out.c_str());
    return true;
}
int main (int argc, char **argv){
    ros::init(argc, argv, "demo_service_server");
    ros::NodeHandle node;
    ros::ServiceServer service=node.advertiseService("demo_service",service_cb);
    ROS_INFO("Ready to recieve from client");
    ros::spin();
    return 0;
}
