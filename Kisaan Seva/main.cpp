#include <iostream>	 // I/O stream
#include <string>	 // Text
#include <ctime>	 // Time 'sleep' function
#include <ctype.h>	 // Validation check
#include <conio.h>	 // 'getch' function
#include <Windows.h> // Loading_Page
#include <fstream>	 // File handling
#include <iomanip>	 // 'setfill' function

// Header Files
// All extra classes are there
#include "Schemes.h"				// Classes for Schemes
#include "Person.h"					// Farmer part
#include "Loading_Page.h"			// Loading Animation
#include "Validation.h"				// Validation for Farmer inputted information
#include "Password_Vali_Asterisk.h" // Password in asterik form "********"

using namespace std;

// Objects
Validation_C Farmer_Validtaion;
Farmer Farmer_1(Name_Memory, TellNum_Memory, Login_Memory, Password_Memory);

// scheme Types
Class_Of_Schemes1 Scheme1_1("The Farmers Produce Trade and Commerce (Promotion and Facilitation), Ordinance, 2020", "\tAgricultural Marketing", "\thttps://agricoop.nic.in/sites/default/files/The%20Farmers%20Produce%20Trade%20and%20Commerce%20%28Promotion%20and%20Facilitation%20Ordinance%2C%202020_0.pdf"),
	Scheme1_2("Farmers Produce Trade and Commerce (Promotion and Facilitation), Rules, 2020", "\tAgricultural Marketing", "\thttps://agricoop.nic.in/sites/default/files/Farmers%20Produce%20Trade%20and%20Commerce%20%28Promotion%20and%20Facilitation%29%2C%20Rules%2C%202020%20%281%29_0.pdf"),
	Scheme1_3("The Farmers (Empowerment and Protection) Agreement on Price Assurance and Farm Services Ordinance, 2020", "\tAgricultural Marketing", "\thttps://agricoop.nic.in/sites/default/files/The%20Farmers%20%28Empowerment%20and%20Protection%29%20Agreement%20on%20Price%20Assurance%20and%20Farm%20Services%20Ordinance%2C%202020_0.pdf");
Class_Of_Schemes2 Scheme2_1("Cooperative Education & Training", "\tCooperation", "\thttps://agricoop.nic.in/sites/default/files/Cooperative_Education_and_Training.doc"),
	Scheme2_2("Assistance of National Cooperative Federations", "\tCooperation", "\thttps://agricoop.nic.in/sites/default/files/Assistance-of-National-Cooperative-Federations.doc"),
	Scheme2_3("Assistance to National Agriculture Cooperative Marketing Federation of India. (NAFED)", "\tCooperation", "\thttps://agricoop.nic.in/sites/default/files/PSS_MIS.doc");
Class_Of_Schemes3 Scheme3_1("Pilot Modified National Agricultural Insurance Scheme (MNAIS) - Scheme", "\tCredit", "\thttps://agricoop.nic.in/sites/default/files/MNAIS%20Scheme.pdf"),
	Scheme3_2("National Agricultural Insurance Scheme (NAIS)", "\tCredit", "\thttps://agricoop.nic.in/sites/default/files/NAIS.doc"),
	Scheme3_3("States / Districts Covered(NAIS)", "\tCredit", "\thttps://agricoop.nic.in/sites/default/files/NAIS-%20district%20covered-%20Kharif%202012%20%26%20Rabi%202012-13.pdf");

string Scheme_Name = "", Scheme_Category = "", Scheme_Description = "";

// Password and login for Admin
string Admin_Login_Sign = "admin";
string Admin_Password_Sign = "admin";

// Functions
// Declaration Functions
void F_General_Menu();
void F_Sign_in();
void F_Developers();
void F_Logo();		 // Logo "Kisaan Seva" for Farmer
void F_Logo_Admin(); // Logo "Kisaan Seva" for Admin

