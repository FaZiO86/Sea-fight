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
	SetConsoleTitle(L"������� ���");
	
	int shipId = 0;
	int ships[10] = {0};
	

	char playerField[10][10];
	char playerFireField[10][10];
	char botField[10][10];
	

	mainMenu(playerField, playerFireField, botField, shipId, ships);
	//� ������� shipId � ������� ships ���� ����������� ������� ��������, 
	//����� 10 ����, � � ������� ����� �������� ����������� ��� ��, 
	//����������� ��������, 2-� 3-� � �.�. � ��� �� ��� �� �������, 
	//��� �� ����� ���������� ������� �� ��������� ����������, �� � � ������, �� ���������� ������ �� ���������!
	
	

	
}