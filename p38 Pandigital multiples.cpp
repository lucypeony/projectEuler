/*
lucypeony@hotmail.com

Euler Project p38 Pandigital multiples
pandigital number . 9 digit number. largest 
987654321
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std; 

long long concatenate(long long x, long long y) {
	string ys = to_string(y);
	int ysize = ys.size();
	for (int i = 1; i <= ysize; i++)
		x *= 10;
	return (x + y);
}

int int_size(long long n) {
	string ns = to_string(n);
	return ns.size();
}

//if n is 1 to 9 pandigital 9-digit. 
bool pandigital(long long n) {
	if (int_size(n) != 9)
		return false;

	int count[10] = { 0 };
	while (n > 0) {
		count[n % 10]++;
		n /= 10;
	}
	if (count[0] > 0)
		return false;
	for (int i = 1; i <= 9; i++)
		if (count[i] != 1)
			return false;

	return true;
}

//brute force method
void solve() {
	long long max = -1;
	ofstream fout("p38.out");
	//num and (1...n); n is at least 2. so num is at most 9999
	for (int num = 1; num <= 9999; num++) {
		long long con = num;
		for (int n = 2; n <= 9; n++) {
			long long temp = num * n;

			//concatenate con und temp
			con = concatenate(con, temp);

			if (int_size(con) >= 9) {
				//if (1 to 9 pandigital) , break
				//if con is not pandigital 
				if (pandigital(con)) {
					if (con > max)
						max = con;
					fout << num << " 1.." << n << "  " << con << endl;
				}
				break;
			}
			
		}
	}
	fout << "max is : " << max << endl;
	fout.close();
}

int main() {
	solve();

	cout << "I am in here. ";
	return 0;
}
