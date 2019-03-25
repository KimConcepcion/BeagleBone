#ifndef PWM_H_
#define PWM_H_

/****************************************************
 / D E F I N E S
 *****************************************************/
#define PERIOD "/sys/class/pwm/pwm-1:0/period"
#define DUTY_CYCLE "/sys/class/pwm/pwm-1:0/duty_cycle"
#define ENABLE "/sys/class/pwm/pwm-1:0/enable"
#define EXPORT "/sys/class/pwm/pwmchip1/export"
#define UNEXPORT "/sys/class/pwm/pwmchip1/unexport"

/****************************************************
 / P R O T O T Y P E S
 *****************************************************/

/**
 * @name writeFile()
 * @param file to be written
 * @param content to write to file
 */
int writeFile(const char *file, int value);

/**
 * @name initServo()
 */
void initServo();

/**
 * @name disableServo()
 */
void disableServo();

/**
 * @name setPeriod()
 * @param period of pwm signal
 */
void setPeriod(int period);

/**
 * @name setDutyCycle()
 * @param duty cycle of pwm signal
 */
void setDutyCycle(int duty_cycle);

#endif
