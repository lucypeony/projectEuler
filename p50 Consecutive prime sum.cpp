/*
lucypeony@hotmail.com

Euler Project p50 Consecutive prime sum
----------------------------------------
这一题其实很简单，因为是求100万以下的素数是哪些连续素数的和，所以我就求出了100万以下的素数，并打算求哪些个素数是哪些连续素数的和。
可想而知，这个方法非常慢。
其实，因为要求的是那个素数必定是某些连续素数的和，而且素数又是递增的。所以，我可以先求出从2,3,4,... 的和，看多少能达到100万。
实际上，这些素数个数很少！只有547个！也就是p1,p2,....,p547 的和就已经超过100万了。
因此我们只要对547个素数进行分别求连续和，看最长连续是多少就行了。
*/
#include<vector>
#include<algorithm>
#include<iostream>
#include<fstream>

using namespace std;

vector<int> generate_primes() {
	const int MAX_M = 1000000;

	bool num[MAX_M / 2];
	memset(num, true, sizeof(num));

	for (int i = 3; i*i <= MAX_M; i += 2)
		if (num[i / 2])
			for (int j = i * i; j <= MAX_M; j += 2 * i)
				num[j / 2] = false;

	vector<int> primes;
	primes.push_back(2);
	for (int i = 3; i <= MAX_M; i += 2)
		if (num[i / 2])
			primes.push_back(i);

	return primes;
}

bool isPrime(long long n) {
	for (int i = 2; i*i < n; i += 1)
		if (n%i == 0)
			return false;

	return true;
}

void solve() {
	ofstream fout("p50.out");
	vector<int> primes = generate_primes();
	vector<int> sum;

	int count = 0;
	long long temp = 0;
	while (temp <= 1000000) {
		temp += primes[count];
		sum.push_back(temp);
		count++;
	}
	fout << temp << endl;
	fout << count << endl;

	int margin = 0;
	int max_primes = -1;
	for (int i = 0; i < count; i++) {
		for (int j = i + 1; j < count; j++)
		{
			temp = sum[j] - sum[i];
			if (isPrime(temp) && j - i + 1 > margin) {
				max_primes = temp;
				margin = j - i + 1;
			}
		}
	}

	fout << "Margin : " << margin << endl;
	fout << "Max Primes: " << max_primes << endl;
	fout.close();
}

int main() {
	solve();
	return 0;
}
