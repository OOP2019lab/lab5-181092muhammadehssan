#include<iostream>
#include"bankAccount.h"
using namespace std;
int main()
{
	
	bankAccount b1("myAccount",549002);
	b1.print();
	cout<<endl;
	b1.withdrawn(2000);
	cout<<endl;
	b1.deposit(250000);
	cout<<endl;
	b1.deposit(50000);
	cout<<endl;
	b1.print();
	int out=0,in=0;
	cout<<"Input deposit and withdraw amounts"<<endl;
	for(int i=0;i<20;i++)
	{
		cin>>in;
		b1.deposit(in);
		cin>>out;
		b1.withdrawn(out);
	}
	b1.print();


return 0;
}
