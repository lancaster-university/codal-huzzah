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

extern int main();

extern "C" void user_init(void)
{
    main();
}
