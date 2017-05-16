#include <reg51.h>
#include "UDF/delay.h"

void main(){
	while(1){
		P0 = ~P0;
		delay(500);
	}

}