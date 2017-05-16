void uart_tx(unsigned char x);
uart_rx(void);
void uart_init(void);
int* uart_string_rx(void);


void uart_init(void)
{
	TMOD=0x20;
	SCON=0x50;
	TH1=0xFD;
	TR1=1;
	TI=1;
}


void uart_tx(unsigned char x)
{
	SBUF=x;
	while(TI==0);
	TI=0;
}

void uart_num(unsigned int m)
{

	uart_tx(m);
}
uart_rx(void)
{
	unsigned char w;
	while (RI==0);
		w=SBUF;
		RI=0;
	return w;
}


int* uart_string_rx(void)
{
	unsigned char i,v[20];
	for(i=0;v[i]!=0x0D;i++)
	{
		while (RI==0);
		v[i]=SBUF;
		RI=0;
		if(v[i]==0x0D)
		{
			break;
		}
		SBUF=v[i];
	while(TI==0);
	TI=0;
	}
	v[i] = '\0';
	return &v;
}

uart_string_tx(unsigned char a[]){
	unsigned char i;
	for(i=0; a[i] != '\0'; i++){
		uart_tx(a[i]);
	}
}