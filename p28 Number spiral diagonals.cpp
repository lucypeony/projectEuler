/*
lucypeony@hotmail.com
P28 Number spiral diagonals.
------------------------
Brute force 
*/

#include<iostream>
#include<fstream>
#include<string>
using namespace std; 

void brute_force() {
	//generate spiral numbers
	const int N = 1001;
	int max_n = N / 2;
	int n = 1; //control the level number
	int count = 0;
	struct dir { int x; int y; };
	dir d[] = { {0,1},{1,0},{0,-1},{-1,0} }; //clockwise : right, down , left, up 
	dir temp;

	static int s[N][N];//store the numbers , add "stack" to avoid StackOverflow
	memset(s, -1, sizeof(s));

	int direction = -1;
	int x, y;
	x = max_n; y = max_n; s[x][y] = 1;
	do {
		for (int c = count; c <= 2; c++) {
			direction++;
			temp = d[direction%4];
			//fill n numbers
			for (int i = 1; i <= n; i++) {
				s[x + temp.x][y + temp.y] = s[x][y] + 1;
				x += temp.x;
				y += temp.y;
			}
		}
		
		if (x + temp.x <= N - 1 && y + temp.y <= N - 1) {
			s[x + temp.x][y + temp.y] = s[x][y] + 1;
			x += temp.x;
			y += temp.y;
		}
		

		count = 1;
		n++;
	} while (n <= N-1);


	long long sum = 0;
	//output the spiral numbers 
	ofstream fout("p28.out");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j || i + j == N - 1)
				sum += s[i][j];
			fout << s[i][j] << " ";
		}
		fout << endl;
	}
	fout << sum << endl;
	fout.close();
	cout << sum << endl;
}


int main() {
	brute_force();

	cout << "Hello World!";
	return 0;
}
