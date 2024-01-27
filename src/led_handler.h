#ifndef LED_HANDLER_H_
#define LED_HANDLER_H_

#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

// Define LED enumeration
enum led_num {
    LED_0,  // Red
    LED_1,  // Green
    LED_2   // Blue
};

// Initialize LEDs
int init_leds();

// Toggle LED
int toggle_led(enum led_num);

#endif /* LED_HANDLER_H_ */