
#
# This file was derived from the 'Hello World!' example recipe in the
# Yocto Project Development Manual.
#

DESCRIPTION = "Simple helloworld application"
SECTION = "examples"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"
PR = "r0"
SRC_URI = "file://uio_lsram_write_read.c \
	   file://uio_ram_access_read.c \
	   file://uio_ram_access_wr_rd.c \
	"

S = "${WORKDIR}/"

do_compile() {
	${CC} uio_lsram_write_read.c ${LDFLAGS} -o uio_lsram_write_read
	${CC} uio_ram_access_read.c  ${LDFLAGS} -o uio_ram_access_read
	${CC} uio_ram_access_wr_rd.c ${LDFLAGS} -o uio_ram_access_wr_rd
}

FILES_${PN} += "/apps"
do_install() {
	     install -d ${D}/apps
	     install -m 0755 uio_lsram_write_read.c ${D}/apps
	     install -m 0755 uio_ram_access_read.c  ${D}/apps
	     install -m 0755 uio_ram_access_wr_rd.c  ${D}/apps
	     install -m 0755 uio_ram_access_read  ${D}/apps
	     install -m 0755 uio_lsram_write_read  ${D}/apps
	     install -m 0755 uio_ram_access_wr_rd  ${D}/apps
}
