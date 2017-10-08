# Creates a folder from the directory 'template_dir'
# where you can solve a problem from 

# usage = ./create...te.sh ${problemNumber}

if [ -d "${1}" ];
then
	echo "directory '${1}' already exists"
else # directory does not exist we're good
	# create new directory with template files
	mkdir ${1}
	cp -r template_dir/* ${1}
	# rename files to reflect new number
	mv ${1}/problem_x.c ${1}/problem_${1}.c
	mv ${1}/problem_x.html ${1}/problem_${1}.html
	# copy html to the text file
	curl "https://projecteuler.net/problem=${1}" >> ${1}/problem_${1}.html
	#copy over problem number to new makefile
	echo 'PROBLEM_NUMBER='${1}''$'\n'"$(cat ${1}/makefile)" > ${1}/makefile

fi