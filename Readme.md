Building images through Yocto

Yocto is an open source build system for creating custom embedded Linux distributions. The term Poky refers to Yocto’s example Linux distribution. It is a starting point for your own use of Yocto to create a custom distribution for your hardware target.
Bitbake is the name of a build tool written in Python. The tool parses recipe files and performs the various build tasks. It caches both downloads and build results in order to speed up repeated builds. While the first full build of a system image can take several hours, the following build times easily collapse down to minutes.

 For more information on Yocto, Bitbake refer to the following:
•       Yocto Project Reference Manual 2.7.1 by Yocto
•       Yocto Project Complete Documentation (MegaManual) Set 2.7.1 by Yocto
•       BitBake User Manual 2.7.1 by Yocto
•       A ractical guide to BitBake by Harald Achitz

The meta RISCV layer is available on Github:
•       $ git clone https://github.com/riscv/meta-riscv.git

Microchip Aloe Vera LC source is a minimal Yocto (poky)  on top of meta-riscv layer which provides new disk image targets for Microchip LC-MPFS-DEV-KIT.
 Using this source, you will be able to:
•       build predefined disk images for Microchip Aloevera Lite development board
•       build bootloader binaries ( u-boot.bin)
•       build Device Tree Binary (DTB)
•       build Linux kernel (bbl.bin which includes dtb and kernel image )
•       build Rootfs (aloelite-image-aloelite.tar.gz)
•       easily modify disk partition layout

Prerequisite Packages to be Installed:
For Ubuntu 18.04 (or newer)

$ sudo apt-get install gawk wget git-core diffstat unzip texinfo gcc-multilib build-essential chrpath socat cpio python python3 python3-pip python3-pexpect  xz-utils debianutils iputils-ping libsdl1.2-dev xterm
$ sudo apt-get install python3-distutils

For centos:
Extra Packages for Enterprise Linux (i.e. epel-release) is a collection of packages from Fedora built on RHEL/CentOS for easy installation of packages not included in enterprise Linux by default. You need to install these packages separately.
The makecache command consumes additional Metadata from epel-release.

$ sudo yum install -y epel-release
$ sudo yum makecache
$ sudo yum install gawk make wget tar bzip2 gzip python unzip perl patch diffutils diffstat git cpp gcc gcc-c++ glibc-devel texinfo chrpath socat  perl-Data-Dumper perl-Text-ParseWords perl-Thread-Queue python34-pip xz which SDL-devel xterm


Fetch all sources


Commands:
$ git clone https://github.com/Microsemi-SoC-IP/mpfs-linux-apps.git
$ cd mpfs-linux-apps/

Setting up the Build Environment
$ source setupenv.sh
Note: This command redirects to $BUILDDIR (<path>/ mpfs-linux-apps /build) as shown in below figure:

Building Disk Images

Building disk image may take anywhere from 30 minutes to several hours depending on your host machine and download speed.
$ ./build_all.sh

Upon successful build, all the available build fragments (incl. disk images) will be available in $BUILDDIR/aloelite_images/ (<path>/mpfs-linux-apps/build/aloelite_images)

Generated disk images for writing to uSD card are
u-boot.bin, bbl.bin and aloelite-image-aloelite.tar.gz

Preparing an SD Card and Programming an Image for the First Time
Connect an SD card to your host system to load the boot image (16 GB or 32 GB). If the SD card is
auto-mounted, first unmount it manually. Check if your SD card is mounted and unmount it using the
following commands, where XN are replaced with the SD card’s specific values found from the mount
command.

$ mount | grep sd
$ sudo umount /dev/sdXN

The SD card should have a GUID Partition Table (GPT) rather than a Master Boot Record (MBR) without any
partitions defined.To automatically partition and format your SD card, from the $BUILDDIR/aloelite_images/  (<path>/mpfs-linux-apps/build/aloelite_images)
     $ cd $BUILDDIR/aloelite_images:
     $ sudo make DISK=/dev/path-to-sdcard-device format-boot-loader

At this point, LC-MPFS-DEV-KIT should be bootable using  new SD card. You can remove it from your PC and insert it into the SD card slot on the LC-MPFS-DEV-KIT.

Upon successful boot, prompt will ask for login, enter "root"


Running applications:

Executing gpio_led_blink:

Run the following command to blink LED4 and LED5 on LC-MPFS-DEV-KIT. These two leds are interfaced to gpio0 and gpio1 in fpga design.
The souce file gpio_led_blink.c is also given for reference.

$ ./gpio_led_blink


        # Choose any number between 1 to 3 to access led
         enter 1 to toggle both leds at a time
         enter 2 to toggle one led at a time
         enter 3 to exit


Executing uio_lsram_check:
This application writes/reads to/from LSRAM.
This application uses Linux UIO framework.
The fpga design has AXIMS0 and AXIMS1.
AXIMS0 is interfaced to one LSRAM block and another is interfaced to 8 LSRAM blocks through AXI interconnect.
Address Map:

AXIMS0 -  address 0x2030000000
AXIMS1 – address  0x2600000000

Run the following command to access LSRAM blocks:


$ ./uio_lsram_check


         # choose LSARM to access
 0).lsram1_0, 1).lsram1_1, 2)lsram1_2, 3).lsram1_3, 4).lsram1_4, 5).lsram1_5, 6).lsram1_6, 7)lsram1_7, 8)lsram0, 9)exit app

1
### lsram1 block 1 is interfaced to AXI_MS1 through AXI Interconnect which is mapped to userspace
         # Enter a digit between 0 to 4 to write a pattern into lsram or
         # Enter 5 to initial 4k memory read or
         # Enter 6 to 64k full memory read or
         # Enter 7 to goto main menu
