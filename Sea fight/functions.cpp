#include <iostream>
#include "windows.h"
#include "functions.h"
#include <conio.h>
#include <time.h>
#include <ctime>
#include <string>

#define up 72
#define down 80
//#define right 77
//#define left 75
#define enter 13
//#define esc 27

void enterShipAuto(char field[10][10], int size, int kolvo, int shipId, int ships[10]) {
	srand(time(NULL));
	
	int countShip = 0, dir = 0, x, y;
	
	while (countShip < kolvo) {

		//первая позиция
		x = rand() % (11 - 1) + 1;
		y = rand() % (11 - 1) + 1;

		int temp_x = x;
		int temp_y = y;

		//случайное направление
		dir = rand() % 4;

		//проверка возможности постановки корабля
		bool isPoss = 1;
		for (int i = 1; i <= size; i++) {
			if (x < 1 || y < 1 || x >= 11 || y >= 11) {
				isPoss = 0;
				break;
			}

			if (field[x][y] == '#' ||
				field[x][y + 1] == '#' ||
				field[x][y - 1] == '#' ||
				field[x + 1][y] == '#' ||
				field[x + 1][y + 1] == '#' ||
				field[x + 1][y - 1] == '#' ||
				field[x - 1][y] == '#' ||
				field[x - 1][y + 1] == '#' ||
				field[x - 1][y - 1] == '#') {
				isPoss = 0;//Не возможно
				break;
			}
			switch (dir) {
			case 0: x++; break;
			case 1: y++; break;
			case 2: x--; break;
			case 3: y--; break;
			}
		}
		if (isPoss == 1) {		//Возможно

			x = temp_x;
			y = temp_y;

			//установка корабля
			for (int i = 1; i <= size; i++) {
				field[x][y] = '#';
				switch (dir) {
				case 0: x++; break;
				case 1: y++; break;
				case 2: x--; break;
				case 3: y--; break;
				}
			}
			
			//ships[shipId] = size;
			shipId++;
			countShip++;
		}
	}
}

void enterCordinateAuto(char playerField[10][10], char playerFireField[10][10], char botField[10][10], int shipId, int ships[10]) {
	enterShipAuto(playerField, 4, 1, shipId, ships);
	enterShipAuto(playerField, 3, 2, shipId, ships);
	enterShipAuto(playerField, 2, 3, shipId, ships);
	enterShipAuto(playerField, 1, 4, shipId, ships);
	Sleep(1500);
	enterShipAuto(botField, 4, 1, shipId, ships);
	enterShipAuto(botField, 3, 2, shipId, ships);
	enterShipAuto(botField, 2, 3, shipId, ships);
	enterShipAuto(botField, 1, 4, shipId, ships);
}

