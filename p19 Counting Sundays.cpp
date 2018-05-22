/*
lucypeony 
lucypeony@hotmail.com
Euler Project P19： counting sundays

Problem Description: 


You are given the following information, but you may prefer to do some research for yourself.

1 Jan 1900 was a Monday.
Thirty days has September,
April, June and November.
All the rest have thirty-one,
Saving February alone,
Which has twenty-eight, rain or shine.
And on leap years, twenty-nine.
A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.

How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

----------------------
Well this is a typical ad hoc problem. :) 

*/
#include<iostream>
#include<fstream>

using namespace std; 

int months[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
void solve() {
	int count = 0; // the result 
	long long sums = 1;
	//calculate if head of the month is Sunday
	int year = 1900;
	while (year <= 2000) {
		bool leap = (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
		int month = 1;
		while (month<=12) {
			//if Sunday
			if (sums % 7 == 0) {
				cout << year << " " << month << "  is Sunday." << endl;
				count++;
			}
				
			sums += months[month];
			if (month==2 && leap) sums++;
			month++;
		}
		year++;
	}

	//output
	cout << count; 
	//this is from 1900.1.1 to 2000.12.31. 
	//should minus the two months in 1900. 
	cout << " count -2 : count is from 1900, should calculate the two months in 1900. " << endl;
}

int main() {
	solve();

	cout << "hello ";
	return 0; 
}
