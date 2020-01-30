meta-riscv
RISC-V Architecture Layer for OpenEmbedded/Yocto

license Build Status

Description
This is the general hardware-specific BSP overlay for the RISC-V based devices.

More information can be found at: https://riscv.org/ (Official Site)

The core BSP part of meta-riscv should work with different OpenEmbedded/Yocto distributions and layer stacks, such as:

Distro-less (only with OE-Core).
Angstrom.
Yocto/Poky.
Dependencies
This layer depends on:

URI: git://github.com/openembedded/openembedded-core
branch: master
revision: HEAD
URI: git://github.com/openembedded/bitbake
branch: master
revision: HEAD
Quick Start
Note: You only need this if you do not have an existing Yocto Project build environment.

Make sure to install the repo command by Google first.

Create workspace
mkdir riscv-yocto && cd riscv-yocto
repo init -u git://github.com/riscv/meta-riscv  -b master -m tools/manifests/riscv-yocto.xml
repo sync
repo start work --all
Update existing workspace
In order to bring all the layers up to date with upstream

cd riscv-yocto
repo sync
repo rebase
Setup Build Environment
. ./meta-riscv/setup.sh
Available Machines
The three different machines you can build for are:

qemuriscv64: The 64-bit RISC-V machine
qemuriscv32: The 32-bit RISC-V machine
freedom-u540: The SiFive HiFive Unleashed board
Build Images
A console-only image for the 64-bit QEMU machine

MACHINE=qemuriscv64 bitbake core-image-full-cmdline







