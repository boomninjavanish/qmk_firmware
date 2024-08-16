#!/bin/zsh

qmk compile -kb adafruit/macropad -km maev
#qmk compile -kb adafruit/macropad -km via


if [ $? -eq 0 ]; then
  cp ../../../adafruit_macropad_maev.uf2 /Volumes/RPI-RP2/
else
  echo "Compile failed! Nothing was copied to the macropad."
fi