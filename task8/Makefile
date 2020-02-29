program: main.o log_.o
	gcc -lm -o program -Wall main.o log_.o
main.o: main.c log_.h
	gcc -o main.o -Wall -c main.c
log_.o: log_.c log_.h
	gcc -o log_.o -Wall -c log_.c

program_debug: main_debug.o log__debug.o
	gcc -lm -o program_debug -Wall -g main_debug.o log__debug.o
main_debug.o: main.c log_.h
	gcc -o main_debug.o -Wall -g -c main.c
log__debug.o: log_.c log_.h
	gcc -o log__debug.o -Wall -g -c log_.c

program_optimize: main_optimize.o log__optimize.o
	gcc -lm -o program_optimize -Wall -O3 main_optimize.o log__optimize.o
main_optimize.o: main.c log_.h
	gcc -o main_optimize.o -Wall -O3 -c main.c
log__optimize.o: log_.c log_.h
	gcc -o log__optimize.o -Wall -O3 -c log_.c
