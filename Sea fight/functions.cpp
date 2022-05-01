#include <iostream>
#include "windows.h"
#include "functions.h"
#include <conio.h>
#include <time.h>
#include <ctime>

#define up 72
#define down 80
#define right 77
#define left 75
#define enter 13
#define esc 27

/*
void manualPlace(char arr1[10][10], char arr2[10][10],char arr3[10][10]) { //функция не доделана!
	int a =0, b = 0, c = 0, x;
	//showMap(arr1, arr2, arr3);
	GoToXY(50, 13);
	std::cout << "В вашем распоряжении 4 вида кораблей.\n";
	std::cout << "Какие вы хотели бы установить первые:\n\n";
	std::cout << "Один четырёхпалубный -> нажмите 1\n";
	std::cout << "Два трёхпалубных -> нажмите 2\n";
	std::cout << "Три трёхпалубных -> нажмите 3\n";
	std::cout << "Четыре однопалубных -> нажмите 4\n";
	std::cin >> x;
	switch(x) {
	case 1: enterCoordinate(arr1, arr2, arr3, 4,1); break;
	case 2: enterCoordinate(arr1, arr2, arr3, 3,2); break;
	case 3: enterCoordinate(arr1, arr2, arr3, 2,3); break;
	case 4: enterCoordinate(arr1, arr2, arr3, 1,4); break;
	}
}
*/
/*void enterCoordinate(char arr1[10][10], char arr2[10][10], char arr3[10][10], int size, int kolvo) {	//функция не доделана!!!
	int a = 0, b = 0, dir = 0, x = 1;
	startMap(arr1, arr2, arr3);
	enterCoordinateAuto(arr3);
	showMap(arr1, arr2, arr3);
	for (int i = 1; i <= kolvo;i++) {

		showMap(arr1, arr2, arr3);
		std::cout << "Введите координату по вертикали " << i << "-ого " << x << " -палубного корабля: "; std::cin >> a;
		std::cout << "Введите координату по горизонтали " << i << "-ого " << x << "-палубного корабля: "; std::cin >> b;

		if (arr1[a + 1][b] != '#' &&
			arr1[a + 1][b + 1] != '#' &&
			arr1[a + 1][b - 1] != '#' &&
			arr1[a - 1][b - 1] != '#' &&
			arr1[a - 1][b + 1] != '#' &&
			arr1[a - 1][b] != '#' &&
			arr1[a][b - 1] != '#' &&
			arr1[a][b + 1] != '#' &&
			arr1[a][b] != '#' &&
			dir == 0) {
			arr1[a][b] = '#';
		}
		/*else if
			(dir != 0 && (arr1[a + 1][b] == '#' ||
				arr1[a][b - 1] == '#' ||
				arr1[a][b + 1] == '#'
				|| arr1[a - 1][b - 1] == '#') && (arr1[a + 1][b + 1] != '#' || arr1[a + 1][b - 1] != '#' || arr1[a - 1][b + 1] != '#'
					|| arr1[a - 1][b - 1] != '#')) {
			int temp = 0;
			if (arr1[a + 1][b] == '#') temp++;
			if (arr1[a - 1][b] == '#') temp++;
			if (arr1[a][b + 1] == '#') temp++;
			if (arr1[a][b - 1] == '#') temp++;
			if (temp == 1)	arr1[a][b] = '#';
		}
		else std::cout << "Error Check Field, illegal number or field, retry " << std::endl;
		dir++;
		if (arr1[a][b] == '#') {
			std::cout << "Your " << x << "-pointed ship: [" << a << "][" << b << "]" << std::endl;
			showMap(arr1, arr2, arr3);
			if ((dir == x) && (dir != 4)) std::cout << "Good, next ship " << std::endl;
			else if (dir == 4) std::cout << "Ok, lets play ! " << std::endl;
			else enterCoordinate(arr1, arr2, arr3, a, b, size, kolvo);
		}* /
		else {
			std::cout << "Ошибка ввода, повторите... " << std::endl;
			kolvo--;
			enterCoordinate(arr1, arr2, arr3, size, kolvo);
		}
	}
	showMap(arr1, arr2, arr3);
	if (kolvo == 4)
		manualPlace(arr1,arr2,arr3);
}*/

