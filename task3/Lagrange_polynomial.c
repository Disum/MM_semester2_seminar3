#include "Lagrange_polynomial.h"

double Lagrange_polynomial(int n, double x0, double *x, double *y)
{
	int i, j;

	for( i = 0; i<n; i++ )
	{
		for( j = 0; j<(n - i - 1); j++ )
			y[j] = ( (x0 - x[j])*y[j + 1] - (x0 - x[j + i + 1])*y[j] )/(x[j + i + 1] - x[j]);
	}

	return y[0];
}
