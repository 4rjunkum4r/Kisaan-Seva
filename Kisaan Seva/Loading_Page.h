#pragma once
#include <iostream>
#include <ctime>     // Time
#include <windows.h> // Loading
using namespace std;
void gotoXY(int x, int y) {
	//'COORD' is a built in function for positioning the objects
	COORD d;
	d.X = x;
	d.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), d);
}

void F_Loading() {
	cout << "\n";
	cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------+"<<endl;
	cout << "+                                                                 CAP      445     PROJECT                                                                 +"<<endl;
	cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------+"<<endl;
	cout << "+                                                                                                                                                          +"<<endl;
	cout << "+                                                                       KISAAN SEVA                                                                        +"<<endl;
    cout << "+                                                                                                                                                          +"<<endl;   
	cout << "+----------------------------------------------------------------------------------------------------------------------------------------------------------+"<<endl;

	char a = 219;
	gotoXY(45, 14);   
	cout << "LOADING........... " << endl;

	gotoXY(37, 16);
	for (int r = 1; r <= 26; r++)
	{
		//for speed
		for (int speed = 0; speed <= 30000000; speed++);
		cout << a;
	}
	cout << endl;
}