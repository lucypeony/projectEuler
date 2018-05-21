/*
lucypeony 
lucypeony@hotmail.com
Euler Project p16 : Power digit sum 

problem description: 
2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
What is the sum of the digits of the number 2^1000?

first I generate the value of 2^1000, implementing BigInteger Multiplication. 
then calculate the sum of digits in the value. 

pretty easy :) 
*/
#include<fstream>

using namespace std; 

ofstream fout("p16.out");

//2^1000 has about 300 digits
//implement a BigInteger *2 function 
string multiply2(string s1) {
	int len_s1 = s1.size();
	int i = len_s1 - 1;

	int carry = 0;
	while (i >= 0){
		int temp = s1[i] - '0';
		temp *= 2;
		temp += carry; 
		carry = temp / 10;
		temp %= 10;
		s1[i] = temp + '0';
		i--;
	}
	if (carry > 0) {
		char t (carry + '0');
		s1 = t+ s1;
	}

	return s1;
}


void output_string(string s) {
	for (int i = 0; i < s.size(); i++)
		fout << s[i];
}

int main() {
	string res = "1024";
	for (int i = 11; i <= 1000; i++) {
		fout << i << "    ";
		res = multiply2(res);
		output_string(res);
		fout << endl;
	}

	long long sum_digits = 0;
	for (int j = 0; j < res.size(); j++)
		sum_digits += res[j] - '0';
	fout << sum_digits;

	return 0;
}
