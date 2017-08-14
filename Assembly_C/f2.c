int f2(long x, long y)

{

   	long c=0;

	long d=0;

	long e=x+y;

 	e=(e>>2);

 	

	while(d<e){

		long f=d&1;

		if(f!=0){

			c=c-y;

		}else{

			c=c+x;

		}		

		d++;

	}


	while(y<c){

		c=c>>1;

	}

 
	return c;

}

