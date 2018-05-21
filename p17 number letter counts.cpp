/*
lucypeony 
lucypeony@hotmail.com
Euler Project P17: Number letter counts

very easy problem
ad hoc
It is a test for my spelling . :D
*/
#include<fstream>
#include<string>
using namespace std; 

string ge[]{ "","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen" };
string shi[]{ "twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety" };
string bai = "hundred";
string qian = "thousand";
string cand = "and";

ofstream fout("p17.out");


int num(int x) {
	string num_s = "";
	int count = 0;
	if (x >= 1000) {
		count += ge[1].size() + qian.size(); // one thousand
		x %= 1000;
		num_s += ge[1]+" " + qian + " ";
	}

	bool f = false;
	//x now <1000
	if (x >= 100) {
		int temp = x / 100; 
		count += ge[temp].size() + bai.size() ; //hundred
		x %= 100;
		num_s += ge[temp] + " " + bai + " ";
		f = true;
	}

	if (f && (x>0) )               //if x is like 200,400 etc. 
	{
		num_s +=cand + " ";
		count += cand.size();
	}

	//x now <= 99
	if (x >= 20) {
		count += shi[x / 10 - 2].size() + ge[x % 10].size();
		num_s += shi[x / 10 - 2] + " " + ge[x % 10] + " ";
	}
	else {
		count += ge[x].size();
		num_s += ge[x] + " ";
	}
	//fout << num_s <<"  "<<count<< endl;
	return count;

}

int main() {
	int res = 0;
	for (int i = 1; i <= 1000; i++)
		res += num(i);
	fout << res << endl;

	fout.close();
	return 0;
}
