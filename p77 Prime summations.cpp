/*
Euler Project p77 Prime summations
求n能分解成多少种素数相加的和？ 
题目原来的要求：What is the first value which can be written as the sum of primes in over five thousand different ways?
－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－
这一题可以看成动态规划。　
类似p31,把不同的素数看成是不同面额的硬币，然后用这些硬币去兑换一个个整数。
*/

#include<iostream>

using namespace std;

int primes[169];
const int MAXN = 1001;
int primes_num = 0;

void generate_primes() {
	bool temp[MAXN+1] = { 0 };
	for (int i = 3; i <= MAXN; i += 2)
		if (!temp[i])
			for (int j = i * i; j <= MAXN; j += 2 * i)
				temp[j] = 1;
	primes[++primes_num] = 2;
	for (int i = 3; i <= MAXN; i += 2)
		if (!temp[i])
			primes[++primes_num] = i;

}

void solve(int n) {
	long long  ways[MAXN + 1] = { 0 };
	ways[0] = 1;
	for (int k = 1; k <= primes_num;k++) {
		for (int i = primes[k]; i <= n; i++) {
			ways[i] += ways[i - primes[k]];
			//cout << ways[i] << " ";
		}
	}
	cout << ways[n] << endl;
}

int main() {
	generate_primes();
	int T, N;
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		cin >> N;
		solve(N);
	}
	return 0;
}
