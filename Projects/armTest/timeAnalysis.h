
#ifndef TIMEANALYSIS_H_
#define TIMEANALYSIS_H_

#include <time.h>

//  Prototypes:
double getCpuTime(clock_t start, clock_t end);
double getDayTime(int start_sec, int start_usec, int end_sec, int end_usecd);
void getTimingReport(double cpuTime, double dayTime, int interrupts);

#endif
