#include <stdio.h>
#include <time.h>
#include <math.h>
#include "sin_.h"
#define ERROR_READ 1

int main(void)
{
	double x, eps, res1, res2;
	clock_t time_beg;

	printf("x = ");
	if( scanf("%lf", &x)!=1 )
	{
		fprintf(stderr, "Error! Can not read x!\n");
		return ERROR_READ;
	}

	printf("eps = ");
	if( scanf("%lf", &eps)!=1 )
	{
		fprintf(stderr, "Error! Can not read eps!\n");
		return ERROR_READ;
	}

	time_beg = clock();
	res1 = sin_(x, eps);
	printf("Result sin_(): %lf\nTime: %.2lf\n", res1, ( (double)(clock() - time_beg) )/CLOCKS_PER_SEC);
	res2 = sin(x);
	printf("Result sin(): %lf\nDifference: %lf\n", res2, fabs(res2 - res1));

	return 0;
}
