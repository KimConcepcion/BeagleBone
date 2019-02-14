
#include <stdint.h>
#include <pru_cfg.h>
#include "resource_table_empty.h"

volatile register uint32_t __R30;
volatile register uint32_t __R31;

int main(void)
{
    uint32_t gpio;

    CT_CFG.SYSCFG_bit.STANDBY_INIT = 0;
    gpio = (1 << 15);   //  p8.11 - remember to configure as pruout (config-pin p8.11 pruout)

    for (;;)
    {
        __R30 |= gpio;
        __delay_cycles(100000000);
        __R30 &= ~gpio;
        __delay_cycles(100000000);
    }
}
