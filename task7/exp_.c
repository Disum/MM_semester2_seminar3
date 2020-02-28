#include <math.h>
#include "exp_.h"

double exp_(double x, double eps)
{
	int flag_sign = 0, i;
	double res, item;

	if( x<0 )
	{
		x *= -1;
		flag_sign = 1;
	}

	item = 1;
	res = 1;
	for( i = 1; item>eps; i++ )
	{
		item *= (x/i);

		res += item;
	}

	if( flag_sign%2 )
		res = 1/res;

	return res;
}
