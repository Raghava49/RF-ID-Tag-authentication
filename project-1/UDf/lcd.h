void lcd_init(void);
void lcd_cmd(unsigned char a);
void lcd_data(unsigned char b);


#define lcd P2
sbit rs  =  P2^2;
sbit en  =  P2^3;
unsigned char a[5];
void lcd_init(void)
{
	lcd_cmd(0x28);
	lcd_cmd(0x0C);
	lcd_cmd(0x02);
	lcd_cmd(0x06);
	lcd_cmd(0x01);
}


void lcd_cmd(unsigned char m)
{
	lcd = ((m)&(0xF0));
	rs=0;
	en=1;
	delay(3);
	en=0;
	
	lcd = ((m<<4)&(0xF0));
	rs=0;
	en=1;
	delay(3);
	en=0;
}


void lcd_data(unsigned char m)
{
	lcd = ((m)&(0xF0));
	rs=1;
	en=1;
	delay(3);
	en=0;
	
	lcd = ((m<<4)&(0xF0));
	rs=1;
	en=1;
	delay(3);
	en=0;
}

void lcd_string(unsigned char m[])
{
	unsigned int i;
	
	for(i=0;m[i]!='\0';i++)
	{
		lcd_data(m[i]);
		m[i-1]='\0';
	}
}

void lcd_num(unsigned int m)
{
	int i=0;
	do {
		a[i] = ((m%10) + '0');
		m = m/10;
		i++;
	} while(m!=0);
	for(i=i-1; i>=0; i--){
		lcd_data(a[i]);
	}
}
