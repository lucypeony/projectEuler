/*
lucypeony@hotmail.com

Euler Project Problem 36 Double-base palindromes
*/

#include<iostream>
#include<string>
using namespace std; 

string to_binary(int n) {
	string binary;
	while (n > 0) {
		if (n % 2)
			binary = '1' + binary;
		else
			binary = '0' + binary;

		n /= 2;
	}
	return binary;
}

bool palindromes(string s) {
	int t = s.size();
	for (int i = 0; i < t; i++) {
		if (s[i] != s[t - i - 1])
			return false;
	}
	return true;
}

void solve() {
	int sum = 0;
	for (int x = 1; x <= 999999; x += 2) {
		string xs = to_string(x);
		if (palindromes(xs) && palindromes(to_binary(x)))
			sum += x;
			
	}
	
	cout << sum << endl;
}

int main() {
	solve();

	//cout << "Hello World!" << endl;
	return 0;
}
