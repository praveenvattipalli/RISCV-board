UIO_Interrupt_DMA:
Objective: 
Using this application, Fabric will write, data to un-cached  LPDDR4 using DMA controller.
 For more information on design,  please refer AC489 document.
Required
You require an ICICLE kit programmed with AC489 design Job file.
Bring-up Icicle Kit with the Pre-built Linux image as mentioned in AC489 doc.  
Running Application:
To execute “uio_dma_interrupt” application, be in microchip-apps directory

 
Type the ./uio_dma_interrupt command and Press Enter. 

 
Enter 1 to access LSRAM1 

 
Enter 2 to write data from LSRAM to LPDDR via DMA controller
 











You can enter option 2 to initiate DMA transfer multiple times. Interrupt count is incremented based on DMA transfer. You can check interrupt count in “cat /proc/interrupts” 
 
