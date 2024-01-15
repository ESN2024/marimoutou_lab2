#include<stdio.h>
#include<stdint.h>
#include "system.h"
#include "altera_avalon_pio_regs.h"
#include "sys/alt_stdio.h"
#include "altera_avalon_timer_regs.h"
#include "altera_avalon_timer.h"
#include <sys/alt_irq.h>
#include <io.h>
#include <alt_types.h>
#include "sys/alt_sys_init.h"

uint32_t cpt=0;


static void timer_irq(void *Context)
{
	//alt_printf("TIC\n");
	uint8_t data[3]={0,0,0};
	
	if(cpt <999)
	{
		
		if(cpt>=10)
		{	
			data[0] = cpt % 10;
			data[1] =  (cpt/10) % 10;
			data[2] = cpt /100;
			
		}else{data[0]=cpt;}
		
		IOWR_ALTERA_AVALON_PIO_DATA(SEG1_BASE,data[0]);
		IOWR_ALTERA_AVALON_PIO_DATA(SEG2_BASE,data[1]);
		IOWR_ALTERA_AVALON_PIO_DATA(SEG3_BASE,data[2]);
		
		
		cpt++;
	}
	else{cpt=0;}
	
	
	IOWR_ALTERA_AVALON_TIMER_STATUS(TIMER_0_BASE, 0b1);
}

int main()
{
	// Init Timer
	
	//IOWR_ALTERA_AVALON_TIMER_CONTROL(TIMER_0_BASE, 0b1000);
	//IOWR_ALTERA_AVALON_TIMER_PERIODL(TIMER_0_BASE,100);
	//IOWR_ALTERA_AVALON_TIMER_PERIODH(TIMER_0_BASE, 100);
	//IOWR_ALTERA_AVALON_TIMER_CONTROL(TIMER_0_BASE, 0b0100);


	// Register IRQ
	alt_irq_register(TIMER_0_IRQ,NULL,timer_irq);
	
	while(1){}
	return 0;
}