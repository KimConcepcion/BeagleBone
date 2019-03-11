
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

//  Det skal være sådan, at jeg i princippet kan nøjes med at køre SimulateRteRun med et ønsket antal ms. Disse ms skal SimulateRteRun forstå som ms der kommer
//  fra pru'en og ikke af ARM processoren!!!
//  Lige nu starter jeg også pruClock programmet fra main. Det burde reelt ske et mere meningsfuldt sted. Der hvor scheduleren initialiseres?
//  I teorien, så skal RTE_TimerIrq_ms_Beaglebone have kørt 10 gange, da jeg har sat 10 ind.

//  Jeg skal have sat en vej op, hvor RTE scheduleren og pru'ens tidsmåling møder hinanden.
//  RTE scheduleren ser ud til at blive trigget på baggrund af et internt ur. Dette ur skal altså blive erstattes/trigges af pru'en for at ændre hvordan 1ms faktisk ses!
