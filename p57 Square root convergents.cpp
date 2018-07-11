#include<iostream>
#include<fstream>
#include<string>
#define ul unsigned long long 
using namespace std; 

ul gcd(ul a, ul b) {
	ul r = a % b;
	while (r > 0) {
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

int main() {
	int n = 1000;
	
	ofstream fout("p57.out");
	int ans = 0;
	ul numerator = 1;
	ul denominator = 2;
	while (n > 1) {
		//2+numerator/denominator
		numerator +=  denominator;
		ul gcd1 = gcd(numerator, denominator);
		if (gcd1 > 1) {
			numerator /= gcd1;
			denominator /= gcd1;
			fout <<1001-n<< "  gcd1 " << gcd1 << endl;
		}
		if (to_string(numerator).size() > to_string(denominator).size()) {
			//fout << numerator << "/" << denominator << endl;
			ans++;
		}
		fout <<1001-n<<" "<< numerator << "/" << denominator << endl;
		numerator += denominator;
		//求倒数
		swap(numerator, denominator);
		n--;
	}
	numerator += denominator;
	fout << numerator << "/" << denominator << endl;
	fout << ans;
	cout << "Hello World!" << endl;
	fout.close();
	return 0;
}
