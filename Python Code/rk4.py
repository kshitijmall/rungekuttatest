def rk4 (a, b, N, alpha):
#
## RK4VEC takes one Runge-Kutta step for a vector ODE.
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
#    Input, real a, the current time.
#
#    Input, integer b, the spatial dimension.
#
#    Input, real N, the solution estimate at the current time.
#
#    Input, real alpha, the time step.
#
#    Output, real U(M), the fourth-order Runge-Kutta solution
#    estimate at time T0+DT.
#
    import numpy as np
    import eom
    h = float((b-a))/N # The step size
    t = np.zeros ( N )
    t[0] = a # Initial time
    w = np.zeros ( (3, N) )
    w[:,0] = alpha # Initial value
    for i in range(N-1):
        k1 = h*np.ones (3)*eom.eom(t[i], w[:,i])
        k2 = h*np.ones (3)*eom.eom(t[i]+h/2, w[:,i]+0.5*k1)
        k3 = h*np.ones (3)*eom.eom(t[i]+h/2, w[:,i]+0.5*k2)
        k4 = h*np.ones (3)*eom.eom(t[i]+h, w[:,i]+k3)
        w[:,i+1] = w[:,i] + (k1 + 2.0*k2 + 2.0*k3 + k4)/6.0
        t[i+1] = t[i] + h
    return t, w
