/*
Project Euler p97 Large non-Mersenne prime
*/
#include<fstream>
#include<iostream>

using namespace std;
int main() {
	freopen("p97.out", "w", stdout);
	const long long int M = 10000000000;
	int n = 7830457;
	long long ans = 1;
	for (int i = 1; i <= n; i++) {
		ans *= 2;
		ans %= M;
	}
	ans *= 28433;
	ans += 1;
	cout << ans % M << endl;
	fclose(stdout);
	return 0;
}