/*
lucypeony 
lucypeony@hotmail.com
Euler Project P20 Factorial digit sum

Description: 
n! means n × (n − 1) × ... × 3 × 2 × 1

For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!

--------------------------------------------------
Big Integer Mulitiplication 
Big Number * (an integer which can be larger than 10 )
*/
#include<iostream>
#include<fstream>
#include<string>


using namespace std; 


//num <=9 
string multiply_num(string s1,int num) {
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

//f can >=10
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
	ofstream fout("p20.out");
	string res = "1";
	for (int i = 2; i <= 100; i++)
	{
		res = bigintegerMultiply(res, i);
		fout << res << endl;
		
	}
	
	fout << res << endl;

	long long sum = 0;
	for (int i = 0; i < res.size(); i++)
		sum += res[i] - '0';
	fout << sum << endl;
	fout.close();
}

int main() {
	solve();
	return 0; 
}
