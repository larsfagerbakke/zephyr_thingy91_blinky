#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

#include <zephyr/logging/log.h>

#define MODULE main
LOG_MODULE_REGISTER(MODULE, LOG_LEVEL_DBG);

#define LED0_NODE DT_ALIAS(led0)

static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios);

int setup_led1()
{
        if (!gpio_is_ready_dt(&led))
        {
                return 0;
        }

        int ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_INACTIVE);

        if (ret < 0)
        {
                return 0;
        }

        return ret;
}

int main(void)
{
        LOG_INF("Application starting...");

        int ret;

        ret = setup_led1();
        if( ret < 0)
        {
                LOG_ERR("LED setup failed, error %d", ret);
                return 0;
        }

        while (1)
        {
                LOG_INF("Toggling LED");

                ret = gpio_pin_toggle_dt(&led);

                if (ret < 0)
                {
                        return 0;
                }

                k_msleep(1000);
        }

        return 0;
}
