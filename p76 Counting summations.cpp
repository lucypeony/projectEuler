/*
lucypeony@hotmail.com

Euler Project p76 Counting summations
*/
#include<iostream>

using namespace std; 

int main() {
	const int MAXN = 100;
	int a[MAXN + 1] = { 0 };
	a[0] = 1;
	for (int i = 1; i < MAXN; i++) {
		for (int j = i; j <= MAXN; j++) {
			a[j] += a[j - i];
		}
	}

	cout << a[MAXN] << endl;
	return 0;
}
