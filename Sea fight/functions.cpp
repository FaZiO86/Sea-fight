#include <iostream>
#include "windows.h"
#include "functions.h"
#include <conio.h>
#include <time.h>
#include <ctime>


void manualPlace(char arr1[10][10], char arr2[10][10],char arr3[10][10]) { //������� �� ��������!
	int a =0, b = 0, c = 0, x;
	//showMap(arr1, arr2, arr3);
	GoToXY(50, 13);
	std::cout << "� ����� ������������ 4 ���� ��������.\n";
	std::cout << "����� �� ������ �� ���������� ������:\n\n";
	std::cout << "���� �������������� -> ������� 1\n";
	std::cout << "��� ����������� -> ������� 2\n";
	std::cout << "��� ����������� -> ������� 3\n";
	std::cout << "������ ������������ -> ������� 4\n";
	std::cin >> x;
	switch(x) {
	case 1: enterCoordinate(arr1, arr2, arr3, 4,1); break;
	case 2: enterCoordinate(arr1, arr2, arr3, 3,2); break;
	case 3: enterCoordinate(arr1, arr2, arr3, 2,3); break;
	case 4: enterCoordinate(arr1, arr2, arr3, 1,4); break;
	}
}

void enterCoordinate(char arr1[10][10], char arr2[10][10], char arr3[10][10], int size, int kolvo) {	//������� �� ��������!!!
	int a = 0, b = 0, dir = 0, x = 1; 
	startMap(arr1, arr2, arr3);
	enterCoordinateAuto(arr3);
	showMap(arr1, arr2, arr3);
	for (int i = 1; i <= kolvo;i++) {
		
		showMap(arr1, arr2, arr3);
		std::cout << "������� ���������� �� ��������� " << i << "-��� " << x << " -��������� �������: "; std::cin >> a;
		std::cout << "������� ���������� �� ����������� " << i << "-��� " << x << "-��������� �������: "; std::cin >> b;
		
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
			std::cout << "������ �����, ���������... " << std::endl;
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
	//��������������
	while (countShip < 1) {

		//������ �������
		x = rand() % 10;
		y = rand() % 10;

		int temp_x = x;
		int temp_y = y;

		//��������� �����������
		dir = rand() % 4;

		//�������� ����������� ���������� �������
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

			//��������� �������
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
	//�����������
	while (countShip < 3) {

		//������ �������
		x = rand() % 10;
		y = rand() % 10;

		int temp_x = x;
		int temp_y = y;

		//��������� �����������
		dir = rand() % 4;

		//�������� ����������� ���������� �������
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

			//��������� �������
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
	//������������
	while (countShip < 6) {

		//������ �������
		x = rand() % 10;
		y = rand() % 10;

		int temp_x = x;
		int temp_y = y;

		//��������� �����������
		dir = rand() % 4;

		//�������� ����������� ���������� �������
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

			//��������� �������
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
	//������������
	while (countShip < 10) {

		//������ �������
		x = rand() % 10;
		y = rand() % 10;

		int temp_x = x;
		int temp_y = y;

		//��������� �����������
		dir = rand() % 4;

		//�������� ����������� ���������� �������
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

			//��������� �������
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
													//��������� ����
void showMap(char arr1[10][10], char arr2[10][10], char arr3[10][10]) {
	system("CLS");
	std::cout << "\n      ���� �������  \t        ���� ��������  \n";
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
	//��������� ���� ��� ����

	std::cout << "��������� ���� ����!\n";
	for (int i = 1; i < 11; i++) {
		if (i == 10) {
			std::cout << i << " ";
		}
		else
			std::cout << i << "  ";
		for (int b = 1; b <= 10; b++) {
			std::cout << arr3[i][b] << " "; //������ arr3 �� arr1 � ����� ������ ��� ����
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
			std::cout << "������� ���������� �� ����������� ������: " << std::endl;
			std::cin >> y;
			if (y < 1 && y > 11)
				throw 0;
		}
		catch (const int ex[]) {
			if (ex == 0) {
				while (y < 1 && y > 11) {
					system("CLS");
					showMap(arr1, arr2, arr3);
					std::cout << "�� ��������� ������� ����������, ���������� ��� ���!" << std::endl;
					std::cin >> y;
				}
			}
		}
		
		
		std::cout << "�������  ���������� �������� �� ��������� ������: " << std::endl;
		std::cin >> x1;
		if (x1 >= 'A' && x1 <= 'J')//�� 65 �� 74
			x = (int)(x1 - 64);
			else
				if (x1 >= 'a' && x1 <= 'j')//�� 97 �� 106
					x = (int)(x1 - 96);
		if (x1 < 'A' && x1 > 'J' || x1 < 'a' && x1 > 'j') {
			system("CLS");
			showMap(arr1, arr2, arr3);
			std::cout << "�� ��������� ������� ����������, ���������� ��� ���!" << std::endl;
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
		//	std::cout << "�� ��������� ������� ����������, ���������� ��� ���!" << std::endl;
		//	std::cin >> x1;
		//}
		
				

		if (arr3[y][x] == '#' && arr2[y][x] != 'X') {
			arr2[y][x] = 'X';
			arr3[y][x] = 'X';
			GoToXY(50, 11);
			std::cout << "�� ������ �� �������!" << std::endl;
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
			std::cout << "�� �������� �������!" << std::endl;
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
				std::cout << "�� ������������!" << std::endl;
				GoToXY(50, 13);
				system("pause");
				fireBot(arr1, arr2, arr3);		//������� ����
			}
		
	}
}//�������

void fireBot(char arr1[10][10], char arr2[10][10], char arr3[10][10]) {
	showMap(arr1, arr2, arr3);
	while (true) {
		int y = rand() % 10 + 1;
		int x = rand() % 10 + 1;
		if (arr1[y][x] == '#' && arr1[y][x] != 'X' && arr1[y][x] != '*') {
			arr1[y][x] = 'X';
			GoToXY(50, 11);
			std::cout << "��� ����� �� ������ �������!" << std::endl;
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
				std::cout << "��� ������� ��� �������!" << std::endl;
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
			std::cout << "��� �����������!" << std::endl;
			GoToXY(50, 13);
			Sleep(1000);
			firePlayer(arr1, arr2, arr3);		//������� ����
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
		std::cout << "����������!!! �� ���������� ��� ������� ����������!\n\n";
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
		std::cout << "��� �������! �� ��������� ��� ���� �������!\n\n";
		system("pause");
		exit(0);
	}
}

void GoToXY(short x, short y) {
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x, y });
}