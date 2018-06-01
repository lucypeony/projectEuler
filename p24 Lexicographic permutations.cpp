#include<iostream>
#include<string>
#include<fstream>

using namespace std; 

int fact[11];

void create_fact() {
	fact[0] = 1;
	for (int i = 1; i <= 10; i++)
		fact[i] =fact[i-1]*i;
}

void solve() {
	create_fact();
	ofstream fout("p24.out");
	for (int i = 0; i <= 10; i++)
		fout << i << "  " << fact[i] << endl;

	const int millionth = 1000000;
	int x=millionth-1;
	int i = 9;
	fout << "i fact[i]  x        y  " << endl;
	while (x > 0) {
		int y = x / fact[i];
		 x = x % fact[i];
		fout << i << " " << fact[i] << "  " << x << "  " << y << endl;
		i--;
	}
	
	fout.close();
}

int main() {
	solve();
	return 0;
}
