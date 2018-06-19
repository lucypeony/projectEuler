/*
lucypeony@hotmail.com

Euler Project p40 Champernowne's constant
*/

#include<iostream>
#include<string>
using namespace std; 


void solve() {
	string s = "";
	int i = 1;
	while (s.size() <= 1000000) {
		string is = to_string(i);
		s = s + is;
		i++;
	}

	int j = 1;
	int sum = 1;
	while (j <= 1000000) {
		sum *= s[j-1]-'0';
		//cout << j << " " << s[j-1] << " "<<sum<<endl;
		j *= 10;
	}
	cout << sum << endl;
	
}

int main() {
	solve();
	return 0;
}
