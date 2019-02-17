double ** rk4(double a, double b, int N, alpha[3]){

  double ** result = new double*[N];
  double h = double((b-a)/N); // The step size
  result[0][0] = a;
  result[1][0] = alpha[0]; //# Initial value
  result[2][0] = alpha[1]; //# Initial value
  result[3][0] = alpha[2]; //# Initial value

  cout << result[0][0] << "\n" << result[1][0] << "\n" << result[2][0] << "\n" << result[3][0] << endl;
  static double k1[4], k2[4], k3[4], k4[4];

  for (int i = 0; i < N-1; ++i) {
    for (int j = 1; i < 4; ++j) {
        k1[j] = eom(result[0][i], result[j][i])[j];
        k2[j] = eom(result[0][i]+h/2, result[j][i]+0.5*k1[j])[j];
        k3[j] = eom(result[0][i]+h/2, result[j][i]+0.5*k2[j])[j];
        k4[j] = eom(result[0][i]+h, result[j][i]+k3[j])[j];
        result[j][i+1] = result[j][i] + h*(k1[j] + 2.0*k2[j] + 2.0*k3[j] + k4[j])/6.0;
        result[0][i+1] = result[0][i] + h;
        cout << result[0][i+1] << "\n";
        }
  }
  return result;
}

if(i == 0){
  result[0][0] = a;
  result[1][0] = alpha[0]; //# Initial value
  result[2][0] = alpha[1]; //# Initial value
  result[3][0] = alpha[2]; //# Initial value
  cout << result[0][0] << result[1][0] << result[2][0] << result[3][0] << endl;
}
else{







  for (int i = 0; i < N; ++i) {
       result[i] = new double[N];
        for (int j = 0; j < 4; ++j) {
        result[i][j] = i + j;
        }
  }
