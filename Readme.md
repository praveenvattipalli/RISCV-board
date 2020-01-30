new master branch after deleting master
Building images through Yocto
Yocto is an open source build system for creating custom embedded Linux distributions. The term Poky refers to Yocto’s example Linux distribution. It is a starting point for your own use of Yocto to create a custom distribution for your hardware target.
Bitbake is the name of a build tool written in Python. The tool parses recipe files and performs the various build tasks. It caches both downloads and build results in order to speed up repeated builds. While the first full build of a system image can take several hours, the following build times easily collapse down to minutes.
 For more information on Yocto, Bitbake refer to the following:
•	Yocto Project Reference Manual 2.7.1 by Yocto
•	Yocto Project Complete Documentation (MegaManual) Set 2.7.1 by Yocto
•	BitBake User Manual 2.7.1 by Yocto
•	A ractical guide to BitBake by Harald Achitz

The Yocto source for LC-MPFS-DEV-KIT is available on Github:
•	$ git clone https://github.com/Microsemi-SoC-IP/mpfs-linux-apps.git 
The meta RISCV layer is available on Github:
•	$ git clone https://github.com/riscv/meta-riscv.git 

Microchip Aloe Vera LC source is a minimal Yocto (poky)  on top of meta-riscv layer which provides new disk image targets for Microchip LC-MPFS-DEV-KIT.
 Using this source, you will be able to:
•	build predefined disk images for Microchip Aloevera Lite development board
•	build bootloader binaries ( u-boot.bin)
•	build Device Tree Binary (DTB)
•	build Linux kernel (bbl.bin which includes dtb and kernel image )
•	build Rootfs (aloelite-image-aloelite.tar.gz)
•	easily modify disk partition layout

Prerequisite Packages to be Installed:
For Ubuntu 18.04 (or newer)
 
•	$ sudo apt-get install gawk wget git-core diffstat unzip texinfo gcc-multilib build-essential chrpath socat cpio python python3 python3-pip python3-pexpect  xz-utils debianutils iputils-ping libsdl1.2-dev xterm
                                            $ sudo apt-get install python3-distutils
For centos:
Extra Packages for Enterprise Linux (i.e. epel-release) is a collection of packages from Fedora built on RHEL/CentOS for easy installation of packages not included in enterprise Linux by default. You need to install these packages separately.
The makecache command consumes additional Metadata from epel-release.
 
$ sudo yum install -y epel-release
 $ sudo yum makecache
$ sudo yum install gawk make wget tar bzip2 gzip python unzip perl patch diffutils diffstat git cpp gcc gcc-c++ glibc-devel texinfo chrpath socat  perl-Data-Dumper perl-Text-ParseWords perl-Thread-Queue python34-pip xz     which SDL-devel xterm 
$ sudo pip3 install GitPython jinja2
                        
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
Upon successful build, all the available build fragments (incl. disk images) will be available in $BUILDDIR/aloelite_images/ (<path>/ Microsemi-SoC-IP_Yocto/build/aloelite_images)
Generated disk images for writing to uSD card are
u-boot.bin, bbl.bin and aloelite-image-aloelite.tar.gz
Preparing an SD Card and Programming an Image for the First Time
refer to QSG section.
To automatically partition and format your SD card, from the $BUILDDIR/aloelite_images/  (<path>/ Microsemi-SoC-IP_Yocto/build/aloelite_images)
     $ cd $BUILDDIR/aloelite_images:
     $ sudo make DISK=/dev/path-to-sdcard-device format-boot-loader
At this point, LC-MPFS-DEV-KIT should be bootable using  new SD card. You can remove it from your PC and insert it into the SD card slot on the LC-MPFS-DEV-KIT.










