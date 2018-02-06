#!/bin/sh

make mechmini2:lie

sudo echo "Prepare your keyboard!"

secs=10
while [ $secs -gt 0 ]; do
   echo -ne " $secs\033[0K\r"
   sleep 1
   : $((secs--))
done

echo " flashing"

sudo dfu-programmer atmega32u4 erase
sudo dfu-programmer atmega32u4 flash mechmini2_lie.hex
sudo dfu-programmer atmega32u4 reset

