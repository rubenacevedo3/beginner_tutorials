/**
 *@author Ruben Acevedo
 *@file changeBaseOutputString.cpp
 *@brief This is the ".cpp" file for the changeBaseOutput service
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

#include <string>
#include "ros/ros.h"
#include "beginner_tutorials/changeBaseOutputString.h"
#include "std_msgs/String.h"

bool changeS(const beginner_tutorials::changeBaseOutputString::Request  &req,
  const beginner_tutorials::changeBaseOutputString::Response &res) {
  // res.out = req.in;
  // ROS_INFO("request: s= ""%s", (std::string)req.in);
  // ROS_INFO("sending back response: [""%s\n""]", (std::string)res.out);
  return true;
}

int main(int argc, char **argv) {
  // ros::init(argc, argv, "changeBaseOutputString");
  // ros::NodeHandle n;

  // ros::ServiceServer service = n.advertiseService
  //  ("changeBaseOutputString", changeS);
  // ROS_INFO("Ready to change the string");
  // ros::spin();

  return 0;
}
