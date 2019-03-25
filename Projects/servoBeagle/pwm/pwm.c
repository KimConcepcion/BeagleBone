/****************************************************
 / I N C L U D E S
 *****************************************************/
#include "pwm.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*****************************************************
 / F U N C T I O N S
 *****************************************************/
int writeFile(const char *file, int value)
{

    FILE *fp = fopen(file, "w");
    fprintf(fp, "%d", value);
    fclose(fp);
    return 0;
}

void initServo()
{
    //  Configure pin as pwm:
    if (system("config-pin p9.22 pwm") == -1)
        fprintf(stderr, "Could not configure pin as pwm\n");

    //  Export pwm:
    writeFile(EXPORT, 0);

    //  Enable pwm:
    writeFile(ENABLE, 1);

    fprintf(stdout, "Servo succesfully enabled\n");
}

void disableServo()
{
    //  Disable pwm:
    writeFile(ENABLE, 0);

    //  Unexport pwm:
    writeFile(UNEXPORT, 0);

    fprintf(stdout, "Servo succesfully disabled\n");
}

void setPeriod(int period)
{
    writeFile(PERIOD, period);
}

void setDutyCycle(int duty_cycle)
{
    writeFile(DUTY_CYCLE, duty_cycle);
}
