CC=gcc 
CFLAGS=-Wall -std=c99 -w -lm

problem_3=problem_3.c
problem_3_Object=problem_3.o

all: problem_3 run clean

problem_3:
	${CC} -o ${problem_3_Object} ${problem_3} ${CFLAGS}

clean:
	rm -f ${problem_3_Object}
run: problem_3
	./${problem_3_Object}
