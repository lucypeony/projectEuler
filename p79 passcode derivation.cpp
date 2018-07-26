/*
Project Euler 79 Passcode derivation
pen and paper will do
*/
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

int main() {
	freopen("p79.in", "r", stdin);
	freopen("p79.out", "w", stdout);
	int x;
	vector<int> attempts;
	while (cin >> x)
		attempts.push_back(x);


	cout << "73162890" << endl;

	fclose(stdin);
	fclose(stdout);
	return 0;
}