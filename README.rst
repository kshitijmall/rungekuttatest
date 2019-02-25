==============================================================
Runge Kutta 4 Solution for a Hypersonics Initial Value Problem
==============================================================

:Author: Kshitij Mall
:Contact: mall@purdue.edu
:URL: https://github.com/kshitijmall/rungekuttatest
:Atom: |atom|
:Python: |version1|
:Cython: |version2|
:readthedocs: |docs|

.. |atom| image:: https://img.shields.io/badge/ATOM-1.34-brightgreen.svg
        :target: https://atom.io/
.. |version1| image:: https://img.shields.io/badge/Python-3.6.8-blue.svg
        :target: https://www.python.org/downloads/release/python-370/
.. |version2| image:: https://img.shields.io/badge/Cython-0.29.5-green.svg
        :target: https://pypi.org/project/Cython/
.. |docs| image:: https://readthedocs.org/projects/rk4test-docs/badge/?version=latest
        :target: https://rk4test-docs.readthedocs.io/en/latest/?badge=latest
        :alt: Documentation Status


Description
----------------

This mini project includes three ways of solving an initial value problem (IVP)
using 4th order Runge Kutta method. First approach uses a pure python file, second
uses python and cython, third includes a pure C++ approach.


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
::
  $sh run.sh

The run shell script would run the python code first, cython code next and finally 
the C++ code. The computation times for these three approaches are displayed. 


Observations
------------

As expected, the Python code takes the most time to compute the results using the RK4
function. Cython is around 30X faster than the Python code. C++ is the fastest and is 
around 125X faster than Python and around 4X faster than Cython.


Documentation
-------------

Please see the documentation at `rk4test-docs.readthedocs.io <https://rk4test-docs.readthedocs.io/en/latest/>`_.


Aknowledgements
---------------

`AAE 590 Hypersonics & Design <https://engineering.purdue.edu/~mjgrant/syllabus-2.pdf>`_ by Professor Michael Grant
Purdue Air Link

.. Local Variables:
.. mode: text
.. coding: utf-8
.. fill-column: 70
.. End:
