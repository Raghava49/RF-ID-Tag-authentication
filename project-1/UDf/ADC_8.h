#define ADC_P  P0

sbit START=  P1^0;
sbit ALE  =  P1^1;
sbit EOC  =  P1^2;
sbit OE   =  P1^3;
sbit S0   =  P1^4;
sbit S1   =  P1^5;
sbit S2   =  P1^6;
unsigned int ADC;

void Read_ADC(unsigned char sel){
	
	unsigned int value;
	EOC = 1;
	ALE = 0;
	OE = 0;
	START = 0;
	
	S0 = sel % 2;
	S1 = (sel/=2) % 2;
	S2 = (sel/ 2) % 2;
	
	delay(1);
	ALE = 1;
	delay(1);
	START = 1;
	delay(1);
	ALE = 0;
	START = 0;
	while(EOC);
	while(!EOC);
	OE = 1;
	delay(1);
	ADC = ADC_P;

return;
}