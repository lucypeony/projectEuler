/*
lucypeony@hotmail.com

Euler Project p45 Pentagon numbers
*/
#include<iostream>
#include<cmath>
using namespace std; 

bool isPentagonal(long long  x) {
	double n = (sqrt(24 * x + 1) + 1) / 6;
	return (n == (int)n);
}

bool isTriangle(long long  x) {
double n = (sqrt(8*x+1)-1)/2;
return (n == (int)n);
}

int main() {
	int count = 0;

	int i = 2;
	while (count < 2) {
		long long temp = i*(2*i-1);
		if (isPentagonal(temp) && isTriangle(temp)) {
			cout << temp << endl;
			count++;
		}	
		i++;
	}

	return 0;
}
