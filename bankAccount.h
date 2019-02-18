#include<iostream>
#include<string>
using namespace std;
class bankAccount
{
	string username;
	int account_number;
	float balance;
	int balancelimit;
	int *transactions;
	int totalnooftransactions;
	int size;
public:
	bankAccount(string username,int number);//Constructor
	void print();//This will print all data
	void withdrawn(int out);//This will withdraw amount from account
	void deposit(int in);//this will add amount in balance
	~bankAccount();//destructor
	void increaseTranCapacity();

};