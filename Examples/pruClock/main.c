/**
 * Small program that applies pru0 on the Beaglebone as a reliable clock signal.
 * After a period of 1ms it will send an interrupt to the host/ARM processor.
 */

#include <stdint.h>
#include <pru_cfg.h>
#include <pru_intc.h>
#include <resource_table_empty.h>

//  Cycles of delay:
#define CYCLES 100000

//  Pru registers:
volatile register unsigned int __R30;
volatile register unsigned int __R31;

void main(void)
{
    CT_CFG.SYSCFG_bit.STANDBY_INIT = 0;

    uint32_t gpio = (1 << 15);

    __R31 = 0x00000000;

    for (;;)
    {
        __R30 &= ~gpio;
        __delay_cycles(CYCLES);

        __R30 |= gpio;
        __delay_cycles(CYCLES);

        __R31 = 35;
    }
}