void F_Farmer_Main_Menu(); // Farmer's Main Menu
void F_Class_Of_Schemes1_Menu();
void F_Class_Of_Schemes2_Menu();
void F_Class_Of_Schemes3_Menu();

void F_Admin_Main_Menu(); // Admin's Main Menu
void F_Modify_Info_Schemes(int take_scheme_location);
void F_Admin_Scheme_List();
void F_Admin_Farmer_List();

///////////////////////////////////////////////////////////////////////////////
int main()
{

	// Loading
	F_Loading();
	F_General_Menu();

	system("pause");
	return 0;
}

void F_General_Menu()
{
	// Main Menu
	for (int i = 0; i < 1000; i++)
	{
		system("cls");
		cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "+  K I S A A N    S E V A                                                                                          A U T H E N T I C A T I O N    P A G E  +" << endl;
		cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "+      1. Sign in                                                                                                                                          +" << endl;
		cout << "+      2. Sign up                                                                                                                                          +" << endl;
		cout << "+      3. About                                                                                                                                            +" << endl;
		cout << "+      0. Exit                                                                                                                                             +" << endl;
		cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;

		cout << "Enter Your Choice :- ";

		switch (_getch())
		{
		case '1':
		{ // Sign in
			system("cls");
			F_Sign_in();
		}
		break;

		case '2':
		{ // Register and Setting details with validation.
			for (int i = 0; i != 1;)
			{
				system("cls");
				cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
				cout << "+  K I S A A N    S E V A                                                                                              R E G I S T R A T I O N    P A G E  +" << endl;
				cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
				cout << "+  E X A M P L E    O F    R E G I S T R A T I O N                                                                                                         +" << endl;
				cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
				cout << "+      Farmer Name : ArjunKumar ( Maximum 30 characters )                                                                                                  +" << endl;
				cout << "+      Telephone   : 1234567890 ( Maximum 10 digits )                                                                                                      +" << endl;
				cout << "+      Login       : ArjunKK ( Maximum 15 characters )                                                                                                     +" << endl;
				cout << "+      Password    : 123456 ( Min 6 characters, Max 16 characters, Password must be include 1 upper, 1 lower, 1 number)                                    +" << endl;
				cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;

				Farmer_Validtaion.SetFarmer();

				////////////

				ValidationPassword(Farmer_Validtaion);
				ValidationName(Farmer_Validtaion);
				ValidationTellNum(Farmer_Validtaion);

				if (Validation == 3)
				{
					////// File Handling For Farmer Info
					ofstream Farmer_Info;
					Farmer_Info.open("Farmer_Info.txt", ios::app); // Opening File

					// Setting Farmer Info in Memory
					Farmer_Info << Name_Memory << endl;
					Farmer_Info << TellNum_Memory << endl;
					Farmer_Info << Login_Memory << endl;
					Farmer_Info << Password_Memory << endl;
					Farmer_Info.close();
					///////// End of the File Handling
					system("cls");
					cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
					cout << "+  K I S A A N    S E V A                                                                                              R E G I S T R A T I O N    P A G E  +" << endl;
					cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
					cout << "+    Correct Validation                                                                                                                                    +" << endl;
					i++;
					cout << "+      Please press any key to continue...                                                                                                                 +" << endl;
					cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
					system("Pause");
					Validation = 0;
				}
				else
				{
					system("cls");
					cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
					cout << "+  K I S A A N    S E V A                                                                                              R E G I S T R A T I O N    P A G E  +" << endl;
					cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
					cout << "+    Invalid Validation                                                                                                                                    +" << endl;
					cout << "+      Please press '1' to rewrite OR  Press any key to go back to menu                                                                                    +" << endl;
					cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
					Validation = 0;
					switch (_getch())
					{
					case '1':
					{
						// Rewriting i=0;
					}
					break;

					default:
					{
						F_General_Menu();
					}
					break;
						// Go back
					}

				} // else
			}
		}
		break;

		case '3':
		{ // Developers
			system("cls");
			F_Developers();
		}
		break;

		case '0':
		{ // Exit
			system("cls");
			cout << "\n\n\n\n\t\t\t\tThank you for your attention!\n\n\n\n\n\n\n\n\n\t\t\t\t";
			system("pause");
			system("exit");
		}
		break;

		default:
		{
			cout << "\n\n\t\t\t       Your choice is not available in Menu." << endl;
			cout << "\t\t\t\t    Please enter correct keys.\n"
				 << endl;
			system("pause");
		}
		break;
		}
	}
}

