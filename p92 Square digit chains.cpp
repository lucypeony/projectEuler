/*
Project Euler p92 Square digit chains

this method is too slow
*/
#include<fstream>
#include<iostream>
#include<stack>
using namespace std;

const int MAX_M = 10000000;
int a[MAX_M + 1] = { 0 };

//return the square of digits of i
int square(int i) {
	int res = 0;
	while (i > 0) {
		res += (i % 10)*(i % 10);
		i /= 10;
	}
	return res;
}

bool visited(int i) {
	if (a[i] == 1 || a[i] == 89)
		return true;
	else
		return false;
}

void solve() {
	freopen("p92.out", "w", stdout);

	int count = MAX_M;
	while (count > 0) {
		for (int i = 1; i <= MAX_M; i++) {
			if (a[i] == 1 || a[i] == 89)
				continue;
			stack<int> temp;
			int x = square(i);
			temp.push(i);
			count--;
			bool flag = false;
			while (x != 1 && x != 89) {
				temp.push(x);
				if (visited(x)) {
					flag = true;
					break;
				}
				x = square(x);
				count--;
			}

			if (flag)
			{
				x = a[x];
			}
			while (!temp.empty()) {
				a[temp.top()] = x;
				temp.pop();
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= MAX_M; i++)
		if (a[i] == 89) {
			//cout << i << endl;
			ans++;
		}


	cout << ans << endl;
	fclose(stdout);
}

int main() {
	solve();
	return 0;
}