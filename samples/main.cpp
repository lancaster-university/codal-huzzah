extern "C"
{
    #include "ets_sys.h"
    #include "osapi.h"
    #include "gpio.h"
    #include "os_type.h"
    #include "user_config.h"
}

int main()
{
    gpio_init();

    GPIO_OUTPUT_SET (12, 1);
    GPIO_OUTPUT_SET (12, 0);
}
