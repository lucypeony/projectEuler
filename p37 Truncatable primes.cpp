/*
lucypeony@hotmail.com

Euler Project p37 Truncatable primes

Brute Force. 
注意分类讨论，这个在简化的时候，不要略过了。比如说safe primes里不能有5，2，可是对于小于100的话，是可以有的。
*/
#include<vector>
#include<iostream>
#include<fstream>
#include<string>

using namespace std; 

vector<int> safePrimes;

bool safe(long long n) {
	string ss = to_string(n);
	int st = ss.size();
	/*
	if (ss[0] == '1' || ss[0] == '9')
		return false;
	
	if (ss[st - 1] == '1' || ss[st - 1] == '9')
		return false;
	*/

	for (int i = 0; i < st; i++) {
		if (n < 100) {
			if (ss[i] == '0' || ss[i] == '4' || ss[i] == '6' || ss[i] == '8')
				return false;
		}
		else {
			if ((int)ss[i] % 2 == 0 || ss[i] == '5')
				return false;
		}

	}
		

	return true;
}

const int MAX_M = 1 * 1000000;
bool nums[MAX_M / 2];
void generate_safe_primes() {
	//const int MAX_M = 100;
	
	memset(nums, true, sizeof(nums));

	vector<int> primes;
	primes.push_back(2);

	for (int i = 3; i*i < MAX_M; i += 2)
		if (nums[i / 2])
			for (int j = i * i; j < MAX_M; j += i * 2)
				nums[j / 2] = false;

	for (long long i = 3; i <= MAX_M; i += 2)
		if (nums[i / 2])
			primes.push_back(i);

	ofstream fout("safe.out");
	for (auto a : primes)
		if (safe(a)) {
			safePrimes.push_back(a);
			fout << a << endl;
		}	
	fout.close();
}

bool inSafe(long long n) {
	auto res = find(begin(safePrimes), end(safePrimes), n);
	if (res != end(safePrimes))
		return true;
	else
		return false;
}

bool truncatable(long long  n) {
	//from right
	long long right = n;

	long long  multiplier = 1;
	while (right > 0) {
		multiplier *= 10;
		if (!inSafe(right))
			return false;
		right /= 10;
	}

	long long  left = n;
	while (left > 0) {
		long long temp = left / multiplier;
		left -= temp * multiplier;
		if (left == 0)
			break;
		if (!inSafe(left))
			return false;
		multiplier /= 10;
	}
	return true;
}

void solve() {
	long long  sum = 0;
	generate_safe_primes();
	ofstream fout("p36.out");
	fout << "safe primes size: "<<safePrimes.size() << endl;
	fout << "truncatable primes: " << endl;

	int count = -3;
	for (auto a : safePrimes)
		if (truncatable(a)) {
			fout << count<<"  "<<a << endl;
			sum += a;
			count++;
		}
	
	sum -= 3;
	sum -= 7;
	sum -= 7;
	fout << "the sum is (without primes under 10): "<<sum << endl;
	fout.close();
}

int main() {
	solve();
	return 0;
}
