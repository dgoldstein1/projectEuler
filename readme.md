### Project Euler Problems

website : https://projecteuler.net

Going to try for 25 for starters

### Running the problems

The majority of these problems are written in C. To run a problem, simply `cd` into a problem directory and run `make`. This will build, run, and clean the direcory. 

To start working on a new problem, I've created a template script. run `./createFolderFromTemplate.sh ${problem_number}` to create a new directory with template code in it. You may need to modify `makefile` depdning on your version of gcc (currently using `gcc (Ubuntu 4.8.5-2ubuntu1~14.04.1) 4.8.5
`). You can also bulk create templated folders by running `for i in {start..end}; do ./createFolderFromTemplate.sh ${i}; done`.

### Currenly solved

1-4

**Author : David Goldstein**
