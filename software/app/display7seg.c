#include<stdio.h>
#include<stdint.h>
#include "system.h"
#include "altera_avalon_pio_regs.h"
#include "sys/alt_stdio.h"
#include "sys/alt_irq.h"
#include "sys/alt_sys_init.h"
#include <unistd.h>

int main()
{
	alt_printf("main() started\n");
	
	uint8_t data=0;
	
	
	while(1)
	{
		IOWR_ALTERA_AVALON_PIO_DATA(SEG1_BASE,data);
		data++;
		usleep(200000);
		if(data>9)
		{
			data=0;
		}
	}
	return 0;
}