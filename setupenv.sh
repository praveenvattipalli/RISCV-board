source ./oe-init-build-env ./build
PSOLD=$PS1
PS1='${debian_chroot:+($debian_chroot)}\[\033[01;32m\]MICROCHIPBitbake\[\033[00m\]:\[\033[01;34m\]\w=>\[\033[00m\] '

MACHINE="aloelite"
BITBAKEIMAGE="aloelite-image"
echo "---------------------------------------------------"
echo "MACHINE=${MACHINE} bitbake ${BITBAKEIMAGE}"
echo "---------------------------------------------------"
echo ""
echo "Buildable machine info"
echo "---------------------------------------------------"
echo "* aloelite: The Microchip Riscv Board"
echo "---------------------------------------------------"

export PS1
bash --norc --noprofile ; export PS1=$PSOLD



