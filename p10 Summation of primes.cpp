/*
the problem: 
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.

*/
/*
author: lucypeony
email: lucypeony@hotmail.com
Euler Project P10 sum of primes less than 2 million 

Using Prime Sieve method. 
because the primes are under 2 million, very easy to implement. 
should know more about the range of int, long long etc in c++ language. 

*/


#include<iostream>
#include<fstream>
#include<string.h>

using namespace std; 

const int MAX_N=2000000;

bool primes[MAX_N+1];

void solve(){
	memset(primes,1,sizeof(primes));
	//cout<<primes[1];
     int count=MAX_N;
     int x=2;count--;
     while(count>0){
     	
       for(;x<=MAX_N;x++){ //find the smallest of remained number as the new largest prime 
       		if(primes[x]){
       			//cout<<"x:"<<x<<endl;
       			count--;
       			//cout<<"count:"<<count<<endl;
       			break;	
			}
	   } //I made a mistake when first implement the prime sieve. shouldn't use while. should find the unused smallest number remained. 
        
        int j=2;
        while(j*x<=MAX_N){
            int y=j*x;
            if(primes[y])
            {
                primes[y]=0;
               // cout<<"y:"<<y<<endl;
                //cout<<"primes[y]:"<<primes[y]<<endl;
                count--;
                //cout<<"count:"<<count<<endl;
            }
            j++;
        }
        x++;
    }
    
    long long sum=0;
    for(int i=2;i<=MAX_N;i++)
        if(primes[i])
            sum+=i;
    cout<<sum;
}




int main(){
    solve();
    return 0;
} 
