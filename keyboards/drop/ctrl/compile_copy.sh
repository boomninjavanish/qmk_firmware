#!/bin/zsh

qmk compile -kb drop/ctrl/v2 -km maev


if [ $? -eq 0 ]; then
  cp ../../../drop_ctrl_v2_maev.uf2 /Volumes/CTRL_V2/
else
  echo "Compile failed! Nothing was copied to the macropad."
fi