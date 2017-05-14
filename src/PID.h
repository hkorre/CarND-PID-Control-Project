#ifndef PID_H
#define PID_H

#include <chrono>


class PID {
public:
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;

  double error_sum;
  double error_last;

  std::chrono::high_resolution_clock::time_point last_time;
  

  /*
  * Coefficients
  */ 
  double Kp;
  double Ki;
  double Kd;

  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp_, double Ki_, double Kd_);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte_);

  /*
  * Calculate the total PID error.
  */
  double TotalError();
};

#endif /* PID_H */
