#!/bin/bash
# create multiresolution windows icon
ICON_SRC=../../src/qt/res/icons/meconcash.png
ICON_DST=../../src/qt/res/icons/meconcash.ico
convert ${ICON_SRC} -resize 16x16 meconcash-16.png
convert ${ICON_SRC} -resize 32x32 meconcash-32.png
convert ${ICON_SRC} -resize 48x48 meconcash-48.png
convert meconcash-48.png meconcash-32.png meconcash-16.png ${ICON_DST}

