/*
Euler Project 31: Coin sums
-------------------------------
两个算法：第一个：暴力

第二个：动态规划
*/

#include<iostream>

using namespace std; 

/*
暴力解法
因为有1块的，所以无论前面如何凑，后面都可以用1块的凑齐。
*/
void brute_force() {
	int res = 0;
	int target = 200;
	for (int a = target; a >= 0; a -= 200) 
		for (int b = a; b >= 0; b -= 100) 
			for (int c = b; c >= 0; c -= 50)
				for (int d = c; d >= 0; d -= 20)
					for (int e = d; e >= 0; e -= 10)
						for (int f = e; f >= 0; f -= 5)
							for (int g = f; g >= 0; g -= 2)
								res++;
	cout << "the result is " << res << endl;
}

/*
动态规划
int ways[i],代表截至到目前为止，凑齐i这个钱的方法数。
另外一个是：状态转移方程
*/
void daynamic() {
	const int target = 200;
	int ways[target + 1] = { 0 };
	ways[0] = 1;

	int coins[] = {1,2,5,10,20,50,100,200};

	for(int i=0;i<=7;i++)
		for (int j = coins[i]; j <= target; j++) {
			ways[j] += ways[j - coins[i]];
		}

	cout << " the result is : " << ways[target];
}

int main() {
	brute_force();
	daynamic();

	return 0;
}
