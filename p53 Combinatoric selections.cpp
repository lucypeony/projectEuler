/*
lucypeony@hotmail.com

Euler Project p53 Combinatoric selections 
*/
#include<climits>
#include<iostream>

using namespace std; 

int main() {
	const int Million = 1000000;
	const int MAX_M = 101;
	int cnr[MAX_M][MAX_M];
	for (int i = 0; i < MAX_M; i++) {
		cnr[i][0] = 1;
		cnr[i][i] = 1;
	}

	int sum = 0;
	for (int i = 1; i < MAX_M; i++) {
		for (int j = 1; j < MAX_M; j++) {
			cnr[i][j] = cnr[i - 1][j - 1] + cnr[i - 1][j];
			if (cnr[i][j] > Million) {
				cnr[i][j] = Million;
				sum++;
			}
				
		}
	}
	cout << sum << endl;
	return 0;
}
