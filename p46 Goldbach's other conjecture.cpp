/*
lucypeony@hotmail.com

Euler Project p46 Goldbach's other conjecture
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std; 

vector<int> primes;
void generate_primes() {
	const int MAX_M = 5000;
	bool nums[MAX_M / 2];
	memset(nums, true, sizeof(nums));

	primes.push_back(2);

	for (int i = 3; i*i < MAX_M; i += 2)
		if (nums[i / 2])
			for (int j = i * i; j < MAX_M; j += i * 2)
				nums[j / 2] = false;

	for (int i = 3; i < MAX_M; i += 2)
		if (nums[i / 2])
			primes.push_back(i);
}

void solve() {
	generate_primes();

	int x = 7;
	while (true) {
		x += 2;
		//if x is not composite
		if (find(primes.begin(), primes.end(), x) != primes.end())
			continue;
		
		//x is composite
		bool t = false;
		for(auto a:primes)
			if (a < x) {
				int y = (x - a) / 2;
				//if y is square
				double yroot = sqrt(y);
				if (yroot == (int)yroot)
				{
					t = true;
					break;
				}
			}
			else
				break;
		if (!t)
		{
			cout << x << endl;
			break;
		}
	}//while
}//solve

int main() {
	solve();
	return 0;
}
