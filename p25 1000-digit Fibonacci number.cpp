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
		int temp = a[i] - '0' + b[j] - '0' + c;
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


int main() {
	int n = 1000;
	
	ofstream fout("p57.out");
	int ans = 0;
	string numerator = "1";
	string denominator = "2";
	while (n > 1) {
		//1+numerator/denominator
		numerator = add(numerator, denominator);
		
		if (numerator.size() > denominator.size()) {
			ans++;
		}
		//fout <<1001-n<<" "<< numerator << "/" << denominator << endl;
		//1+numerator/denominator
		numerator = add(numerator, denominator);
		//求倒数
		swap(numerator, denominator);
		n--;
	}
	numerator = add(numerator, denominator);
	fout << numerator << "/" << denominator << endl;
	fout << ans;
	fout.close();
	return 0;
}
