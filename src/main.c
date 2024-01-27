#include <zephyr/kernel.h>

#include <zephyr/logging/log.h>

#define MODULE main
LOG_MODULE_REGISTER(MODULE, LOG_LEVEL_DBG);

int main(void)
{
        LOG_INF("Application starting...");

        while (1)
        {
                k_msleep(1000);
        }

        return 0;
}
