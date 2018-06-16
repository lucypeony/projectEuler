/*
lucypeony@hotmail.com

Euler Project Problem 34 Digit factorials
*/

#include<iostream>

using namespace std; 

int factorial[] = { 1,1,2,6,24,120,720,5040,40320,362880 };

int fact_sum(int n) {
	int res = 0;
	while (n > 0) {
		res += factorial[n % 10];
		n /= 10;
	}
	return res;
}

void solve() {
	int total = 0;
	for (int x = 100; x <= 9999999; x++) {
		int sum = fact_sum(x);
		if (sum == x) {
			cout << x << endl;
			total += sum;
		}
			
	}
	cout << "total: " << total << endl;
	
}

int main() {
	solve();

	cout << "Hello Wordl!";
	return 0;
}
