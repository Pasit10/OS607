all: goodCnt

goodCnt : lab9_q1.o peterson.o
	gcc -o goodCnt lab9_q1.o peterson.o

lab9_q1.o: lab9_q1.c
	gcc -c lab9_q1.c

peterson.o: peterson.c
	gcc -c peterson.c

clean:
	rm -rf *.o goodCnt