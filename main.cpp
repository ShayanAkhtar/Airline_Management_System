#include<iostream>
#include<fstream>
#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include"Admin.h"                // Admin Class
#include"User.h"                 // User Class
using namespace std;
int main(){
	admin a;
	user u;
    cout<<"\t\t\t\t************"<<endl;
	cout<<"\t\t\t\t     Airline Mangement System   "<<endl;
	cout<<"\t\t\t\t************"<<endl;
	cout<<"\n\n\t\t\t\t\t\t Project by : ";
	cout<<"\n\t\t\t\t\t\t     Shayan Akhtar ";
	cout<<"\n\n\n\t\t Press any key to continue.....";
	getch();
	p:
	system("cls");
	int choice;
	cout<<"\t\t\t\t************"<<endl;
	cout<<"\t\t\t\t     Airline Mangement System   "<<endl;
	cout<<"\t\t\t\t************"<<endl;
	cout<<"\n\n";
	cout<<"\n\t1. ADMIN "<<endl;
	cout<<"\n\t2. USER "<<endl;
	cout<<"\n\t3. Exit "<<endl;
	cout<<"\n\t> Select : ";
	
	cin>>choice;
	switch(choice){
		case 1:
			a.adminlogin();
			break;
		case 2:
			u.u_menu();
			break;
		case 3:
			exit(0);
		default:
			cout<<"\nInvalid choice ....";
			goto p;
	}

	return 0;
}
