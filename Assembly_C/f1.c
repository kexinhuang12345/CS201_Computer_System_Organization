int f1(long x, long y)

{

	if(x<=y){

		x=x>>1;

		y=y<<2;

		return x+y;

	}else{

		if(y<=4){

			return x*y+(x-y);

		}else{

			return x<<5;

		}

	}

}

