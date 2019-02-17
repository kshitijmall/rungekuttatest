def eom (t,x):
#
## eom includes all the dynamic constraints in the problem
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
#    Input, real T0, the current time.
#
#    Input, integer M, the spatial dimension.
#
#    Output, real U(M), the fourth-order Runge-Kutta solution
#    estimate at time T0+DT.
#
    import numpy as np
    g = 9.80665
    re = 6378000
    B = 157
    rho0 = 1.225
    H = 7200
    xdot = [x[1]*np.sin(x[2]),\
           -rho0*np.exp(-x[0]/H)*x[1]**2/(2*B)-g*np.sin(x[2]),\
           (x[1]/(re+x[0]) - g/x[1])*np.cos(x[2])]
    return xdot
