#include <math.h>
#include "sin_.h"

double sin_(double x, double eps)
{
	int flag_sign = 0, flag_div = 0, i, fact;
	double res, item, x_in_deg;

	if( x<0 )
	{
		x *= -1;
		flag_sign = 1;
	}

	x -= floor( x/(2*M_PI) )*2*M_PI;

	if( x>M_PI )
	{
		x -= M_PI;
		flag_sign += 1;
	}

	if( x>1 )
	{
		x /= 4;
		flag_div = 1;
	}

	x_in_deg = x;
	fact = 1;
	item = x;
	res = x;
	for( i = 1; item>eps; i++ )
	{
		x_in_deg *= x*x;
		fact *= 2*i*(2*i + 1);
		item = x_in_deg/fact;

		if( i%2 )
			res -= item;
		else
			res += item;
	}

	if( flag_div&1 )
		res = (4*res - 8*res*res*res)*sqrt(1 - res*res);
		//res = 5*res - 20*res*res*res + 16*res*res*res*res*res;

	if( flag_sign%2 )
		res *= -1;

	return res;
}
