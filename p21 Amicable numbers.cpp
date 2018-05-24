/*
lucypeony 
lucypeony@hotmail.com
Euler Project P21 Amicable numbers :

Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.
For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.
-----------------------------------
here we have two methods;
1, naive one. calculate sum of divisors using naive methods
2, calculate sum of divisors using a little math
let d(n)= sum of divisors of n ,and n=p[i]^i *... ... p[j]^j (prime factorial)
then d(n)= (p[i]^(i+1) -1)* ... ... *(p[j]^(j+1)-1)
*/
#include<iostream>
#include<fstream>
#include<string>


using namespace std; 

int sum_divisors(int x) {
	int r = 1;
	for (int i = 2; i <= sqrt(x); i++) {
		if (x %i == 0)
		{
			r += i;
			int j = x / i;
			if (i != j)
				r += j;
		}
	}
	return r;
}


const int MAX_N = 10000;
long long  res[MAX_N + 1];
void solve() {
	ofstream fout("p21");
	for (int i = 1; i <= MAX_N; i++) {
		res[i] = sum_divisors(i);
		//fout << res[i] << endl;
	}

	int sum = 0;
	
	for (int i = 1; i <= MAX_N; i++) {
		int t = res[i];
		if (t <= MAX_N && t!=i) {
			int s = res[t];
			if (s == i) {
				fout << i<<" "<<t<< endl;
				sum += s;
			}
		}
		
	}

	fout << "result is :" << sum << endl;
	fout.close();
}

int main() {
	solve();
	return 0; 
}
