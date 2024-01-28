#include <zephyr/kernel.h>

#include <zephyr/logging/log.h>

#include "led_handler.h"

#define MODULE main
LOG_MODULE_REGISTER(MODULE, LOG_LEVEL_DBG);

int main(void)
{
    LOG_INF("Application starting...");

    int ret;

    ret = init_leds();
    if (ret < 0)
    {
        LOG_ERR("LED setup failed, error %d", ret);
        return 0;
    }

    while (1)
    {
        LOG_INF("Blinking LED");

        ret = blink_led_color(LED_COLOR_BLUE, 6, 100); // BLink on a even number to end off!

        if (ret < 0)
        {
            LOG_ERR("LED blinking failed, error %d", ret);
            return 0;
        }

        k_msleep(1000);

        LOG_INF("Toggling LED");

        ret = toggle_led_color(LED_COLOR_WHITE);
        k_msleep(1000);
        ret = toggle_led_color(LED_COLOR_WHITE);

        if (ret < 0)
        {
            LOG_ERR("LED toggle failed, error %d", ret);
            return 0;
        }

        k_msleep(3000);
    }

    return 0;
}