void enterCordinate(char playerField[10][10], char playerFireField[10][10], char botField[10][10], int size, int kolvo, int shipId, int ships[10]) {	//функция не доделана!!!
	int y = 0, x = 0, dir = 0, count = 0;
	char x1;
	startMap(playerField, playerFireField, botField);
	enterShipAuto(botField, 4, 1, shipId, ships);
	enterShipAuto(botField, 3, 2, shipId, ships);
	enterShipAuto(botField, 2, 3, shipId, ships);
	enterShipAuto(botField, 1, 4, shipId, ships);
	showMap(playerField, playerFireField, botField, shipId, ships);
	for (int i = 1; i <= kolvo; i++) {
		for (int j = 1; j <= size; j++) {
			showMap(playerField, playerFireField, botField, shipId, ships);
			do {
				y = 0;
				system("cls");
				showMap(playerField, playerFireField, botField, shipId, ships);
				try {
					std::string str;
					std::cout << "Введите " << j << " координату по вертикали " << i << "-ого " << size << " - палубного корабля: ";
					std::cin >> str;

					y = stoi(str);
					if (y < 1 || y > 10) {
						std::cout << "Не корректно введена координата, попробуйте ещё раз!" << std::endl;
						system("pause");
					}
					else
						break;
				}
				catch (const std::exception& ex) {
					std::string err = ex.what();
					if (err == "invalid stoi argument") {
						std::cout << "Не корректно введена координата, попробуйте ещё раз!" << std::endl;
						system("pause");
					}
				}
			} while (true);

			do {
				std::cout << "Введите " << j << " координату по горизонтали " << i << "-ого " << size << " - палубного корабля: ";
				std::cin >> x1;
				if (x1 >= 'A' && x1 <= 'J')//от 65 до 74
					x = (int)(x1 - 64);
				else
					if (x1 >= 'a' && x1 <= 'j')//от 97 до 106
						x = (int)(x1 - 96);
					else {
						showMap(playerField, playerFireField, botField, shipId, ships);
						std::cout << "Не корректно введена координата, попробуйте ещё раз!" << std::endl;
					}
			} while (x1 != 'a' && x1 != 'A' &&
				x1 != 'b' && x1 != 'B' &&
				x1 != 'c' && x1 != 'C' &&
				x1 != 'd' && x1 != 'D' &&
				x1 != 'e' && x1 != 'E' &&
				x1 != 'f' && x1 != 'F' &&
				x1 != 'g' && x1 != 'G' &&
				x1 != 'h' && x1 != 'H' &&
				x1 != 'i' && x1 != 'I' &&
				x1 != 'j' && x1 != 'J');
			
			if (playerField[y + 1][x] != '#' &&
				playerField[y + 1][x + 1] != '#' &&
				playerField[y + 1][x - 1] != '#' &&
				playerField[y - 1][x - 1] != '#' &&
				playerField[y - 1][x + 1] != '#' &&
				playerField[y - 1][x] != '#' &&
				playerField[y][x - 1] != '#' &&
				playerField[y][x + 1] != '#' &&
				playerField[y][x] != '#' /* && dir == 0 */ ) {
				playerField[y][x] = '#';
			}
			else {
				std::cout << "Сюда ставить нельзя!\n";
				system("pause");
				continue;						//цикл запускается заново
			}
			/*else if
				(dir != 0 && (playerField[a + 1][b] == '#' ||
					playerField[a][b - 1] == '#' ||
					playerField[a][b + 1] == '#'
					|| playerField[a - 1][b - 1] == '#') && (playerField[a + 1][b + 1] != '#' || playerField[a + 1][b - 1] != '#' || playerField[a - 1][b + 1] != '#'
						|| playerField[a - 1][b - 1] != '#')) {
				int temp = 0;
				if (playerField[a + 1][b] == '#') temp++;
				if (playerField[a - 1][b] == '#') temp++;
				if (playerField[a][b + 1] == '#') temp++;
				if (playerField[a][b - 1] == '#') temp++;
				if (temp == 1)	playerField[a][b] = '#';
			}
			else std::cout << "Error Check Field, illegal number or field, retry " << std::endl;
			dir++;
			if (playerField[a][b] == '#') {
				std::cout << "Your " << x << "-pointed ship: [" << a << "][" << b << "]" << std::endl;
				showMap(playerField, playerFireField, botField);
				if ((dir == x) && (dir != 4)) std::cout << "Good, next ship " << std::endl;
				else if (dir == 4) std::cout << "Ok, lets play ! " << std::endl;
				else enterCoordinate(playerField, playerFireField, botField, a, b, size, kolvo);
			}
			else {
				std::cout << "Ошибка ввода, повторите... " << std::endl;
				kolvo--;
				enterCoordinate(playerField, playerFireField, botField, size, kolvo);
			}*/
		}
		showMap(playerField, playerFireField, botField, shipId, ships);
		count++;
		if (kolvo == count)
			manualMenu(playerField, playerFireField, botField, shipId, ships);
	}
}

