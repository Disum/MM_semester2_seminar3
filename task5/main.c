#include <stdio.h>
#include <time.h>
#include <math.h>
#include "sin_.h"
#define ERROR_READ 1

int main(int argc, const char **argv)
{
	double x, eps, res1, res2;
	clock_t time_beg;

	if( argc!=3 )
	{
		fprintf(stderr, "Usage: %s x eps\n", argv[0]);
		return ERROR_READ;
	}
	if( sscanf(argv[1], "%lf", &x)!=1 || sscanf(argv[2], "%lf", &eps)!=1 || eps<0 )
	{
		fprintf(stderr, "Error! Can not read!\n");
		return ERROR_READ;
	}

	time_beg = clock();
	res1 = sin_(x, eps);
	printf("Result sin_(): %lf\nTime: %.2lf sec\n", res1, ( (double)(clock() - time_beg) )/CLOCKS_PER_SEC);
	res2 = sin(x);
	printf("Result sin(): %lf\nDifference: %lf\n", res2, fabs(res2 - res1));

	return 0;
}
