#include "PID.h"

#include <iostream>
//#include <time.h>       // time_t, struct tm, difftime, time, mktime
#include <chrono>

#define LOOP_TIME_MS  (100)


using namespace std;

//using namespace std::chrono;

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
  last_time = std::chrono::high_resolution_clock::now();

  std::cout << "PID initialized." << std::endl;
}

void PID::UpdateError(double cte_) {
  
  std::chrono::high_resolution_clock::time_point now;
  now = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> timeDiff_ms = now - last_time;
  //std::cout << "timeDiff_ms = " << timeDiff_ms.count() << std::endl;

  if (timeDiff_ms.count() > LOOP_TIME_MS) {
    std::cout << "Update!" << std::endl;

    // P error...
    p_error = Kp * cte_;

    // I error...
    error_sum += cte_;
    i_error = Ki * error_sum;

    // D error...
    double error_diff = cte_ - error_last;
    error_last = cte_;
    d_error = Kd  * error_diff;

    last_time = now;
  }
}

double PID::TotalError() {
  return (p_error + i_error + d_error);
}

