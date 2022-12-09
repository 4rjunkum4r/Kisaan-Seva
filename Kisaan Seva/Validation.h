#include <iostream>
#include <string>	 // Text
#include <ctime>	 // Time
#include <ctype.h>	 // Validation
#include <conio.h>	 // Getch
#include <windows.h> // Loading

using namespace std;

// Global Identifires for validation
int Num_Upper = 0, Num_Lower = 0, Num_Number = 0, Validation = 0;
string Login_Sign, Password_Sign;

// Identifires for File Handling
string Name_Memory, Login_Memory, Password_Memory, TellNum_Memory;

class Validation_C
{
private:
	// Identifires
	string Name, Login, Password, TellNum;

public:
	// Function display
	void Display()
	{
		cout << "\t\t\tFarmer Information :" << endl
			 << endl;
		cout << "\t\tFarmer Name  : " << Name << endl;
		cout << "\t\tTelephone  : " << TellNum << endl;
		cout << "\t\tLogin      : " << Login << endl;
		cout << "\t\tPassword   : " << Password << endl;
	}

	// Set Info of Farmer
	void SetFarmer()
	{
		cout << "+  R E G I S T E R        F A R M E R                                                                                                                      +" << endl;
		cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "       Farmer Name :- ";
		cin >> Name;
		cout << "       Telephone   :- ";
		cin >> TellNum;
		cout << "       Login       :- ";
		cin >> Login;
		cout << "       Password    :- ";
		cin >> Password;

		// Info sended to Memory
		Name_Memory = Name;
		Password_Memory = Password;
		Login_Memory = Login;
		TellNum_Memory = TellNum;
	}

	// Friend Functions
	// Validation Check for Name
	friend void ValidationName(Validation_C Farmer)
	{
		if (Farmer.Name.length() >= 1 && Farmer.Name.length() <= 30)
		{
			for (int i = 0; i < Farmer.Name.length(); i++)
			{
				if (isupper(Farmer.Name[i]))
				{
					Num_Upper += 1;
				}
				if (islower(Farmer.Name[i]))
				{
					Num_Lower += 1;
				}
				if (isdigit(Farmer.Name[i]))
				{
					Num_Number += 1;
				}
			}

			if (Num_Upper <= 30 && Num_Lower <= 30 && Num_Number == 0)
			{
				Validation++;
				Num_Upper = 0;
				Num_Lower = 0;
				Num_Number = 0;
			}
			else
			{
				Num_Upper = 0;
				Num_Lower = 0;
				Num_Number = 0;
			}
		}
		else
		{
			Num_Upper = 0;
			Num_Lower = 0;
			Num_Number = 0;
		}
	}
	// Validation Check for TellNum
	friend void ValidationTellNum(Validation_C Farmer)
	{
		if (Farmer.TellNum.length() > 0 && Farmer.TellNum.length() <= 10)
		{
			for (int i = 0; i < Farmer.TellNum.length(); i++)
			{
				if (isupper(Farmer.TellNum[i]))
				{
					Num_Upper += 1;
				}
				if (islower(Farmer.TellNum[i]))
				{
					Num_Lower += 1;
				}
				if (isdigit(Farmer.TellNum[i]))
				{
					Num_Number += 1;
				}
			}
			if (Num_Upper == 0 && Num_Lower == 0 && Num_Number > 0 && Num_Number <= 10)
			{
				Validation++;
				Num_Upper = 0;
				Num_Lower = 0;
				Num_Number = 0;
			}
			else
			{
				Num_Upper = 0;
				Num_Lower = 0;
				Num_Number = 0;
			}
		}
		else
		{
			Num_Upper = 0;
			Num_Lower = 0;
			Num_Number = 0;
		}
	}

	// Validation Check for Password
	friend void ValidationPassword(Validation_C Farmer)
	{
		if (Farmer.Password.length() >= 8 && Farmer.Password.length() <= 16)
		{
			for (int i = 0; i < Farmer.Password.length(); i++)
			{
				if (isupper(Farmer.Password[i]))
				{ // Number of Upper Letters
					Num_Upper += 1;
				}
				if (islower(Farmer.Password[i]))
				{ // Number of Lower Letters
					Num_Lower += 1;
				}
				if (isdigit(Farmer.Password[i]))
				{ // Number of Digits
					Num_Number += 1;
				}
			}
			if (Num_Upper >= 1 && Num_Upper <= 16 && Num_Lower >= 1 && Num_Lower <= 16 && Num_Number >= 1 && Num_Number <= 16)
			{
				Validation++;
				Num_Upper = 0;
				Num_Lower = 0;
				Num_Number = 0;
			}
			else
			{
				Num_Upper = 0;
				Num_Lower = 0;
				Num_Number = 0;
			}
		}
		else
		{
			Num_Upper = 0;
			Num_Lower = 0;
			Num_Number = 0;
		}
	}
};