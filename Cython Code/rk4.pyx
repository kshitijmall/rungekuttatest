# cython: profile=True
# cython: boundscheck=False
# cython: wraparound=False
# cython: cdivision=True
# cython: profile=True
cimport numpy as cnp

from libc.math cimport (cos, sin, exp, pow) # Import all C-based libraries

cnp.import_array() # This step is needed for ndarrays to work

cpdef rk4 (double a, double b, int N, int M, cnp.ndarray[cnp.float64_t,ndim=1] alpha):
################################################################################
## RK4 calculates the state values for each time step
#
#  Author: Kshitij Mall
#
#  Modified: 24 February 2019
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

# Declare and initialize all the necessary constants and variables for RK4 method
  cdef:
      double h = (b-a)/N # The step size
      cnp.npy_intp *dim1 = [N]
      cnp.npy_intp *dim2 = [M,N]
      cnp.ndarray[cnp.float64_t,ndim=1,mode='c'] t = \
       cnp.PyArray_EMPTY(1, dim1, cnp.NPY_DOUBLE, 0)
      cnp.ndarray[cnp.float64_t,ndim=2,mode='c'] w = \
       cnp.PyArray_EMPTY(2, dim2, cnp.NPY_DOUBLE, 0)
      Py_ssize_t i, j # Needed to handle 64-bit architectures
      cnp.ndarray[cnp.float64_t,ndim=1,mode='c'] k1, k2, k3, k4
      cnp.ndarray[cnp.float64_t,ndim=1,mode='c'] k2inp = \
       cnp.PyArray_EMPTY(1, dim1, cnp.NPY_DOUBLE, 0)
      cnp.ndarray[cnp.float64_t,ndim=1,mode='c'] k3inp = \
       cnp.PyArray_EMPTY(1, dim1, cnp.NPY_DOUBLE, 0)
      cnp.ndarray[cnp.float64_t,ndim=1,mode='c'] k4inp = \
       cnp.PyArray_EMPTY(1, dim1, cnp.NPY_DOUBLE, 0)

  t[0] = a # Initial time
  for j in range(M):
      w[j,0] = alpha[j] # Insert initial value input as the first row of the state
  # Obtain the states for the given times using rk4
  for i in range(N-1):
      k1 = eom(t[i], w[:,i]) # Calculate k1 for each time inputs
      for j in range(M):
          k2inp[j] = w[j,i]+0.5*k1[j]
      k2 = eom(t[i]+h/2, k2inp) # Calculate k2 for each time inputs
      for j in range(M):
          k3inp[j] = w[j,i]+0.5*k2[j]
      k3 = eom(t[i]+h/2, k3inp) # Calculate k3 for each time inputs
      for j in range(M):
          k4inp[j] = w[j,i]+k3[j]
      k4 = eom(t[i]+h, k4inp) # Calculate k4 for each time inputs
      t[i+1] = t[i] + h # Update the time values
      # Update the state matrix with k1, k2, k3, k4, and old state value
      for j in range(M):
          w[j,i+1] = w[j,i] + h*(k1[j] + 2.0*k2[j] + 2.0*k3[j] + k4[j])/6.0
  return t, w # Return the time and state vectors

cdef eom (double t, cnp.ndarray[cnp.float64_t,ndim=1] x):
################################################################################
## eom calculates the state derivative vectors at the given time and states
#
#  Author: Kshitij Mall
#
#  Modified: 24 February 2019
#  Parameters:
#
#    Input: double t, the given time.
#
#           double vector x, the given state vector.
#
#    Output: double xdot: the state derivative vector
#
################################################################################

  # Inputs to calculate the state derivatives
  cdef:
      double g = 9.80665 # Acceleration due to gravity, m/s^2
      double re = 6378000.0 # Radius of Earth, m
      double B = 157.0 # Ballistic Coefficient, kg/m^2
      double rho0 = 1.225 # Surface atmospheric density, kg/m^3
      double H = 7200.0 # Scale height, m
      cnp.npy_intp *dims = [3] # Dimension of the derivative vector
      cnp.ndarray[cnp.float64_t,ndim=1,mode='c'] xdot = \
        cnp.PyArray_EMPTY(1, dims, cnp.NPY_DOUBLE, 0)
  xdot[0] = x[1]*sin(x[2])
  xdot[1] = -rho0*exp(-x[0]/H)*pow(x[1],2)/(2*B)-g*sin(x[2])
  xdot[2] = (x[1]/(re+x[0]) - g/x[1])*cos(x[2])
  return xdot # Calculate the state derivative vector
