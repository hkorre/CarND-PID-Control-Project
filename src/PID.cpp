#include "PID.h"

#include <iostream>
//#include <time.h>       // time_t, struct tm, difftime, time, mktime
#include <chrono>

#define LOOP_TIME_MS    (100)
#define MS_TO_SEC       (0.001)
#define ERROR_SUM_MAX   (5)


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

  if (timeDiff_ms.count() > LOOP_TIME_MS) {
    double timeDiff_sec = static_cast<double>(timeDiff_ms.count())*MS_TO_SEC;

    // P error...
    p_error = Kp * cte_;

    // I error...
    error_sum += cte_;
    if (error_sum > ERROR_SUM_MAX) {
      error_sum = ERROR_SUM_MAX;
    }
    if (error_sum < (-1)*ERROR_SUM_MAX) {
      error_sum = ERROR_SUM_MAX;
    }
    i_error = Ki * error_sum*timeDiff_sec;

    // D error...
    double error_deriv = (cte_ - error_last) / timeDiff_sec;
    error_last = cte_;
    d_error = Kd  * error_deriv;

    last_time = now;

    //std::cout << "P: " << p_error << "  I: " << i_error << "  D: " << d_error << std::endl;
    //std::cout << std::endl;
  }
}

double PID::TotalError() {
  return (p_error + i_error + d_error);
}

