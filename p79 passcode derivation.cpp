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

	int digits[10] = { 0 };
	for (auto a : attempts) {
		while (a > 0) {
			digits[a % 10]++;
			a /= 10;
		}
	}

	for (int i = 0; i <= 9; i++)
		cout << digits[i] << " ";

	fclose(stdin);
	fclose(stdout);
	return 0;
}