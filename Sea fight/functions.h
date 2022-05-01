#pragma once
#include <iostream>
//Главное меню
void mainMenu(char playerField[10][10], char playerFireField[10][10], char botField[10][10]);
//меню расстановки кораблей
void manualMenu(char playerField[10][10], char playerFireField[10][10], char botField[10][10]);
//размещение чего либо в консоли
void GoToXY(short x, short y);
//построение полей
void startMap(char arr1[10][10], char arr2[10][10], char arr3[10][10]);
//показать поля
void showMap(char arr1[10][10], char arr2[10][10], char arr3[10][10]);
//авторасстановка кораблей
void enterCoordinateAuto(char field[10][10]);
//Выстрелы игрока
void firePlayer(char arr1[10][10], char arr2[10][10], char arr3[10][10]);
//Стрельба бота
void fireBot(char arr1[10][10], char arr2[10][10], char arr3[10][10]);

//void manualPlace(char arr1[10][10], char arr2[10][10], char arr3[10][10]);

void enterCoordinateManual(char player[10][10], char bot[10][10]);

//void enterCoordinate(char field1[10][10], char field2[10][10], char field3[10][10], int size, int kolvo);
//Проверка игрока на победу
void checkFieldPlayer(char playerField[10][10], char playerFireField[10][10], char botField[10][10]);
//Проверка бота на победу
void chekFieldBot(char playerField[10][10], char playerFireField[10][10], char botField[10][10]);