#include <iostream>
#include "windows.h"
#include "functions.h"
//#include <conio.h>
//#include <time.h>
//#include <ctime>


using namespace std;






int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleTitle(L"Морской бой");
	
	//int shipId = 0;
	//int ships[10] = {0};
	

	char playerField[10][10];
	char playerFireField[10][10];
	char botField[10][10];
	
	
	mainMenu(playerField, playerFireField, botField);
	
	
	

	
}