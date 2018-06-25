/*
lucypeony@hotmail.com

Euler Project p48 Self powers
*/
#include<iostream>
using namespace std; 

const long long  M = 10000000000;
//return the last 10 digits 
long long last10(int x,int y) {
	long long res = 1;
	for (int i = 1; i <= y; i++) {
		res *= x;
		res %= M;
	}

	return res;
}

void solve() {
	long long res = 0;
	for (int i = 1; i <= 1000; i++) {
		long long temp=last10(i,i);
		cout << i << " " << temp << endl;
		res += temp;
	}

	cout << res << endl;
}

int main() {
	solve();
	return 0;
}
