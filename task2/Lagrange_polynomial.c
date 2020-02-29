#include "Lagrange_polynomial.h"

double Lagrange_polynomial(int n, double x0, double *x, double *y)
{
	int i, j;
	double prod = 1, res = y[0];

	for( i = 0; i<(n - 1); i++ )
	{
		prod *= (x0 - x[i]);
		for( j = 0; j<(n - i - 1); j++ )
			y[j] = ( y[j + 1] - y[j] )/( x[j + i + 1] - x[j] );

		res += y[0]*prod;
	}

	return res;
}
