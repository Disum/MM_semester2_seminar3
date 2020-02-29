#include "Lagrange_polynomial.h"

double Lagrange_polynomial(int n, double x0, double *x, double *y, double *d)
{
	int i, j;
	double prod = 1, res = y[0];

	for( i = 0; i<(n - 1); i++ )
	{
		y[i] = ( y[i + 1] - y[i] )/( x[i + 1] - x[i] );
	}

	prod *= (x0 - x[0]);
	res += d[0]*prod;
	if( n==1 )
		return res;
	prod *= (x0 - x[0]);
	for( j = 0; j<(n - 1); j++ )
	{
		d[j] = ( y[j] - d[j] )/( x[j + 1] - x[j] );
		y[j] = ( d[j + 1] - y[j] )/( x[j + 1] - x[j] );
	}
	res += d[0]*prod;

	for( i = 1; i<(n - 1); i++ )
	{
		prod *= (x0 - x[i]);
		for( j = 0; j<(n - i - 1); j++ )
		{
			d[j] = ( y[j] - d[j] )/( x[j + i] - x[j] );
			y[j] = ( d[j + 1] - y[j] )/( x[j + i + 1] - x[j] );
		}
		d[j] = ( y[j] - d[j] )/( x[j + i] - x[j] );
		res += d[0]*prod;

		prod *= (x0 - x[i]);
		for( j = 0; j<(n - i - 1); j++ )
		{
			d[j] = ( y[j] - d[j] )/( x[j + i + 1] - x[j] );
			y[j] = ( d[j + 1] - y[j] )/( x[j + i + 1] - x[j] );
		}
		res += d[0]*prod;
	}

	prod *= (x0 - x[n - 1]);
	d[0] = ( y[0] - d[0] )/( x[n - 1] - x[0] );
	res += d[0]*prod;

	return res;
}
