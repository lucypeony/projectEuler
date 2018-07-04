#include<iostream>
using namespace std; 

int main(){
	
	for(int x=100;x<=999;x++){
		int flag[10]={0};
		bool f=true;
		for(int i=1;i<=6;i++){
			int y=x*i;
			while(y>0){
				flag[y%10]++;
				y/=10;
			}
		}
		
		for(int j=0;j<=9;j++)
			if(flag[j]!=0 && flag[j]!=6)
			{
				f=false;
				break;
			}
		if(f==false)
			continue;
		else
		{
			cout<<x<<endl;
			cout<<2*x<<endl;
			cout<<3*x<<endl;
			cout<<4*x<<endl;
			cout<<5*x<<endl;
			cout<<6*x<<endl;
			break;
		}
	}
	
	return 0;
} 
