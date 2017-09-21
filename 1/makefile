CC=gcc 
CFLAGS=-Wall -std=c99 -w -lm

problem_1=problem_1.c
problem_1Object=problem_1.o

all: problem_1 run clean

problem_1:
	${CC} -o ${problem_1Object} ${problem_1} ${CFLAGS}

clean:
	rm -f ${problem_1Object}
run: problem_1
	./${problem_1Object}
