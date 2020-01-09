require u-boot-common_${PV}.inc
require u-boot.inc

DEPENDS += "bc-native dtc-native"
DEPENDS_append_aloelite = " u-boot-tools-native"
DEPENDS += "flex-native bison-native"
