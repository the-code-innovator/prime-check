#!/bin/bash
# compile utilprime.cpp
g++ ./utilprimes.cpp -o ./utilp
# compile exactprimes.cpp
g++ ./exactprimes.cpp -o ./xactp
# create a testfile for utilp
touch ./utilptest.txt
# create a testfile for xactp
touch ./xactptest.txt
# create a resultfile for results
touch ./results.txt
# execute utilp for values ${START} -to- ${END}
./utilp $1 $2 > ./utilptest.txt
# execute xactp for values ${START} -to- ${END}
./xactp $1 $2 > ./xactptest.txt
# create a diff file
touch testdiff.txt
# execute diff and append to testdiff.txt
diff ./utilptest.txt ./xactptest.txt > testdiff.txt
# conditional based on the ${LINES} variable
if [ `expr $(cat ./testdiff.txt | wc -l)` -eq "0" ]
then
	# print message to user
	echo "the algorithms are exact and correct."
	echo "there was no difference between the two files."
	echo "the primes between $1 & $2 are:"
	cat ./utilptest.txt > ./results.txt
	cat ./results.txt
	echo "COUNT: `expr $(cat ./utilptest.txt | wc -l)`" >> results.txt
	echo "COUNT: `expr $(cat ./utilptest.txt | wc -l)`"
elif [ `expr $(cat ./testdiff.txt | wc -l)` -ne "0" ]
then
	# print message to user
	echo "the algorithms have an inconsistency."
	echo "LINES: `expr $(cat ./testdiff.txt | wc -l)`"
	echo "the difference found was (* from utilp -to- xactp):"
	# print the testdiff.txt file
	cat ./testdiff.txt
else
	echo "illegal argument for execution ..."
fi
