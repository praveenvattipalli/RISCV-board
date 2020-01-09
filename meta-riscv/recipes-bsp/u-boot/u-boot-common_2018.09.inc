SECTION = "bootloaders"

LICENSE = "GPLv2+"
LIC_FILES_CHKSUM = "file://Licenses/README;md5=30503fd321432fc713238f582193b78e"
PE = "1"

# We use the revision in order to avoid having to fetch it from the
# repo during parse
SRCREV = "6f6e014ef0d11367fcc66af74f021dd3d0df69d3"

SRC_URI = "git://github.com/Microsemi-SoC-IP/HiFive_U-Boot.git \
	   file://0001-added-mmc-command-to-boot-bbl.bin.patch \
	   file://0001-added-bootdelay.patch \
	   file://0001-auto-boot-work-around.patch \
"
S = "${WORKDIR}/git"
