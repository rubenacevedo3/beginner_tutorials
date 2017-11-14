# beginner_tutorials

## Overview

This Week 11 Hw is on learning and implementing ROS TF, unit testing, and bag files using the talker and listener nodes we created a couple weeks ago.

## License

MIT License

Copyright 2017 Ruben Acevedo 

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
© 2017 GitHub, Inc.

## Dependencies

* ROS Kinetic
* Catkin
* roscpp package
* std_msgs package
* message_generation package
* tf package

## Build/Run Steps

First, create and build a catkin workspace if you do not have one already

```
$ mkdir -p ~/catkin_ws/src
$ cd ~/catkin_ws/
$ catkin_make
```

To add your catkin workspace into the ROS enviroment you need to source the generated setup file.

```
$ . ~/catkin_ws/devel/setup.bash
```

To download this repository to your catkin workpace do the following steps:

```
$ cd ~/catkin_ws/src
$ mkdir week11hw
$ cd week11hw
$ git clone --recursive https://github.com/rubenacevedo3/beginner_tutorials.git
$ git pull origin Week11_HW
```

To build any catkin projects found in the src folder use: 
```
# In a catkin workspace
$ catkin_make
```

To build any test found in the test folder use: 
```
# In a catkin workspace
$ catkin_make test
```

To run the launch file:

(In terminal 1)
```
$ roscore
```

(In terminal 2)
```
$ cd ~/catkin_ws
$ source ./devel/setup.bash
$ roslaunch beginner_tutorials modifyPubFreq.launch
```

To run the tests: 
(In terminal 3)
```
$ cd ~/catkin_ws
$ source ./devel/setup.bash
$ rostest beginner_tutorials talkerTest.launch
```

## Run cpplint 

Use cpplint to identify potential source code issues that are in conflict with the Google C++ style guide. 

To install and run from terminal:

```
$ sudo apt-get install python-pip
$ sudo pip install cpplint
$ cd ~/catkin_ws/src/week11hw/beginner_tutorials
$ cpplint $( find . -name \*.hpp -or -name \*.cpp | grep -vE -e "^./build/" -e "^./vendor/" -e "^./docs/" -e "^./results" )
```

## Run cppcheck 

Use cppcheck for static code analysis.

To run from terminal:

```
$ cd ~/catkin_ws/src/week11hw/beginner_tutorials
$ cppcheck --enable=all --std=c++11 -I include/ --suppress=missingIncludeSystem $( find . -name *.cpp | grep -vE -e "^./build/" -e "^./vendor/" )
```
