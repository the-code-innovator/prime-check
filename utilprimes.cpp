#include <iostream>

void convertParams(char *argv[], int &startValue, int &endValue){
	startValue = atoi(argv[1]);
	endValue = atoi(argv[2]);
}

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

int main(int argc, char *argv[]){
	int start, end;
	convertParams(argv, start, end);
	for(int i = start; i <= end; i++){
		// std :: cout << i << ": " << ((isPrime(i))?"Prime":"Not Prime");
		// std :: cout << ((isPrime(i))?i:);
		if(isPrime(i)){
			std :: cout << i;
			std :: cout << std :: endl;
		}
	}
	return 0;
}
