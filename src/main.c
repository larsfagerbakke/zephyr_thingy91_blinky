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
                LOG_INF("Toggling LED");

                ret = toggle_led(LED_2);

                if (ret < 0)
                {
                        return 0;
                }

                k_msleep(1000);
        }

        return 0;
}
