program: main.o Lagrange_polynomial.o
	gcc -o program -Wall main.o Lagrange_polynomial.o
main.o: main.c Lagrange_polynomial.h
	gcc -o main.o -Wall -c main.c
Lagrange_polynomial.o: Lagrange_polynomial.c Lagrange_polynomial.h
	gcc -o Lagrange_polynomial.o -Wall -c Lagrange_polynomial.c

program_debug: main_debug.o Lagrange_polynomial_debug.o
	gcc -o program_debug -Wall -g main_debug.o Lagrange_polynomial_debug.o
main_debug.o: main.c Lagrange_polynomial.h
	gcc -o main_debug.o -Wall -g -c main.c
Lagrange_polynomial_debug.o: Lagrange_polynomial.c Lagrange_polynomial.h
	gcc -o Lagrange_polynomial_debug.o -Wall -g -c Lagrange_polynomial.c

program_optimize: main_optimize.o Lagrange_polynomial_optimize.o
	gcc -o program_optimize -Wall -O3 main_optimize.o Lagrange_polynomial_optimize.o
main_optimize.o: main.c Lagrange_polynomial.h
	gcc -o main_optimize.o -Wall -O3 -c main.c
Lagrange_polynomial_optimize.o: Lagrange_polynomial.c Lagrange_polynomial.h
	gcc -o Lagrange_polynomial_optimize.o -Wall -O3 -c Lagrange_polynomial.c
