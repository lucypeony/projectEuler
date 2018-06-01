/*
lucypeony@hotmail.com

Problem: Euler Project 24 Lexicographic permutations.
A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:
012   021   102   120   201   210
What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
----------------------------------------------------------------------------------------------
use vectors erase() method 


*/
#include<list>
#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;

int fact[11];
void create_fact() {
	fact[0] = 1;
	for (int i = 1; i <= 10; i++)
		fact[i] = fact[i - 1] * i;
}

void solve() {
	create_fact();
	int n = 10;
	string permNum = "";
	int remain = 1000000 - 1;

	vector<int> numbers;
	for (int i = 0; i < n; i++)
		numbers.push_back(i);

	for (int i = 1; i < n; i++) {
		int j = remain / fact[n - i];
		remain = remain % fact[n - i];

		permNum += ('0'+numbers[j]);
		numbers.erase(numbers.begin()+j);

		if (remain == 0)
			break;
	}

	for (int i = 0; i < numbers.size(); i++)
		permNum += ('0' + numbers[i]);
	
	
	ofstream fout("p24.out");
	fout << permNum << endl;
	fout.close();
}

int main() {
	solve();
	return 0;
}
