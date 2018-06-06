/*
Problem 49:Prime permutations
*/

#include<iostream>
#include<fstream>
#include<vector>

using namespace std; 

vector<int> generate_primes(int n) {
	const int N = 10000;
	bool primes[N / 2];

	for (int i = 3; i*i <= n; i += 2) {
		if (primes[i/2])
			for (int j = i * i; j <= n; j += 2 * i)
				primes[j/2] = false;
	}

	vector<int> res;
	res.push_back(2);
	for (int i = 3; i <= n; i += 2)
		if (primes[i / 2])
			res.push_back(i);
	return res;
}

bool isPerm(int a, int b) {
	

}

void solve() {
	vector<int> primes = generate_primes(10000);
	vector<int> data;
	for (auto a : primes)
		if (a > 1000)
			data.push_back(a);

	ofstream fout("euler.out");
	for(auto a:data)
		for(auto b:data)
			for (auto c : data) {
				if (isPerm(a, b) && isPerm(a, c)) {

				}
			}
	fout.close();
}

int main() {
	solve();
	return 0;
}
