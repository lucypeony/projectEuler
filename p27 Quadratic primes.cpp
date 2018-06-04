/*
lucypeony@hotmail.com
problem description: 
https://projecteuler.net/problem=27
--------------------------------------
I want to use a clever method at first. But I was wrong. 
So now I use a brute force method. 
But I still made a mistake. The problem asks to calculate if n*n+n*a+b is prime. What I calculate at first is n*n+a*b+b.What a shame!
Brute Force: a,b two for loops. 
b must be prime. 

something can be improve: 
I can generate more primes, when I need to check if x is prime, i can check if x is in the prime array. 

I make use of the fact that when n=0, the result is b. so b must be prime. 

when n=1,the result is 1+a+b, I can make use of this fact as well. 
*/

#include<iostream>
#include<string>
#include<fstream>
#include<vector>


using namespace std; 

const int MAX_PRIME = 1000;
vector<int> create_primes() {
	vector<int> res;
	bool tarray[MAX_PRIME + 1];
	memset(tarray, 1, sizeof(tarray));

	int count = MAX_PRIME - 2;
	tarray[1] = false;
	int start = 2;
	while (count > 0) {
		int i = 2;
		while (i*start <= MAX_PRIME) {
			int temp = i * start;
			if (tarray[temp]) {
				tarray[temp] = false;
				count--;
			}
			i++;
		}
		start++;
		while (!tarray[start])
		{
			start++;
		}
		count--;
	}

	for (int k = 2; k <= MAX_PRIME; k++)
		if (tarray[k])
			res.push_back(k);

	return res;
}

bool prime(int a) {
	int i = 2;
	if (a < 0)
		a = 0 - a;
	if (a == 0)
		return false;
	while (i*i <= a) {
		if (a%i == 0)
		{
			return false;
		}
		i++;
	}
	return true;
}

int gcd(int a, int b) {
	if (a < b)
		swap(a, b);

	int r = a % b;
	while (r != 0) {
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}


void solve() {
	vector<int> p = create_primes();

	int x = -1;
	int y, z;
	
	for (int a = -999; a <= 999; a++) {
		for (auto b : p) {
			int n = 0;
			int temp=0;
			bool tempf = false;
			do {
				n++;
				temp = n * n + a * n + b;
				tempf = prime(temp);
			} while (tempf);
			
			if (n > x) {
				x = n;
				y = a;
				z = b;
			}
		}
	}
	

	for (int a = -999; a <= 999; a++) {
		for (auto b : p) {
			b = 0 - b;
			int n = 0;
			int temp;
			do {
				n++;
				temp = n * n + a * n + b; 
			} while (prime(temp));

			if (n > x) {
				x = n;
				y = a;
				z = b;
			}
		}
	}

	cout << x << endl;
	cout << y << " " << z << " "<<y*z<<endl;
	
}

void test() {
	ofstream fout("p27.out");
	int a = -79, b = 1601;
	for (int i = 0; i <= 1000; i++) {
		int temp = i * i + a * i + b;
		fout << i << " " << temp << " " << prime(temp) << endl;

	}
}

int main() {
	solve();
	//test();
	cout << "hello world";
	return 0;
}
