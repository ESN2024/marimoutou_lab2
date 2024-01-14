#include "system.h"
#include "alt_types.h"
#include "altera_avalon_timer_regs.h"
#include "altera_avalon_timer.h"
#include <sys/alt_irq.h>
#include "sys/alt_sys_init.h"


// Init Timer
IOWR_ALTERA_AVALON_TIMER_PERIOD_0(TIMER_0_BASE, TIMER_PERIOD_0);
IOWR_ALTERA_AVALON_TIMER_PERIOD_1(TIMER_0_BASE, TIMER_PERIOD_1);
IOWR_ALTERA_AVALON_TIMER_CONTROL (TIMER_0_BASE, SOME_MASKS );
// Register IRQ
alt_irq_register(TIMER_0_IRQ,NULL,simple_irq)