extern "C"
{
#include "ets_sys.h"
#include "os_type.h"
#include "esp8266_sdk.h"
#include "osapi.h"
#include "gpio.h"
#include "gpio16.h"
#include "user_config.h"
#include "eagle_soc.h"
#include "user_interface.h"
}

int main()
{
    uart_div_modify(0, UART_CLK_FREQ / 115200);
    while(1)
    {
        os_printf("Hello");
        system_soft_wdt_restart();
        for(int p = 0; p < 17; p++)
            GPIO_OUTPUT_SET(p,1);
        os_delay_us(65535);
        for(int p = 0; p < 17; p++)
            GPIO_OUTPUT_SET(p,0);
        system_soft_wdt_restart();
        os_delay_us(65535);
        os_printf(" World\r\n");
    }
}
