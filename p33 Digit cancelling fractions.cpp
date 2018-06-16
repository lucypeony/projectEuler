/*
lucypeony@hotmail.com

Euler Project Problem 33 Digit cancelling fractions 
*/

#include<iostream>

using namespace std; 

int gcd(int m, int n) {
	if (m < n)
		swap(m, n);

	int r = m % n;
	while (r > 0) {
		m = n;
		n = r;
		r = m % n;
	}
	return n;
}

void solve() {
	//brute force 
	// x/y is less than 1 
	//x and y are both less than 100, we can handle it pretty eaisly
	for (int x = 11; x <= 98; x++) {
		//x: b*10 + a
		int a = x % 10;
		if (a == 0) continue;
		int b = x / 10;
		for (int y = x+1; y <= 99; y++) {

			//y:d*10 + c
			int c = y % 10;
			if (c == 0) continue;
			int d = y / 10;

			int m = -1, n = -1;
			if (b == d)
			{
				m = a; n = c;
			}

			if (b == c)
			{
				m = a;
				n = d;
			}

			if (a == d) {
				m = b;
				n = c;
			}

			if (a == c)
			{
				m = b;
				n = d;
			}

			if (m == -1 || n == -1)
				continue;

			int xy_gcd = gcd(x, y);
			//if (xy_gcd == 1)
				//continue;
			int m1 = x / xy_gcd; int n1 = y / xy_gcd;

			if (m1 == m && n == n1)
				cout << x << "/" << y << endl;
			else {
				if (m>n && m / n == m1 / n1 && m%n == 0 && m1%n1 == 0)
					cout << x << "/" << y << endl;
				if (m < n && n / m == n1 / m1 && n%m == 0 && n1%m1 == 0)
					cout << x << "/" << y << endl;
			}
			
		}
	}
}

int main() {
	solve();

	cout << "Hello Wordl!";
	return 0;
}
