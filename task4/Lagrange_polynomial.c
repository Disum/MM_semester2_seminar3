#include "Lagrange_polynomial.h"

double Lagrange_polynomial(int n, double x0, double *x, double *y, double *d)
{
	int i, j;
	double res = y[0];

	for( i = 0; i<n; i++ )
		d[i] *= (x0 - x[0]);

	for( i = 0; i<(n - 1); i++ )
	{
		y[i] = (x0 - x[0])*( y[i + 1] - y[i] )/( x[i + 1] - x[i] );
	}

	res += d[0];
	if( n==1 )
		return res;
	for( j = 0; j<(n - 1); j++ )
	{
		d[j] = (x0 - x[0])*( y[j] - d[j] )/( x[j + 1] - x[j] );
		y[j] = (x0 - x[0])*( d[j + 1] - y[j] )/( x[j + 1] - x[j] );
	}
	res += d[0];

	for( i = 1; i<(n - 1); i++ )
	{
		for( j = 0; j<(n - i - 1); j++ )
		{
			d[j] = (x0 - x[i])*( y[j] - d[j] )/( x[j + i] - x[j] );
			y[j] = (x0 - x[i])*( d[j + 1] - y[j] )/( x[j + i + 1] - x[j] );
		}
		d[j] = (x0 - x[i])*( y[j] - d[j] )/( x[j + i] - x[j] );
		res += d[0];

		for( j = 0; j<(n - i - 1); j++ )
		{
			d[j] = (x0 - x[i])*( y[j] - d[j] )/( x[j + i + 1] - x[j] );
			y[j] = (x0 - x[i])*( d[j + 1] - y[j] )/( x[j + i + 1] - x[j] );
		}
		res += d[0];
	}

	d[0] = (x0 - x[n - 1])*( y[0] - d[0] )/( x[n - 1] - x[0] );
	res += d[0];

	return res;
}