void mainMenu(char playerField[10][10], char playerFireField[10][10], char botField[10][10], int shipId, int ships[10]) {
	std::string menu[] = { "Автоматическая расстановка кораблей", "Ручная расстановка кораблей", "Играть", "Выход" };
	GoToXY(50, 11);
	std::cout << "Главное меню";
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
			std::cout << menu[i] << std::endl;
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
				
				std::cout << "Ваши корабли расставлены!";
				enterCordinateAuto(playerField, playerFireField, botField, shipId, ships);
				system("cls");
				GoToXY(x, y);
				std::cout << "Ждём расстановку бота!";
				Sleep(1500);
				system("cls");
				GoToXY(x, y);
				std::cout << "Все корабли расставлены, нажмите enter, что бы продолжить...";
				ch = _getch();
				system("cls");
				break;
			case 1:
				manualMenu(playerField, playerFireField, botField, shipId, ships);
				ch = _getch();
				system("cls");
				break;

			case 2:
				system("cls");
				GoToXY(x, y);
				a = rand() % 2;
				switch (a) {
				case 0: std::cout << "Вы ходите первым!\n\t\t\t\t\t\t"; system("pause"); firePlayer(playerField, playerFireField, botField, shipId, ships); break;
				case 1:	std::cout << "Бот ходит первым!\n\t\t\t\t\t\t"; system("pause"); fireBot(playerField, playerFireField, botField, shipId, ships); break;
				}		//требуется условие, если игрок не заполнил своё поле кораблями...
				ch = _getch();
				system("cls");
				break;
			case 3:
				exit(0);
			}
		}
	}
}

void manualMenu(char playerField[10][10], char playerFireField[10][10], char botField[10][10], int shipId, int ships[10]) {
	int active_menu = 0;
	char ch;
	std::string manualMenu[] = { "Один четырёхпалубный", "два трёхпалубных", "три двухпалубных", "четыре однопалубных", "возврат в главное меню" };
	system("cls");
	GoToXY(50, 11);
	std::cout << "В вашем распоряжении 4 вида кораблей:\n";
	while (true) {
		int x = 50, y = 13;
		GoToXY(x, y);
		for (int i = 0; i < size(manualMenu); i++) {
			if (i == active_menu)
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
			else
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			GoToXY(x, y++);
			std::cout << manualMenu[i] << std::endl;
		}

		ch = _getch();
		if (ch == -32)
			ch = _getch();
		switch (ch) {
		case up: if (active_menu > 0) active_menu--; break;
		case down: if (active_menu < size(manualMenu) - 1) active_menu++; break;
		case enter:
			switch (active_menu) {
			case 0:enterCordinate(playerField, playerFireField, botField, 4,1, shipId, ships); ch = _getch(); break;
			case 1:enterCordinate(playerField, playerFireField, botField, 3,2, shipId, ships); ch = _getch(); break;
			case 2:enterCordinate(playerField, playerFireField, botField, 2,3, shipId, ships); ch = _getch(); break;
			case 3:enterCordinate(playerField, playerFireField, botField, 1,4, shipId, ships); ch = _getch(); break;
			case 4: system("cls"); mainMenu(playerField, playerFireField, botField,shipId,ships); break;
			}
		}
	}
}
													//временное поле
