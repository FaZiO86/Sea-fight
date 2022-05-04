#pragma once
#include <iostream>

//Главное меню
void mainMenu(char playerField[10][10], char playerFireField[10][10], char botField[10][10], int shipId, int ships[10]);

//меню расстановки кораблей
void manualMenu(char playerField[10][10], char playerFireField[10][10], char botField[10][10], int shipId, int ships[10]);

//размещение чего либо в консоли
void GoToXY(short x, short y);

//построение полей
void startMap(char playerField[10][10], char playerFireField[10][10], char botField[10][10]);

//показать поля
void showMap(char playerField[10][10], char playerFireField[10][10], char botField[10][10], int shipId, int ships[10]);

//авторасстановка кораблей
void enterCordinateAuto(char playerField[10][10], char playerFireField[10][10], char botField[10][10], int shipId, int ships[10]);

//Выстрелы игрока
void firePlayer(char playerField[10][10], char playerFireField[10][10], char botField[10][10], int shipId, int ships[10]);

//Стрельба бота
void fireBot(char playerField[10][10], char playerFireField[10][10], char botField[10][10], int shipId, int ships[10]);

void enterCordinate(char playerField[10][10], char playerFireField[10][10], char botField[10][10], int size, int kolvo, int shipId, int ships[10]);

//Проверка игрока на победу
void checkFieldPlayer(char playerField[10][10], char playerFireField[10][10], char botField[10][10]);

//Проверка бота на победу
void chekFieldBot(char playerField[10][10], char playerFireField[10][10], char botField[10][10]);

//Автомматическая установка корабля
void enterShipAuto(char field[10][10], int size, int kolvo, int shipId, int ships[10]);