void mainMenu(char playerField[10][10], char playerFireField[10][10], char botField[10][10]) {
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
				enterCoordinateAuto(playerField);
				std::cout << "Ваши корабли расставлены!";
				Sleep(1500);
				system("cls");
				GoToXY(x, y);
				std::cout << "Ждём расстановку бота!";
				Sleep(1500);
				system("cls");
				GoToXY(x, y);
				enterCoordinateAuto(botField);
				std::cout << "Все корабли расставлены, нажмите enter, что бы продолжить...";
				ch = _getch();
				system("cls");
				break;
			case 1:
				manualMenu(playerField, playerFireField, botField);
				ch = _getch();
				system("cls");
				break;

			case 2:
				system("cls");
				GoToXY(x, y);
				a = rand() % 2;
				switch (a) {
				case 0: std::cout << "Вы ходите первым!\n\t\t\t\t\t\t"; system("pause"); firePlayer(playerField, playerFireField, botField); break;
				case 1:	std::cout << "Бот ходит первым!\n\t\t\t\t\t\t"; system("pause"); fireBot(playerField, playerFireField, botField); break;
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

void manualMenu(char playerField[10][10], char playerFireField[10][10], char botField[10][10]) {
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
			case 0: std::cout << "4"; ch = _getch(); break;
			case 1:std::cout << "3"; ch = _getch(); break;
			case 2:std::cout << "2"; ch = _getch(); break;
			case 3:std::cout << "1"; ch = _getch(); break;
			case 4: system("cls"); mainMenu(playerField, playerFireField, botField); break;
			}
		}
	}
}

void enterCoordinateManual(char player[10][10], char bot[10][10]) {

}

void enterCoordinateAuto(char field[10][10]) {
	srand(time(NULL));

	int countShip = 0, x, y, dir;
	//Четырёхпалубный
	while (countShip < 1) {

		//первая позиция
		x = rand() % 10;
		y = rand() % 10;

		int temp_x = x;
		int temp_y = y;

		//случайное направление
		dir = rand() % 4;

		//проверка возможности постановки корабля
		bool isPoss = 1;
		for (int i = 1; i <= 4; i++) {
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
				isPoss = 0;
				break;
			}
			switch (dir) {
			case 0: x++; break;
			case 1: y++; break;
			case 2: x--; break;
			case 3: y--; break;
			}
		}
		if (isPoss == 1) {

			x = temp_x;
			y = temp_y;

			//установка корабля
			for (int i = 1; i <= 4; i++) {
				field[x][y] = '#';
				switch (dir) {
				case 0: x++; break;
				case 1: y++; break;
				case 2: x--; break;
				case 3: y--; break;
				}
			}
			countShip++;
		}
	}
	//трёхпалубный
	while (countShip < 3) {

		//первая позиция
		x = rand() % 10;
		y = rand() % 10;

		int temp_x = x;
		int temp_y = y;

		//случайное направление
		dir = rand() % 4;

		//проверка возможности постановки корабля
		bool isPoss = 1;
		for (int i = 1; i <= 3; i++) {
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
				isPoss = 0;
				break;
			}
			switch (dir) {
			case 0: x++; break;
			case 1: y++; break;
			case 2: x--; break;
			case 3: y--; break;
			}
		}
		if (isPoss == 1) {

			x = temp_x;
			y = temp_y;

			//установка корабля
			for (int i = 1; i <= 3; i++) {
				field[x][y] = '#';
				switch (dir) {
				case 0: x++; break;
				case 1: y++; break;
				case 2: x--; break;
				case 3: y--; break;
				}
			}
			countShip++;
		}

	}
	//двухпалубные
	while (countShip < 6) {

		//первая позиция
		x = rand() % 10;
		y = rand() % 10;

		int temp_x = x;
		int temp_y = y;

		//случайное направление
		dir = rand() % 4;

		//проверка возможности постановки корабля
		bool isPoss = 1;
		for (int i = 0; i < 2; i++) {
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
				isPoss = 0;
				break;
			}
			switch (dir) {
			case 0: x++; break;
			case 1: y++; break;
			case 2: x--; break;
			case 3: y--; break;
			}
		}
		if (isPoss == 1) {

			x = temp_x;
			y = temp_y;

			//установка корабля
			for (int i = 0; i < 2; i++) {
				field[x][y] = '#';
				switch (dir) {
				case 0: x++; break;
				case 1: y++; break;
				case 2: x--; break;
				case 3: y--; break;
				}
			}
			countShip++;
		}
	}
	//Однопалубный
	while (countShip < 10) {

		//первая позиция
		x = rand() % 10;
		y = rand() % 10;

		int temp_x = x;
		int temp_y = y;

		//случайное направление
		dir = rand() % 4;

		//проверка возможности постановки корабля
		bool isPoss = 1;
		for (int i = 0; i < 1; i++) {
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
				isPoss = 0;
				break;
			}
			switch (dir) {
			case 0: x++; break;
			case 1: y++; break;
			case 2: x--; break;
			case 3: y--; break;
			}
		}
		if (isPoss == 1) {

			x = temp_x;
			y = temp_y;

			//установка корабля
			field[x][y] = '#';
			switch (dir) {
			case 0: x++; break;
			case 1: y++; break;
			case 2: x--; break;
			case 3: y--; break;
			}
			countShip++;
		}
	}
}
													//временное поле
