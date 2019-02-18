#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include <time.h>
//#include <cmath>
using namespace std;
using namespace std::chrono;

const int N = 1000; // time steps
const double g = 9.80665;
const double re = 6378000.0;
const double B = 157.0;
const double rho0 = 1.225;
const double H = 7200.0;

double * eom(double t, double x[]);
double ** rk4(double a, double b, int N, double alpha[]);
void printResult(double ** result);

//******************************************************************************

int main (int argc, const char * argv[]) {

//******************************************************************************
//
//  Purpose:
//
//    MAIN is the main program for RK4.
//
//  Discussion:
//
//    RK4_PRB tests the RK4 library.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    17 February 2019
//
//  Author:
//
//    Kshitij Mall
//
cout << "\n" << "C++ version\n";
cout << "Test the RK4 function.\n";

const double vatm = 11060.0; // Entry Velocity, m/s
const double hatm = 80000.0; // Entry Height, m
const double gamma0 = -50.0/180.0*M_PI; // Initial flight path angle, rad

const double t0 = 0.0; // initial time
const double tf = 206.0; // final time

double init[] = {hatm,vatm,gamma0}; // Initial guess

// Get starting timepoint
clock_t t;
	t = clock();
double ** result = rk4(t0, tf, N, init);

// Get ending timepoint
t = clock() - t;
	cout << "Computation Time: " << t*1.0/CLOCKS_PER_SEC << " seconds" << endl;

//printResult(result);
return 0;
}

// Function for equations of motion
double * eom(double t, double x[]) {

    static double xdot[3];

    xdot[0] = x[1]*sin(x[2]);
    xdot[1] = -rho0*exp(-x[0]/H)*pow(x[1],2.0)/(2.0*B) - g*sin(x[2]);
    xdot[2] = (x[1]/(re+x[0]) - g/x[1])*cos(x[2]);

    return xdot;
}

double ** rk4(double a, double b, int N, double alpha[]){

  double ** state = new double*[N];

  double h = double((b-a)/N); // The step size
  double * k1, * k2, * k3, * k4, t[N], k2inp[3], k3inp[3], k4inp[3];

  for (int i = 0; i < N+1; ++i) {
       state[i] = new double[N];
       if(i == 0){
         t[i] = a;
         state[i][0] = alpha[0];
         state[i][1] = alpha[1];
         state[i][2] = alpha[2];
       }
       else{
         // Determine k1
         k1 = eom(t[i-1], state[i-1]);

         // Determine k2
         for (int j = 0; j < 3; ++j) {
          k2inp[j]  = state[i-1][j]+0.5*k1[j];
         }
         k2 = eom(t[i-1] + h/2.0, k2inp);

         // Determine k3
         for (int j = 0; j < 3; ++j) {
          k3inp[j]  = state[i-1][j]+0.5*k2[j];
         }
         k3 = eom(t[i-1] + h/2.0, k3inp);

         // Determine k4
         for (int j = 0; j < 3; ++j) {
          k4inp[j]  = state[i-1][j]+k3[j];
         }
         k4 = eom(t[i-1] + h, k4inp);

         // Determine new result
         for (int j = 0; j < 3; ++j) {
           state[i][j] = state[i-1][j] + h*(k1[j] + 2.0*k2[j] + 2.0*k3[j] + k4[j])/6.0;
         }
         t[i] = t[i-1] + h;
       }
  }
  
  return state;
}

void printResult(double ** state){
  for (int i = 0; i < N+1; ++i) {
    for (int j = 0; j < 3; ++j) {
      cout << "state[" <<i<<"][" <<j <<"] = " << state[i][j] << " ";
    }
    cout << endl;
  }

}
