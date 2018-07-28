/*
Project Euler p99 Largest exponential

这一题比较指数那个大，可以都对它对e求对数，然后比较
*/
#include<fstream>
#include<iostream>
#include<string>
#include<sstream>
#include<cmath>

using namespace std;
int main() {
	freopen("p99.in", "r", stdin);
	freopen("p99.out", "w", stdout);

	int a, b;
	int ta, tb, tline;
	double ans = -1;
	for (int i = 1; i <= 1000; i++) {
		string s;			//split int from comma. 
		getline(cin, s);
		istringstream is(s);

		char ch;
		is >> a;
		is >> ch;
		is >> b;
		is >> ch;

		double x = b * log(a);
		if (x > ans) {
			ans = x;
			ta = a;
			tb = b;
			tline = i;
		}

	}

	cout << tline << " " << ans << " " << ta << " " << tb << endl;

	fclose(stdin);
	fclose(stdout);
	return 0;
}