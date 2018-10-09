#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include "ros_basics/demo.h"
#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char **argv)

{

	//Initializing ROS node with a name of demo_topic_publisher
	ros::init(argc, argv,"demo_msg_publisher");
	//Created a nodehandle object
	ros::NodeHandle node;
	//Create a publisher object
	ros::Publisher number_publisher = node.advertise<ros_basics::demo>("/demo_msg_topic",10);
	//Create a rate object
	ros::Rate loop_rate(10);
	//Variable of the number initializing as zero
	int number_count = 0;

	//While loop for incrementing number and publishing to topic /numbers
	while (ros::ok())
	{

		//Created a Int32 message
		ros_basics::demo msg;
		//Inserted data to message header

  
	       std::stringstream ss;
	       ss << "hello world ";
	       msg.greeting = ss.str();

		msg.number = number_count;
		//Printing message data
		ROS_INFO("%d",msg.number);
		ROS_INFO("%s",msg.greeting.c_str());

		//Publishing the message
		number_publisher.publish(msg);
		//Spining once for doing the  all operation once
		ros::spinOnce();
		//Setting the loop rate
		loop_rate.sleep();
		//Increamenting the count
		++number_count;
	
	

	}
	
	return 0;
}