
#include <stdio.h>
#include <stdlib.h>
#include "testGpioArm.h"

void setupGPIOtest()
{
    system("config-pin p9.12 out");
}

void writeGPIOtest(char filename[], char value[])
{
    FILE *fp = fopen(filename, "w+");
    fprintf(fp, value);
    fclose(fp);
}
