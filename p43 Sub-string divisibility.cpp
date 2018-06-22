/*
这一题有两个方法：第一个brute force。复杂度：9*9!

另外一个就是通过分析数的可整除性，一个一个推。很容易就完成，paper and pencil! 
*/
#include<iostream>
#include<fstream>
using namespace std; 

int main(){
	ofstream fout("test.out");
	long long x=0;
	x+=1460357289;
	x+=4160357289;
	x+=1406357289;
	x+=4106357289;
	x+=4130952867;
	x+=1430952867;
	fout<<x<<endl;
	fout.close();
	return 0;
} 
