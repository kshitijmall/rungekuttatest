def rk4 (a, b, N, M, alpha):
################################################################################
## RK4VEC takes one Runge-Kutta step for a vector ODE.
#
#
#  Author: Kshitij Mall
#
#  Modified: 18 February 2019
#  Parameters:
#
#    Input: double a, the initial time.
#
#           double b, the final time.
#
#           integer N, the time step.
#
#           integer M, the number of states.
#
#           double alpha, the initial state vector.
#
#    Output: double t, w: the fourth-order Runge-Kutta solution
#
################################################################################
# Import the necessary packages
    import numpy as np
    import eom
    h = float((b-a))/N # The step size
    t = np.zeros ( N ) # Initialize the time vector with zero values
    t[0] = a # Initial time
    w = np.zeros ( (M, N) ) # Initialize the state matrix with zero values
    w[:,0] = alpha # Insert initial value input as the first row of the state
    for i in range(N-1):
        # Calculate k1, k2, k3, and k4 for each time inputs
        k1 = h*np.ones (M)*eom.eom(t[i], w[:,i])
        k2 = h*np.ones (M)*eom.eom(t[i]+h/2, w[:,i]+0.5*k1)
        k3 = h*np.ones (M)*eom.eom(t[i]+h/2, w[:,i]+0.5*k2)
        k4 = h*np.ones (M)*eom.eom(t[i]+h, w[:,i]+k3)
        # Update the state matrix with k1, k2, k3, k4, and old state value
        w[:,i+1] = w[:,i] + (k1 + 2.0*k2 + 2.0*k3 + k4)/6.0
        t[i+1] = t[i] + h # Update the time values
    return t, w # Return the time and state vectors
