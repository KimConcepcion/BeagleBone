
//  Path to gpio file to toggle:
#define GPIO_FILE "/sys/class/gpio/gpio60/value"

/**
 * Setup pin p9.11 (gpio60) as gpio output:
 */
void setupGPIOtest();

/**
 * Write either high or low to the gpio pin
 */
void writeGPIOtest(char *filename, char *value);
