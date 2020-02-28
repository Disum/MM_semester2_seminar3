#include <math.h>
#include "exp_.h"

double exp_(double x, double eps)
{
	int flag_sign = 0, i, fact;
	double res, item, x_in_deg;

	if( x<0 )
	{
		x *= -1;
		flag_sign = 1;
	}

	x_in_deg = 1;
	fact = 1;
	item = 1;
	res = 1;
	for( i = 1; item>eps; i++ )
	{
		x_in_deg *= x;
		fact *= i;
		item = x_in_deg/fact;

		res += item;
	}

	if( flag_sign%2 )
		res = 1/res;

	return res;
}
