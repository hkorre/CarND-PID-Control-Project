# Reflection

---

## Describe the effect each of the P, I, D components had in your implementation.

* P (Proportional Gain) - Responds to immediate differences between the process variable and the setpoint (i.e. error).
* I (Integral Gain) - Sums error over time. Used to get rid of systematic offsets.
* D (Derivative Gain) - Based on derivative of the error. Fights against strong, sudden movements.


## Describe how the final hyperparameters were chosen.

1. Started with P. Generally P is tuned to respond to the error quickly: To quickly make up the error, overshoot and then cause oscillations. In this situation, I significantly lowered the P value: The P value chosen does make up the error, overshoot and oscillate, BUT it takes a long time to make up the error. I did this because it gave a smoother motion which more closely resembled the driving behaviour of a human.
2. Tuned D. I used D to dampen out the oscillations to the point that they are very minor.
3. Tune I. I tuned I to make sure the system would hover around 0 cte instead of at an offset.

All my PID paraameters are very small in order to have smooth motion that resembled a human driving.
