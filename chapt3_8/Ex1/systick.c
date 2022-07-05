#include <stdint.h>

#define SCS_BASE            (0xE000E000)                 /*System Control Space Base Address */
#define SYSTICK_BASE        (SCS_BASE +  0x0010)         /*SysTick Base Address*/
#define SCB_BASE            (SCS_BASE +  0x0D00)
#define HSI_CLK             12000000UL
#define SYSTICK_PRIO_REG    (0xE000ED23)



typedef struct systick_tag {
    volatile uint32_t ctrl;
    volatile uint32_t load;
    volatile uint32_t val;
    volatile uint32_t calrb;
}systick_t;


void init_systick()
{
    systick_t *systick_p = (systick_t *)SYSTICK_BASE;
	uint8_t *sys_prio_p = (uint8_t *)SYSTICK_PRIO_REG;
 	/*Set systick as lowest prio*/
   	*sys_prio_p = 0xf0;
	/*set systick 1s*/
    systick_p->load = (HSI_CLK & 0xffffffUL) - 1;
    systick_p->val = 0;
	/*Enable interrupt, System clock source, Enable Systick*/    
	systick_p->ctrl = 0x7;
}