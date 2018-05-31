/*
lucypeony@hotmail.com

Non-abundant sums Project Euler 23 
problem description: 
A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
-------------------------------------------------------------------------------------------------------------------
Brute force : 
1, find all the abundant numbers less than 28123, store them in a list 
2, create and mark all the numbers that can be created as the sum of two abundant numbers. 
3, sum up all non-marked numbers 
*/

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std; 


const int MAX_NUM = 28121;
const int MAX_PRIME = 28121;
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


int sum_of_divisors(int num,vector<int> primes) {
	int res = 1;
	int n = num;
	for (auto a : primes) {
		int t = 1;
		int res1 = 1;
		while (n%a == 0 && n>1) {
			t *= a;
			res1 += t;
			n /= a;
		}
		res *= res1;

		if (n <= 1)
			break;
	}
	return res-num; 
}


vector<int> brute_force() {
	vector<int> non_abundant_sum;
	vector<int> primes = create_primes();

	//create abundant number vector
	vector<int> abundant;
	for (int i = 12; i <= MAX_NUM; i++) {
		if (sum_of_divisors(i, primes) > i)
			abundant.push_back(i);
	}

	bool sums[MAX_NUM + 1]; //the array that stores the nums created by sums of abundant vectors 
	memset(sums, 0, sizeof(sums));
	for (auto a : abundant) {
		for (auto b : abundant) {
			int temp = a + b;
			if (temp >= 1 && temp <= MAX_NUM)
				if (!sums[temp])
					sums[temp] = true;
		}
	}

	for (int i = 1; i <= MAX_NUM; i++)
		if (!sums[i])
			non_abundant_sum.push_back(i);

	return non_abundant_sum;

}



int main() {
	ofstream fout("p23.out");
	vector<int> res = brute_force();
	fout << res.size() << endl;
	long long total = 0;
	for (auto a : res) {
		fout << a << endl;
		total += a;
	}
	fout << total << endl;
	fout.close();
	return 0;
}
