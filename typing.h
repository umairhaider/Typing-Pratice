#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include <conio.h>
#include <string.h>
#include <time.h>
#include<Windows.h>
#include<fstream>
using namespace std;
void gotoxy(int, int);
void extview();
void mainmenu(string);
void beginner(string);
void beginner_unit_1(string);
void beginner_unit_2(string);
void beginner_unit_3(string);
void intermediate(string);
void intermediate_unit_1(string);
void intermediate_unit_2(string);
void intermediate_unit_3(string);
void advanced(string);
void advanced_unit_1(string);
void advanced_unit_2(string);
void advanced_unit_3(string);
void gotoxy(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
		);
}
void extview()
{
	int z = 4;
	int i;
	gotoxy(8, 3);
	printf("%c", 218);
	for (i = 0; i<53; i++){
		printf("%c", 196);
	}
	gotoxy(62, 3);
	printf("%c", 191);
	gotoxy(8, 4);
	for (i = 0; i<40; i++){
		printf("%c", 179);
		gotoxy(8, z++);
	}
	z = 4;
	for (i = 0; i<40; i++){
		printf("%c", 179);
		gotoxy(62, z++);
	}
	gotoxy(8, 43);
	printf("%c", 192);
	gotoxy(62, 43);
	printf("%c", 217);
	z = 4;
	gotoxy(9, 43);
	for (i = 0; i<53; i++){
		printf("%c", 196);
	}
	gotoxy(63, 3);
	printf("%c", 218);
	gotoxy(63, 4);
	z = 4;
	for (i = 0; i<40; i++){
		printf("%c", 179);
		gotoxy(63, z++);
	}
	gotoxy(63, 43);
	printf("%c", 192);
	gotoxy(64, 3);
	for (i = 0; i<16; i++){
		printf("%c", 196);
	}
	gotoxy(64, 43);
	for (i = 0; i<16; i++){
		printf("%c", 196);
	}
}
void mainmenu(string username)
{
	int choice = 1;
	system("cls");
	extview();
	gotoxy(12, 4);
	cout << "Dear " << username << "! Welcome to typing practice." << endl;
	gotoxy(15, 10);
	cout << "[ Select your level ]";
	gotoxy(18, 12);
	cout << "1. Beginner" << endl;
	gotoxy(18, 14);
	cout << "2. Intermediate" << endl;
	gotoxy(18, 16);
	cout << "3. Advanced" << endl;
	gotoxy(18, 18);
	cout << "4. Exit" << endl;
	gotoxy(15, 21);
	cout << "Enter your choice from 1 to 4: ";
	while (!(cin >> choice) || choice < 1 || choice > 4)
	{
		cin.sync();
		cin.clear();
		gotoxy(15, 21);
		cout << "\aYou have entered a wrong choice.";
		gotoxy(15, 22);
		cout << "Please enter a valid choice : ";
		gotoxy(45, 22);
	};

	system("cls");
	extview();
	if (choice == 1)
	{
		beginner(username);
	}
	else if (choice == 2)
	{
		intermediate(username);
	}
	else if (choice == 3)
	{
		advanced(username);
	}
	else if (choice == 4)
		exit(1);
	else
		cout << "Wrong choice";
}



