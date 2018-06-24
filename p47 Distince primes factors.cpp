/*
lucypeony@hotmail.com

Euler Project p47 Distince primes factors
*/
#include<iostream>
#include<set>

using namespace std; 

int primesfactors(int x) {
	set<int> res;
	int m = 2;
	while (m*m <= x) {
		if (x%m == 0) {
			x /= m;
			res.insert(m);
		}
			
		else
			m++;
	}

	if (x != 1)
	{
		res.insert(x);
	}
	return res.size();
}

void solve() {
	int x = 2 * 3 * 5 * 7;
	int c = 1;
	while (c < 4) {
		x++;
		//get the numbers of distinct primes factors
		if (primesfactors(x) == 4)
			c++;
		else
			c = 0;
	}
	cout <<x-3<<" "<<x-2<<" "<<x-1<<" "<< x << endl;
}//solve

int main() {
	solve();
	return 0;
}
