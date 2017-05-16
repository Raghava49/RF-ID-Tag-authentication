sbit sw1 = P3^7;
sbit sw2 = P3^6;

unsigned char sw_fg = 9;
unsigned int i;

get_key(){
	for(i=0; i<1000 || sw_fg == 9; i++){
		if(!sw1){
			sw_fg = 0;
			break;
		}
		if(!sw2){
			sw_fg = 1;
			break;
		}				
	}
	return;
}