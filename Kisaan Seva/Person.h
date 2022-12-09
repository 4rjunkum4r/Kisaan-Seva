// Farmer Registration - Name, Telephone Number, 
// class Farmer which takes the values of Schemes which a specific Farmer has bought

#pragma once
#include <iostream>  // I/O stream
#include <string>    // Text
#include <ctime>     // Time sleep
#include <ctype.h>   // Validation
#include <conio.h>   // Getch
#include <windows.h> // Loading
#include <fstream>   // File handling 
#include <iomanip>   // setfill

/////////////////////////////////////////////////
class Person {
protected:
	string name;
	string tell;

public:
	// Constructor for Person class 
	Person(string name, string tell) {
		this->name = name;
		this->tell = tell;
	}

	// pure virtual function 'Display' 
	virtual void Display() = 0;
};


/////////////////////////////////////////////////
// Sub class of Person
class Security : public Person {
protected:
	string login;
	string password;

public:
	// Constructor for Security class 
	Security(string name, string tell, string login, string password) : Person(name, tell) {
		this->login = login;
		this->password = password;
	}
};


/////////////////////////////////////////////////
// 1st Sub class of Security
class Farmer : public Security { 
public:
	// Storage
	int Scheme1_1_Farmer = 0, Scheme1_2_Farmer = 0, Scheme1_3_Farmer = 0;
	int Scheme2_1_Farmer = 0, Scheme2_2_Farmer = 0, Scheme2_3_Farmer = 0;
	int Scheme3_1_Farmer = 0, Scheme3_2_Farmer = 0, Scheme3_3_Farmer = 0;

	// Constructor for Farmer's sign up
	Farmer(string name, string tell, string login, string password) : Security(name, tell, login, password) {
		this->name = name;
		this->tell = tell;
		this->login = login;
		this->password = password;
	}

	// get Name of Farmer
	string getName() {
		return name;
	}
	// get Tell of Farmer
	string getTell() {
		return tell;
	}

	// get Login of Farmer
	string getLogin() {
		return login;
	}

	// get Password of Farmer
	string getPassword() {
		return password;
	}

	// Display Info
	void Display() {
		cout << "\t\tName     : " << name << endl;
		cout << "\t\tTell     : " << tell << endl;
		cout << "\t\tLogin    : " << login << endl;
		cout << "\t\tPassword : " << password << endl;
	}
};


/////////////////////////////////////////////////
// 2nd Sub class of Security
class Admin : public Security { 
public:
	// Constructor for Farmer's sign up
	Admin(string name, string tell, string login, string password) : Security(name, tell, login, password) { }
	// get Name of Farmer
	string getName() {
		return name;
	}

	// get Tell of Farmer
	string getTell() {
		return tell;
	}

	// get Login of Farmer
	string getLogin() {
		return login;
	}

	// get Password of Farmer
	string getPassword() {
		return password;
	}

	// Display Info
	void Display() {
		cout << "\t\tName     : " << name << endl;
		cout << "\t\tTell     : " << tell << endl;
		cout << "\t\tLogin    : " << login << endl;
		cout << "\t\tPassword : " << password << endl;
	}
};