#include "ros/ros.h"
#include "beginner_tutorials/changeBaseOutputString.h"
#include "std_msgs/String.h"
#include <string>

bool changeS(beginner_tutorials::changeBaseOutputString::Request  &req,
  beginner_tutorials::changeBaseOutputString::Response &res)
{
  res.out = req.in;
  ROS_INFO("request: s=%s \n", (std::string)req.in);
  ROS_INFO("sending back response: [%s \n]", (std::string)res.out);
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "changeBaseOutputString");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("changeBaseOutputString", changeS);
  ROS_INFO("Ready to change the string");
  ros::spin();
 
  return 0;
}
