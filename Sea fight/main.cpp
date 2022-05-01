#include <iostream>
#include "windows.h"
#include "functions.h"
//#include <conio.h>
//#include <time.h>
//#include <ctime>


using namespace std;

//HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);




int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleTitle(L"Морской бой");


	char playerField[10][10];
	char playerFireField[10][10];
	char botField[10][10];

	mainMenu(playerField, playerFireField, botField);


	/*
	string menu[] = { "Автоматическая расстановка кораблей", "Ручная расстановка кораблей", "Играть", "Выход" };
	//string mMenu[] = { "Один четырёхпалубный", "два трёхпалубных", "три двухпалубных", "четыре однопалубных", "возврат в главное меню" };
	GoToXY(50, 11);
	cout << "Главное меню";
	int a = 0;
	int active_menu = 0;
	char ch;
	while (true) {
		int x = 50, y = 13;
		GoToXY(x, y);
		for (int i = 0; i < size(menu); i++) {
			if (i == active_menu)
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
			else
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			GoToXY(x, y++);
			cout << menu[i] << endl;
		}

		ch = _getch();
		if (ch == -32)			// -32 это вторая кодировка стрелочек, тоесть у стрелочек данные хранятся не в одном байте а в двух
			ch = _getch();
		switch (ch) {
		case up: if (active_menu > 0) active_menu--; break;
		case down: if (active_menu < size(menu) - 1) active_menu++; break;
		case enter:
			switch (active_menu) {
			case 0:
				system("cls");
				GoToXY(x, y);
				startMap(playerField, playerFireField, botField);
				enterCoordinateAuto(playerField);
				cout << "Ваши корабли расставлены!";
				Sleep(1500);
				system("cls");
				GoToXY(x, y);
				cout << "Ждём расстановку бота!";
				Sleep(1500);
				system("cls");
				GoToXY(x, y);
				enterCoordinateAuto(botField);
				cout << "Все корабли расставлены, нажмите enter, что бы продолжить...";
				ch = _getch();
				system("cls");
				break;
			case 1:
				manualMenu();
				ch = _getch();
				system("cls");
				break;

			case 2:
				system("cls");
				GoToXY(x, y);
				a = rand() % 2;
				switch (a) {
				case 0: cout << "Вы ходите первым!\n\t\t\t\t\t\t"; system("pause"); firePlayer(playerField, playerFireField, botField); break;
				case 1:	cout << "Бот ходит первым!\n\t\t\t\t\t\t"; system("pause"); fireBot(playerField, playerFireField, botField); break;
				}		//требуется условие, если игрок не заполнил своё поле кораблями...
				ch = _getch();
				system("cls");
				break;
			case 3:
				exit(0);
			}
		}
	}*/
}