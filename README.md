# beginner_tutorials

## Overview

This Week 10 Hw is on learning and implementing ROS Services, Logging and Launch files using the talker and listener nodes we created the previous week.

## License

MIT License

Copyright 2017 Ruben Acevedo 

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
© 2017 GitHub, Inc.


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
$ mkdir -p ~/week10hw
$ cd ~/week10hw
$ git clone --recursive https://github.com/rubenacevedo3/beginner_tutorials.git
$ git pull origin Week10_HW
```

To build any catkin projects found in the src folder use: 
```
# In a catkin workspace
$ catkin_make
```

## How to run cpplint 

Use cpplint to identify potential source code issues that are in conflict with the Google C++ style guide. 

To install and run from terminal:

wget https://raw.githubusercontent.com/google/styleguide/gh-pages/cpplint/cpplint.py (Links to an external site.)
Change permission to executable: chmod +x cpplint.py
cd <repository>
Run cpplint
Example run with cpp-boilerplate (cpplint.py is in the parent directory):

cd cpp-boilerplate

../cpplint.py --extensions=h,hpp,cpp $( find . -name *.h -or -name *.hpp -or -name *.cpp | grep -vE -e "^./build/" -e "^./vendor/" )

This command runs cpplint.py and tells the script to examine files with extension .h, .hpp, or .cpp. The script expects a list of files so the bash command first finds all files in the directory and sub-directories that have the extension .h, .hpp, or .cpp. It then excludes any file found in the build or vendor sub-directories.

## How to run cppcheck 

Use cppcheck for static code analysis using the command-line from repository root "RoboDogVoiceController-eclipse"

cppcheck --enable=all --std=c++11 -I include/ --suppress=missingIncludeSystem $( find . -name *.cpp | grep -vE -e "^./build/" -e "^./vendor/" )
