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
	
	int shipId = 0;
	int ships[10] = {0};
	

	char playerField[10][10];
	char playerFireField[10][10];
	char botField[10][10];
	

	mainMenu(playerField, playerFireField, botField, shipId, ships);
	//с помощью shipId и массива ships хочу реализовать счётчик кораблей, 
	//всего 10 штук, и с помощью этого счётчика реализовать как то, 
	//расстановку кораблей, 2-х 3-х и т.д. а так же как то сделать, 
	//что бы после потопления корабля он обводился звёздочками, но я в тупике, не получается ничего со счётчиком!
	
	

	
}