#include <reg51.h>
#include <stdio.h>
#include "UDF/delay.h"
#include "UDF/uart.h"
#include "UDF/lcd.h"
#include "UDF/RF_ID.h"
#include "UDF/ADC_8.h"
#include "UDF/keys.h"

sbit M0 = P3^2;
sbit M1 = P3^3;
sbit M2 = P3^4;
sbit M3 = P3^5;

void main() {
	unsigned int *cde;


	uart_init();
	lcd_init();
	printf("PLEASE AUTHENTICATE YOURSELF\n");
	lcd_string("AUTHENTICATION");
	lcd_cmd(0xC0);
	lcd_string("PLEASE");
	cde = scan_RF_ID();
	if(cde[0] == 32 && cde[1] == 55990){
		lcd_cmd(1);
		printf("Welcome ROS");
		lcd_cmd(0x82);
		lcd_string("WELCOME _ROS");
		lcd_cmd(0xc0);
		lcd_string("SEL. DEV. 1-2");
	  get_key();
		lcd_cmd(0xC0);
		lcd_string("DEVICE_");
		while(1){
			get_key();
			Read_ADC(sw_fg);
			lcd_cmd(0xC7);
			lcd_data(sw_fg+1+48);
			printf("%d\n", ADC);
			lcd_cmd(0xC8);
			lcd_string(" : ");
			lcd_num(ADC);
			lcd_string("  ");
			if(ADC > 127){
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
			else{
				M0 = M1 = M2 = M3 = 0;
			}
		}
	}
	else{
		lcd_cmd(1);
		lcd_string("PLEASE TRY AGAIN");
		printf("PLEASE TRY AGAIN\n");
		delay(500);
	}
}