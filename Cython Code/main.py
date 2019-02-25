import sys
import time
import numpy as np
import platform
import rk4

def input():
################################################################################
# main
#
#  Author: Kshitij Mall
#
#  Modified: 24 February 2019
#  Parameters:
#
#    Input: None
#
#    Output: real [t,y], the fourth-order Runge-Kutta solution
#
################################################################################

    print ( '' )
    print ( '  Test the RK4 Function with Cython.' )
    # Write the necessary inputs
    vatm = 11060 # Entry Velocity, m/s
    hatm = 80000 # Entry Height, m
    gamma0 = -50/180*np.pi # Initial flight path angle, rad
    t0 = 0 # Initial time
    tf = 212.2 # Final time
    step = 1000 # Time steps
    S = 3 # Number of states
    init = np.array([hatm,vatm,gamma0],np.float64) # Initial state vector

    try:
        tic = time.time() # Start the timer
        # Obtain the states for the given times using rk4
        [tout,y] = rk4.rk4(t0, tf, step, S, init)
        elapsed = time.time() - tic # Calculate the elapsed time
        # Print the computation time
        print('  Time taken by python with cython code:',elapsed)
    except:
        # In case of an unexpected error catch and raise an exception
        print("  Unexpected error:", sys.exc_info()[0])
        raise

"""The following if condition allows this python module to be imported by other modules
without calling main function. If desired, this main function can be called by
the other module that imports this module.
"""
if ( __name__ == '__main__' ):
   input ( )
