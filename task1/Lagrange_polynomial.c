#include "Lagrange_polynomial.h"

double Lagrange_polynomial(int n, double x0, double *x, double *y)
{
	int i, j;
	double basic_polynomial, res = 0;;

	for( i = 0; i<n; i++ )
	{
		basic_polynomial = 1;
		for( j = 0; j<n; j++ )
		{
			if( i==j )
				continue;

			basic_polynomial *= (x0 - x[j])/(x[i] - x[j]);
		}

		res += y[i]*basic_polynomial;
	}

	return res;
}
