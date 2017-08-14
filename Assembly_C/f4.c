int f4(long x, long y)
{
 	long c=0;
	long d=0;
	long e=0;
	e=x^y;
	while(c<=0x3f){
		long f=(1<<c);
		long g=(e&f);
		if(g==0){
			c=c+2;
		}else{
			d++;
			c=c+2;
		}		
	}
	
	if(x<=y){
		d=d|0x1;
	}else{
		d=d|0x70;
	}

	return d;
}