void beginner(string username)
{
	int cho;
	gotoxy(10, 4);
	cout << "In this stage you will learn the basics of typing.";
	gotoxy(10, 5);
	cout << "This involves typing the letters on the keyboard.";
	gotoxy(15, 10);
	cout << "[ Select your unit ]";
	gotoxy(18, 12);
	cout << "1. Unit One" << endl;
	gotoxy(18, 14);
	cout << "2. Unit Two" << endl;
	gotoxy(18, 16);
	cout << "3. Unit Three" << endl;
	gotoxy(18, 18);
	cout << "4. Return to Main Menu" << endl;
	gotoxy(15, 21);
	cout << "Enter your choice from 1 to 4: ";
	while (!(cin >> cho) || cho < 1 || cho > 4)
	{
		cin.sync();
		cin.clear();
		gotoxy(15, 21);
		cout << "\aYou have entered a wrong choice.";
		gotoxy(15, 22);
		cout << "Please enter a valid choice : ";
		gotoxy(45, 22);
	};
	system("cls");
	extview();
	if (cho == 1)
	{
		beginner_unit_1(username);
	}
	else if (cho == 2)
	{
		beginner_unit_2(username);
	}
	else if (cho == 3)
	{
		beginner_unit_3(username);
	}
	else if (cho == 4)
	{
		mainmenu(username);
	}
	else
		cout << "Wrong choice";
}
void beginner_unit_1(string username)
{
	FILE *fp;
	int i = 0;
	int x = 0;
	int y = 0;
	int errcnt = 0;
	int cnt = 0;
	float acc;
	time_t start = 0, end = 0;
	char str[650];
	char ch;
	system("cls");

	fp = fopen("beginner_unit_1.txt", "rt");
	fgets(str, 650, fp);

	extview();
	gotoxy(64, 5);
	cout << "Beginner";
	gotoxy(64, 7);
	cout << "Unit: 1";
	gotoxy(64, 9);
	cout << "Name: " << username;
	gotoxy(64, 11);
	cout << "Accuracy:  ?";
	gotoxy(64, 13);
	cout << "CPM:  ?";
	gotoxy(64, 15);
	cout << "Error Count: ?";

	/* Loop To Print The String */

	for (i = 0; i<strlen(str); i++){
		gotoxy(10 + (x++), 5 + y);
		cout << str[i];
		if ((i % 50 == 0) && (i != 0)){
			y += 3;
			x = 0;
		}
	}
	cout << endl;

	x = 0;
	y = 0;
	ch = 0;

	/* Getting Input From The User */

	for (i = 0; i<strlen(str) && ch != 27; i++)
	{
		gotoxy(10 + (x++), 6 + y);
		ch = _getch();
		if (start == 0){
			start = time(NULL);
		}
		cnt++;
		if (ch != str[i])
		{
			if (ch == 32)
			{
				_cprintf("%c", 24);
				cout << "\a";
			}
			else
			{
				_cprintf("%c", ch);
				cout << "\a";
			}
			errcnt++;
		}
		else
			cout << ch;
		if ((i % 50 == 0) && (i != 0))
		{
			y += 3;
			x = 0;
		}
	}

	/* Accuracy & WPM Calculation */

	end = time(NULL);
	acc = (1.0*(cnt - errcnt) / cnt) * 100.0;
	gotoxy(74, 11);
	printf(" %.1f%\n", acc);
	gotoxy(68, 13);
	printf(" %.2f\n", (65 / (difftime(end, start) / 60)));
	gotoxy(77, 15);
	cout << errcnt;
	gotoxy(13, 22);
	system("pause");
	system("cls");
	extview();
	if ((65 / (difftime(end, start) / 60)) < 80 || acc<80)
	{
		char or;
		gotoxy(18, 18);
		cout << "You failed to pass unit one.";
		gotoxy(18, 19);
		cout << "Do you want to repeat unit one? (Y/N):";
		cin >> or;
		while (or != 'y' && or != 'Y' && or !='n' && or !='N')
		{
			system("cls");
			extview();
			gotoxy(18, 18);
			cout << "\aYou have entered a wrong choice.";
			gotoxy(18, 19);
			cout << "Please enter a valid choice : ";
			gotoxy(48, 19);
			cin >> or;
		}

		if (or == 'y' || or == 'Y')
		{
			system("cls");
			extview();
			beginner_unit_1(username);
		}
		else
			mainmenu(username);
	}
	else
	{
		std::ofstream record((username+".txt").c_str());
		record << "Name: " << username << std::endl;
		record << "Level: Beginner"<<std::endl;
		record << "Unit: 1" << std::endl;
		record << "Accuracy: " << acc << std::endl;
		record << "Character per Minute: " << (65 / (difftime(end, start) / 60)) << std::endl;
		record.close();

		gotoxy(18, 18);
		cout << "Unit one completed";
		gotoxy(18, 19);
		cout << "Congratulations! you have passed unit one.";
		gotoxy(18, 20);
		system("pause");
		system("cls");
		extview();
		beginner_unit_2(username);

	}

}
void beginner_unit_2(string username)
{
	FILE *fp;
	int i = 0;
	int x = 0;
	int y = 0;
	int errcnt = 0;
	int cnt = 0;
	float acc;
	time_t start = 0, end = 0;
	char str[650];
	char ch;
	system("cls");

	fp = fopen("beginner_unit_2.txt", "rt");
	fgets(str, 650, fp);

	extview();
	gotoxy(64, 5);
	cout << "Beginner";
	gotoxy(64, 7);
	cout << "Unit: 2";
	gotoxy(64, 9);
	cout << "Name: " << username;
	gotoxy(64, 11);
	cout << "Accuracy:  ?";
	gotoxy(64, 13);
	cout << "CPM:  ?";
	gotoxy(64, 15);
	cout << "Error Count: ?";

	/* Loop To Print The String */

	for (i = 0; i<strlen(str); i++){
		gotoxy(10 + (x++), 5 + y);
		cout << str[i];
		if ((i % 50 == 0) && (i != 0)){
			y += 3;
			x = 0;
		}
	}
	cout << endl;

	x = 0;
	y = 0;
	ch = 0;

	/* Getting Input From The User */

	for (i = 0; i<strlen(str) && ch != 27; i++)
	{
		gotoxy(10 + (x++), 6 + y);
		ch = _getch();
		if (start == 0){
			start = time(NULL);
		}
		cnt++;
		if (ch != str[i])
		{
			if (ch == 32)
			{
				_cprintf("%c", 24);
				cout << "\a";
			}
			else
			{
				_cprintf("%c", ch);
				cout << "\a";
			}
			errcnt++;
		}
		else
			cout << ch;
		if ((i % 50 == 0) && (i != 0))
		{
			y += 3;
			x = 0;
		}
	}

	/* Accuracy & WPM Calculation */

	end = time(NULL);
	acc = (1.0*(cnt - errcnt) / cnt) * 100.0;
	gotoxy(74, 11);
	printf(" %.1f%\n", acc);
	gotoxy(68, 13);
	printf(" %.2f\n", (65 / (difftime(end, start) / 60)));
	gotoxy(77, 15);
	cout << errcnt;
	gotoxy(13, 22);
	system("pause");
	system("cls");
	extview();
	if ((65 / (difftime(end, start) / 60)) < 50 || acc<70)
	{
		char or;
		gotoxy(18, 18);
		cout << "You failed to pass unit two.";
		gotoxy(18, 19);
		cout << "Do you want to repeat unit two? (Y/N):";
		cin >> or;
		while (or != 'y' && or != 'Y' && or != 'n' && or != 'N')
		{
			system("cls");
			extview();
			gotoxy(18, 18);
			cout << "\aYou have entered a wrong choice.";
			gotoxy(18, 19);
			cout << "Please enter a valid choice (Y/N) : ";
			gotoxy(48, 19);
			cin >> or;
		}

		if (or == 'y' || or == 'Y')
		{
			system("cls");
			extview();
			beginner_unit_2(username);
		}
		else
			mainmenu(username);
	}
	else
	{
		std::ofstream record((username + ".txt").c_str());
		record << "Name: " << username << std::endl;
		record << "Level: Beginner" << std::endl;
		record << "Unit: 2" << std::endl;
		record << "Accuracy: " << acc << std::endl;
		record << "Character per Minute: " << (65 / (difftime(end, start) / 60)) << std::endl;
		record.close();

		gotoxy(18, 18);
		cout << "Unit two completed";
		gotoxy(18, 19);
		cout << "Congratulations! you have passed unit two.";
		gotoxy(18, 20);
		system("pause");
		system("cls");
		extview();
		beginner_unit_3(username);

	}
}
void beginner_unit_3(string username)
{
	FILE *fp;
	int i = 0;
	int x = 0;
	int y = 0;
	//int z = 4;
	int errcnt = 0;
	int cnt = 0;
	float acc;
	time_t start = 0, end = 0;
	char str[650];
	char ch;
	system("cls");

	fp = fopen("beginner_unit_3.txt", "rt");
	fgets(str, 650, fp);

	extview();
	gotoxy(64, 5);
	cout << "Beginner";
	gotoxy(64, 7);
	cout << "Unit: 3";
	gotoxy(64, 9);
	cout << "Name: " << username;
	gotoxy(64, 11);
	cout << "Accuracy:  ?";
	gotoxy(64, 13);
	cout << "CPM:  ?";
	gotoxy(64, 15);
	cout << "Error Count: ?";

	/* Loop To Print The String */

	for (i = 0; i<strlen(str); i++){
		gotoxy(10 + (x++), 5 + y);
		cout << str[i];
		if ((i % 50 == 0) && (i != 0)){
			y += 3;
			x = 0;
		}
	}
	cout << endl;

	x = 0;
	y = 0;
	ch = 0;

	/* Getting Input From The User */

	for (i = 0; i<strlen(str) && ch != 27; i++)
	{
		gotoxy(10 + (x++), 6 + y);
		ch = _getch();
		if (start == 0){
			start = time(NULL);
		}
		cnt++;
		if (ch != str[i])
		{
			if (ch == 32)
			{
				_cprintf("%c", 24);
				cout << "\a";
			}
			else
			{
				_cprintf("%c", ch);
				cout << "\a";
			}
			errcnt++;
		}
		else
			cout << ch;
		if ((i % 50 == 0) && (i != 0))
		{
			y += 3;
			x = 0;
		}
	}

	/* Accuracy & WPM Calculation */

	end = time(NULL);
	acc = (1.0*(cnt - errcnt) / cnt) * 100.0;
	gotoxy(74, 11);
	printf(" %.1f%\n", acc);
	gotoxy(68, 13);
	printf(" %.2f\n", (65 / (difftime(end, start) / 60)));
	gotoxy(77, 15);
	cout << errcnt;
	gotoxy(13, 22);
	system("pause");
	system("cls");
	extview();
	if ((65 / (difftime(end, start) / 60)) < 40 || acc<70)
	{
		char or;
		gotoxy(18, 18);
		cout << "You failed to pass unit three.";
		gotoxy(18, 19);
		cout << "Do you want to repeat unit three? (Y/N):";
		cin >> or;
		while (or != 'y' && or != 'Y' && or != 'n' && or != 'N')
		{
			system("cls");
			extview();
			gotoxy(18, 18);
			cout << "\aYou have entered a wrong choice.";
			gotoxy(18, 19);
			cout << "Please enter a valid choice (Y/N) : ";
			gotoxy(48, 19);
			cin >> or;
		};

		if (or == 'y' || or == 'Y')
		{
			system("cls");
			extview();
			beginner_unit_3(username);
		}
		else
			mainmenu(username);
	}
	else
	{
		std::ofstream record((username + ".txt").c_str());
		record << "Name: " << username << std::endl;
		record << "Level: Beginner" << std::endl;
		record << "Unit: 3" << std::endl;
		record << "Accuracy: " << acc << std::endl;
		record << "Character per Minute: " << (65 / (difftime(end, start) / 60)) << std::endl;
		record.close();

		gotoxy(18, 18);
		cout << "Unit three completed";
		gotoxy(18, 19);
		cout << "Congratulations! you have passed unit three.";
		gotoxy(18, 20);
		system("pause");
		system("cls");
		extview();
		intermediate_unit_1(username);

	}
}
void intermediate(string username)
{
	int cho;
	system("cls");
	extview();
	gotoxy(10, 4);
	cout << "In this step you will learn the intermediate level";
	gotoxy(10, 5);
	cout << "typing. You will learn typing words.";
	gotoxy(15, 10);
	cout << "[ Select your unit ]";
	gotoxy(18, 12);
	cout << "1. Unit One" << endl;
	gotoxy(18, 14);
	cout << "2. Unit Two" << endl;
	gotoxy(18, 16);
	cout << "3. Unit Three" << endl;
	gotoxy(18, 18);
	cout << "4. Return to Main Menu" << endl;
	gotoxy(15, 21);
	cout << "Enter your choice from 1 to 4: ";
	while (!(cin >> cho) || cho < 1 || cho > 4)
	{
		cin.sync();
		cin.clear();
		gotoxy(15, 21);
		cout << "\aYou have entered a wrong choice.";
		gotoxy(15, 22);
		cout << "Please enter a valid choice : ";
		gotoxy(45, 22);
	};
	system("cls");
	extview();
	if (cho == 1)
	{
		intermediate_unit_1(username);
	}
	else if (cho == 2)
	{
		intermediate_unit_2(username);
	}
	else if (cho == 3)
	{
		intermediate_unit_3(username);
	}
	else if (cho == 4)
	{
		mainmenu(username);
	}
	else
		cout << "Wrong choice";
}
void intermediate_unit_1(string username)
{
	FILE *fp;
	int i = 0;
	int x = 0;
	int y = 0;
	//int z = 4;
	int errcnt = 0;
	int cnt = 0;
	float acc;
	time_t start = 0, end = 0;
	char str[650];
	char ch;
	system("cls");

	fp = fopen("intermediate_unit_1.txt", "rt");
	fgets(str, 650, fp);

	extview();
	gotoxy(64, 5);
	cout << "Intermediate";
	gotoxy(64, 7);
	cout << "Unit: 1";
	gotoxy(64, 9);
	cout << "Name: " << username;
	gotoxy(64, 11);
	cout << "Accuracy:  ?";
	gotoxy(64, 13);
	cout << "WPM:  ?";
	gotoxy(64, 15);
	cout << "Error Count: ?";

	/* Loop To Print The String */

	for (i = 0; i<strlen(str); i++){
		gotoxy(10 + (x++), 5 + y);
		cout << str[i];
		if ((i % 50 == 0) && (i != 0)){
			y += 3;
			x = 0;
		}
	}
	cout << endl;

	x = 0;
	y = 0;
	ch = 0;

	/* Getting Input From The User  */

	for (i = 0; i<strlen(str) && ch != 27; i++)
	{
		gotoxy(10 + (x++), 6 + y);
		ch = _getch();
		if (start == 0){
			start = time(NULL);
		}
		cnt++;
		if (ch != str[i])
		{
			if (ch == 32)
			{
				_cprintf("%c", 24);
				cout << "\a";
			}
			else
			{
				_cprintf("%c", ch);
				cout << "\a";
			}
			errcnt++;
		}
		else
			cout << ch;
		if ((i % 50 == 0) && (i != 0))
		{
			y += 3;
			x = 0;
		}
	}

	/* Accuracy & WPM Calculation */

	end = time(NULL);
	acc = (1.0*(cnt - errcnt) / cnt) * 100.0;
	gotoxy(74, 11);
	printf(" %.1f%\n", acc);
	gotoxy(68, 13);
	printf(" %.2f\n", (65 / (difftime(end, start) / 60)));
	gotoxy(77, 15);
	cout << errcnt;
	gotoxy(13, 22);
	system("pause");
	system("cls");
	extview();
	if ((65 / (difftime(end, start) / 60)) < 30 || acc<60)
	{
		char or;
		gotoxy(18, 18);
		cout << "You failed to pass unit one.";
		gotoxy(18, 19);
		cout << "Do you want to repeat unit one? (Y/N):";
		cin >> or;
		while (or != 'y' && or != 'Y' && or != 'n' && or != 'N')
		{
			system("cls");
			extview();
			gotoxy(18, 18);
			cout << "\aYou have entered a wrong choice.";
			gotoxy(18, 19);
			cout << "Please enter a valid choice (Y/N) : ";
			gotoxy(48, 19);
			cin >> or;
		};

		if (or == 'y' || or == 'Y')
		{
			system("cls");
			extview();
			intermediate_unit_1(username);
		}
		else
			mainmenu(username);
	}
	else
	{
		std::ofstream record((username + ".txt").c_str());
		record << "Name: " << username << std::endl;
		record << "Level: Intermediate" << std::endl;
		record << "Unit: 1" << std::endl;
		record << "Accuracy: " << acc << std::endl;
		record << "Words per Minute: " << (65 / (difftime(end, start) / 60)) << std::endl;
		record.close();
		gotoxy(18, 18);
		cout << "Unit one completed";
		gotoxy(18, 19);
		cout << "Congratulations! you have passed unit one.";
		gotoxy(18, 20);
		system("pause");
		system("cls");
		extview();
		intermediate_unit_2(username);

	}
}
void intermediate_unit_2(string username)
{
	FILE *fp;
	int i = 0;
	int x = 0;
	int y = 0;
	//int z = 4;
	int errcnt = 0;
	int cnt = 0;
	float acc;
	time_t start = 0, end = 0;
	char str[650];
	char ch;
	system("cls");

	fp = fopen("intermediate_unit_2.txt", "rt");
	fgets(str, 650, fp);

	extview();
	gotoxy(64, 5);
	cout << "Intermediate";
	gotoxy(64, 7);
	cout << "Unit: 2";
	gotoxy(64, 9);
	cout << "Name: " << username;
	gotoxy(64, 11);
	cout << "Accuracy:  ?";
	gotoxy(64, 13);
	cout << "WPM:  ?";
	gotoxy(64, 15);
	cout << "Error Count: ?";

	/* Loop To Print The String */

	for (i = 0; i<strlen(str); i++){
		gotoxy(10 + (x++), 5 + y);
		cout << str[i];
		if ((i % 50 == 0) && (i != 0)){
			y += 3;
			x = 0;
		}
	}
	cout << endl;

	x = 0;
	y = 0;
	ch = 0;

	/* Getting Input From The User */

	for (i = 0; i<strlen(str) && ch != 27; i++)
	{
		gotoxy(10 + (x++), 6 + y);
		ch = _getch();
		if (start == 0){
			start = time(NULL);
		}
		cnt++;
		if (ch != str[i])
		{
			if (ch == 32)
			{
				_cprintf("%c", 24);
				cout << "\a";
			}
			else
			{
				_cprintf("%c", ch);
				cout << "\a";
			}
			errcnt++;
		}
		else
			cout << ch;
		if ((i % 50 == 0) && (i != 0))
		{
			y += 3;
			x = 0;
		}
	}

	/* Accuracy & WPM Calculation */

	end = time(NULL);
	acc = (1.0*(cnt - errcnt) / cnt) * 100.0;
	gotoxy(74, 11);
	printf(" %.1f%\n", acc);
	gotoxy(68, 13);
	printf(" %.2f\n", (65 / (difftime(end, start) / 60)));
	gotoxy(77, 15);
	cout << errcnt;
	gotoxy(13, 22);
	system("pause");
	system("cls");
	extview();
	if ((65 / (difftime(end, start) / 60)) < 30 || acc<60)
	{
		char or;
		gotoxy(18, 18);
		cout << "You failed to pass unit two.";
		gotoxy(18, 19);
		cout << "Do you want to repeat unit two? (Y/N):";
		cin >> or;
		while (or != 'y' && or != 'Y' && or != 'n' && or != 'N')
		{
			system("cls");
			extview();
			gotoxy(18, 18);
			cout << "\aYou have entered a wrong choice.";
			gotoxy(18, 19);
			cout << "Please enter a valid choice (Y/N) : ";
			gotoxy(48, 19);
			cin >> or;
		};

		if (or == 'y' || or == 'Y')
		{
			system("cls");
			extview();
			intermediate_unit_2(username);
		}
		else
			mainmenu(username);
	}
	else
	{
		std::ofstream record((username + ".txt").c_str());
		record << "Name: " << username << std::endl;
		record << "Level: Intermediate" << std::endl;
		record << "Unit: 2" << std::endl;
		record << "Accuracy: " << acc << std::endl;
		record << "Words per Minute: " << (65 / (difftime(end, start) / 60)) << std::endl;
		record.close();
		gotoxy(18, 18);
		cout << "Unit two completed";
		gotoxy(18, 19);
		cout << "Congratulations! you have passed unit two.";
		gotoxy(18, 20);
		system("pause");
		system("cls");
		extview();
		intermediate_unit_3(username);

	}
}
void intermediate_unit_3(string username)
{
	FILE *fp;
	int i = 0;
	int x = 0;
	int y = 0;
	//int z = 4;
	int errcnt = 0;
	int cnt = 0;
	float acc;
	time_t start = 0, end = 0;
	char str[650];
	char ch;
	system("cls");

	fp = fopen("intermediate_unit_3.txt", "rt");
	fgets(str, 650, fp);

	extview();
	gotoxy(64, 5);
	cout << "Intermediate";
	gotoxy(64, 7);
	cout << "Unit: 3";
	gotoxy(64, 9);
	cout << "Name: " << username;
	gotoxy(64, 11);
	cout << "Accuracy:  ?";
	gotoxy(64, 13);
	cout << "WPM:  ?";
	gotoxy(64, 15);
	cout << "Error Count: ?";

	/* Loop To Print The String */

	for (i = 0; i<strlen(str); i++){
		gotoxy(10 + (x++), 5 + y);
		cout << str[i];
		if ((i % 50 == 0) && (i != 0)){
			y += 3;
			x = 0;
		}
	}
	cout << endl;

	x = 0;
	y = 0;
	ch = 0;

	/* Getting Input From The User */

	for (i = 0; i<strlen(str) && ch != 27; i++)
	{
		gotoxy(10 + (x++), 6 + y);
		ch = _getch();
		if (start == 0){
			start = time(NULL);
		}
		cnt++;
		if (ch != str[i])
		{
			if (ch == 32)
			{
				_cprintf("%c", 24);
				cout << "\a";
			}
			else
			{
				_cprintf("%c", ch);
				cout << "\a";
			}
			errcnt++;
		}
		else
			cout << ch;
		if ((i % 50 == 0) && (i != 0))
		{
			y += 3;
			x = 0;
		}
	}

	/* Accuracy & WPM Calculation */

	end = time(NULL);
	acc = (1.0*(cnt - errcnt) / cnt) * 100.0;
	gotoxy(74, 11);
	printf(" %.1f%\n", acc);
	gotoxy(68, 13);
	printf(" %.2f\n", (65 / (difftime(end, start) / 60)));
	gotoxy(77, 15);
	cout << errcnt;
	gotoxy(13, 22);
	system("pause");
	system("cls");
	extview();
	if ((65 / (difftime(end, start) / 60)) < 30 || acc<60)
	{
		char or;
		gotoxy(18, 18);
		cout << "You failed to pass unit three.";
		gotoxy(18, 19);
		cout << "Do you want to repeat unit three? (Y/N):";
		cin >> or;
		while (or != 'y' && or != 'Y' && or != 'n' && or != 'N')
		{
			system("cls");
			extview();
			gotoxy(18, 18);
			cout << "\aYou have entered a wrong choice.";
			gotoxy(18, 19);
			cout << "Please enter a valid choice (Y/N) : ";
			gotoxy(48, 19);
			cin >> or;
		};

		if (or == 'y' || or == 'Y')
		{
			system("cls");
			extview();
			intermediate_unit_3(username);
		}
		else
			mainmenu(username);
	}
	else
	{
		std::ofstream record((username + ".txt").c_str());
		record << "Name: " << username << std::endl;
		record << "Level: Intermediate" << std::endl;
		record << "Unit: 3" << std::endl;
		record << "Accuracy: " << acc << std::endl;
		record << "Words per Minute: " << (65 / (difftime(end, start) / 60)) << std::endl;
		record.close();
		gotoxy(18, 18);
		cout << "Unit three completed";
		gotoxy(18, 19);
		cout << "Congratulations! you have passed unit three.";
		gotoxy(18, 20);
		system("pause");
		system("cls");
		extview();
		advanced_unit_1(username);

	}
}
void advanced(string username)
{
	int cho;
	system("cls");
	extview();
	gotoxy(10, 4);
	cout << "As you already know the basics and intermediate";
	gotoxy(10, 5);
	cout << "level typing so you will enhance your speed in";
	gotoxy(10, 6);
	cout<<"this step by typing in paragraphs.";
	gotoxy(15, 10);
	cout << "[ Select your unit ]";
	gotoxy(18, 12);
	cout << "1. Unit One" << endl;
	gotoxy(18, 14);
	cout << "2. Unit Two" << endl;
	gotoxy(18, 16);
	cout << "3. Unit Three" << endl;
	gotoxy(18, 18);
	cout << "4. Return to Main Menu" << endl;
	gotoxy(15, 21);
	cout << "Enter your choice from 1 to 4: ";
	while (!(cin >> cho) || cho < 1 || cho > 4)
	{
		cin.sync();
		cin.clear();
		gotoxy(15, 21);
		cout << "\aYou have entered a wrong choice.";
		gotoxy(15, 22);
		cout << "Please enter a valid choice : ";
		gotoxy(45, 22);
	};
	system("cls");
	extview();
	if (cho == 1)
	{
		advanced_unit_1(username);
	}
	else if (cho == 2)
	{
		advanced_unit_2(username);
	}
	else if (cho == 3)
	{
		advanced_unit_3(username);
	}
	else if (cho == 4)
	{
		mainmenu(username);
	}
	else
		cout << "Wrong choice";
}
void advanced_unit_1(string username)
{
	FILE *fp;
	int i = 0;
	int x = 0;
	int y = 0;
	//int z = 4;
	int errcnt = 0;
	int cnt = 0;
	float acc;
	time_t start = 0, end = 0;
	char str[650];
	char ch;
	system("cls");

	fp = fopen("advanced_unit_1.txt", "rt");
	fgets(str, 650, fp);

	extview();
	gotoxy(64, 5);
	cout << "Advanced";
	gotoxy(64, 7);
	cout << "Unit: 1";
	gotoxy(64, 9);
	cout << "Name: " << username;
	gotoxy(64, 11);
	cout << "Accuracy:  ?";
	gotoxy(64, 13);
	cout << "WPM:  ?";
	gotoxy(64, 15);
	cout << "Error Count: ?";

	/* Loop To Print The String */

	for (i = 0; i<strlen(str); i++){
		gotoxy(10 + (x++), 5 + y);
		cout << str[i];
		if ((i % 50 == 0) && (i != 0)){
			y += 3;
			x = 0;
		}
	}
	cout << endl;

	x = 0;
	y = 0;
	ch = 0;

	/* Getting Input From The User  */

	for (i = 0; i<strlen(str) && ch != 27; i++)
	{
		gotoxy(10 + (x++), 6 + y);
		ch = _getch();
		if (start == 0){
			start = time(NULL);
		}
		cnt++;
		if (ch != str[i])
		{
			if (ch == 32)
			{
				_cprintf("%c", 24);
				cout << "\a";
			}
			else
			{
				_cprintf("%c", ch);
				cout << "\a";
			}
			errcnt++;
		}
		else
			cout << ch;
		if ((i % 50 == 0) && (i != 0))
		{
			y += 3;
			x = 0;
		}
	}

	/* Accuracy & WPM Calculation */

	end = time(NULL);
	acc = (1.0*(cnt - errcnt) / cnt) * 100.0;
	gotoxy(74, 11);
	printf(" %.1f%\n", acc);
	gotoxy(68, 13);
	printf(" %.2f\n", (65 / (difftime(end, start) / 60)));
	gotoxy(77, 15);
	cout << errcnt;
	gotoxy(13, 22);
	system("pause");
	system("cls");
	extview();
	if ((65 / (difftime(end, start) / 60)) < 30 || acc<60)
	{
		char or;
		gotoxy(18, 18);
		cout << "You failed to pass unit one.";
		gotoxy(18, 19);
		cout << "Do you want to repeat unit one? (Y/N):";
		cin >> or;
		while (or != 'y' && or != 'Y' && or != 'n' && or != 'N')
		{
			system("cls");
			extview();
			gotoxy(18, 18);
			cout << "\aYou have entered a wrong choice.";
			gotoxy(18, 19);
			cout << "Please enter a valid choice (Y/N) : ";
			gotoxy(48, 19);
			cin >> or;
		};

		if (or == 'y' || or == 'Y')
		{
			system("cls");
			extview();
			advanced_unit_1(username);
		}
		else
			mainmenu(username);
	}
	else
	{
		std::ofstream record((username + ".txt").c_str());
		record << "Name: " << username << std::endl;
		record << "Level: Advanced" << std::endl;
		record << "Unit: 1" << std::endl;
		record << "Accuracy: " << acc << std::endl;
		record << "Words per Minute: " << (65 / (difftime(end, start) / 60)) << std::endl;
		record.close();
		gotoxy(18, 18);
		cout << "Unit one completed";
		gotoxy(18, 19);
		cout << "Congratulations! you have passed unit one.";
		gotoxy(18, 20);
		system("pause");
		system("cls");
		extview();
		advanced_unit_2(username);

	}
}
void advanced_unit_2(string username)
{
	FILE *fp;
	int i = 0;
	int x = 0;
	int y = 0;
	//int z = 4;
	int errcnt = 0;
	int cnt = 0;
	float acc;
	time_t start = 0, end = 0;
	char str[650];
	char ch;
	system("cls");

	fp = fopen("advanced_unit_2.txt", "rt");
	fgets(str, 650, fp);

	extview();
	gotoxy(64, 5);
	cout << "Advanced";
	gotoxy(64, 7);
	cout << "Unit: 2";
	gotoxy(64, 9);
	cout << "Name: " << username;
	gotoxy(64, 11);
	cout << "Accuracy:  ?";
	gotoxy(64, 13);
	cout << "WPM:  ?";
	gotoxy(64, 15);
	cout << "Error Count: ?";

	/* Loop To Print The String */

	for (i = 0; i<strlen(str); i++){
		gotoxy(10 + (x++), 5 + y);
		cout << str[i];
		if ((i % 50 == 0) && (i != 0)){
			y += 3;
			x = 0;
		}
	}
	cout << endl;

	x = 0;
	y = 0;
	ch = 0;

	/* Getting Input From The User */

	for (i = 0; i<strlen(str) && ch != 27; i++)
	{
		gotoxy(10 + (x++), 6 + y);
		ch = _getch();
		if (start == 0){
			start = time(NULL);
		}
		cnt++;
		if (ch != str[i])
		{
			if (ch == 32)
			{
				_cprintf("%c", 24);
				cout << "\a";
			}
			else
			{
				_cprintf("%c", ch);
				cout << "\a";
			}
			errcnt++;
		}
		else
			cout << ch;
		if ((i % 50 == 0) && (i != 0))
		{
			y += 3;
			x = 0;
		}
	}

	/* Accuracy & WPM Calculation */

	end = time(NULL);
	acc = (1.0*(cnt - errcnt) / cnt) * 100.0;
	gotoxy(74, 11);
	printf(" %.1f%\n", acc);
	gotoxy(68, 13);
	printf(" %.2f\n", (65 / (difftime(end, start) / 60)));
	gotoxy(77, 15);
	cout << errcnt;
	gotoxy(13, 22);
	system("pause");
	system("cls");
	extview();
	if ((65 / (difftime(end, start) / 60)) < 30 || acc<60)
	{
		char or;
		gotoxy(18, 18);
		cout << "You failed to pass unit two.";
		gotoxy(18, 19);
		cout << "Do you want to repeat unit two? (Y/N):";
		cin >> or;
		while (or != 'y' && or != 'Y' && or != 'n' && or != 'N')
		{
			system("cls");
			extview();
			gotoxy(18, 18);
			cout << "\aYou have entered a wrong choice.";
			gotoxy(18, 19);
			cout << "Please enter a valid choice (Y/N) : ";
			gotoxy(48, 19);
			cin >> or;
		};

		if (or == 'y' || or == 'Y')
		{
			system("cls");
			extview();
			advanced_unit_2(username);
		}
		else
			mainmenu(username);
	}
	else
	{
		std::ofstream record((username + ".txt").c_str());
		record << "Name: " << username << std::endl;
		record << "Level: Advanced" << std::endl;
		record << "Unit: 2" << std::endl;
		record << "Accuracy: " << acc << std::endl;
		record << "Words per Minute: " << (65 / (difftime(end, start) / 60)) << std::endl;
		record.close();
		gotoxy(18, 18);
		cout << "Unit two completed";
		gotoxy(18, 19);
		cout << "Congratulations! you have passed unit two.";
		gotoxy(18, 20);
		system("pause");
		system("cls");
		extview();
		advanced_unit_3(username);

	}
}
void advanced_unit_3(string username)
{
	FILE *fp;
	int i = 0;
	int x = 0;
	int y = 0;
	//int z = 4;
	int errcnt = 0;
	int cnt = 0;
	float acc;
	time_t start = 0, end = 0;
	char str[650];
	char ch;
	system("cls");

	fp = fopen("advanced_unit_3.txt", "rt");
	fgets(str, 650, fp);

	extview();
	gotoxy(64, 5);
	cout << "Advanced";
	gotoxy(64, 7);
	cout << "Unit: 3";
	gotoxy(64, 9);
	cout << "Name: " << username;
	gotoxy(64, 11);
	cout << "Accuracy:  ?";
	gotoxy(64, 13);
	cout << "WPM:  ?";
	gotoxy(64, 15);
	cout << "Error Count: ?";

	/* Loop To Print The String */

	for (i = 0; i<strlen(str); i++){
		gotoxy(10 + (x++), 5 + y);
		cout << str[i];
		if ((i % 50 == 0) && (i != 0)){
			y += 3;
			x = 0;
		}
	}
	cout << endl;

	x = 0;
	y = 0;
	ch = 0;

	/* Getting Input From The User */

	for (i = 0; i<strlen(str) && ch != 27; i++)
	{
		gotoxy(10 + (x++), 6 + y);
		ch = _getch();
		if (start == 0){
			start = time(NULL);
		}
		cnt++;
		if (ch != str[i])
		{
			if (ch == 32)
			{
				_cprintf("%c", 24);
				cout << "\a";
			}
			else
			{
				_cprintf("%c", ch);
				cout << "\a";
			}
			errcnt++;
		}
		else
			cout << ch;
		if ((i % 50 == 0) && (i != 0))
		{
			y += 3;
			x = 0;
		}
	}

	/* Accuracy & WPM Calculation */

	end = time(NULL);
	acc = (1.0*(cnt - errcnt) / cnt) * 100.0;
	gotoxy(74, 11);
	printf(" %.1f%\n", acc);
	gotoxy(68, 13);
	printf(" %.2f\n", (65 / (difftime(end, start) / 60)));
	gotoxy(77, 15);
	cout << errcnt;
	gotoxy(13, 22);
	system("pause");
	system("cls");
	extview();
	if ((65 / (difftime(end, start) / 60)) < 30 || acc<60)
	{
		char or;
		gotoxy(18, 18);
		cout << "You failed to pass unit three.";
		gotoxy(18, 19);
		cout << "Do you want to repeat unit three? (Y/N):";
		cin >> or;
		while (or != 'y' && or != 'Y' && or != 'n' && or != 'N')
		{
			system("cls");
			extview();
			gotoxy(18, 18);
			cout << "\aYou have entered a wrong choice.";
			gotoxy(18, 19);
			cout << "Please enter a valid choice (Y/N) : ";
			gotoxy(48, 19);
			cin >> or;
		};

		if (or == 'y' || or == 'Y')
		{
			system("cls");
			extview();
			advanced_unit_3(username);
		}
		else
			mainmenu(username);
	}
	else
	{
		std::ofstream record((username + ".txt").c_str());
		record << "Name: " << username << std::endl;
		record << "Level: Advanced" << std::endl;
		record << "Unit: 3" << std::endl;
		record << "Accuracy: " << acc << std::endl;
		record << "Words per Minute: " << (65 / (difftime(end, start) / 60)) << std::endl;
		record.close();
		gotoxy(18, 18);
		cout << "Unit three completed";
		gotoxy(18, 19);
		cout << "Congratulations! you have passed unit three.";
		gotoxy(18, 20);
		system("pause");
		system("cls");
		extview();
		mainmenu(username);

	}
}
