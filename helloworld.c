#include <stdio.h>
#include "xil_printf.h"
#include "sleep.h"


#define XPAR_AXI_XADC_0_DEVICE_ID 0
#define C_BASEADDR 0x43C00000


int main()

{



  u16 data1;
  u16 data2;
  u16 data3;
  u16 data4;


       Xil_Out32(C_BASEADDR +  0x300 , 0x1110);  //40h
       Xil_Out32(C_BASEADDR +  0x304 , 0x2F0F);//41h enable channel sequencer
       Xil_Out32(C_BASEADDR +  0x308 , 0x0400);//42h
       Xil_Out32(C_BASEADDR +  0x324 , 0xC0C0); //49h
       Xil_Out32(C_BASEADDR +  0x32C , 0xC0C0); //4Bh sequencer register 3 Averaging
       Xil_Out32(C_BASEADDR +  0x33C , 0xC0C0); //4Fh sequencer register 3 Settling time

       printf("VOLTAGE OBSERVER START\n\r");
       int i;
       i=1;

       while(1)
		{

    	    printf("RESULTS %d:\n\r",i);
			i++;

			data1 = Xil_In32(C_BASEADDR +  0x278);
			data1 = data1 >> 4;
			data1 = data1*0.244;
			xil_printf("V1 = %03dmv\n\r",data1);

			data2 = Xil_In32(C_BASEADDR +  0x25c);
			data2 = data2 >> 4;
			data2 = data2*0.244;
			xil_printf("V2 = %03dmv\n\r",data2);

			data3 = Xil_In32(C_BASEADDR +  0x27c);
			data3 = data3 >> 4;
			data3 = data3*0.244;
			xil_printf("V3 = %03dmv\n\r",data3);

			data4 = Xil_In32(C_BASEADDR +  0x258);
			data4 = data4 >> 4;
			data4 = data4*0.244;
			xil_printf("V4 = %03dmv",data4);

            printf("end\n\r");

			sleep(5);

		 }



		return 0;

}