void F_Developers()
{
	cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
	cout << "+  K I S A A N    S E V A                                                                                                                       A B O U T  +" << endl;
	cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
	cout << "+      'Kisaan Seva' Online farmer helpline application                                                                                                    +" << endl;
	cout << "+      Subject code :- CAP445                                                                                                                              +" << endl;
	cout << "+      Team Section :- D2217                                                                                                                               +" << endl;
	cout << "+      Team Members :-                                                                                                                                     +" << endl;
	cout << "+                   Arjun Kumar ( 11916159 )                                                                                                               +" << endl;
	cout << "+                   Tanish Tomar ( 12211032 )                                                                                                              +" << endl;
	cout << "+                   Om Bhai Patel ( 12212030 )                                                                                                             +" << endl;
	cout << "+                                                                                                                                                          +" << endl;
	cout << "+      Submitted to:- Mrs. Uminder Kaur Ma'am                                                                                                              +" << endl;
	cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
	system("pause");
}

void F_Sign_in()
{
	// Sign in Function
	for (int i = 0; i < 1000; i++)
	{
		system("cls");
		cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "+  K I S A A N    S E V A                                                                                                            L O G I N    P A G E  +" << endl;
		cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
		cout << "+      Sign in                                                                                                                                             +" << endl;
		cout << "+            1. Sign in as Admin                                                                                                                           +" << endl;
		cout << "+            2. Sign in as Farmer                                                                                                                          +" << endl;
		cout << "+            0. Back                                                                                                                                       +" << endl;
		cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;

		cout << "Enter Your Choice :- ";

		switch (_getch())
		{
		case '1':
		{ // Sign in as Admin

			system("cls");
			cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
			cout << "+  K I S A A N    S E V A                                                                                                     A U T H E N T I C A T I O N  +" << endl;
			cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
			cout << "+      Admin Authentication                                                                                                                                +" << endl;
			cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
			cout << "Login    :- ";
			cin >> Login_Sign;
			// cout << "\t\t\t\t\tPassword : "; cin >> Password_Sign;
			F_Password_Val();
			Password_Sign = Password_Val;

			if (Login_Sign == Admin_Login_Sign && Password_Sign == Admin_Password_Sign)
			{
				/////// Admin's Menu
				F_Admin_Main_Menu();
				//////
				system("pause");
			}
			else
			{ // If Login hasn't Registered
				cout << "!!!! Your Login and Password are Invalid. !!!" << endl;
				cout << "!!!! Please press any key to go back to 'Sign in' Menu. !!!!" << endl;
				system("pause");
				F_Sign_in();
			}
		}
		break;

		case '2':
		{ // Sign in as Farmer
			system("cls");
			cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
			cout << "+  K I S A A N    S E V A                                                                                                     A U T H E N T I C A T I O N  +" << endl;
			cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
			cout << "+      Farmer Authentication                                                                                                                               +" << endl;
			cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
			cout << "Login    :- ";
			cin >> Login_Sign;
			F_Password_Val();
			Password_Sign = Password_Val;
			//////   File Handling For Farmer Info
			ifstream Search;
			Search.open("Farmer_Info.txt");

			while (Search)
			{
				Search >> Name_Memory;
				Search >> TellNum_Memory;
				Search >> Login_Memory;
				Search >> Password_Memory;
				if (Login_Sign == Login_Memory && Password_Sign == Password_Memory)
				{
					Farmer Farmer_1(Name_Memory, TellNum_Memory, Login_Memory, Password_Memory);
					F_Farmer_Main_Menu();
				}
			}
			Search.close();
			///////// End of the File Handling

			cout << "\n\n\t\t\t        Your Login and Password are Invalid." << endl;
			cout << "\t\t\t   Please press any key to go back to 'Sign in' Menu.\n\n"
				 << endl;
			system("pause");
			F_Sign_in();
		}
		break;

		case '0':
		{ // Back
			system("cls");
			i = 1000;
			F_General_Menu();
		}
		break;

		default:
		{
			cout << "!!!! Your Login and Password are Invalid. !!!" << endl;
			cout << "!!!! Please press any key to go back to 'Sign in' Menu. !!!!" << endl;
			system("pause");
			F_Sign_in();
		}
		break;
		}
	}
}

