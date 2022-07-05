#include "start.h"

#include <ARMCM3.h>

void SVC_Handler(void)
{
  logPrint("SVC_Handler\n");
}

void SysTick_Handler()
{
   logPrint("SysTick_Handler\n"); 
}