/*
Project Euler 81:Path sum: two ways

greedy algorithm
*/
#include<iostream>
#include<fstream>
#include<cmath>
#include<algorithm>
#include<sstream>

using namespace std;

int main() {
	freopen("p81.in", "r", stdin);
	freopen("p81.out", "w", stdout);
	const int m = 80;
	int a[m + 1][m + 1];
	int n = m;

	for (int i = 1; i <= n; i++) {
		int count = 0;
		string s;			//split int from comma. 
		getline(cin, s);
		istringstream is(s);
		int inter;
		char ch;
		while (is >> inter) {
			a[i][++count] = inter;
			is >> ch;
		}
	}

	int sum[m + 1][m + 1] = { 0 };
	for (int i = 1; i <= n; i++) {
		sum[1][i] = sum[1][i - 1] + a[1][i];
		sum[i][1] = sum[i - 1][1] + a[i][1];
	}

	for (int i = 2; i <= n; i++)
		for (int j = 2; j <= n; j++)
			sum[i][j] = a[i][j] + min(sum[i][j - 1], sum[i - 1][j]);



	cout << sum[n][n];

	fclose(stdin);
	fclose(stdout);
	return 0;
}