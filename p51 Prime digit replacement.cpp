/*
lucypeony@hotmail.com

Euler Project p51 Prime digit replacement

因为3的整除性，同时又要保证至少有8个素数，因此，只能重复三个位数或三的倍数的位数。
假设一共有六位数。

现在脑子乱，有时间完善
*/
#include<iostream>
using namespace std; 

int sixPatterns[10][6]={
{1,1,0,0,0,1},
{1,0,1,0,0,1},
{1,0,0,1,0,1},
{1,0,0,0,1,1},
{0,1,1,0,0,1},
{0,1,0,1,0,1},
{0,1,0,0,1,1},
{0,0,1,1,0,1},
{0,0,1,0,1,1},
{0,0,0,1,1,1}
};

void solve() {
	for (int i = 100; i <= 999; i++) {
		int c = i % 10;
		if (c != 1 || c != 3 || c != 7 || c != 9)
			continue;
		int pattern[6];
		for (int j = 0; j < 10; j++) {

			//get sixPattern[j]
			for (int m = 0; m < 6; m++)
				pattern[m] = sixPatterns[j][m];

			int primeNum = 0;
			for (int k = 0; k <= 9; k++) {
				if (pattern[0] == 0 && k == 0)
					continue;
				//generate a number according to the pattern and k 
				int temp = 0;// generated num
				int x = 1;
				int y = i;
				for (int n = 0; n < 6; n++) {
					temp *= x;
					if (pattern[n] == 1) {
						temp+=
					}
				}
			}//generate 10 numbers 
		
		}
	}
}

int main() {

	return 0;
}
