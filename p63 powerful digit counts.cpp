/*
Project Euler p63 Powerful digit counts

其实没必要算这么多，只需要额外算算9的情况就可以
*/
#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
using namespace std;

string multiply_num(string s1, int num) {
	int len_s1 = s1.size();
	int i = len_s1 - 1;

	int carry = 0;
	while (i >= 0) {
		int temp = s1[i] - '0';
		temp *= num;
		temp += carry;
		carry = temp / 10;
		temp %= 10;
		s1[i] = temp + '0';
		i--;
	}
	if (carry > 0) {
		char t(carry + '0');
		s1 = t + s1;
	}

	return s1;
}

string add(string a, string b) {
	if (a.size()<b.size())
		swap(a, b);			//a.size() >=b.size()
	int alen = a.size();
	int blen = b.size();
	string res = "";
	int x = alen - 1;
	int y = blen - 1;
	int carry = 0;
	while (x >= 0 && y >= 0) {
		int i = a[x] - '0';
		int j = b[y] - '0';
		int temp = i + j + carry;
		res += (temp % 10) + '0';
		carry = temp / 10;
		x--; y--;
	}

	while (x >= 0) {				//when there are some digits in a string left 										
		int p = a[x--] - '0' + carry;
		carry = p / 10;
		p %= 10;
		res += p + '0';
	}

	if (carry>0)
		res += carry + '0';

	int rlen = res.size();
	for (int i = 0; i<rlen / 2; i++) {
		swap(res[i], res[rlen - 1 - i]);
	}

	return res;
}

string bigintegerMultiply(string s, int f) {
	int ls = s.size();
	string res = "";

	int t = f % 10;
	f /= 10;
	res = multiply_num(s, t);

	int pivot = 0;
	while (f > 0) {
		pivot++;
		t = f % 10;
		f /= 10;
		string temp = multiply_num(s, t);

		for (int i = 0; i < pivot; i++)
			temp += '0';
		res = add(temp, res);
	}


	return res;
}

void solve() {
	freopen("p63.out", "w", stdout);
	//1^1,1^2, ... ... , 1^9
	//... ... 
	//9^1,  ... ... , 9^9
	int ans = 0;
	for (int i = 1; i <= 100; i++) {
		string s = "1";
		for (int j = 1; j <= 100; j++) {
			s = bigintegerMultiply(s, i);
			if (s.size() == j)
			{
				ans++;
				cout << s << " = " << i << "^" << j << endl;
			}
		}
	}

	cout << ans << endl;



}

int main() {
	solve();

	fclose(stdout);
	return 0;
}