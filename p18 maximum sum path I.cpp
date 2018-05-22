/*
lucypeony 
lucypeony@hotmail.com
Euler Project P18 & P67: Maximum path sum I & II

this problem I had worked before. 
3
7 4
2 4 6
8 5 9 3
for a input array like this,
we can define d[i][j] = maximum path from bottom up to i,j
d[i][j]=c[i][j] + max(d[i+1][j],d[i+1],[j+1])


for me, this problem reminds how to read file line by line in C++
when you don't know how many lines there. 
read varied length lines from file. 

*/
#include<fstream>
#include<algorithm>
#include<string>
#include<sstream>
#include<iostream>
using namespace std; 

const int MAX_N = 101;
int c[MAX_N][MAX_N];
int res[MAX_N][MAX_N];
int N=0;

ofstream fout("p18.out");


//get integers from line 
//read lines from file
void getData() {
	ifstream fin("p18.in");
	string line;
	while (getline(fin, line)) {
		N++;
		//process this line 
		stringstream stream(line);
		for (int i = 0; i < N; i++)
			stream >> c[N - 1][i];
	}
	fin.close();
	
}

void solve() {
	getData();
	memset(res, 0, sizeof(res));
	//initilisation 
	for (int i = 0; i < N; i++) {
		res[N - 1][i] = c[N - 1][i];
	}

	for (int i = N-2; i >=0; i--) {
		for (int j = 0; j <= i; j++) {
			if (res[i+1][j ] > res[i + 1][j + 1]) {
				res[i][j] = c[i][j] + res[i+1][j];
			}
			else {
				res[i][j] = c[i][j] + res[i + 1][j + 1];
			}
		}
	}

	fout << res[0][0];
}



int main() {
	solve();
	return 0; 
}
