#!/bin/bash
PRJ_NAME="aloelite"

echo "Start Building Bootloader"
bitbake virtual/bootloader

echo "Start Building Kernel"
bitbake virtual/kernel 


echo "Started cleaning ${PRJ_NAME}-image"
bitbake -c cleansstate ${PRJ_NAME}-image

echo "Start Building ${PRJ_NAME} Image"
bitbake -f ${PRJ_NAME}-image

cp tmp/deploy/images/${PRJ_NAME}/${PRJ_NAME}-image-${PRJ_NAME}.tar.gz aloelite_images/
cp tmp/deploy/images/${PRJ_NAME}/u-boot-${PRJ_NAME}.bin aloelite_images/u-boot.bin
cp tmp/deploy/images/${PRJ_NAME}/bbl.bin aloelite_images/

