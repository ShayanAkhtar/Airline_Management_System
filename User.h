#include<windows.h>
#include<string>
#include<iostream>
#include<fstream>
using namespace std;
class user{
	private:
		string first_name,last_name,email_address,login_address,u_email,c_email;
		int age,pin,pinn,price,airline_no,press,seats,new_seats,new_pr,charac;                // Member variables
		 string departure,destination,u_departure,u_destination,new_dep,new_des;
		public:
			void u_menu();
			void usersignup();
			void userlogin();
			void flightschedule();                                                     // Member functions
			void flightbooking();
			void confirmflight();
			void viewbooking();
			void cancelbooking();
};


void user::u_menu(){
	p:
	system("cls");
	int choose;
	cout<<"\n";
    cout<<"\t\t\t\t************"<<endl;
	cout<<"\t\t\t\t          User Details          "<<endl;
	cout<<"\t\t\t\t************"<<endl;
	cout<<"\n\n";
	cout<<"\n\t1. SIGN UP "<<endl;
	cout<<"\n\t2. LOGIN "<<endl;
	cout<<"\n\t3. Exit "<<endl;
	cout<<"\n\t> Select : ";
	cin>>choose;
	switch(choose){
		case 1:
			usersignup();
			break;
		case 2:
			userlogin();
			break;
		case 3:
			exit(0);
			break;
		default:
			cout<<"\n\t  Invalid choice ";
			goto p;
			
	}
}
void user::usersignup(){
	system("cls");
	fstream file;
	
	cout<<"\n";
    cout<<"\t\t\t\t************"<<endl;
	cout<<"\t\t\t\t          User Sign Up          "<<endl;
	cout<<"\t\t\t\t************"<<endl;
	cout<<"\n\n";
	cout<<"\n\t> Enter your First name : ";
	cin>>first_name;
	cout<<"\n\t> Enter your Last name : ";
	cin>>last_name;
	cout<<"\n\t> Enter your age : ";
	cin>>age;
	if(age<18){
		cout<<"\n\n\t You are not eligible ";
		cout<<"\n\n\n\t\t\t\t -------- See You Again ---------   ";
	exit(0);
	}
	cout<<"\n\t> Enter your email address : ";
	cin>>email_address;
	cout<<"\n\t> Set the 4 digits password : ";
	cin>>pin;	
	cout<<"\n\n\n\t\t\t\t -------- You are Registered Successfully ---------   ";
	Sleep(600);
	file.open("D://usersignups.txt",ios::app|ios::out);
	file<<first_name<<"     "<<last_name<<"     "<<age<<"     "<<email_address<<"     "<<pin<<"\n\n";
	file.close();
	s:
	cout<<"\n\n\t> Do you want to Login ( press 3 for login page or 0 to exit ) : ";
	cin>>charac;
	if(charac==3){
		userlogin();
	}
	else if(charac==0){
		exit(0);
	}
	else{
		cout<<"\n\n\t Invalid input !!!";
		Sleep(600);
		goto s;
	}
}
void user::userlogin(){
	s:
	system("cls");
	char ch;
	fstream filein;
	int check=0;
	cout<<"\n";
    cout<<"\t\t\t\t************"<<endl;
	cout<<"\t\t\t\t           User Login           "<<endl;
	cout<<"\t\t\t\t************"<<endl;
	cout<<"\n\n\n\t> Enter the email address : ";
	cin>>login_address;
	cout<<"\n\n\t> Enter the 4 digit Pin : ";
	cin>>pinn;
	filein.open("D://usersignups.txt",ios::in);
	filein>>first_name>>last_name>>age>>email_address>>pin;
	while(!filein.eof()){
		if(login_address==email_address&&pinn==pin){
			check++;
			break;
		}
		filein>>first_name>>last_name>>age>>email_address>>pin;
	}
	filein.close();
	if(check==1){
		p:
		system("cls");
		int choose;
		cout<<"\n";
    cout<<"\t\t\t\t************"<<endl;
	cout<<"\t\t\t\t           User Menu           "<<endl;
	cout<<"\t\t\t\t************"<<endl;
	cout<<"\n\n\t -> Name : "<<first_name<<" "<<last_name;
	cout<<"\n\n\t -> Email : "<<email_address;
	cout<<"\n\n\n";
	cout<<"\n\t1. Flight Schedule "<<endl;
	cout<<"\n\t2. Flight Boooking "<<endl;
	cout<<"\n\t3. View  Booking "<<endl;
	cout<<"\n\t4. Cancel Booking "<<endl;
	cout<<"\n\t5. Exit "<<endl;
	
	cout<<"\n\t> Select : ";
	cin>>choose;
	switch(choose){
		case 1:
			flightschedule();
			break;
		case 2:
			flightbooking();
			break;
		case 3:
			viewbooking();
			break;
		case 4:
			cancelbooking();
			break;
		case 5:
			exit(0);
			break;
		default:
			cout<<"\n\t  Invalid choice ";
			goto p;
		}
	}
	else{
		cout<<"\n\n\n\t Invalid email address or pin";
		goto s;
	}
}
void user::flightschedule(){
	system("cls");
	fstream file;
	cout<<"\n";
    cout<<"\t\t\t\t************"<<endl;
	cout<<"\t\t\t\t          Flight Schedule       "<<endl;
	cout<<"\t\t\t\t************"<<endl;
	cout<<"\n\n\t -> Name : "<<first_name<<" "<<last_name;
	cout<<"\n\n\t -> Email : "<<email_address;
	cout<<"\n\n";
	file.open("D://flightdetails.txt",ios::in);
	cout<<"\n   Airline no >            ";  
	file>>airline_no>>departure>>destination>>price;
	while(!file.eof()){
		cout<<" "<<airline_no<<"           ";
		file>>airline_no>>departure>>destination>>price;
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
void user::flightbooking(){
	system("cls");
	fstream file1;
	int found=0;
	cout<<"\n";
    cout<<"\t\t\t\t************"<<endl;
	cout<<"\t\t\t\t          Flight Booking        "<<endl;
	cout<<"\t\t\t\t************"<<endl;
	cout<<"\n\n\t> Enter your departure : ";
	cin>>u_departure;
	cout<<"\n\t> Enter your destination : ";
	cin>>u_destination;
	file1.open("D://flightdetails.txt",ios::in);
	file1>>airline_no>>departure>>destination>>price;
	while(!file1.eof()){
		if(u_departure==departure&&u_destination==destination){
			found++;
			break;
		}
	file1>>airline_no>>departure>>destination>>price;
}
file1.close();
if(found==0){
		cout<<"\n\n\t Sorry, No Flight available !!!";
	exit(0);
	}
	else{
		system("cls");
	cout<<"\n";
    cout<<"\t\t\t\t************"<<endl;
	cout<<"\t\t\t\t          Flight Booking        "<<endl;
	cout<<"\t\t\t\t************"<<endl;
	cout<<"\n\n\t> Name : "<<first_name<<" "<<last_name;
	cout<<"\n\n\t> Email : "<<email_address;
	cout<<"\n\n\t> Airline No : "<<airline_no;
	cout<<"\n\n\t> Departure : "<<departure;
	cout<<"\n\n\t> Destination : "<<destination;
	cout<<"\n\n\t> Price : "<<price;
	cout<<"\n\n\t> Number of seats : ";
	cin>>seats;
	price=price*seats;
	cout<<"\n\t> Your Total price is : "<<price;
	p:
	cout<<"\n\n\t> Press 1 to Confirm your flight : ";
	cin>>press;
	if(press==1){
	confirmflight();
	}
	else{
		cout<<"\n\n\t Invalid entry !!!";
		goto p;
	}
	}
}
void user::confirmflight(){
	system("cls");
	fstream file;
	cout<<"\n";
    cout<<"\t\t\t\t************"<<endl;
	cout<<"\t\t\t\t          Flight Booking        "<<endl;
	cout<<"\t\t\t\t************"<<endl;
	cout<<"\n\n\t\t> Name : "<<first_name<<" "<<last_name;
	cout<<"\n\n\t\t> Email : "<<email_address;
	cout<<"\n\n\t\t --------------Your Flight has Booked-------------- ";
	cout<<"\n\n\t\t Thanks "<<first_name<<" "<<last_name<<" for using our service ";
	file.open("D://BookFlights.txt",ios::app|ios::out);
	file<<first_name<<" "<<last_name<<" "<<email_address<<" "<<airline_no<<"  "<<departure<<" "<<destination<<" "<<seats<<"  "<<price<<"\n";
	file.close();
}
void user::viewbooking(){
	system("cls");
	fstream file;
	int found=0;
	cout<<"\n";
    cout<<"\t\t\t\t************"<<endl;
	cout<<"\t\t\t\t           View Booking         "<<endl;
	cout<<"\t\t\t\t************"<<endl;
	cout<<"\n\n\t> Enter the email address : ";
	cin>>u_email;
	file.open("D://BookFlights.txt",ios::in);
	file>>first_name>>last_name>>email_address>>airline_no>>departure>>destination>>seats>>price;
	while(!file.eof()){
		if(u_email==email_address){
			found++;
			break;
		}
		file>>first_name>>last_name>>email_address>>airline_no>>departure>>destination>>seats>>price;
	}
	if(found==0){
		cout<<"\n\n\t\t --------------No Book Flights-------------- ";
	}
	else{
		system("cls");
		cout<<"\n";
    cout<<"\t\t\t\t************"<<endl;
	cout<<"\t\t\t\t          Booking Receipt       "<<endl;
	cout<<"\t\t\t\t************"<<endl;
	cout<<"\n\n";
	cout<<"\n\n\t> Name : "<<first_name<<" "<<last_name;
	cout<<"\n\n\t> Email : "<<email_address;
	cout<<"\n\n\t> Airline No : "<<airline_no;
	cout<<"\n\n\t> Departure : "<<departure;
	cout<<"\n\n\t> Destination : "<<destination;
	cout<<"\n\n\t> Seats : "<<seats;
	cout<<"\n\n\t> Price : "<<price;
	}
	
	
}
void user::cancelbooking(){
	system("cls");
	fstream filee,filee1;
	 cout<<"\t\t\t\t**********"<<endl;
	cout<<"\t\t\t\t         Cancel Flight       "<<endl;
	cout<<"\t\t\t\t***********"<<endl;
	cout<<"\n\n";
	cout<<"\n\n\t> Enter the Email Address : ";
	cin>>c_email;
    cout<<"\n\n";
	filee1.open("D://BookFlights.txt",ios::in);
	if(!filee1){
		cout<<"\nFile Opening Error ";
		filee1.close();
	}
		filee.open("D://BookFlights1.txt",ios::app|ios::out);
	filee1>>first_name>>last_name>>email_address>>airline_no>>departure>>destination>>seats>>price;
		while(!filee1.eof()){
			if(c_email==email_address){
				filee<<" ";
			}
			else{
				filee<<first_name<<" "<<last_name<<" "<<email_address<<" "<<airline_no<<"  "<<departure<<" "<<destination<<" "<<seats<<"  "<<price<<"\n";
			}
			filee1>>first_name>>last_name>>email_address>>airline_no>>departure>>destination>>seats>>price;
		}
		filee.close();
		filee1.close();
		remove("D://BookFlights.txt");
		rename("D://BookFlights1.txt","D://BookFlights.txt");
		cout<<"\n\t\t\t\t -------- Flight Cancelled ---------   ";
	
	
	
}

