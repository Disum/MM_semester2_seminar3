#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Lagrange_polynomial.h"
#define ERROR_READ 1
#define ERROR_ALLOCATE 2
#define ERROR_OPEN 3

int main(int argc, const char **argv)
{
	double x0, *x, *y, res;
	int n, i;
	FILE *x_arr, *y_arr;
	clock_t time_beg;

	if( argc!=4 )
	{
		fprintf(stderr, "Usage: %s n x_array_file y_array_file\n", argv[0]);
		return ERROR_READ;
	}
	if( sscanf(argv[1], "%d", &n)!=1 || n<2)
	{
		fprintf(stderr, "Error! Can not read n>=2!\n");
		return ERROR_READ;
	}

	if( !(x = (double *)malloc(n*sizeof(double))) )
	{
		fprintf(stderr, "Error! Can not allocate memory!\n");
		return ERROR_ALLOCATE;
	}
	if( !(x_arr = fopen(argv[2], "r")) )
	{
		fprintf(stderr, "Error! Can not open %s!\n", argv[2]);
		free(x);
		return ERROR_OPEN;
	}
	for( i = 0; i<n; i++ )
	{
		if( fscanf(x_arr, "%lf", x + i)!=1 )
		{
			fprintf(stderr, "Error! Can not read element number %d from %s!", i + 1, argv[2]);
			free(x);
			fclose(x_arr);
			return ERROR_READ;
		}
	}
	fclose(x_arr);

	if( !(y = (double *)malloc(n*sizeof(double))) )
	{
		fprintf(stderr, "Error! Can not allocate memory!\n");
		free(x);
		return ERROR_ALLOCATE;
	}
	if( !(y_arr = fopen(argv[3], "r")) )
	{
		fprintf(stderr, "Error! Can not open %s!\n", argv[3]);
		free(x);
		free(y);
		return ERROR_OPEN;
	}
	for( i = 0; i<n; i++ )
	{
		if( fscanf(y_arr, "%lf", y + i)!=1 )
		{
			fprintf(stderr, "Error! Can not read element number %d from %s!", i + 1, argv[3]);
			free(x);
			free(y);
			fclose(y_arr);
			return ERROR_READ;
		}
	}
	fclose(y_arr);

	printf("x0 = ");
	if( scanf("%lf", &x0)!=1 )
	{
		fprintf(stderr, "Error! Can not read x0!\n");
		free(x);
		free(y);
		return ERROR_READ;
	}

	time_beg = clock();
	res = Lagrange_polynomial(n, x0, x, y);
	printf("Result: %.8lf\nTime: %.2lf\n", res, ( (double)(clock() - time_beg) )/CLOCKS_PER_SEC);

	free(x);
	free(y);
	return 0;
}
