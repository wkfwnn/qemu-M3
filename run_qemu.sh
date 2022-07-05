#! /bin/bash

qemu-system-arm -cpu cortex-m3 -machine lm3s6965evb \
  -semihosting \
  --semihosting-config enable=on,target=native \
  -serial mon:stdio \
  -nographic -no-reboot \
  -kernel $1 -gdb tcp::3333 -S &
