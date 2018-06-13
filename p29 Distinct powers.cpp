/*
lucypeony@hotmail.com

Euler Project Problem 29 
-----------------------------------------
We can use the brute force method. 100^100 is the biggest number. 
But we can use double variables.
<set> is a container without duplicates. 
-----------------------------------------
there is also a pen and paper way to solve this problem. 
there are only 99*99 numbers. some numbers are duplicates. Then we can decide which are duplicates. 
*/
#include<iostream>
#include<set>
#include<cmath>

using namespace std; 

int main(){
	set<double> res;
	for(int a=2;a<=100;a++){
		for(int b=2;b<=100;b++){
			double temp=pow(a,b);
			res.insert(temp);
		}
	}
	
	cout<<res.size();
} 