void showMap(char playerField[10][10], char playerFireField[10][10], char botField[10][10], int shipId, int ships[10]) {
	system("CLS");
	std::cout << "\n      Ваши корабли  \t        Ваши выстрелы  \n";
	std::cout << "\n   A B C D E F G H I J \t     A B C D E F G H I J\n";
	std::cout << "  _____________________     _____________________\n";

	for (int i = 1; i < 11; i++) {
		if (i == 10) {
			std::cout << i << "|";
		}
		else
			std::cout << i << " |";
		for (int j = 1; j < 11; j++) {
			std::cout << playerField[i][j] << " ";
		}

		std::cout << "\b|   ";
		if (i == 10) {
			std::cout << i << "|";
		}
		else
			std::cout << i << " |";
		for (int k = 1; k < 11; k++) {
			std::cout << playerFireField[i][k] << " ";
		}
		std::cout << "\b|" << std::endl;
	}
	std::cout << "  ---------------------     ---------------------" << std::endl;

	//GoToXY(80, 1);
	//std::cout << "Корабли:\n";
	for (int i = 0; i < 10; i++) {
		//GoToXY(80, 2);
		std::cout << i << " " << ships[i] << std::endl;
	}

	//Временное поле для Бота

	//std::cout << "Временное поле бота!\n";
	//for (int i = 1; i < 11; i++) {
	//	if (i == 10) {
	//		std::cout << i << " ";
	//	}
	//	else
	//		std::cout << i << "  ";
	//	for (int b = 1; b <= 10; b++) {
	//		std::cout << botField[i][b] << " "; //меняем botField на playerField и видим второе своё поле
	//	}
	//	std::cout << "\b|" << std::endl;
	//}
};

void startMap(char playerField[10][10], char playerFireField[10][10], char botField[10][10]) {
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			playerField[i][j] = '.';
			playerFireField[i][j] = '.';
			botField[i][j] = '.';
		}
	}
}

void firePlayer(char playerField[10][10], char playerFireField[10][10], char botField[10][10], int shipId, int ships[10]) {
	while (true) {
		showMap(playerField, playerFireField, botField, shipId, ships);
		int y, x;
		char x1;

		do {
			y = 0;
			system("cls");
			showMap(playerField, playerFireField, botField, shipId, ships);
			try {
				std::string str;
				std::cout << "Введите координату по вертикали цифрой: " << std::endl;
				std::cin >> str;

				y = stoi(str);
				if (y < 1 || y > 10) {
					std::cout << "Не корректно введена координата, попробуйте ещё раз!" << std::endl;
					system("pause");
				}
				else
					break;
			}
			catch (const std::exception& ex) {
				std::string err = ex.what();
				if (err == "invalid stoi argument") {
					std::cout << "Не корректно введена координата, попробуйте ещё раз!" << std::endl;
					system("pause");
				}
			}
		} while (true);
		
		system("cls");
		showMap(playerField, playerFireField, botField, shipId, ships);
		do {
			std::cout << "Введите  координату выстрела по горизонтали буквой: " << std::endl;
			std::cin >> x1;
			if (x1 >= 'A' && x1 <= 'J')//от 65 до 74
				x = (int)(x1 - 64);
			else
				if (x1 >= 'a' && x1 <= 'j')//от 97 до 106
					x = (int)(x1 - 96);
				else {
					showMap(playerField, playerFireField, botField, shipId, ships);
					std::cout << "Не корректно введена координата, попробуйте ещё раз!" << std::endl;
				}
		} while (x1 != 'a' && x1 != 'A' &&
			x1 != 'b' && x1 != 'B' &&
			x1 != 'c' && x1 != 'C' &&
			x1 != 'd' && x1 != 'D' &&
			x1 != 'e' && x1 != 'E' &&
			x1 != 'f' && x1 != 'F' &&
			x1 != 'g' && x1 != 'G' &&
			x1 != 'h' && x1 != 'H' &&
			x1 != 'i' && x1 != 'I' &&
			x1 != 'j' && x1 != 'J');
			

		if (botField[y][x] == 'X' || botField[y][x] == '*') {
			std::cout << "Вы сюда уже стреляли, попробуйте ещё раз!\n";
			system("pause");
			continue;						//цикл запускается заново
		}
			


		if (botField[y][x] == '#' && playerFireField[y][x] != 'X') {
			playerFireField[y][x] = 'X';
			botField[y][x] = 'X';
			GoToXY(50, 11);
			std::cout << "Вы попали по кораблю!" << std::endl;
			GoToXY(50, 13);
			system("pause");
			if (botField[y - 1][x] != '#' && botField[y + 1][x] != '#' && botField[y][x - 1] != '#' && botField[y][x + 1] != '#') {
				GoToXY(50, 11);
				std::cout << "Вы потопили корабль!" << std::endl;
				GoToXY(50, 13);
				system("pause");
			}
			system("cls");
			showMap(playerField, playerFireField, botField, shipId, ships);
			checkFieldPlayer(playerField, playerFireField, botField, shipId, ships);
			firePlayer(playerField, playerFireField, botField, shipId, ships);
		}
		else {
			playerFireField[y][x] = '*';
			botField[y][x] = '*';
			GoToXY(50, 11);
			std::cout << "Вы промахнулись!" << std::endl;
			GoToXY(50, 13);
			system("pause");
			fireBot(playerField, playerFireField, botField, shipId, ships);		//переход хода
		}

	}
}//функция

