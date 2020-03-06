#include <math.h>
#include "exp_.h"

double exp_(double x, double eps)
{
	int flag_sign = 0, i;
	double res_ip, res, item;

	if( x<-40 )
		return 0;

	if( x<0 )
	{
		x *= -1;
		flag_sign = 1;
	}

	res_ip = 1;
	for( i = 0; i<ceil(x); i++ )
		res_ip *= M_E;
	x -= ceil(x);

	item = 1;
	res = 1;
	for( i = 1; fabs(item)>eps; i++ )
	{
		item *= (x/i);

		res += item;
	}

	res *= res_ip;

	if( flag_sign&1 )
		res = 1/res;

	return res;
}
