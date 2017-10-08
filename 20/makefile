PROBLEM_NUMBER=20
CC=gcc
CFLAGS=-Wall -std=c99 -w -lm

problem_${PROBLEM_NUMBER}=problem_${PROBLEM_NUMBER}.c
problem_${PROBLEM_NUMBER}_Object=problem_${PROBLEM_NUMBER}.o

all: problem_${PROBLEM_NUMBER} run clean

problem_${PROBLEM_NUMBER}:
	${CC} -o ${problem_${PROBLEM_NUMBER}_Object} ${problem_${PROBLEM_NUMBER}} ${CFLAGS}

clean:
	rm -f ${problem_${PROBLEM_NUMBER}_Object}
run: problem_${PROBLEM_NUMBER}
	./${problem_${PROBLEM_NUMBER}_Object}
