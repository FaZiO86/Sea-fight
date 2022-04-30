#include <iostream>
#include "windows.h"
#include "functions.h"
#include <conio.h>
#include <time.h>
#include <ctime>


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

void enterCoordinate(char arr1[10][10], char arr2[10][10], char arr3[10][10], int size, int kolvo) {	//функция не доделана!!!
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
		}*/
		else {
			std::cout << "Ошибка ввода, повторите... " << std::endl;
			kolvo--;
			enterCoordinate(arr1, arr2, arr3, size, kolvo);
		}
	}
	showMap(arr1, arr2, arr3);
	if (kolvo == 4)
		manualPlace(arr1,arr2,arr3);
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

			if (field[x    ][y] == '#' ||
				field[x    ][y + 1] == '#' ||
				field[x    ][y - 1] == '#' ||
				field[x + 1][y    ] == '#' ||
				field[x + 1][y + 1] == '#' ||
				field[x + 1][y - 1] == '#' ||
				field[x - 1][y    ] == '#' ||
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

void firePlayer(char arr1[10][10], char arr2[10][10], char arr3[10][10]) {
	while (true) {
		showMap(arr1, arr2, arr3);
		int y, x = 0;
		char x1;
		try {
			std::cout << "Введите координату по горизонтали цифрой: " << std::endl;
			std::cin >> y;
			if (y < 1 && y > 11)
				throw 0;
		}
		catch (const int ex[]) {
			if (ex == 0) {
				while (y < 1 && y > 11) {
					system("CLS");
					showMap(arr1, arr2, arr3);
					std::cout << "Не корректно введена координата, попробуйте ещё раз!" << std::endl;
					std::cin >> y;
				}
			}
		}
		
		
		std::cout << "Введите  координату выстрела по вертикали буквой: " << std::endl;
		std::cin >> x1;
		if (x1 >= 'A' && x1 <= 'J')//от 65 до 74
			x = (int)(x1 - 64);
			else
				if (x1 >= 'a' && x1 <= 'j')//от 97 до 106
					x = (int)(x1 - 96);
		if (x1 < 'A' && x1 > 'J' || x1 < 'a' && x1 > 'j') {
			system("CLS");
			showMap(arr1, arr2, arr3);
			std::cout << "Не корректно введена координата, попробуйте ещё раз!" << std::endl;
			std::cin >> x1;
		}

		//while (x1 != 'a' && x1 != 'A' &&
		//	x1 != 'b' && x1 != 'B' &&
		//	x1 != 'c' && x1 != 'C' &&
		//	x1 != 'd' && x1 != 'D' &&
		//	x1 != 'e' && x1 != 'E' &&
		//	x1 != 'f' && x1 != 'F' &&
		//	x1 != 'g' && x1 != 'G' &&
		//	x1 != 'h' && x1 != 'H' &&
		//	x1 != 'i' && x1 != 'I' &&
		//	x1 != 'j' && x1 != 'J') {
		//	system("CLS");
		//	showMap(arr1, arr2, arr3);
		//	std::cout << "Не корректно введена координата, попробуйте ещё раз!" << std::endl;
		//	std::cin >> x1;
		//}
		
				

		if (arr3[y][x] == '#' && arr2[y][x] != 'X') {
			arr2[y][x] = 'X';
			arr3[y][x] = 'X';
			GoToXY(50, 11);
			std::cout << "Вы попали по кораблю!" << std::endl;
			GoToXY(50, 13);
			system("pause");
		if (arr3[y - 1][x] != '#' && arr3[y + 1][x] != '#' && arr3[y][x - 1] != '#' && arr3[y][x + 1] != '#') {
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
			showMap(arr1, arr2, arr3);
			checkFieldPlayer(arr3);
			firePlayer(arr1, arr2, arr3);
		}
			else{
				arr2[y][x] = '*';
				arr3[y][x] = '*';
				GoToXY(50, 11);
				std::cout << "Вы промахнулись!" << std::endl;
				GoToXY(50, 13);
				system("pause");
				fireBot(arr1, arr2, arr3);		//переход хода
			}
		
	}
}//функция

void fireBot(char arr1[10][10], char arr2[10][10], char arr3[10][10]) {
	showMap(arr1, arr2, arr3);
	while (true) {
		int y = rand() % 10 + 1;
		int x = rand() % 10 + 1;
		if (arr1[y][x] == '#' && arr1[y][x] != 'X' && arr1[y][x] != '*') {
			arr1[y][x] = 'X';
			GoToXY(50, 11);
			std::cout << "Бот попал по вашему кораблю!" << std::endl;
			GoToXY(50, 13);
			Sleep(1000);
			if (arr1[y - 1][x] != '#' && arr1[y + 1][x] != '#' && arr1[y][x - 1] != '#' && arr1[y][x + 1] != '#') {
				//arr2[y + 1][x + 1] = '*';
				//arr2[y + 1][x - 1] = '*';
				//arr2[y + 1][x] = '*';
				//arr2[y - 1][x + 1] = '*';
				//arr2[y - 1][x - 1] = '*';
				//arr2[y - 1][x] = '*';
				//arr2[y][x + 1] = '*';
				//arr2[y][x - 1] = '*';
				GoToXY(50, 11);
				std::cout << "Бот потопил ваш корабль!" << std::endl;
				GoToXY(50, 13);
				Sleep(1000);
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
			showMap(arr1, arr2, arr3);
			chekFieldBot(arr1);
			fireBot(arr1, arr2, arr3);
		}
		else {
			arr1[y][x] = '*';
			GoToXY(50, 11);
			std::cout << "Бот промахнулся!" << std::endl;
			GoToXY(50, 13);
			Sleep(1000);
			firePlayer(arr1, arr2, arr3);		//переход хода
		}
	}
}

void checkFieldPlayer(char field[10][10]) {
	int temp = 0;
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			if (field[i][j] == 'X') temp++;
		}
	}
	if (temp == 20) {
		GoToXY(50, 13);
		std::cout << "Поздравляю!!! Вы уничтожили все корабли противника!\n\n";
		system("pause");
		exit(0);
	}
}

void chekFieldBot(char field[10][10]) {
	int temp = 0;
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			if (field[i][j] == 'X') temp++;
		}
	}
	if (temp == 20) {
		GoToXY(50, 13);
		std::cout << "Бот выиграл! Он уничтожил все ваши корабли!\n\n";
		system("pause");
		exit(0);
	}
}

void GoToXY(short x, short y) {
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x, y });
}