// Farmer
void F_Logo()
{
	system("cls");
	cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
	cout << "+  K I S A A N    S E V A                                                                                                                     F A R M E R  +" << endl;
	cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
}

void F_Farmer_Main_Menu()
{
	// Entering as a Guest
	for (int i = 0; i < 1; i++)
	{

		F_Logo();

		cout << "       Categories\n\n";
		cout << "       1. Agricultural Marketing\n\n";
		cout << "       2. Cooperation\n\n";
		cout << "       3. Credit\n\n";
		cout << "       4. Farmer Information\n\n";
		cout << "       0. Go Back\n\n";
		cout << "       Your choice: ";

		switch (_getch())
		{
		case '1':
		{
			F_Class_Of_Schemes1_Menu();
		}
		break;

		case '2':
		{
			F_Class_Of_Schemes2_Menu();
		}
		break;

		case '3':
		{
			F_Class_Of_Schemes3_Menu();
		}
		break;

		case '4':
		{ // Farmer info
			system("cls");
			cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
			cout << "+  K I S A A N    S E V A                                                                                                            F A R M E R  I N F O  +" << endl;
			cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
			cout << "      Farmer Information :" << endl
				 << endl;
			cout << "             Farmer Name : " << Name_Memory << endl;
			cout << "             Telephone : " << TellNum_Memory << endl;
			cout << "             Login     : " << Login_Memory << endl;
			cout << "             Password  : " << Password_Memory << endl
				 << endl
				 << endl;
			system("pause");
			F_Farmer_Main_Menu();
		}
		break;

		case '0':
		{ // Back to Menu
			system("cls");
			i = 1;
			F_Sign_in();
		}
		break;

		default:
		{
			cout << "!!!! Your choice is not available in Menu. !!!!" << endl;
			cout << "!!!! Please enter correct keys. !!!!"
				 << endl;
			system("pause");
		}
		break;
		} // switch
	}	  // for loop
}

void F_Class_Of_Schemes1_Menu()
{
	for (int k = 0; k < 1000; k++)
	{
		F_Logo();

		cout << setw(5) << left << "Schemes List" << setw(10) << left << "Category" << setw(15) << left << "Description\n";
		Scheme1_1.Display();
		Scheme1_2.Display();
		Scheme1_3.Display();
		position1 = 1;

		cout << " 0. Back\n\n";
		cout << " Your choice: ";

		switch (_getch())
		{
		case '0':
		{
			system("cls");

			F_Farmer_Main_Menu();
		}
		break;
		default:
		{
			cout << "!!!! Your choice is not available in Menu. !!!!" << endl;
			cout << "!!!! Please enter correct keys. !!!!\n"
				 << endl;
			system("pause");
		}
		break;
		}
	} // loop ends
} // function ends

