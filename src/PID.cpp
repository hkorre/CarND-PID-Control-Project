#include "PID.h"

#include <iostream>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  // set coeffs
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;

  // other...
  error_sum = 0;
  error_last = 0;

  std::cout << "PID initialized." << std::endl;
}

void PID::UpdateError(double cte_) {
  // P error...
  p_error = Kp * cte_;

  // I error...
  error_sum += cte_;
  i_error = Ki * error_sum;

  // D error...
  double error_diff = cte_ - error_last;
  error_last = cte_;
  d_error = Kd  * error_diff;

  std::cout << "UpdateError() done." << std::endl;
}

double PID::TotalError() {
  return (p_error + i_error + d_error);
}

