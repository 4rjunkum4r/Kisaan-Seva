#pragma once
#include <iostream> // I/O stream
#include <string>
#include <iomanip>   // Text

using namespace std;

int position1 = 1; // for numbering the Schemes

//////////////////////////////////////////////// description and name of Schemes
class Schemes
{
public:
	string schemesName;
	string category_of_schemes;
	string description;

public:
	Schemes(string schemesName, string category_of_schemes, string description) {
		this->schemesName = schemesName;
		this->category_of_schemes = category_of_schemes;
		this->description = description;
	}

	virtual void Display() = 0; // pure virtual function
};


///////////////////////////////////////////////// Vegetables
class Class_Of_Schemes1 : public Schemes
{
public:
	Class_Of_Schemes1(string schemesName, string category_of_schemes, string description) : Schemes(schemesName, category_of_schemes, description) {
	}

	string getSchemesName() {
		return schemesName;
	}

	string getCategoryOfSchemes() {
		return category_of_schemes;
	}

	string getDescription() {
		return description;
	}

	void Display() {
		cout << " " << position1 << ". " << left << setw(50) << schemesName << left << setw(50) << category_of_schemes  << description  << endl;
		position1++;
	}

};


///////////////////////////////////////////////// 
class Class_Of_Schemes2 : public Schemes
{
public:
	Class_Of_Schemes2(string schemesName, string category_of_schemes, string description) : Schemes(schemesName, category_of_schemes, description) {
	}

	string getSchemesName() {
		return schemesName;
	}

	string getCategoryOfSchemes() {
		return category_of_schemes;
	}

	string getDescription() {
		return description;
	}

	void Display() {
		cout << " " << position1 << ". " << left << setw(5) << schemesName << left << setw(10) << category_of_schemes << left << setw(15) << description  << endl;
		position1++;                                                                 
	}
};


/////////////////////////////////////////////////
class Class_Of_Schemes3 : public Schemes
{

public:
	Class_Of_Schemes3(string schemesName, string category_of_schemes, string description) : Schemes(schemesName, category_of_schemes, description) {
	}

	string getSchemesName() {
		return schemesName;
	}

	string getCategoryOfSchemes() {
		return category_of_schemes;
	}

	string getDescription() {
		return description;
	}

	void Display() {
		cout << " " << position1 << ". " << left << setw(5) << schemesName << left << setw(10) << category_of_schemes << left << setw(15) << description  << endl;
		position1++;                                                                 
	}
};