void fireBot(char playerField[10][10], char playerFireField[10][10], char botField[10][10], int shipId, int ships[10]) {
	showMap(playerField, playerFireField, botField, shipId, ships);
	while (true) {
		int y = rand() % (11 - 1) + 1;
		int x = rand() % (11 - 1) + 1;
		if (playerField[y][x] == '#' && (playerField[y][x] != 'X' && playerField[y][x] != '*')) {
			playerField[y][x] = 'X';
			GoToXY(50, 11);
			std::cout << "Бот попал по вашему кораблю!" << y << " " << x << std::endl; // временно
			GoToXY(50, 13);
			system("pause");//Sleep(1000);
			if (playerField[y - 1][x] != '#' && playerField[y + 1][x] != '#' && playerField[y][x - 1] != '#' && playerField[y][x + 1] != '#') {
				system("cls");
				showMap(playerField, playerFireField, botField, shipId, ships);
				GoToXY(50, 11);
				std::cout << "Бот потопил ваш корабль!" << std::endl;
				GoToXY(50, 13);
				system("pause");//Sleep(1000);
			}
			system("cls");
			showMap(playerField, playerFireField, botField, shipId, ships);
			chekFieldBot(playerField, playerFireField, botField, shipId, ships);
			fireBot(playerField, playerFireField, botField, shipId, ships);
		}
		if (playerField[y][x] == '.' && (playerField[y][x] != 'X' && playerField[y][x] != '*')) {
			playerField[y][x] = '*';
			GoToXY(50, 11);
			std::cout << "Бот промахнулся!" << y << " " << x << std::endl;		//Временно
			GoToXY(50, 13);
			system("pause");//Sleep(1000);
			firePlayer(playerField, playerFireField, botField, shipId, ships);		//переход хода
		}
	}
}

void checkFieldPlayer(char playerField[10][10], char playerFireField[10][10], char botField[10][10], int shipId, int ships[10]) {
	int temp = 0;
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			if (botField[i][j] == 'X') temp++;
		}
	}
	if (temp == 20) {
		GoToXY(50, 13);
		std::cout << "Поздравляю!!! Вы уничтожили все корабли противника!\n\n";
		system("pause");
		system("cls");
		startMap(playerField, playerFireField, botField);		//очистка полей
		mainMenu(playerField, playerFireField, botField, shipId, ships);
	}
}

void chekFieldBot(char playerField[10][10], char playerFireField[10][10], char botField[10][10], int shipId, int ships[10]) {
	int temp = 0;
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			if (playerField[i][j] == 'X') temp++;
		}
	}
	if (temp == 20) {
		GoToXY(50, 13);
		std::cout << "Бот выиграл! Он уничтожил все ваши корабли!\n\n";
		system("pause");
		system("cls");
		startMap(playerField, playerFireField, botField);//очистка полей
		mainMenu(playerField, playerFireField, botField, shipId, ships);
	}
}

void GoToXY(short x, short y) {
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x, y });
}