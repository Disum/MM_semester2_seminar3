program: main.o cos_.o
	gcc -lm -o program -Wall main.o cos_.o
main.o: main.c cos_.h
	gcc -o main.o -Wall -c main.c
cos_.o: cos_.c cos_.h
	gcc -o cos_.o -Wall -c cos_.c

program_debug: main_debug.o cos__debug.o
	gcc -lm -o program_debug -Wall -g main_debug.o cos__debug.o
main_debug.o: main.c cos_.h
	gcc -o main_debug.o -Wall -g -c main.c
cos__debug.o: cos_.c cos_.h
	gcc -o cos__debug.o -Wall -g -c cos_.c

program_optimize: main_optimize.o cos__optimize.o
	gcc -lm -o program_optimize -Wall -O3 main_optimize.o cos__optimize.o
main_optimize.o: main.c cos_.h
	gcc -o main_optimize.o -Wall -O3 -c main.c
cos__optimize.o: cos_.c cos_.h
	gcc -o cos__optimize.o -Wall -O3 -c cos_.c
