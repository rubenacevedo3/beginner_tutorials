#include "ros/ros.h"
#include "beginner_tutorials/changeBaseOutputString.h"
#include <string>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "changeBaseOutputStringClient");
  if (argc != 2)
  {
    ROS_WARN("enter only one string");
    return 1;
  }

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<beginner_tutorials::changeBaseOutputString>("changeBaseOutputString");
  beginner_tutorials::changeBaseOutputString srv;
  srv.request.in = atoll(argv[1]);
  if (client.call(srv))
  {
    ROS_INFO("Change string to: %s \n", (std::string)srv.response.out);
  }
  else
  {
    ROS_ERROR("Failed to call service changeBaseOutputString");
    return 1;
  }

  return 0;
}
