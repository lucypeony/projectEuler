/*
lucypeony@hotmail.com

Euler Project Problem 35 Circular primes

Well, rotation is not permutation! 
By rotating, it means that you remove the first digit and append it to the back.
For example: 123--->231--->312 it's rotation.
123--->132--->213--->231--->312---->321 it's permutation. 
*/

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<set>
using namespace std; 

//a circular primes cannot have even digits or 5 
bool safe(int n) {
	while (n > 0) {
		int x = n % 10;
		if (x == 0 || x == 2 || x == 4 || x == 6 || x == 8 ||x==5)
			return false;
		n /= 10;
	}
	return true;
}

void solve() {
	const int MILLION = 1000000;
	bool nums[MILLION / 2];
	memset(nums, true, sizeof(nums));

	vector<int> primes;
	primes.push_back(2);

	for (int i = 3; i*i < MILLION; i += 2)
		if (nums[i / 2])
			for (int j = i * i; j < MILLION; j += i*2)
				nums[j / 2] = false;

	for (int i = 3; i <= MILLION; i += 2)
		if (nums[i / 2])
			primes.push_back(i);

	set<int> safev;
	safev.insert(2);
	for (auto a : primes)
		if (safe(a))
			safev.insert(a);

	ofstream fout("p35.out");
	fout << "safev size:"<<safev.size()<<endl;
	for (auto a : safev)
		fout << a<<endl;
	

	set<int> circular;
	circular.insert(2); circular.insert(3); circular.insert(5); circular.insert(7);
	safev.erase(2); safev.erase(3); safev.erase(5); safev.erase(7);

	for (auto a : safev) {
		//generate all circular for a 
		string temp = to_string(a);
		int count = temp.size();
		int x = a;
		vector<int> acir;
		bool f = true;
		for (int i =1; i < count; i++) {
			int m = x % 10;
			 x = (int)m * pow(10, count - 1) + (x / 10);
			set<int>::iterator it = safev.find(x);
			if (it != safev.end()) {
				acir.push_back(x);
			}
			else {
				f = false;
				break;
			}
		}

		if (f) {
			circular.insert(a); 
			for (int item : acir) {
				circular.insert(item);
			}
		}
	}

	fout << "the num of circular primes: "<<circular.size() << endl;
	for (auto b : circular)
		fout << b << endl;
	fout.close();

}


int main() {
	solve();
	return 0;
}
