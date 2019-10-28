#P1 Makefile

all: *.c
	gcc -g -Wall -o scanner *.c

clean:
	$(RM) scanner
