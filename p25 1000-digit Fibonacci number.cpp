/*
lucypeony@hotmail.com
p25 1000-digit Fibonacci number
The 12th term, F12,144, is the first term to contain three digits.
What is the index of the first term in the Fibonacci sequence to contain 1000 digits?
--------------------------------------------------------------------------------------
Big Integer Addition
*/
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

string add(string a, string b) {
	if (a.size()<b.size())
		swap(a, b);
	int len_a = a.size();
	int len_b = b.size();
	

	int i = len_a - 1;
	int j = len_b - 1;
	int c = 0;
	while (i >= 0 && j >= 0) {
		int temp = a[i] - '0' + b[j] - '0'+c;
		c = temp / 10;
		temp %= 10;
		a[i] = '0' + temp;
		i--;
		j--;
	}

	while (i >= 0) {
		int temp = a[i] - '0' + c;
		c = temp / 10;
		temp %= 10;
		a[i] = '0' + temp;
		i--;
	}

	if (c > 0) {
		char t(c + '0');
		a = t + a;
	}

	return a;
}

void solve() {
	ofstream fout("p25.out");
	string f1 = "1";
	string f2 = "1";
	//fout << f1 << endl;
	//fout << f2 << endl;
	int count = 2;
	while (1) {
		f1 = add(f1, f2);
		count++;
		//fout << f1 << endl;
		if (f1.size() == 1000)
			break;
		
		f2 = add(f1, f2);
		count++;
		//fout << f2 << endl;
		if (f2.size() == 1000)
			break;
		
	}

	string res = f1.size() > f2.size() ? f1 : f2;
	fout << "res:" << res << endl;
	fout << count << endl;
	
	fout.close();
}

int main() {
	solve();
	return 0;
}
