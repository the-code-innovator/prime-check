#include <iostream>

void convertParams(char *argv[], int &startValue, int &endValue){
	startValue = atoi(argv[1]);
	endValue = atoi(argv[2]);
}

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
