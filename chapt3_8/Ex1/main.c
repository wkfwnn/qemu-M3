#include "start.h"

#include <ARMCM3.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>


extern void init_systick();



void func(uint8_t *array)
{

  //  logPrint("Control 0x%x\n"
  //          "PSP 0x%x\n"
  //          "MSP 0x%x\n\n",
  //           __get_CONTROL(), __get_PSP(), __get_MSP());
  //  logPrint("array[0] = %x",array[0]);
  array[0] = 1;

  //  logPrint("Control 0x%x\n"
  //          "PSP 0x%x\n"
  //          "MSP 0x%x\n\n",
  //           __get_CONTROL(), __get_PSP(), __get_MSP());
}

int main(void)
{

  uint8_t array[4] = {1};
  uint8_t *p = malloc(16);
  if(array[0]) return -1;
  uint8_t test[64] = {2,};
  memset(&test,0x33,sizeof(test));




  func(test);
  return 0;
}