void F_Class_Of_Schemes2_Menu()
{
	for (int k = 0; k < 1000; k++)
	{
		F_Logo();

		cout << "    Schemes List  \t\t    Category\t\t       description\t\t In Stock\n";
		Scheme2_1.Display();
		Scheme2_2.Display();
		Scheme2_3.Display();
		position1 = 1;

		cout << " 0. Back\n\n";
		cout << " Your choice: ";
		switch (_getch())
		{
		case '0':
		{
			system("cls");

			F_Farmer_Main_Menu();
		}
		break;
		default:
		{
			cout << "Please press 0 to go back ";
		}
		break;
		}
	} // loop ends

} // function ends

void F_Class_Of_Schemes3_Menu()
{
	for (int k = 0; k < 1000; k++)
	{
		F_Logo();
		cout << "    Schemes List  \t\t    Category\t\t       description\t\t In Stock\n";
		Scheme3_1.Display();
		Scheme3_2.Display();
		Scheme3_3.Display();
		position1 = 1;

		cout << " 0. Back\n\n";
		cout << " Your choice: ";
		switch (_getch())
		{
		case '0':
		{
			system("cls");

			F_Farmer_Main_Menu();
		}
		break;
		default:
		{
			cout << "!!!! Your choice is not available in Menu. !!!!" << endl;
			cout << "!!!! Please enter correct keys. !!!!\n"
				 << endl;
			system("pause");
		}
		break;
		} // loop ends
	}
} // function ends

void F_Logo_Admin()
{
	system("cls");
	cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
	cout << "+  A D M I N                                                                                                                                      M E N U  +" << endl;
	cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
}

void F_Admin_Main_Menu()
{
	system("cls");
	cout << endl;

	// Entering as a Admin
	for (int k = 0; k < 1000; k++)
	{
		F_Logo_Admin();
		cout << "      Main Menu " << endl;
		cout << "            1. Goverment Schemes  " << endl;
		cout << "            2. Farmers list  " << endl;
		cout << "            0. Back " << endl;
		cout << endl;
		cout << "      Enter Your choice: ";

		switch (_getch())
		{
		case '1':
		{
			F_Admin_Scheme_List();
		}
		break;

		case '2':
		{

			system("cls");
			cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
			cout << "+  K I S A A N    S E V A                                                                                                          F A R M E R    L I S T  +" << endl;
			cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------+" << endl;
			cout << "  Farmer list :- " << endl;

			F_Admin_Farmer_List();

			system("pause");
		}
		break;

		case '0':
		{ // Back to Menu
			system("cls");
			k = 1000;
			F_Sign_in();
		}
		break;

		default:
		{
			cout << "!!!! Your choice is not available in Menu. !!!!" << endl;
			cout << "!!!! Please enter correct keys. !!!!\n"
				 << endl;
			system("pause");
		}
		break;
		} // switch
	}	  // for loop
}

