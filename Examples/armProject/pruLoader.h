#ifndef PRULOADER_H_
#define PRULOADER_H_

#include <sys/time.h>
#include <time.h>

/* DEFINES */
#define PRU0 0
#define PRU1 1

/**
 * Initialize and open pru's:
 */
int pruInit(int pruNum);

/**
 * Start the clock program on specified pru:
 */
void pruClock(char *program);

#endif
