#include<iostream>
#include"bankAccount.h"
using namespace std;

bankAccount::bankAccount(string name,int number)//default constructor
{
	username=name;
	account_number=number;
	balance=0;
	balancelimit=200000;
	size=10;
	totalnooftransactions=0;
	transactions=new int[size];
	cout<<"In constr"<<endl;
}
void bankAccount::print()//prints all info
{
	cout<<"THe name of account is : "<<username<<endl;
	cout<<"Account number is : "<<account_number<<endl;
	cout<<"Balance is : "<<balance<<endl;
	cout<<"Total no of transactions are : "<<totalnooftransactions<<endl;
	for(int i=0;i<totalnooftransactions;i++)
		cout<<i+1<<"  transaction is : "<<transactions[i]<<endl;
	if(totalnooftransactions==0)//if no transaction the show this
		cout<<"No transactions had done "<<endl;


}
void bankAccount::withdrawn(int out)
{
	increaseTranCapacity();//first check availlibity of transaction 
							//if not available it wil double memory
	if(out>balance)//checks withdrwan balance is not more then available balance
		cout<<"Transaction not possible "<<endl<<"Not enough balance :"<<endl;
	else if(out<balance)
	{
		balance=balance-out;
		transactions[totalnooftransactions]=out*-1;
		totalnooftransactions++;
		cout<<"Transaction successful : "<<endl;
	}

}
void bankAccount::deposit(int in)
{
	increaseTranCapacity();//first check availlibity of transaction 
							//if not available it wil double memory
	if(in<balancelimit)//checks deposit balance is not more then available balance
	{
		balance=balance+in;
		if(balance<balancelimit)
		{
			transactions[totalnooftransactions]=balance;
		totalnooftransactions++;
		cout<<"Transaction successful "<<endl;
	}
		}
	else
		cout<<"Balance limit reached :"<<endl;
}
void bankAccount:: increaseTranCapacity()
{
	if(totalnooftransactions==size-1)
	{
		int * arr=new int[size*2];
		for(int i=0;i<size;i++)
			arr[i]=transactions[i];

		delete[]transactions;
		transactions=new int [size*2];
		for(int i=0;i<size;i++)
			transactions[i]=arr[i];
		delete[]arr;
		arr=nullptr;
		size=size*2;

	}

}
bankAccount::~bankAccount()
{

	delete [] transactions;

	transactions=nullptr;
	cout<<"In des"<<endl;
}