void showMap(char arr1[10][10], char arr2[10][10], char arr3[10][10]) {
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
			std::cout << arr1[i][j] << " ";
		}

		std::cout << "\b|   ";
		if (i == 10) {
			std::cout << i << "|";
		}
		else
			std::cout << i << " |";
		for (int k = 1; k < 11; k++) {
			std::cout << arr2[i][k] << " ";
		}
		std::cout << "\b|" << std::endl;
	}
	std::cout << "  ---------------------     ---------------------" << std::endl;
	//Временное поле для Бота

	std::cout << "Временное поле бота!\n";
	for (int i = 1; i < 11; i++) {
		if (i == 10) {
			std::cout << i << " ";
		}
		else
			std::cout << i << "  ";
		for (int b = 1; b <= 10; b++) {
			std::cout << arr3[i][b] << " "; //меняем arr3 на arr1 и видим второе своё поле
		}
		std::cout << "\b|" << std::endl;
	}
};

void startMap(char arr1[10][10], char arr2[10][10], char arr3[10][10]) {
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			arr1[i][j] = '.';
			arr2[i][j] = '.';
			arr3[i][j] = '.';
		}
	}
}

void firePlayer(char playerField[10][10], char playerFireField[10][10], char botField[10][10]) {
	while (true) {
		showMap(playerField, playerFireField, botField);
		int y, x;
		char x1;
		std::cout << "Введите координату по горизонтали цифрой: " << std::endl;
		std::cin >> y;
		while (y < 1 && y > 11) {//не работает
			showMap(playerField, playerFireField, botField);
			std::cout << "Не корректно введена координата, попробуйте ещё раз!" << std::endl;
			std::cin >> y;
		}
		system("cls");
		showMap(playerField, playerFireField, botField);
		std::cout << "Введите  координату выстрела по вертикали буквой: " << std::endl;
		std::cin >> x1;
		while (x1 != 'a' && x1 != 'A' &&
			x1 != 'b' && x1 != 'B' &&
			x1 != 'c' && x1 != 'C' &&
			x1 != 'd' && x1 != 'D' &&
			x1 != 'e' && x1 != 'E' &&
			x1 != 'f' && x1 != 'F' &&
			x1 != 'g' && x1 != 'G' &&
			x1 != 'h' && x1 != 'H' &&
			x1 != 'i' && x1 != 'I' &&
			x1 != 'j' && x1 != 'J') {
			showMap(playerField, playerFireField, botField);
			std::cout << "Не корректно введена координата, попробуйте ещё раз!" << std::endl;
			std::cin >> x1;
		}
		if (x1 >= 'A' && x1 <= 'J')//от 65 до 74
			x = (int)(x1 - 64);
		else
			if (x1 >= 'a' && x1 <= 'j')//от 97 до 106
				x = (int)(x1 - 96);




		if (botField[y][x] == '#' && playerFireField[y][x] != 'X') {
			playerFireField[y][x] = 'X';
			botField[y][x] = 'X';
			GoToXY(50, 11);
			std::cout << "Вы попали по кораблю!" << std::endl;
			GoToXY(50, 13);
			system("pause");
			if (botField[y - 1][x] != '#' && botField[y + 1][x] != '#' && botField[y][x - 1] != '#' && botField[y][x + 1] != '#') {
				//arr2[y + 1][x + 1] = '*';
				//arr2[y + 1][x - 1] = '*';
				//arr2[y + 1][x] = '*';
				//arr2[y - 1][x + 1] = '*';
				//arr2[y - 1][x - 1] = '*';
				//arr2[y - 1][x] = '*';
				//arr2[y][x + 1] = '*';
				//arr2[y][x - 1] = '*';
				GoToXY(50, 11);
				std::cout << "Вы потопили корабль!" << std::endl;
				GoToXY(50, 13);
				system("pause");
			}
			/*
			if (arr2[y + 1][x + 1] == '.')  arr2[y + 1][x + 1] = '*';
			if (arr2[y + 1][x - 1] == '.')  arr2[y + 1][x - 1] = '*';
			if (arr2[y + 1][x] == '.')      arr2[y + 1][x] = '*';
			if (arr2[y - 1][x + 1] == '.')  arr2[y - 1][x + 1] = '*';
			if (arr2[y - 1][x - 1] == '.')  arr2[y - 1][x - 1] = '*';
			if (arr2[y - 1][x] == '.')      arr2[y - 1][x] = '*';
			if (arr2[y][x + 1] == '.')      arr2[y][x + 1] = '*';
			if (arr2[y][x - 1] == '.')      arr2[y][x - 1] = '*';
			*/
			system("cls");
			showMap(playerField, playerFireField, botField);
			checkFieldPlayer(playerField, playerFireField, botField);
			firePlayer(playerField, playerFireField, botField);
		}
		else {
			playerFireField[y][x] = '*';
			botField[y][x] = '*';
			GoToXY(50, 11);
			std::cout << "Вы промахнулись!" << std::endl;
			GoToXY(50, 13);
			system("pause");
			fireBot(playerField, playerFireField, botField);		//переход хода
		}

	}
}//функция

