#!/bin/zsh

qmk compile -kb ploopyco/madromys -km maev


if [ $? -eq 0 ]; then
  cp ../../ploopyco_madromys_rev1_001_maev.uf2 /Volumes/RPI-RP2/
else
  echo "Compile failed! Nothing was copied to the mouse."
fi