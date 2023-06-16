#ifndef Admin_H
#define Admin_H
#include<windows.h>
#include<string>
#include<iostream>
#include<fstream>
using namespace std;
class admin{
	private:
    int airline_no,airlinee_no,n_airline,pr,price,charac;      // Member Vaiables
    string departure,destination,dep,des,adminemail,adminpass;
    public:
    	
    	void adminlogin();
    	void menu();
    	void addflight();
    	void viewflight();                              // Member functions
    	void updateflight();
};
void admin::adminlogin(){
	p:
	system("cls");
	string ch;
	cout<<"\n";
    cout<<"\t\t\t\t************"<<endl;
	cout<<"\t\t\t\t          Admin Details         "<<endl;
	cout<<"\t\t\t\t************"<<endl;
	cout<<"\n\n\n\t> Enter the email address : ";
	cin>>adminemail;
	cout<<"\n\n\t> Enter the password : ";
	cin>>adminpass;
	if(adminemail=="fahadmalik@gmail.com"&&adminpass=="fahad"){
		cout<<"\n\n\n\t\t\t\t -------- Login Successfully ---------   ";
	Sleep(600);
       menu();
		}
	else{
		
		cout<<"\n\n\t Invalid Email or password";
		Sleep(600);
		goto p;
		
		
	}
	
}
void admin::menu(){
	p:
	system("cls");
	int c;
	cout<<"\t\t\t\t************"<<endl;
	cout<<"\t\t\t\t           Admin Menu           "<<endl;
	cout<<"\t\t\t\t************"<<endl;
	cout<<"\n\n\n\t1. Add Flight "<<endl;
	cout<<"\n\t2. View Flights "<<endl;
	cout<<"\n\t3. Update Flight "<<endl;
	cout<<"\n\t4. Exit "<<endl;
	cout<<"\n\t> Select : ";
	cin>>c;
	switch(c){
		case 1:
			addflight();
			s:
	cout<<"\n\n\t> Do you want to Go Back ( press 3 to go back or 0 to exit ) : ";
	cin>>charac;
	if(charac==3){
		menu();
	}
	else if(charac==0){
		exit(0);
	}
	else{
		cout<<"\n\n\t Invalid input !!!";
		Sleep(600);
		goto s;
	}
			break;
		case 2:
			viewflight();
	a:
    cout<<"\n\n\t> Do you want to Go Back ( press 3 to go back or 0 to exit ) : ";  
	cin>>charac;
	if(charac==3){
		menu();
	}
	else if(charac==0){
		exit(0);
	}
	else{
		cout<<"\n\n\t Invalid input !!!";
		Sleep(600);
		goto a;
	}
			break;
		case 3:
			updateflight();
	b:
	cout<<"\n\n\t> Do you want to Go Back ( press 3 to go back or 0 to exit ) : ";
	cin>>charac;
	if(charac==3){
		menu();
	}
	else if(charac==0){
		exit(0);
	}
	else{
		cout<<"\n\n\t Invalid input !!!";
		Sleep(600);
		goto b;
	}
			break;
		case 4:
			exit(0);
			break;
		default:
			cout<<"\n\nInvalid Choice....";
			goto p;
	}
}
void admin::addflight(){
	system("cls");
	fstream file;
	cout<<"\n";
    cout<<"\t\t\t\t************"<<endl;
	cout<<"\t\t\t\t           Add Flight           "<<endl;
	cout<<"\t\t\t\t************"<<endl;
	cout<<"\n\n";
	cout<<"\n\n Airline number : ";
	cin>>airline_no;
	cout<<"\n Departure : ";
	cin>>departure;
	cout<<"\n Destination : ";
	cin>>destination;
	cout<<"\n Price : ";
	cin>>price;
	file.open("D://flightdetails.txt",ios::app|ios::out);
	file<<airline_no<<" "<<departure<<" "<<destination<<" "<<price<<"\n";
	file.close();
	
}
void admin::viewflight(){
	system("cls");
	fstream file;
	cout<<"\n";
    cout<<"\t\t\t\t************"<<endl;
	cout<<"\t\t\t\t          Flight Details        "<<endl;
	cout<<"\t\t\t\t************"<<endl;
	cout<<"\n\n";
	file.open("D://flightdetails.txt",ios::in);
      cout<<"\n   Airline no >            ";  

	while(!file.eof()){
		
		file>>airline_no>>departure>>destination>>price;
		cout<<" "<<airline_no<<"           ";
	}
	cout<<"\n";
	file.close();
	file.open("D://flightdetails.txt",ios::in);
        cout<<"\n   Departure >           ";
	file>>airline_no>>departure>>destination>>price;
	while(!file.eof()){
		cout<<departure<<"        ";
		file>>airline_no>>departure>>destination>>price;
	}
	cout<<"\n";
	file.close();
	file.open("D://flightdetails.txt",ios::in);
	cout<<"\n   Destination >           ";
	file>>airline_no>>departure>>destination>>price;
	while(!file.eof()){
		cout<<""<<destination<<"        ";
		file>>airline_no>>departure>>destination>>price;
	}
	cout<<"\n";
	file.close();
	file.open("D://flightdetails.txt",ios::in);
     cout<<"\n   Price >           ";
	file>>airline_no>>departure>>destination>>price;
	while(!file.eof()){
		cout<<"     "<<price<<"       ";
		file>>airline_no>>departure>>destination>>price;
	}
	cout<<"\n";
	file.close();
	
}
void admin::updateflight(){
	system("cls");
	fstream filee,filee1;
	 cout<<"\t\t\t\t**********"<<endl;
	cout<<"\t\t\t\t         Update Menu       "<<endl;
	cout<<"\t\t\t\t***********"<<endl;
	cout<<"\n\n";
	cout<<"\nEnter the Airline number : ";
	cin>>airlinee_no;
    cout<<"\n\n";
	filee1.open("D://flightdetails.txt",ios::in);
	if(!filee1){
		cout<<"\nFile Opening Error ";
		filee1.close();
	}
		filee.open("D://flightdetails1.txt",ios::app|ios::out);
	filee1>>airline_no>>departure>>destination>>price;
		while(!filee1.eof()){
			if(airlinee_no==airline_no){
				cout<<"\n\n\tEnter the new airline no : ";
				cin>>n_airline;
				cout<<"\n\tEnter the new departure : ";
				cin>>dep;
				cout<<"\n\tEnter the new destination : ";
				cin>>des;
				cout<<"\n\tEnter the new price : ";
				cin>>pr;
				filee<<" "<<n_airline<<"  "<<dep<<"  "<<des<<"  "<<pr<<"\n";
			}
			else{
				filee<<" "<<airline_no<<"  "<<departure<<"  "<<destination<<"  "<<price<<"\n";
			}
			filee1>>airline_no>>departure>>destination>>price;
		}
		filee.close();
		filee1.close();
		remove("D://flightdetails.txt");
		rename("D://flightdetails1.txt","D://flightdetails.txt");
	
	
	

	
}
#endif
