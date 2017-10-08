### Project Euler Problems

website : https://projecteuler.net

Going to try for 25 for starters

### Running the problems

The majority of these problems are written in C. To run a problem, simply `cd` into a problem directory and run `make`. This will build, run, and clean the direcory. 

### Development

To start working on a new problem, I've created a template script. run
```sh
./createFolderFromTemplate.sh ${problem_number}
```
to create a new directory with template code in it. You can also bulk create templated folders by running
```sh
for i in {start..end}; do
	./createFolderFromTemplate.sh ${i};	
done
```

GCC version used: `Ubuntu 4.8.5-2ubuntu1~14.04.1`.

### Viewing Problems Locally

All folders included a downloaded html file with the problem in it. To open the problem html in terminal run:
```sh
# install w3m if not already installed
sudo apt-get install w3m
w3m ${problem_number}.html | less
```

### Currenly solved

1-6

**Author : David Goldstein**
