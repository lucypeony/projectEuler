/*
lucypeony@hotmail.com

Euler Project p50 Consecutive prime sum
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

void solve() {
	vector<int> primes = generate_primes();
	//const int NUM = 87498; //num of primes under 1 million 
	long long sum = 0;
	long long max_con = -1;
	for (int i = 0; i < primes.size(); i++) {
		for (int j = i + 1; j < primes.size(); j+=2) {
			//calculate if sum[i..j] is prime,if so, store j-i and the sum;
			long long temp = 0;
			int k = i;
			while (k <= j) {
				temp += primes[k];
				k++;
			}
			if (find(primes.begin(), primes.end(), temp) != primes.end()) { //if sum is prime
				{
					if (j - i + 1 > max_con) {
						max_con = j - i + 1;
						sum = temp;
					}
				}
			}
		}
	}
	ofstream fout("p50.out");
	fout << max_con << "  " << sum << endl;
	fout.close();
}

int main() {
	solve();
	return 0;
}
