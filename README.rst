====================================
Runge Kutta Based IVP Problem Solver
====================================

:Author: Kshitij Mall
:Contact: mall@purdue.edu
:URL: https://github.com/kshitijmall/rungekuttatest
:Atom: |atom|
:Python: |version|

.. |atom| image:: https://img.shields.io/badge/ATOM-1.34-brightgreen.svg
        :target: https://atom.io/
.. |version| image:: https://img.shields.io/badge/Python-3.7-blue.svg
        :target: https://www.python.org/downloads/release/python-370/


Description
----------------

This mini project includes three ways of solving an IVP using 4th order Runge
Kutta method. First approach uses a pure python file, second uses python and
cython, third includes a pure C++ approach.


Approach
--------

The main python file is named as main. This main file calls the rk4 function
file, which in turn calls the eom files to compute the values of k1, k2, k3 and
k4 used in the Runge-Kutta 4 formula. This project was developed using Python
3.6.8 and fix for using it with Python 2 is yet to be included. An error is
raised if an unexpected situation arises.

The optimized Cython code comprises of a main file, an RK4 file and a setup file. 
The RK4 file with an extension of pyx contains the eom and rk4 functions. The main
file is very similar to the Python code, but the rk4.pyx has optimized cython code.
The setup file is used to compile and build the cython code. 

The C++ file consists only one main file, which includes the eom and rk4
functions as well. This file is heavily commented and the user would notice
that the approach is very similar to the python code, where the idea is to
compute the values of k1, k2, k3, and k4 to compute the new state values based
on the RK4 formula.


Usage
-----

To run the code from the terminal, the user can just clone/download the files
and then use the terminal to run the shell script named run. To run such a
shell script, the user need to just type:
sh run.sh

The run shell script would run the python code first, cython code next and finally 
the C++ code. The computation times for the given hypersonic IVP are shown for these 
three approaches. 

Observations
------------

As expected, the Python code takes the most time to compute the results using the RK4
function. Cython is around 30X faster than the python code. C++ is the fastest of the
three and is around 125X faster than Python and around 4X faster than Cython.

Aknowledgements
---------------

Purdue Air Link

.. Local Variables:
.. mode: text
.. coding: utf-8
.. fill-column: 70
.. End:
