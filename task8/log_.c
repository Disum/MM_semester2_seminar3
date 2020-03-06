#include <math.h>
#include "log_.h"

double log_(double x, double eps)
{
	int i, cnt_div = 0, cnt_mult = 0;
	double res, x_in_deg;

	while( x>=1 )
	{
		x /= 2;
		cnt_div++;
	}
	while( x<0.1 )
	{
		x *= 2;
		cnt_mult++;
	}

	res = 0;
	x -= 1;
	x_in_deg = 1;
	for( i = 1; fabs( x_in_deg/(1 + x) )>eps; i++ )
	{
		x_in_deg *= x;

		if( i&1 )
			res += x_in_deg/i;
		else
			res -= x_in_deg/i;
	}

	res += (cnt_div - cnt_mult)*M_LN2;

	return res;
}
