#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>

#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <stdio.h>

#define UIO_DEVICE    "/dev/uio0"
#define MMAP_SIZE     0x4000

int main(int argc, char* argvp[])
{
	int retCode = 0;
	int uioFd,i=0;
	volatile uint32_t* mem_ptr;
	uint32_t memread[5]={0x12345678,0x98abcdef,0x05050505,0x34343434,0xAAAAAAAA};
  // Open uio device
  uioFd = open(UIO_DEVICE, O_RDWR);
  if(uioFd < 0)
  {
    fprintf(stderr, "Cannot open %s: %s\n", UIO_DEVICE, strerror(errno));
    return -1;
  }

  // Mmap memory region containing counters value
  mem_ptr = mmap(NULL, MMAP_SIZE, PROT_READ|PROT_WRITE, MAP_SHARED, uioFd, 0);
  if(mem_ptr == MAP_FAILED)
  {
    fprintf(stderr, "Cannot mmap: %s\n", strerror(errno));
    close(uioFd);
    return -1;
  }

	for(i=0;i<(MMAP_SIZE/4);i++){
		printf("lsram_location[%6d]=0x%x\n", i*4,*(mem_ptr+i));
	}
  // Should never reach
  munmap((void*)mem_ptr, MMAP_SIZE);
  close(uioFd);

  return retCode;
}
