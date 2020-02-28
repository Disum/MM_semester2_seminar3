program: main.o sin_.o
	gcc -lm -o program -Wall main.o sin_.o
main.o: main.c sin_.h
	gcc -o main.o -Wall -c main.c
sin_.o: sin_.c sin_.h
	gcc -o sin_.o -Wall -c sin_.c

program_debug: main_debug.o sin__debug.o
	gcc -lm -o program_debug -Wall -g main_debug.o sin__debug.o
main_debug.o: main.c sin_.h
	gcc -o main_debug.o -Wall -g -c main.c
sin__debug.o: sin_.c sin_.h
	gcc -o sin__debug.o -Wall -g -c sin_.c

program_optimize: main_optimize.o sin__optimize.o
	gcc -lm -o program_optimize -Wall -O3 main_optimize.o sin__optimize.o
main_optimize.o: main.c sin_.h
	gcc -o main_optimize.o -Wall -O3 -c main.c
sin__optimize.o: sin_.c sin_.h
	gcc -o sin__optimize.o -Wall -O3 -c sin_.c
