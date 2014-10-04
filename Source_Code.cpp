#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<string>
#include"typing.h"
using namespace std;


int main()
{
	string username;
	system("cls");
	extview();
	gotoxy(10, 5);
	cout << "Welcome! Please enter you name to start:";
	getline(cin, username);
	system("cls");
	mainmenu(username);;

	return 0;
}
