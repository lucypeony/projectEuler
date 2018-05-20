/*
lucypeony
lucypeony@hotmail.com
Euler Project: p5 lattice paths
*/

/*
calculate a lattice path problem:
from (0,0) to (n,k), can only move toward south or east , one grid 
res :binomial coefficient(n+k,n)
for this problem: binomial coeeicient (2n,n)=(2n)!/(n!*(2n-n)!)
*/

#include<iostream>
#include<fstream>
#include<string>

using namespace std;


void solve() {
	//calculate 40! / 20! /20!
	//21*22*23*... ... * 39*40
	//1*2*3*... ...*19*20
	ofstream fout("p15.out");
	unsigned long long res = 1;
	int f[9] = { 0,22,21,23,29,31,37,39,10 };   //be cautious about the Interger Overflow.
	int i = 1;
	while (i <= 8) {
		res *= f[i];
		fout << f[i ]<< " " << res << endl;
		i++;
	}

	fout << res;
	fout.close();
	
}
