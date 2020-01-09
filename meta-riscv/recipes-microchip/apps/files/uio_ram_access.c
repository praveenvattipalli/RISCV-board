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
  int uioFd,i=0,d=0;
  volatile uint32_t* counters;
uint32_t memread[5]={0x12345678,0x98abcdef,0x05050505,0x34343434,0xAAAAAAAA};
  // Open uio device
  uioFd = open(UIO_DEVICE, O_RDWR);
  if(uioFd < 0)
  {
    fprintf(stderr, "Cannot open %s: %s\n", UIO_DEVICE, strerror(errno));
    return -1;
  }

  // Mmap memory region containing counters value
  counters = mmap(NULL, MMAP_SIZE, PROT_READ|PROT_WRITE, MAP_SHARED, uioFd, 0);
  if(counters == MAP_FAILED)
  {
    fprintf(stderr, "Cannot mmap: %s\n", strerror(errno));
    close(uioFd);
    return -1;
  }

  while(1){
	printf("enter in a digit between 0 to 4 enter 5 to exit\n");
	scanf("%d",&d);
	if(d==5){
		break;
	}
	for(i=0;i<(MMAP_SIZE/4);i++){
		*(counters+i)=memread[d];
		printf("counter[%d]=0x%x\n", i,*(counters+i));

	}
}
#if 0
  // Interrupt loop
  while(0)
  {
    uint32_t intInfo;
    ssize_t readSize;

    // Acknowldege interrupt
    intInfo = 1;
    if(write(uioFd, &intInfo, sizeof(intInfo)) < 0)
    {
      fprintf(stderr, "Cannot acknowledge uio device interrupt: %s\n",
        strerror(errno));
      retCode = -1;
      break;
    }

    printf("write to memory succeful\n");

    // Wait for interrupt
    readSize = read(uioFd, &intInfo, sizeof(intInfo));
    if(readSize < 0)
    {
      fprintf(stderr, "Cannot wait for uio device interrupt: %s\n",
        strerror(errno));
      retCode = -1;
      break;
    }
printf(" readsize =0x%x\n",readSize);
    // Display counter value
    printf("We got %lu interrupts, counter value: 0x%08x\n",
      intInfo, counters[0]);
  }
#endif
  // Should never reach
  munmap((void*)counters, MMAP_SIZE);
  close(uioFd);

  return retCode;
}
