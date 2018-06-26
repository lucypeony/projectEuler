/*
lucypeony@hotmail.com

Euler Project p49 Prime permutations 
*/
#include<iostream>

using namespace std; 

bool isPrime(int x) {
	int i = 2;
	while (i*i <= x) {
		if (x%i == 0)
			return false;
		i++;
	}
	return true;
}

bool isPermutations(int x, int y) {
	int c[10] = { 0 };
	int c1[10] = { 0 };

	while (x != 0) {
		c[x % 10]++;
		x /= 10;
	}

	while (y != 0) {
		c1[y % 10]++;
		y /= 10;
	}

	for (int i = 0; i <= 9; i++)
		if (c[i] != c1[i])
			return false;
	
	return true; 
}

void solve() {
	int x = 1489;
	while (1) {
		int y = x + 3330;
		int z = x + 6660;
		if (isPrime(x) && isPrime(y) && isPrime(z) && isPermutations(x, y) && isPermutations(y, z)) {
			cout << x << " " << y << " " << z << endl;
			break;
		}
		x += 2;
	}
}

int main() {
	solve();
	return 0;
}
