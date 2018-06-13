/*
this is a funny little problem. 
*/
#include<iostream>
#include<fstream>

using namespace std; 

int main(){
	
	int fifth[10];
	for(int i=0;i<=9;i++){
		fifth[i]=i*i*i*i*i;
		cout<<fifth[i]<<endl;
	}
	
	cout<<" ------------------- ";
	
	long long res=0;
		 
		
	ofstream fout("p30.out");
	
	//1000~9999
	for(int a=1;a<=9;a++)
		for(int b=0;b<=9;b++)	
			for(int c=0;c<=9;c++)
				for(int d=0;d<=9;d++){
						int x=a*1000+b*100+c*10+d;
						int y=fifth[a]+fifth[b]+fifth[c]+fifth[d];
						fout<<x<<" "<<y<<endl;
						if(x==y){
							cout<<x<<endl;
							res+=x;
						}
							
				}
		//10000~99999		
		for(int a=1;a<=9;a++)
		for(int b=0;b<=9;b++)	
			for(int c=0;c<=9;c++)
				for(int d=0;d<=9;d++)
					for(int e=0;e<=9;e++){
						int x=a*10000+b*1000+c*100+d*10+e;
						int y=fifth[a]+fifth[b]+fifth[c]+fifth[d]+fifth[e];
						fout<<x<<" "<<y<<endl;
						if(x==y){
							cout<<x<<endl;
							res+=x;
						}
				}
		//100000~999999
		for(int a=1;a<=9;a++)
		for(int b=0;b<=9;b++)	
			for(int c=0;c<=9;c++)
				for(int d=0;d<=9;d++)
					for(int e=0;e<=9;e++)
						for(int f=0;f<=9;f++){
						int x=a*100000+b*10000+c*1000+d*100+e*10+f;
						int y=fifth[a]+fifth[b]+fifth[c]+fifth[d]+fifth[e]+fifth[f];
						fout<<x<<" "<<y<<endl;
						if(x==y){
							cout<<x<<endl;
							res+=x;
						}
				}
	
	cout<<res<<endl;
	fout.close();
	
	return 0;
}
