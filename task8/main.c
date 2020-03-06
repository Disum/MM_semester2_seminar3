#include <stdio.h>
#include <math.h>
#include "log_.h"
#define ERROR_READ 1

int main(void)
{
	double x, eps, res;

	if( scanf("%lf", &x)!=1 || scanf("%lf", &eps)!=1 || x<0 )
	{
		fprintf(stderr, "Error! Can not read!\n");
		return ERROR_READ;
	}
	while( eps>0 )
	{
		res = log_(x, eps);
		printf("Result log_(): %.16lf\nDifference: %e\n", res, fabs(res - log(x)));

		if( scanf("%lf", &x)!=1 || scanf("%lf", &eps)!=1 || x<0 )
		{
			fprintf(stderr, "Error! Can not read!\n");
			return ERROR_READ;
		}
	}

	return 0;
}
