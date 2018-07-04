/*
lucypeony@hotmail.com

Euler Project p52 Permuted multiples 
*/

#include<iostream>
using namespace std;

bool isPermuted(int a, int b) {
	int a1[10] = { 0 };
	int b1[10] = { 0 };

	while (a > 0) {
		a1[a % 10]++;
		a /= 10;
	}

	while (b > 0) {
		b1[b % 10]++;
		b /= 10;
	}

	for (int i = 0; i < 10; i++)
		if (a1[i] != b1[i])
			return false;

	return true; 
}

int main() {

	for (int x = 100; x <= 999999; x++) {
		int flag[10] = { 0 };
		bool f = true;
		for (int i = 2; i <= 6; i++) {
			int y = x * i;
			f = isPermuted(x, y);
			if (!f)
				break;
			
		}

		
		if (f == false)
			continue;
		else
		{
			cout << x << endl;
			cout << 2 * x << endl;
			cout << 3 * x << endl;
			cout << 4 * x << endl;
			cout << 5 * x << endl;
			cout << 6 * x << endl;
			break;
		}
	}

	return 0;
}
