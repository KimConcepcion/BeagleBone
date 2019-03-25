
#include <stdio.h>
#include <stdlib.h>
#include "pwm.h"

/**
 * Main function
 */
int main(int argc, char **argv)
{
    if(argc != 3) {
        fprintf(stderr, "Specify period and duty cycle\n");
        return -1;
    }

    initServo();
    setPeriod( atoi(argv[1]) );
    setDutyCycle( atoi(argv[2] ));
    //disableServo();

    return 0;
}
