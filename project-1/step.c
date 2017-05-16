#include<reg51.h>
#include "UDF/delay.h"
sbit M0 = P3^2;
sbit M1 = P3^3;
sbit M2 = P3^4;
sbit M3 = P3^5;

main()
{
	unsigned int i;
	for(i=0;i<50;i++){
					
					M3 = 0; M0 = M1 = M2 = 1;
					delay(2);
					M2 = 0; M0 = M1 = M3 = 1;
					delay(2);
					M1 = 0; M0 = M3 = M2 = 1;
					delay(2);
					M0 = 0; M3 = M1 = M2 = 1;
					delay(2);
				}
	
	}	