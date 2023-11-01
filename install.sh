#!/bin/bash

repository="https://github.com/MertGunduz/yiffy.git"

echo "This is a example install.sh file, it doesn't check for packages needed for installing yiffy currently."
echo "You need to install the needed packages by yourself, please check the github page."
echo "This script will build yiffy from source. Do you want to continue? (y/n)?"

read input

if [ "$input" == "n" ]; then
echo " "

elif [ "$input" == "y" ]; then
echo "Starting..."
git clone "$repository"
cd yiffy
mkdir build
cd build
cmake ..
make
sudo cmake --install .

else
echo "Invalid input, please try it again."

fi
