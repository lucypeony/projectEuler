/*
lucypeony@hotmail.com

Euler Project p41 Pandigital prime
*/
#include<iostream>

using namespace std; 

/*
这一题要求求出最大的n-位pandigital number. 那么n可能为多少呢？
有没有可能是9位的？
这里我们要用到3的整除定理。
因为9位的pandigital ,它的digits不计次序，总是1~9，如果他们的和能被3整除，这个数就能被3整除
那么：
9 digits: 1+2+3+4+5+6+7+8+9=45 mod 3=0
8 digits: 1+2+3+4+5+6+7+8=36 mod 3=0
7 digits: 1+2+3+4+5+6+7=28 mod 3 =1 
6 digits: 1+2+3+4+5+6=21 mod 3=0
5 digits: 1+2+3+4+5=15 mod 3=0
4 digits: 1+2+3+4=10 mod 3=1
3 digits: 1+2+3=6 mod 3=0

因此这样的素数只能是四位数或者七位数！
因为我们要找最大的，所以，从7开始！

the last digit can only be 1,3,7. all digits are euql or smaller than 7 
*/

bool isPandigital(int n,int digit) {
	int a[10] = { 0 }; //1~9

	while (n > 0) {
		a[n % 10]++;
		n /= 10;
	}

	for (int i = 1; i <= digit; i++) {
		if (a[i] != 1)
			return false;
	}

	return true;
}

bool isPrime(int n) {
	for (int i = 2; i*i < n; i++) {
		if (n%i == 0)
			return false;
	}
	return true;
}

void solve(){
	int i = 7000001;
	int max = -1;
	while (i <= 8000000) {
		if (isPandigital(i,7) && isPrime(i)) {
			if (max < i)
				max = i;
			cout << i << endl;
		}
		i += 2;
	}

	cout << "the max is : " << max << endl;
}

int main() {
	solve();

	cout << "Stop here!";
	return 0;
}
