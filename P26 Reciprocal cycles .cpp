/*
lucypeony@hotmail.com

Euler Project Problem 26 Reciprocal cycles 
description :
A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:
1/2	= 	0.5
1/3	= 	0.(3)
1/4	= 	0.25
1/5	= 	0.2
1/6	= 	0.1(6)
1/7	= 	0.(142857)
1/8	= 	0.125
1/9	= 	0.(1)
1/10	= 	0.1
Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.
Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.
---------------------------------------------------------------------------------------------------------------
this code is a mess . try to clean it up later
*/
#include<string>
#include<vector>
#include<fstream>
#include<iostream>
#include<algorithm>

using namespace std;

ofstream fout("p26.out");

//calculate 1/n
string divide1(int n) {
	string res = "0.";
	int quotient;
	int remainder;
	int dividend = 1;

	const int DIGITS = 2000;
	int count = 1;

	do {
		count++;
		if (dividend < n)
			dividend *= 10;

		while (dividend < n) {
			dividend *= 10;
			res += '0';
		}

		quotient = dividend / n;
		res += char(quotient + '0');
		remainder = dividend % n;
		//fout << dividend << " / " << n << "=" << quotient << "......" << remainder << "   " << res << endl;
		dividend = remainder;
	} while (remainder != 0 && count <= DIGITS);

	return res;
}

void test() {
	fout << divide1(998) << endl;
}

//return the length of reciprocal cycles of 1/n
int cycle_length(int n) {
	int len = 0;
	vector<int> rem; //store remainders 
	vector<int> res;//store the result of division 
	int quotient;
	int remainder;
	int dividend = 1;

	const int DIGITS = 2000;
	int count = 1;

	if (dividend < n) {
		dividend *= 10;
	}
		

	while (dividend < n) {
		dividend *= 10;
		res.push_back(0);
	}

	quotient = dividend / n;
	res.push_back(quotient);
	remainder = dividend % n;

	rem.push_back(remainder);

	while (remainder != 0 && count <= DIGITS){
		dividend = remainder;
		count++;
		if (dividend < n)
			dividend *= 10;

		while (dividend < n) {
			dividend *= 10;
			res.push_back(0);
		}

		quotient = dividend / n;
		
		remainder = dividend % n;
		
		vector<int>::iterator it;
		it = find(rem.begin(), rem.end(), remainder);
		if (it != rem.end()) {
			while (it != rem.end()) {
				len++;
				it++;
			}
			break;
		}//if
		rem.push_back(remainder);
		res.push_back(quotient);
	}//while

	fout << res.size() << " ";
	for (auto a : res)
		fout << a;
	fout << " ";
	return res.size();
}

void solve() {
	int most = -1;
	for (int i = 1; i <= 1000; i++)
	{
		fout << i << " ";
		int temp = cycle_length(i);
		fout << " "<<divide1(i) << endl;
		if (most < temp)
			most = temp;
	}
	fout << most << endl;
}

int main() {
	solve();
	//test();
	cout << "Hello world!";
	cout << "Hello world!";
	return 0;
}
