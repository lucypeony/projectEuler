/*
lucypeony
lucypeony@hotmail.com
P14 of Euler Project 
Longest Collatz sequence
The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:
13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1

It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.

*/
/*
this problem is easy. Be careful not to overflow. 
can we do better ? 
Brute force and naive method
Can we do better ? 
Memory search. We can store the data if we can use it later. 
*/
#include "p14.h"

const int MAX_N = 1000000;
long long  fc[MAX_N + 1];       //the arrary holds faster_collatz numbers

ofstream fout("p14.out");

int t_collatz(int num) {        //naive method to calculate the collatz 
	int count = 1;
	while (num != 1) {
		if (num % 2 == 0)
			num /= 2;
		else
			num = 3 * num + 1;	
		count++;
	}
	return count;
}

long long collatz(long long  num) {           //num can be larger than one million, long long 
	//fout <<  num << ":";
	long long  count = 1;
	while (num != 1) {
		if (num % 2 == 0) {
			num /= 2;
			//fout << num << " ";
			if (num <= MAX_N && fc[num] != 0 )      //num<=MAX_N should be first calculated ; num can be larger than MAX_N
				return fc[num]+count;                 //don't recalculate fc[num]
		}
		else {
			num = 3 * num + 1;
			//fout << num << " ";
			if ( num<=MAX_N && fc[num] != 0  )
				return fc[num]+count;
		}
		count++;
	}
	return count;
}

void faster_collatz( ) {
	
	memset(fc, 0, sizeof(fc));          
	long long  i = 1;
	long long  res = -1;
	long long  res_i = -1;
	while(i<=MAX_N)
	{
		fc[i] = collatz(i);
		//fout<<i<<": "<< fc[i] << endl;
		if (fc[i] > res) {
			res = fc[i];
			res_i = i;
		}
		i++;
	}
	fout << "res: "<<res << endl;
	fout << "res_i: "<<res_i << endl;

}
