/*
lucypeony@hotmail.com

Euler Project p55 lychrel numbers
*/
#include<iostream>
#include<string>

using namespace std;

long long reverse_add(long long  n) {
	long long  t = n;
	long long  num = 0;
	while (n > 0) {
		num *= 10;
		num += (n % 10);
		n /= 10;
	}
	return t + num;
}

bool palindromes(long long n) {
	string s = to_string(n);
	int x = s.size();
	for (int i = 0; i < x / 2; i++) {
		if (s[i] != s[x - i - 1])
			return false;
	}
	return true;
}
bool lychrel(int n) {
	int x = 0;
	long long m = n;
	while (x <= 50) {
		m = reverse_add(m);
		if (palindromes(m))
			return false;
		x++;
	}
	return true;
}

int main() {
	const int MOST = 10000;
	int count = 0;
	for (int i = 1; i <= MOST; i++) {
		if (lychrel(i))
		{
			count++;
		}
	}

	cout << count << endl;
	return 0;
}