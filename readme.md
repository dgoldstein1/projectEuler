### Project Euler Problems

website : https://projecteuler.net. Going to try for 25 for starters, all written in C.

### Dependencies

- `w3m` (for downloading the problems http://w3m.sourceforge.net/)
- `gmp` (c / c++ library for big numbers https://gmplib.org/)

### Running the problems

To run a problem, simply `cd` into a problem directory and run `make`. This will build, run, and clean the direcory. The answer will be outputted to the console.

### Development

To start working on a new problem, I've created a template script. For example, to create a directory for the problem 8, run
```sh
./createFolderFromTemplate.sh 8
ls 8
makefile  problem_8.c  problem_8.txt
```

to create a new directory with template code in it. You can also bulk create templated folders by running
```sh
for i in {start..end}; do
	./createFolderFromTemplate.sh ${i};	
done
```

GCC version used: `Ubuntu 4.8.5-2ubuntu1~14.04.1`.

### Currenly solved

1-21

**Author : David Goldstein**
