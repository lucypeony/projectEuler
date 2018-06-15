/*
lucypeony@hotmail.com

Euler Project Problem 32 Pandigital numbers
*/

#include<iostream>
#include<set>
#include<string>
using namespace std;

//return set of digits without 0 of n 
set<int> getDigits(int n) {
	set<int> ret;
	while (n > 0) {
		ret.insert(n % 10);
		n /= 10;
	}

	ret.erase(0);
	return ret;
}

int int_size(int n) {
	string s = to_string(n);
	return s.size();
}

//1 4 4 
//2 3 4 
void brute_force() {
	set<int> ans;
	//1 4 4 
	for (int a = 1; a <= 9; a++) {
		for (int b = 1000; b <= 9999; b++) {
			set<int> all;
			all.insert(a);

			set<int> bs = getDigits(b);
			if (bs.size() < int_size(b))
				continue;

			int c = a * b;
			set<int> cs = getDigits(c);
			if (cs.size() < int_size(c))
				continue;

			for (auto x : bs)
				all.insert(x);
			for (auto x : cs)
				all.insert(x);

			if (all.size() == 9 && bs.size() + cs.size() == 8) {
				cout << a << " " << b << " " << c << endl;
				ans.insert(c);
			}

		}
	}

	//2 3 4 
	for (int a = 10; a <= 99; a++) {
		set<int> as = getDigits(a);
		if (as.size() < int_size(a))
			continue;
		for (int b = 100; b <= 999; b++) {
			set<int> all;

			set<int> bs = getDigits(b);
			if (bs.size() < int_size(b))
				continue;

			int c = a * b;
			set<int> cs = getDigits(c);
			if (cs.size() < int_size(c))
				continue;


			for (auto x : as)
				all.insert(x);
			for (auto x : bs)
				all.insert(x);
			for (auto x : cs)
				all.insert(x);

			if (all.size() == 9 && bs.size() + cs.size() + as.size() == 9) {
				cout << a << " " << b << " " << c << endl;
				ans.insert(c);
			}

		}
	}

	int count = 0;
	for (auto a : ans)
		count += a;
	cout << " the sum is : " << count << endl;
}

int main() {
	brute_force();

	cout << "Hello World!";
	return 0;
}
