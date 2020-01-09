SUMMARY = "A small image just capable of allowing a device to boot."

IMAGE_INSTALL = "packagegroup-core-boot ${CORE_IMAGE_EXTRA_INSTALL}"

IMAGE_LINGUAS = " "

LICENSE = "MIT"

inherit core-image

IMAGE_ROOTFS_SIZE ?= "8192"
IMAGE_ROOTFS_EXTRA_SPACE_append = "${@bb.utils.contains("DISTRO_FEATURES", "systemd", " + 4096", "" ,d)}"

IMAGE_INSTALL_append += " apps gdb vim   "
IMAGE_INSTALL_append += " gcc make perl  "
IMAGE_INSTALL_append += " apache2 php php-cli "
IMAGE_INSTALL_append += " openssh-sftp-server wget openssh openssl python"
