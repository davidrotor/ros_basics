#include "ros/ros.h"
#include <iostream>
#include "ros_basics/demo_srv.h"
#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char **argv){
    ros::init(argc,argv,"demo_service_client");
    ros::NodeHandle node;
    ros::Rate loop(10);
    ros::ServiceClient client=node.serviceClient<ros_basics::demo_srv>("demo_service");
    while(ros::ok()){
        ros_basics::demo_srv srv;
        std::stringstream ss;
        ss<< "Sending from Here";
        srv.request.in =ss.str();
        if(client.call(srv)){
            ROS_INFO("From Client [%s], Server says [%s]",srv.request.in.c_str(),srv.response.out.c_str());
        }else{
            ROS_ERROR("Failed to call service");
            return 1;
        }
        ros::spinOnce();
        loop.sleep();
    }
    return 0;
}
