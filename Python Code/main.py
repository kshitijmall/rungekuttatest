import sys
import time
def input():
#
## main
#
#  Discussion:
#
#  Licensing: This code is distributed under the GNU LGPL license.
#
#  Author: Kshitij Mall
#
#  Modified: 13 February 2019
#  Parameters:
#
#    Input: None
#
#    Output, real U(M), the fourth-order Runge-Kutta solution
#    estimate at time T0+DT.
#
    import numpy as np
    import platform
    import rk4

    print ( '' )
    print ( '' )
    print ( '  Python version: %s' % ( platform.python_version ( ) ) )
    print ( '  Test the RK4 Function.' )

    vatm = 11060 # Entry Velocity, m/s
    hatm = 80000 # Entry Height, m
    gamma0 = -50/180*np.pi # Initial flight path angle, rad

    t0 = 0 # initial time
    tf = 500 # final time
    step = 2000 # time steps
    init = [hatm,vatm,gamma0]
    try:
        tic = time.time()
        [t,y] = rk4.rk4(t0, tf, step, init)
        elapsed = time.time() - tic
        print('Time taken by pure python code:',elapsed)
        import matplotlib
        import matplotlib.pyplot as plt
        matplotlib.use("TkAgg")
        plt.plot(y[1,:]/1000, y[0,:]/1000, linestyle='--', marker='o')
        plt.title('Energy Plot')
        plt.xlabel('Velocity [km/s]')
        plt.ylabel('Position [km]')
        plt.show()
    except IOError as err:
        print("I/O error: {0}".format(err))
    except:
        print("Unexpected error:", sys.exc_info()[0])
    raise

"""The following if condition allows this python module to be imported by other modules
without calling main function. If desired, this main function can be called by
the other module that imports this module.
"""
if ( __name__ == '__main__' ):
   input ( )
