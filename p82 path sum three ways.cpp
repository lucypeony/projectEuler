/*
Project Euler 82:Path sum: three ways

mathblog.dk:
The information we want to get for the column is the smallest value to get from each entry in that column to somewhere in the last column. When we are standing in the last column answering this is trivial. So assume that we now stand in the next to last column and let¡¯s figure out how we solve that problem.

When we stand in one of the entries we have three options, we can go up, right or down. So the question is which of them will give us the shorter path and how do we break this? The thing we need to know here is that all numbers are positive. So if we find that the minimal path is to go up, the minimal path for the entry above cannot be to go down.

That means we can make two sweeps over the column. One sweep going down checking if the cheaper solution is to go up or right.  For the first entry we only calculate the price for going to the right. For the second entry we can check if it is cheaper to go up to the first and then right, or go to the right directly. It is possible that it would be cheaper for the first entry to go down, but in that case it would not be beneficial to go up for the second entry. In case we want to go up we already know the solution for continuing to go up as that problem is already solved. This is the reason we can compare the right and the up paths.

The second sweep goes up checking if it would be cheaper to go down rather than the previously found solution. Since we start from below we can check if the already found solution of going up or right is more expensive of going down.  This we do for each of the entries.

Now we have solved for a column, so for each entry we know the cheapest path from there to the right side. So now we can take the column to the left until we are at the first column
*/
#include<iostream>
#include<fstream>
#include<cmath>
#include<algorithm>
#include<sstream>

using namespace std;

int main() {
	freopen("p82.in", "r", stdin);
	freopen("p82.out", "w", stdout);
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

	//initialise solution 
	int sum[m + 1];
	for (int i = 1; i <= n; i++)
		sum[i] = a[i][n];

	for (int i = n - 1; i >= 1; i--) {
		//traverse down
		sum[1] += a[1][i];
		for (int j = 2; j <= n; j++) {
			sum[j] = min(sum[j - 1] + a[j][i], sum[j] + a[j][i]);
		}

		//traverse up 
		for (int j = n - 1; j >= 1; j--) {
			sum[j] = min(sum[j], sum[j + 1] + a[j][i]);
		}
	}

	int ans = sum[1];
	for (int i = 1; i <= n; i++)
		if (ans > sum[i])
			ans = sum[i];
	cout << ans << endl;

	fclose(stdin);
	fclose(stdout);
	return 0;
}