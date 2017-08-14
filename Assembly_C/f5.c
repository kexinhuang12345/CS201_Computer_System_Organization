int f5(long x, long y)
{
	long c=0;
	if(x<=y){
		if(x!=y){
			long d=x;
			long e=y;
			c=f53(d,e);
			return c;
		}else{
			long d=x;
			long e=y;
			c=f52(d,e);
			return c;
		}
	}else{
		long d=x;
		long e=y;
		c=f51(d,e);
		return c;
	}
}

int f51(long x,long y){
	long c=0;
	long f=0;
	long d=x+y;
	f=(0x66666667*d)>>32;
	f=f>>1;
	long h=(x+y)>>(0x1f);
	f=f-h;
	long g=0;
	g=(f<<2)+f;
	d=d-g;
	c=d;
	if(c>5){
		return 0xa;
	}else{
		switch (c) {
			case 0:
				return 0x11;
			case 1:
				return 0x12;
			case 2:
				return 0x13;
			case 3:
				return 0x14;
			case 4:
				return 0x15;
			case 5:
				return 0x16;
			default:
				return 0xa;
		}
	

	}
}


int f52(long x,long y){
	long c=0;
	long d=0;
	while(d<=0x3f){
		long f=(x>>d)&1;
		if(f==0){
			d++;
		}else{
			c++;
			d++;
		}
	}
	return c;
}


int f53(long x, long y){
	long c=0;
	long d=0;
	while(c<=0x3e){
		long e=(y>>c)&1;
		if(e==0){
			c++;
		}else{
			c++;
			d++;
		}
	}
	return d;
}
