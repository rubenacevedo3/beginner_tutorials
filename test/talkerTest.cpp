/**
 * @author Ruben Acevedo
 * @file talkerTest.cpp
 * @brief This is the ".cpp" file for testing the talker node
 * @copyright [2017] Ruben Acevedo
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
#include <tf/transform_listener.h>
#include <src/talker.cpp>
#include <gtest/gtest.h>

//! test the talker broadcaster
/**
 * This tests makes sure that the talker does not broadcast a 
 * zero translation. 
 *
 */
TEST(talkerTest, noZeroTranslationTest) {
  ros::init();
  ros::NodeHandle node;
  /**
   *Create the listener to see what talker is broadcasting
   */
  tf::TransformListener listener;
  ros::Rate rate(10.0);
  int i = 0;
  while (i < 100) {
    tf::StampedTransform transform;
    /**
     * listens to the latest transform from frame /world to frame /talker
     * and saves it as transform. 
     */
    try {
      listener.lookupTransform("/talker", "/world",
                               ros::Time(0), transform);
    }
    /**
     * to have a non zero translation at least one has to be none zero
     */
    EXPECT_TRUE(transform.getOrigin().x() != 0 || 
      transform.getOrigin().y() != 0 ||
      transform.getOrigin().z() != 0);
    rate.sleep();
    i++;
  }
}


int main(int argc,
         char **argv)
{
  ros::init(argc, argv, "talkerTest");
  nh.reset(new ros::NodeHandle);
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