void F_Admin_Scheme_List()
{
	for (int i = 0; i < 1000; i++)
	{
		F_Logo_Admin();

		cout << left << setw(50) << "Schemes List" << left << setw(50) << "Category"
			 << "Description" << endl;
		Scheme1_1.Display();
		cout << endl
			 << endl;
		Scheme1_2.Display();
		cout << endl
			 << endl;
		Scheme1_3.Display();
		cout << endl
			 << endl;
		Scheme2_1.Display();
		cout << endl
			 << endl;
		Scheme2_2.Display();
		cout << endl
			 << endl;
		Scheme2_3.Display();
		cout << endl
			 << endl;
		Scheme3_1.Display();
		cout << endl
			 << endl;
		Scheme3_2.Display();
		cout << endl
			 << endl;
		Scheme3_3.Display();
		cout << endl
			 << endl;

		position1 = 1; // numbering of Schemes return to 1

		cout << " 0. Back" << endl;
		cout << "    Make changes in :- ";
		switch (_getch())
		{
		case '1':
			F_Modify_Info_Schemes(1);
			break;
		case '2':
			F_Modify_Info_Schemes(2);
			break;
		case '3':
			F_Modify_Info_Schemes(3);
			break;
		case '4':
			F_Modify_Info_Schemes(4);
			break;
		case '5':
			F_Modify_Info_Schemes(5);
			break;
		case '6':
			F_Modify_Info_Schemes(6);
			break;
		case '7':
			F_Modify_Info_Schemes(7);
			break;
		case '8':
			F_Modify_Info_Schemes(8);
			break;
		case '9':
			F_Modify_Info_Schemes(9);
			break;
		case '0': // Back to Menu
			system("cls");
			i = 1000;
			F_Admin_Main_Menu();
			break;

		case 'i' || 'I': // Farmer info
			system("cls");
			cout << "\n\t\t\t   Farmer Information:" << endl;
			;
			cout << "\t\t    _______________________________" << endl
				 << endl;
			;
			cout << "\t\t      Farmer Name  : " << Name_Memory << endl;
			cout << "\t\t      Telephone  : " << TellNum_Memory << endl;
			cout << "\t\t      Login      : " << Login_Memory << endl;
			cout << "\t\t      Password   : " << Password_Memory << endl
				 << endl
				 << endl;
			system("pause");
			break;

		default:
			cout << "\n\t\t      Your choice is not available in Menu" << endl;
			cout << "\t\tPlease press any keyboard to continue program\n"
				 << endl;
			system("pause");
			break;

		} // switch

	} // for loop for Schemes in stock
}

