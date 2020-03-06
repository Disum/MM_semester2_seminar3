#include <math.h>
#include "sin_.h"

double sin_(double x, double eps)
{
	int flag_sign = 0, flag_div = 0, i;
	double res, item;

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
		x /= 5;
		eps *= eps*eps*eps*eps;
		flag_div = 1;
	}

	item = x;
	res = x;
	for( i = 1; item>eps; i++ )
	{
		item *= x*x/( 2*i*(2*i + 1) );

		if( i%2 )
			res -= item;
		else
			res += item;
	}

	if( flag_div )
		res = 16*res*res*res*res*res - 20*res*res*res + 5*res;

	if( flag_sign&1 )
		res *= -1;

	return res;
}
