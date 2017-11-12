/**
 *@author Ruben Acevedo
 *@file changeBaseOutputStringClient.cpp
 *@brief This is the ".cpp" file for the changeBaseOutput client
 *@copyright [2017] Ruben Acevedo
 *
 */

/**
 * MIT License
 *
 * Copyright 2017 Ruben Acevedo
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without
 * limitation the rights to use, copy, modify, merge, publish, distribute,
 * sublicense, and/or sell copies of the Software, and to permit persons to
 * whom the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software. THE SOFTWARE IS
 * PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE. © 2017 GitHub, Inc.
 */
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
