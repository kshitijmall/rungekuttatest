# Runge Kutta Based IVP Problem Solver
This mini project includes three ways of solving an IVP using 4th order Runge Kutta method. First approach uses a pure python file, second uses python and cython, third includes a pure C++ approach. 

## Approach

The main python file is named as main. This main file calls the rk4 function file, which in turn calls the eom files to compute the values of k1, k2, k3 and k4 used in the Runge-Kutta 4 formula. This project was developed using Python 3.7 and fix for using it with Python 2 is yet to be included. An error were raised if an unexpected situation arised. 

The C++ file consists only one main file, which includes the eom and rk4 functions as well. This file is heavily commented and the user would notice that the approach is very similar to the python code, where the idea is to compute the values of k1, k2, k3, and k4 to compute the new state values based on the RK4 formula. 

## Running the code

To run the code from the terminal, the user can just clone/download the files and then use the terminal to run the shell script named run. To run such a shell script, the user need to just type: 
sh run.sh

The run shell scripot would run the python code first and then the C++ code. The energy plot would be displayed for the python code along with the computation time. After the user closes the figure window of the energy plot, the C++ code would then execute and display the computation time for this hypersonics problem. 

## Built With

* [Atom](https://atom.io/) - Text and source code editor
* [Python](https://www.python.org/) Programming tool

## Author

* **Kshitij Mall**

## Acknowledgments

* Purdue Air Link

