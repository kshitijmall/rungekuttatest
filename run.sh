#!/bin/bash
#
# This shell code executes the main python module.
# It reads the input in the main file and then calls the rk4 and eom files.
# It obtains the energy plot based on the datet obtained for h and v.
cd Python\ Code/
python ./main.py
cd ..
cd C++\ Code/
make main
./main
