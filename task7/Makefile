program: main.o exp_.o
	gcc -lm -o program -Wall main.o exp_.o
main.o: main.c exp_.h
	gcc -o main.o -Wall -c main.c
exp_.o: exp_.c exp_.h
	gcc -o exp_.o -Wall -c exp_.c

program_debug: main_debug.o exp__debug.o
	gcc -lm -o program_debug -Wall -g main_debug.o exp__debug.o
main_debug.o: main.c exp_.h
	gcc -o main_debug.o -Wall -g -c main.c
exp__debug.o: exp_.c exp_.h
	gcc -o exp__debug.o -Wall -g -c exp_.c

program_optimize: main_optimize.o exp__optimize.o
	gcc -lm -o program_optimize -Wall -O3 main_optimize.o exp__optimize.o
main_optimize.o: main.c exp_.h
	gcc -o main_optimize.o -Wall -O3 -c main.c
exp__optimize.o: exp_.c exp_.h
	gcc -o exp__optimize.o -Wall -O3 -c exp_.c
