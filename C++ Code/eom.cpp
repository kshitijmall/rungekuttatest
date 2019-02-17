#include <iostream>
#include <math.h>
using namespace std;

// function to generate and retrun random numbers.
double * eom(double t, double x[]) {

    const double g = 9.80665;
    const double re = 6378000.0;
    const double B = 157.0;
    const double rho0 = 1.225;
    const double H = 7200.0;
    static double xdot[3];

    xdot[0] = x[1]*sin(x[2]);
    xdot[1] = -rho0*exp(-x[0]/H)*pow(x[1],2.0)/(2*B)-g*sin(x[2]);
    xdot[2] = (x[1]/(re+x[0]) - g/x[1])*cos(x[2]);

    cout << xdot[0] << "\n" << xdot[1] << "\n" << xdot[2] << "\n";
    return xdot;
}
