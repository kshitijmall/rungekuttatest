#!/bin/bash
#
# This shell code executes the main python module, main cython module and the cpp file.
cd Python\ Code/
python ./main.py
cd ..
cd Cython\ Code/
python setup.py build_ext --inplace
python ./main.py
cd ..
cd C++\ Code/
make main
./main
