/*
lucypeony@hotmail.com

Euler Project p48 Self powers
*/
#include<iostream>
using namespace std; 

const int M = 1000000000000;
//return the last digit 
long long last10(int x,int y) {
	if (y == 1)
		return x % M;

	int y1 = y / 2;
	int y2 = y - y1;
	long long  r1 = last10(x, y1);
	long long  r2 = last10(x, y2);
	return (r1*r2) % M;
	//return (last10(x, y1)*last10(x, y2)) % M;
}

void solve() {
	long long res = 0;
	for (int i = 1; i <= 12; i++) {
		long long temp=last10(i,i);
		cout << i << " " << temp << endl;
		res += temp;
	}

	cout << res << endl;
}

int main() {
	solve();

	cout << "Hello World！" << endl;
	return 0;
}
