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
	int i=0;
	int data=0;
	uint8_t data_tab[3]={0,0,0};
	
	while(1)
	{	
		if(data<999)
		{	
			if(data>10)
			{	
				data_tab[i] = data % 10;
				data = data / 10;
				i = i+1;
			}
			data_tab[i]=data;
			
			IOWR_ALTERA_AVALON_PIO_DATA(SEG1_BASE,data_tab[0]);
			IOWR_ALTERA_AVALON_PIO_DATA(SEG2_BASE,data_tab[1]);
			IOWR_ALTERA_AVALON_PIO_DATA(SEG3_BASE,data_tab[2]);
			
			data++;
			alt_printf("%d",data);
			usleep(200000);
			
		}else{data=0;}
		

	}
	return 0;
}