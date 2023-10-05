all: q2

q2 : lab9_q2.o
	gcc -o q2 lab9_q2.o

lab9_q2.o: lab9_q2.c
	gcc -c lab9_q2.c

clean:
	rm -rf *.o q2