
BBL		= 2E54B353-1271-4842-806F-E436D6AF6985
VFAT		= EBD0A0A2-B9E5-4433-87C0-68B6B72699C7
LINUX		= 0FC63DAF-8483-4772-8E79-3D69D8477DE4
FSBL		= 5B193300-FC78-40CD-8002-E86C45580B47
UBOOT		= 5B193300-FC78-40CD-8002-E86C45580B47
UBOOTENV	= a09354ac-cd63-11e8-9aff-70b3d592f0fa
UBOOTDTB	= 070dd1a8-cd64-11e8-aa3d-70b3d592f0fa
UBOOTFIT	= 04ffcafa-cd65-11e8-b974-70b3d592f0fa

bin := $(shell pwd)/bbl.bin

.PHONY: format-boot-loader
format-boot-loader: $(bin)
	@test -b $(DISK) || (echo "$(DISK): is not a block device"; exit 1)
	sgdisk -g --clear                                                               \
		--new=1:2048:4095   --change-name=1:uboot      --typecode=1:$(FSBL)   \
		--new=2:4096:69631  --change-name=2:bootloader --typecode=2:$(BBL)   \
		--new=3:264192:     --change-name=3:root       --typecode=3:$(LINUX) \
		-g $(DISK)
	@sleep 1
ifeq ($(DISK)p1,$(wildcard $(DISK)p1))
	@$(eval PART1 := $(DISK)p1)
	@$(eval PART2 := $(DISK)p2)
	@$(eval PART3 := $(DISK)p3)
else ifeq ($(DISK)s1,$(wildcard $(DISK)s1))
	@$(eval PART1 := $(DISK)s1)
	@$(eval PART2 := $(DISK)s2)
	@$(eval PART3 := $(DISK)s3)
else ifeq ($(DISK)1,$(wildcard $(DISK)1))
	@$(eval PART1 := $(DISK)1)
	@$(eval PART2 := $(DISK)2)
	@$(eval PART3 := $(DISK)3)
else
	@echo Error: Could not find bootloader partition for $(DISK)
	@exit 1
endif
	dd if=$(shell pwd)/u-boot.bin of=$(PART1) bs=4096

	dd if=$(shell pwd)/bbl.bin of=$(PART2) bs=4096

	mke2fs -t ext3 $(PART3)
	mkdir -p /tmp/aloelite_rootfs
	mount $(PART3) /tmp/aloelite_rootfs
	tar -xvf aloelite-image-freedom-u540.tar.gz -C /tmp/aloelite_rootfs/
	sync
	umount /tmp/aloelite_rootfs/
	rm -rf /tmp/aloelite_rootfs/
