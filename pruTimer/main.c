
#include <stdint.h>
#include <pru_cfg.h>
#include <resource_table_empty.h>

#define DELAY_NS 100

//  PRU interrupt control registers:
#define PRU_INTC 0x00020000
#define PRU_INTC_GER ( (volatile uint32_t *) (PRU_INTC + 0x10) )
#define PRU_INTC_SICR ( (volatile uint32_t *) (PRU_INTC + 0x24) )
#define PRU_INTC_GPIR ( (volatile uint32_t *) (PRU_INTC + 0x80) )

//  Interrupt control register R31:
volatile register unsigned int __R31;

/**
 * A timer is used to trigger an interrupt at a fixed frequency. The pru program will signal the ARM processor through this interrupt and the code running on the ARM processor will call the timer_irq_ms method
 */

void main(void) {

}

void wait_for_timer() {
    while ( !(__R31 & (1 << 30) ) ) {}
}
