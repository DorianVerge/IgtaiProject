              Dlib C++ Installation in Ubuntu 18.04 LTS

Download the latest version from the official website of Dlib library http://dlib.net/
extract the downloaded file by right clicking on it.

commands for installing required OS Libraries 

$ sudo apt-get install build-essential cmake pkg-config
$ sudo apt-get install libx11-dev libatlas-base-dev
$ sudo apt-get install libgtk-3-dev libboost-python-dev
$ sudo apt-get install libx11-dev
$ sudo apt-get install libblas-dev liblapack-dev

commands for installing dlib 
$ wget http://dlib.net/files/dlib-19.20.tar.bz2
$ tar xvf dlib-19.20.tar.bz2
$ cd dlib-19,20/
$ mkdir build
$ cd build
$ cmake ..
$ sudo cmake --build . --target install
$ sudo make install
$ sudo ldconfig