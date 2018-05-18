/*
author:Lucy Peony
email:lucypeony@hotmail.com
P13 Euler Project :Large sum
this problem is to calculate the sum of Big Numbers 
*/
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

//global variables
const int MAX_N=100;
string s[MAX_N+1];

ofstream fout("p13.out");

void getData(){
	ifstream fin("p13.in");
	for(int i=1;i<=MAX_N;i++)
		fin>>s[i];
	fin.close();
}


string add(string a, string b){
	if(a.size()<b.size())
		swap(a,b);			//a.size() >=b.size()
	int alen=a.size();
	int blen=b.size();
	string res="";
	int x=alen-1;
	int y=blen-1;
	int carry=0;
	while(x>=0 && y>=0){
		int i=a[x]-'0';
		int j=b[y]-'0';
		int temp=i+j+carry;
		res+=(temp%10)+'0';
		carry=temp/10;
		x--;y--;
	}
	
	while(x>=0){				//when there are some digits in a string left 										
		int p=a[x--]-'0'+carry;
		carry=p/10;
		p%=10;
		res+=p+'0';		
	}
	
	if(carry>0)
		res+=carry+'0';
		
	int rlen=res.size();
	for(int i=0;i<rlen/2;i++){
		swap(res[i],res[rlen-1-i]);
	}
	
	return res;
}


void solve(){
	getData();
	
	string c=add(s[1],s[2]);
	for(int i=3;i<=MAX_N;i++)
		c=add(c,s[i]);
		
	fout<<c;
	
}


int main(){
	solve();
	fout.close();
	return 0;
}
