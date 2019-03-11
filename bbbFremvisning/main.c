
#include <prussdrv.h>
#include <stdio.h>
#include "pruLoader.h"

int main(){

    printf("###### Starting bbbFremvisning ######\n");

    pruInit(PRU0);
    pruClock("/home/debian/gf/text.bin");

    for(;;){}

   return 0;
}