void F_Modify_Info_Schemes(int take_scheme_location)
{
	for (int j = 0; j < 1000; j++)
	{
		system("cls");

		// It is for Displaying the Schemes in order
		cout << left << setw(50) << "Schemes List" << left << setw(50) << "Category"
			 << "Description" << endl;
		if (take_scheme_location == 1)
		{
			Scheme1_1.Display();
		}
		else if (take_scheme_location == 2)
		{
			Scheme1_2.Display();
		}
		else if (take_scheme_location == 3)
		{
			Scheme1_3.Display();
		}
		else if (take_scheme_location == 4)
		{
			Scheme2_1.Display();
		}
		else if (take_scheme_location == 5)
		{
			Scheme2_2.Display();
		}
		else if (take_scheme_location == 6)
		{
			Scheme2_3.Display();
		}
		else if (take_scheme_location == 7)
		{
			Scheme3_1.Display();
		}
		else if (take_scheme_location == 8)
		{
			Scheme3_2.Display();
		}
		else if (take_scheme_location == 9)
		{
			Scheme3_3.Display();
		}
		position1 = 1;
		cout << "____________________________________________________________________________________________________ \n";

		cout << " 1. Change the name of scheme\n";
		cout << " 2. Change the Category of scheme\n";
		cout << " 3. Change the description \n";
		cout << " 0. Go back \n";
		cout << " Your choice:\n\n";

		switch (_getch())
		{
			// FOR CHANGING A description
		case '1':
			cout << " Enter a new Scheme name: ";
			getline(cin, Scheme_Name);
			if (take_scheme_location == 1)
			{
				Scheme1_1.schemesName = Scheme_Name;
			}
			else if (take_scheme_location == 2)
			{
				Scheme1_2.schemesName = Scheme_Name;
			}
			else if (take_scheme_location == 3)
			{
				Scheme1_3.schemesName = Scheme_Name;
			}
			else if (take_scheme_location == 4)
			{
				Scheme2_1.schemesName = Scheme_Name;
			}
			else if (take_scheme_location == 5)
			{
				Scheme2_2.schemesName = Scheme_Name;
			}
			else if (take_scheme_location == 6)
			{
				Scheme2_3.schemesName = Scheme_Name;
			}
			else if (take_scheme_location == 7)
			{
				Scheme3_1.schemesName = Scheme_Name;
			}
			else if (take_scheme_location == 8)
			{
				Scheme3_2.schemesName = Scheme_Name;
			}
			else if (take_scheme_location == 9)
			{
				Scheme3_3.schemesName = Scheme_Name;
			}
			break;

			// FOR CHANGING THE Category OF scheme
		case '2':
			cout << " Enter a new Category Name: ";
			getline(cin, Scheme_Category);
			if (take_scheme_location == 1)
			{
				Scheme1_1.category_of_schemes = Scheme_Category;
			}
			else if (take_scheme_location == 2)
			{
				Scheme1_2.category_of_schemes = Scheme_Category;
			}
			else if (take_scheme_location == 3)
			{
				Scheme1_3.category_of_schemes = Scheme_Category;
			}
			else if (take_scheme_location == 4)
			{
				Scheme2_1.category_of_schemes = Scheme_Category;
			}
			else if (take_scheme_location == 5)
			{
				Scheme2_2.category_of_schemes = Scheme_Category;
			}
			else if (take_scheme_location == 6)
			{
				Scheme2_3.category_of_schemes = Scheme_Category;
			}
			else if (take_scheme_location == 7)
			{
				Scheme3_1.category_of_schemes = Scheme_Category;
			}
			else if (take_scheme_location == 8)
			{
				Scheme3_2.category_of_schemes = Scheme_Category;
			}
			else if (take_scheme_location == 9)
			{
				Scheme3_3.category_of_schemes = Scheme_Category;
			}
			break;

		case '3':
			cout << " Enter a new Description: ";
			getline(cin, Scheme_Description);
			if (take_scheme_location == 1)
			{
				Scheme1_1.description = Scheme_Description;
				cout << " Successfully changed!\n";
			}
			else if (take_scheme_location == 2)
			{
				Scheme1_2.description = Scheme_Description;
				cout << " Successfully changed!\n";
			}
			else if (take_scheme_location == 3)
			{
				Scheme1_3.description = Scheme_Description;
				cout << " Successfully changed!\n";
			}
			else if (take_scheme_location == 4)
			{
				Scheme2_1.description = Scheme_Description;
				cout << " Successfully changed!\n";
			}
			else if (take_scheme_location == 5)
			{
				Scheme2_2.description = Scheme_Description;
				cout << " Successfully changed!\n";
			}
			else if (take_scheme_location == 6)
			{
				Scheme2_3.description = Scheme_Description;
				cout << " Successfully changed!\n";
			}
			else if (take_scheme_location == 7)
			{
				Scheme3_1.description = Scheme_Description;
				cout << " Successfully changed!\n";
			}
			else if (take_scheme_location == 8)
			{
				Scheme3_2.description = Scheme_Description;
				cout << " Successfully changed!\n";
			}
			else if (take_scheme_location == 9)
			{
				Scheme3_3.description = Scheme_Description;
				cout << " Successfully changed!\n";
			}
			else
				cout << " Description cannot be changed! Please check one more time.\n";
			break;

		case '0':
			F_Admin_Scheme_List();
			break;
		default:
			cout << "\n\t\t      Your choice is not available in Menu" << endl;
			cout << "\t\tPlease press any keyboard to continue program\n"
				 << endl;
			system("pause");
			break;

		} // 'switch'
	}	  // 'for' loop
}

// Farmer List
void F_Admin_Farmer_List()
{
	cout << endl;

	ifstream in;
	int Num = 1;
	string Info;

	in.open("Farmer_Info.txt");
	while (in)
	{
		cout << "\t+---+" << endl;
		cout << "\t+ " << Num << " +" << endl;
		cout << "\t+---+" << endl
			 << endl;
		getline(in, Info);
		cout << "\to Farmer Name :- " << Info << endl;
		getline(in, Info);
		cout << "\to Phone    : " << Info << endl;
		getline(in, Info);
		cout << "\to Login    : " << Info << endl;
		getline(in, Info);
		cout << "\to Password : " << Info << endl;
		Num++;
		cout << endl;
	}
	in.close();
}