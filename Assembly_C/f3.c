int f3(long x, long y)

{

	long c=(x+y);

	c=c<<1;

	c=c+17;

	c=3*c;

  	if(x<=y){

		if(x!=y){

			c=c+(y>>2);

			return c;

		}else{

			c=c-60;

			return c;

		}

	}else{

		c=c+(x>>2);

		return c;

	}

}

