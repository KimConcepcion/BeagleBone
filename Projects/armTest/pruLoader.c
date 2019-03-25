//  Local includes:
#include "pruLoader.h"
#include "testGpioArm.h"
#include "timeAnalysis.h"
#include <pruss_intc_mapping.h>
#include <prussdrv.h>
#include <prussdrv.c>

//  Standard includes:
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <signal.h>
#include <pthread.h>
#include <stdbool.h>

//  Store the selected pru:
int pruSelected;

//  Thread routine that monitors interrupts from pru:
void *readIrq(void *arg)
{
    printf("@Thread routine started.\n");

    //  Store current amount of cpu cycles in start and get current day time:
    //start = clock();
    //gettimeofday(&start_t, NULL);

    //  Work loop:
    for (;;)
    {
        //  Get interrupt from pru:
        //prussdrv_pru_wait_event(PRU_EVTOUT_0);

        //  Update the internal time counter with 1:
        //RTE_UpdateTimeStamp(1);

        //  Send signal 34 to process:
        //kill(getpid(), 34);

        //  Clear interrupt:
        //prussdrv_pru_clear_event(PRU_EVTOUT_0, PRU0_ARM_INTERRUPT);

        //  Simulation of thread capturing interrupts from pru with small delays (100us):

        prussdrv_pru_wait_event(PRU_EVTOUT_0);
        writeGPIOtest(GPIO_FILE, "0");
        prussdrv_pru_clear_event(PRU_EVTOUT_0, PRU0_ARM_INTERRUPT);

        prussdrv_pru_wait_event(PRU_EVTOUT_0);
        writeGPIOtest(GPIO_FILE, "1");
        prussdrv_pru_clear_event(PRU_EVTOUT_0, PRU0_ARM_INTERRUPT);
    }
}

int pruInit(int pruNum)
{
    //  Initialize gpio test pin as pruout:
    system("config-pin p8.11 pruout");
    setupGPIOtest();

    //  Set the pru number:
    pruSelected = pruNum;

    //  Intialize pru:
    prussdrv_init();

    //  Open pru:
    if (prussdrv_open(PRU_EVTOUT_0) == -1)
    {
        fprintf(stderr, "prussdrv_open failed...\n");
        return -1;
    }

    //  Initialize interrupt controller:
    tpruss_intc_initdata pruss_intc_initdata = PRUSS_INTC_INITDATA;
    prussdrv_pruintc_init(&pruss_intc_initdata);

    //  Start IRQ thread routine:
    prussdrv_start_irqthread(PRU_EVTOUT_0,
                             sched_get_priority_max(SCHED_FIFO) - 2, readIrq);
    return 0;
}

void pruClock(char *program)
{
    if (prussdrv_exec_program(pruSelected, program) < 0)
    {
        fprintf(stderr, "Error loading the %s file\n", program);
    }

    else
    {
        printf("@Clock is running on pru [%d]\n", pruSelected);
    }
}
