# beginner_tutorials

Make sure that a roscore is up and running:

$ roscore

catkin specific If you are using catkin, make sure you have sourced your workspace's setup.sh file after calling catkin_make but before trying to use your applications:

# In your catkin workspace
$ cd ~/catkin_ws
$ source ./devel/setup.bash

In the last tutorial we made a publisher called "talker". Let's run it:

$ rosrun beginner_tutorials talker      (C++)


You will see something similar to:

    [INFO] [WallTime: 1314931831.774057] I am pickle Rick 1314931831.77


The publisher node is up and running. Now we need a subscriber to receive messages from the publisher.

Running the Subscriber

In the last tutorial we made a subscriber called "listener". Let's run it:

$ rosrun beginner_tutorials listener     (C++)


You will see something similar to:

    [INFO] [WallTime: 1314931969.258941] /listener_17657_1314931968795I heard I am pickle Rick 1314931969.26
