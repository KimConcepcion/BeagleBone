
#include <stdio.h>
#include <time.h>
#include "timeAnalysis.h"

double getCpuTime(clock_t start, clock_t end)
{
    //  Return the cputime:
    return ((double) (end - start)) / CLOCKS_PER_SEC;
}

double getDayTime(int start_sec, int start_usec, int end_sec, int end_usec) {

    //  Get time in us:
    int interval = 1000000 * (end_sec - start_sec)
                                + (end_usec - start_usec);

    //  Return elapsed time in ms:
    return ((double) interval / 1000) ;
}

void getTimingReport(double cpuTime, double dayTime, int interrupts)
{
    printf("###### Timing Report ######\n");
    printf("[ Elapsed cpu-time: %.2lf ms ]\n", cpuTime*1000.0);
    printf("[ Elapsed day-time: %.2lf ms ]\n", dayTime);
    printf("[ Time according to amount of interrupts: %d ms ]\n", interrupts);
    printf("###### Timing Report ######\n");
}
