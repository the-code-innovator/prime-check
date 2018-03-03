# prime-check
+ Checks Prime Numbers in two methods and compares the two methods for inconsistency.
+ uses shell script to execute.
___
#### Algorithm 1:
<!-- cpp code: -->
<!--
```cpp
bool isPrime(int n){
	if(n == 1)	return false;
	if(n == 2)	return true;
	else if(n == 3)	return true;
	else if(n % 2 == 0)	return false;
	else if(n % 3 == 0)	return false;
	else{
		int i = 5;
		int w = 2;
		while((i * i) <= n){
			if(n % i == 0)
				return false;
			i += w;
			w = 6 - w;
		}
		return true;
	}
	return false;
}
```
-->
```python
def isPrime(n):
	if n == 1:
		return True
	elif n == 2:
		return True
	elif n == 3:
		return True
	elif n % 2 == 0:
		return False
	elif n % 3 == 0:
		return False
	else
		i = 5
		w = 2
		while i * i <= n:
			if n % i == 0:
				return False
			i += w
			w = 6 - w
		return True
	return False
```
___
#### Algorithm 2:
<!-- cpp code: -->
<!--
```cpp
bool isPrime(int n){
	if(n == 1)	return false;
	bool result = true;
	for(int i = 2; i < n; i++)
		if(n % i == 0){
			result = false;
			break;
		}
	return result;
}
```
-->
```python
def isPrime(n):
	if n == 1:
		return False
	result = True
	for(i in range(2, n))
		if n % i == 0:
			result = False
			break
	return result
```
___
#### Shell Scripts:
+ Compile Script:
```bash
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
```
+ CleanUp Script:
```bash
#!/bin/bash
# remove all text files
rm ./*.txt
# remove utilp executable
rm ./utilp
# remove xactp executable
rm ./xactp
```
