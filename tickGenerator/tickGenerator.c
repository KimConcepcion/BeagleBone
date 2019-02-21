#include <stdint.h>
#include <pru_cfg.h>
#include <pru_intc.h>
#include <pru_ctrl.h>
#include "resource_table_empty.h"

#define PRU0_DRAM 0x00000
#define MAXC 2

volatile unsigned int *pru0_dram = (unsigned int *) (PRU0_DRAM + 0x200);
volatile register uint32_t __R31;

void main(void)
{
    uint32_t ch = 0;

    //  Enable master port:
    CT_CFG.SYSCFG_bit.STANDBY_INIT = 0;

    //  Write into the shared memory every 1 ms:
    for (;;)
    {
        //  Write ticks into the dram channels:
        pru0_dram[2 * (ch) + 0] += 1;

        //  If counter has reached 999, then reset to 0:
        if ((pru0_dram[2 * (ch) + 0]) == 1000)
        {
            pru0_dram[2 * (ch) + 0] = 0;
        }

        //  Delay for 1ms before it generates the next tick:
        //  Each cycle is 5ns - 1000000 cycles * 5ns = 5000000ns or 5ms
        //  5ns*200000=1000000ns or 1ms
        __delay_cycles(200000);
    }
}

/*
 //  Write ticks into dram:
 pru0_dram[2 * (ch) + 0] += 1;

 //  Consider meassuring how long it takes to count up to 1000.
 //  Evaluate if it has reached 1000 and reset the counting value:
 if ((pru0_dram[2 * (ch) + 0]) > 1000)
 {
 pru0_dram[2 * (ch) + 0] = 0;
 }

 //__delay_cycles(1000000);
 //__delay_cycles(1000000000);
 *
 */
