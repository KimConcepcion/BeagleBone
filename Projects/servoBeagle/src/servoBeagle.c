#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "pwm.h"

/**
 * Main function
 */
int main(int argc, char **argv)
{
    initServo();

    //servoCounterClockWise();
    //servoClockWise();

    for(;;)
    {
        servoClockWise();
        usleep(8000);
        servoCounterClockWise();
    }

    disableServo();
    return 0;
}
