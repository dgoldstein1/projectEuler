CC=gcc 
CFLAGS=-Wall -std=c99 -w -lm -lrt 

problem_2=problem_2.c
problem_2_Object=problem_2.o

all: problem_2 run clean

problem_2:
	${CC} -o ${problem_2_Object} ${problem_2} ${CFLAGS}

clean:
	rm -f ${problem_2_Object}
run: problem_2
	./${problem_2_Object}