void fireBot(char playerField[10][10], char playerFireField[10][10], char botField[10][10]) {
	showMap(playerField, playerFireField, botField);
	while (true) {
		int y = rand() % (11 - 1) + 1;
		int x = rand() % (11 - 1) + 1;
		if (playerField[y][x] == '#' && (playerField[y][x] != 'X' || playerField[y][x] != '*')) {
			playerField[y][x] = 'X';
			GoToXY(50, 11);
			std::cout << "Бот попал по вашему кораблю!" << y << " " << x << std::endl; // временно
			GoToXY(50, 13);
			system("pause");//Sleep(1000);
			if (playerField[y - 1][x] != '#' && playerField[y + 1][x] != '#' && playerField[y][x - 1] != '#' && playerField[y][x + 1] != '#') {
				//arr2[y + 1][x + 1] = '*';
				//arr2[y + 1][x - 1] = '*';
				//arr2[y + 1][x] = '*';
				//arr2[y - 1][x + 1] = '*';
				//arr2[y - 1][x - 1] = '*';
				//arr2[y - 1][x] = '*';
				//arr2[y][x + 1] = '*';
				//arr2[y][x - 1] = '*';
				system("cls");
				showMap(playerField, playerFireField, botField);
				GoToXY(50, 11);
				std::cout << "Бот потопил ваш корабль!" << std::endl;
				GoToXY(50, 13);
				system("pause");//Sleep(1000);
			}
			/*
			if (arr2[y + 1][x + 1] == '.')  arr2[y + 1][x + 1] = '*';
			if (arr2[y + 1][x - 1] == '.')  arr2[y + 1][x - 1] = '*';
			if (arr2[y + 1][x] == '.')      arr2[y + 1][x] = '*';
			if (arr2[y - 1][x + 1] == '.')  arr2[y - 1][x + 1] = '*';
			if (arr2[y - 1][x - 1] == '.')  arr2[y - 1][x - 1] = '*';
			if (arr2[y - 1][x] == '.')      arr2[y - 1][x] = '*';
			if (arr2[y][x + 1] == '.')      arr2[y][x + 1] = '*';
			if (arr2[y][x - 1] == '.')      arr2[y][x - 1] = '*';
			*/
			system("cls");
			showMap(playerField, playerFireField, botField);
			chekFieldBot(playerField, playerFireField, botField);
			fireBot(playerField, playerFireField, botField);
		}
		if (playerField[y][x] == '.' && (playerField[y][x] != 'X' || playerField[y][x] != '*')) {
			playerField[y][x] = '*';
			GoToXY(50, 11);
			std::cout << "Бот промахнулся!" << y << " " << x << std::endl;		//Временно
			GoToXY(50, 13);
			system("pause");//Sleep(1000);
			firePlayer(playerField, playerFireField, botField);		//переход хода
		}
	}
}

void checkFieldPlayer(char playerField[10][10], char playerFireField[10][10], char botField[10][10]) {
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
		startMap(playerField, playerFireField, botField);
		mainMenu(playerField, playerFireField, botField);
	}
}

void chekFieldBot(char playerField[10][10], char playerFireField[10][10], char botField[10][10]) {
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
		mainMenu(playerField, playerFireField, botField);
	}
}

void GoToXY(short x, short y) {
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x, y });
}