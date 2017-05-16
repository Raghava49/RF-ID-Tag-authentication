sbit D0 = P2^0;
sbit D1 = P2^1;

unsigned int* scan_RF_ID(){
	static unsigned int cde[2]=0;
	unsigned char count=0;
	while(1){
			if(count == 25)
				break;
			if(!D0){
			while(!D0);
				if(count != 0){
					if(count <= 8)
						cde[0] = ((cde[0] << 1) | 0);
					else 
						cde[1] = ((cde[1] << 1) | 0);
				}
				count++;
			}
			else if(!D1) {
				while(!D1);
				if(count != 0){
					if(count <= 8)
						cde[0] = ((cde[0] << 1) | 1);
					else 
						cde[1] = ((cde[1] << 1) | 1);
				}
				count++;
			}
			
	}
	return &cde;
}