
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "pruLoader.h"
#include "RTE_BBBAbstraction.h"

//  Entry point - main is only used to start the RTE scheduler:
int main()
{
    printf("@Program started.\n");

    bbbStart();
    pruInit(PRU0);
    pruClock("/home/debian/RTEScheduler/text.bin");

    //  Simulate Rte scheduler on Beaglebone 10s - test of simple component that switches a gpio pin (p9.12/gpio60):
    //SimulateRteRunBeaglebone(2000);
    //SimulateRteRunBeaglebone(5000);
    SimulateRteRunBeaglebone(10000);

    printf("@Program ended.\n");
    return 0;
}

//  Det skal v�re s�dan, at jeg i princippet kan n�jes med at k�re SimulateRteRun med et �nsket antal ms. Disse ms skal SimulateRteRun forst� som ms der kommer
//  fra pru'en og ikke af ARM processoren!!!
//  Lige nu starter jeg ogs� pruClock programmet fra main. Det burde reelt ske et mere meningsfuldt sted. Der hvor scheduleren initialiseres?
//  I teorien, s� skal RTE_TimerIrq_ms_Beaglebone have k�rt 10 gange, da jeg har sat 10 ind.

//  Jeg skal have sat en vej op, hvor RTE scheduleren og pru'ens tidsm�ling m�der hinanden.
//  RTE scheduleren ser ud til at blive trigget p� baggrund af et internt ur. Dette ur skal alts� blive erstattes/trigges af pru'en for at �ndre hvordan 1ms faktisk ses!
