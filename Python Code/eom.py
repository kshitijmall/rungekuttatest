def eom (t,x):
################################################################################
## eom calculates the state derivative vectors at the given time and states
#
#  Author: Kshitij Mall
#
#  Modified: 18 February 2019
#  Parameters:
#
#    Input: double t, the given time.
#
#           double x, the given state vector.
#
#    Output: double xdot: the state derivative vector
#
################################################################################
# Import the necessary packages
    import numpy as np
    # Inputs to calculate the state derivatives
    g = 9.80665
    re = 6378000
    B = 157
    rho0 = 1.225
    H = 7200
    xdot = [x[1]*np.sin(x[2]),\
           -rho0*np.exp(-x[0]/H)*x[1]**2/(2*B)-g*np.sin(x[2]),\
           (x[1]/(re+x[0]) - g/x[1])*np.cos(x[2])] 
    return xdot # Calculate the state derivative vector
