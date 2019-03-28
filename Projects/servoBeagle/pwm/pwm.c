/****************************************************
 / I N C L U D E S
 *****************************************************/
#include "pwm.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

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

    setPeriod(SERVO_PERIOD);
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

void servoCounterClockWise()
{
    int tick = 0;

    usleep(DELAY+3000);
    printf("##### Servo is moving counter clockwise #####\n");
    for(tick = SERVO_DUTY_CYCLE_START; tick != SERVO_DUTY_CYCLE_STOP; tick += STEP)
    {
        //  Place a sleep here. This will make the servo move more smoothly)
        usleep(DELAY);
        setDutyCycle(tick);
    }
}

void servoClockWise()
{
    int tick = 0;

    usleep(DELAY+3000);
    printf("##### Servo is moving clockwise #####\n");
    for(tick = SERVO_DUTY_CYCLE_STOP; tick != SERVO_DUTY_CYCLE_START; tick -= STEP)
        {
            //  Place a sleep here. This will make the servo move more smoothly)
            usleep(DELAY);
            setDutyCycle(tick);
        }
}

