void delay(unsigned int c);

void delay(unsigned int c)
{
	int i,j;
	for(i=0;i<c;i++)
	{
		for(j=0;j<127;j++);
	}
}