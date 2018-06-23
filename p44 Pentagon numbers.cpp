/*
lucypeony@hotmail.com

Euler Project p44 Pentagon numbers
*/
#include<iostream>
#include<cmath>
using namespace std; 

bool isPentagonal(int x) {
	double n = (sqrt(24 * x + 1) + 1) / 6;
	return (n == (int)n);
}

int main() {

	for(int i=1;i<3000;i++){
		int pi = i * (3 * i - 1) / 2;
		for (int j = i + 1; j <= 3000; j++) {
			int pj = j * (3 * j - 1) / 2;
			if (isPentagonal(pi + pj) && (isPentagonal(pj - pi))) {
				cout << pj - pi << endl;
			}
				
		}
	}

	cout << "Hello World!" << endl;
	return 0;
}
