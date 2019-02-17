#include <iostream>
#include <math.h>
// #include "eom.h"
using namespace std;

#define PI 3.14159265
const double g = 9.80665;
const double re = 6378000.0;
const double B = 157.0;
const double rho0 = 1.225;
const double H = 7200.0;
const int N = 1000; // time steps

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
//    16 February 2019
//
//  Author:
//
//    Kshitij Mall
//
cout << "\n" << "C++ version\n";
cout << "Test the RK4 library.\n";

const double vatm = 11060.0; // Entry Velocity, m/s
const double hatm = 80000.0; // Entry Height, m
const double gamma0 = -50/180*PI; // Initial flight path angle, rad

const double t0 = 0.0; // initial time
const double tf = 500.0; // final time

double init[] = {hatm,vatm,gamma0}; // Initial guess

double * result = eom(t0,init);
cout << result[0] << "\n" << result[1] << "\n" << result[2] << endl;
double ** result2 = rk4(t0, tf, N, init);
printResult(result2);
return 0;
}

// function to generate and retrun random numbers.
double * eom(double t, double x[]) {
    //int * xdot = new int[3];
    static double xdot[3];

    xdot[0] = x[1]*sin(x[2]);
    xdot[1] = -rho0*exp(-x[0]/H)*pow(x[1],2.0)/(2*B)-g*sin(x[2]);
    xdot[2] = (x[1]/(re+x[0]) - g/x[1])*cos(x[2]);

    return xdot;
}

double ** rk4(double a, double b, int N, double alpha[]){

  double ** result = new double*[N];

  double h = double((b-a)/N); // The step size
  static double * k1, * k2, * k3, * k4;
  double * t[N];
  for (int i = 0; i < N; ++i) {
       result[i] = new double[N];
       if(i == 0){
         t[i] = a;
         result[i][1] = alpha[0];
         result[i][2] = alpha[1];
         result[i][3] = alpha[2];
       }
       else{
         result[i][0] = result[i-1][0] + h;
         for (int j = 0; j < 3; ++j) {
         //result[i][j] = result[i-1][j] + i + j;
         k1 = eom(t[i-1], result[i-1][j]);
         k2 = eom(t[i-1]+h/2, result[i-1][j]+0.5*k1[j]);
         k3 = eom(t[i-1]+h/2, result[i-1][j]+0.5*k2[j]);
         k4 = eom(t[i-1]+h, result[i-1][j]+k3[j]);
         result[i][j] = result[i-1][j] + h*(k1[j] + 2.0*k2[j] + 2.0*k3[j] + k4[j])/6.0;
         }
       }
  }
  return result;
}

void printResult(double ** result){
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < 4; ++j) {
      cout << "result[" <<i<<"][" <<j <<"] =" << result[i][j];
    }
    cout << endl;
  }

}
