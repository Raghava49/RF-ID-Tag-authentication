char presskey(void);

char presskey(void)
{
  unsigned char k,key,ch[]={0x01,0x02,0x04,0x08};
	while(1)
	{ 
    for(k=0;k<4;k++){
      P3 ^=ch[k];
      key=P3;
      while(P3 < 0xF0);
      if(key < 0xF0){
        break;
      }
      P3=0xFF; 
    }
      P3=0xFF;
      switch (key){
          case 0xEE: return '1'; key=0xFF; break;
          case 0xED: return '2'; key=0xFF; break;
          case 0xEB: return '3'; key=0xFF; break;
          case 0xE7: return 'A'; key=0xFF; break;
          case 0xDE: return '4'; key=0xFF; break;
          case 0xDD: return '5'; key=0xFF; break;
          case 0xDB: return '6'; key=0xFF; break;
          case 0xD7: return 'B'; key=0xFF; break;
          case 0xBE: return '7'; key=0xFF; break;
          case 0xBD: return '8'; key=0xFF; break;
          case 0xBB: return '9'; key=0xFF; break;
          case 0xB7: return 'C'; key=0xFF; break;
          case 0x7E: return '*'; key=0xFF; break;
          case 0x7D: return '0'; key=0xFF; break;
          case 0x7B: return '#'; key=0xFF; break;
          case 0x77: return 'D'; key=0xFF; break;
        }
   }
}
  