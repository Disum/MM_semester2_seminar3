#include <stdio.h>
#include <math.h>
#include "sin_.h"
#define ERROR_READ 1

int main(void)
{
	double x, eps, res;

	if( scanf("%lf", &x)!=1 || scanf("%lf", &eps)!=1 )
	{
		fprintf(stderr, "Error! Can not read!\n");
		return ERROR_READ;
	}
	while( eps>0 )
	{
		res = sin_(x, eps);
		printf("Result sin_(): %.16lf\nDifference: %.16lf\n", res, fabs(res - sin(x)));

		if( scanf("%lf", &x)!=1 || scanf("%lf", &eps)!=1 )
		{
			fprintf(stderr, "Error! Can not read!\n");
			return ERROR_READ;
		}
	}

	return 0;
}
