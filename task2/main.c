#include <stdio.h>
#include <stdlib.h>
#include "Lagrange_polynomial.h"
#define ERROR_READ 1
#define ERROR_ALLOCATE 2
#define ERROR_OPEN 3

int main(int argc, const char **argv)
{
	double x0, *x, *y;
	int n, i;
	FILE *input;

	if( argc!=3 )
	{
		fprintf(stderr, "Usage: %s n input_file\n", argv[0]);
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
	if( !(y = (double *)malloc(n*sizeof(double))) )
	{
		fprintf(stderr, "Error! Can not allocate memory!\n");
		free(x);
		return ERROR_ALLOCATE;
	}

	if( !(input = fopen(argv[2], "r")) )
	{
		fprintf(stderr, "Error! Can not open %s!\n", argv[2]);
		free(x);
		free(y);
		return ERROR_OPEN;
	}

	for( i = 0; i<n; i++ )
	{
		if( fscanf(input, "%lf", x + i)!=1 || fscanf(input, "%lf", y + i)!=1  )
		{
			fprintf(stderr, "Error! Can not read element from %s!", argv[2]);
			free(x);
			free(y);
			fclose(input);
			return ERROR_READ;
		}
	}
	fclose(input);

	printf("x0 = ");
	if( scanf("%lf", &x0)!=1 )
	{
		fprintf(stderr, "Error! Can not read x0!\n");
		free(x);
		free(y);
		return ERROR_READ;
	}

	printf("Result: %.16lf\n", Lagrange_polynomial(n, x0, x, y));

	free(x);
	free(y);
	return 0;
}
