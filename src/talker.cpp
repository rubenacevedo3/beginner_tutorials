/**
 *@author Ruben Acevedo
 *@file talker.cpp
 *@brief This is the ".cpp" file for the talker node
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

#include <tf/transform_broadcaster.h>
#include <sstream>
#include "ros/ros.h"
#include "std_msgs/String.h"

/**
* This tutorial demonstrates simple sending of messages over the ROS system.
*/
int main(int argc, char **argv) {
   /**
    * The ros::init() function needs to see argc and argv so that it can perform
    * any ROS arguments and name remapping that were provided at the command line.
    * For programmatic remappings you can use a different version of init() which takes
    * remappings directly, but for most command-line programs, passing argc and argv is
    * the easiest way to do it.  The third argument to init() is the name of the node.
    *
    * You must call one of the versions of ros::init() before using any other
    * part of the ROS system.
    */
  ros::init(argc, argv, "talker");
   /**
    * NodeHandle is the main access point to communications with the ROS system.
    * The first NodeHandle constructed will fully initialize this node, and the last
      * NodeHandle destructed will close down the node.
      */
  ros::NodeHandle n;

     /**
      * The advertise() function is how you tell ROS that you want to
      * publish on a given topic name. This invokes a call to the ROS
      * master node, which keeps a registry of who is publishing and who
      * is subscribing. After this advertise() call is made, the master
      * node will notify anyone who is trying to subscribe to this topic name,
      * and they will in turn negotiate a peer-to-peer connection with this
      * node.  advertise() returns a Publisher object which allows you to
      * publish messages on that topic through a call to publish().  Once
      * all copies of the returned Publisher object are destroyed, the topic
      * will be automatically unadvertised.
      *
      * The second parameter to advertise() is the size of the message queue
      * used for publishing messages.  If messages are published more quickly
      * than we can send them, the number here specifies how many messages to
      * buffer up before throwing some away.
      */
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);

  ros::Rate loop_rate(10);

     /**
      * A count of how many messages we have sent. This is used to create
      * a unique string for each message.
      */
  int count = 0;

  /**
   * This creates a transform broadcaster
   */
  static tf::TransformBroadcaster br;
  /**
   * This creates a transform
   */
  tf::Transform transform;

  while (ros::ok()) {
    /**
     * This creates the tf frame called /talk with parent /world
     */  
    transform.setOrigin(tf::Vector3(6.0, 2.0, 5.0));
    tf::Quaternion q;
    q.setRPY(0.5, 0.5, 1);
    transform.setRotation(q);
    br.sendTransform(tf::StampedTransform(transform, ros::Time::now(),
       "/world", "/talk"));

      /**
       * This is a message object. You stuff it with data, and then publish it.
       */
    std_msgs::String msg;
    std::stringstream ss;
    ss << "I am pickle Rick!!!" << count;
    msg.data = ss.str();
    ROS_INFO("%s", msg.data.c_str());

      /**
       * The publish() function is how you send messages. The parameter
       * is the message object. The type of this object must agree with the type
       * given as a template parameter to the advertise<>() call, as was done
       * in the constructor above.
       */
    chatter_pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
    ++count;
    }
  return 0;
}
