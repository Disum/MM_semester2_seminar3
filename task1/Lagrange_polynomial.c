#include "Lagrange_polynomial.h"

double Lagrange_polynomial(int n, double x0, double *x, double *y)
{
	int i, j;
	double term, res = 0;

	for( i = 0; i<n; i++ )
	{
		term = y[i];
		for( j = 0; j<n; j++ )
		{
			if( i==j )
				continue;

			term *= (x0 - x[j])/(x[i] - x[j]);
		}

		res += term;
	}

	return res;
}
