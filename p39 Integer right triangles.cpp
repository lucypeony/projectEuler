/*
lucypeony@hotmail.com

Euler Project p39 Integer right triangles
*/
#include<iostream>
using namespace std; 

void solve() {
	int p[1001] = { 0 };

	for (int x = 1; x < 1000; x++) {
		for (int y = x; y < 1000; y++) {
			for (int z = y; z <= (1000 - x - y); z++) {
				if (x*x + y * y == z * z && x + y > z && z - x < y && z - y < x)
					p[x + y + z]++;
			}
		}
	}

	int max = -1; int max_pos;
	for (int i = 1; i <= 1000; i++) {
		if (p[i] > max) {
			max = p[i];
			max_pos = i;
		}
	}
	cout << max_pos << " " << max << endl;
}

int main() {
	solve();
	return 0;
}
