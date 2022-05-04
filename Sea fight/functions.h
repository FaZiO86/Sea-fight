#pragma once
#include <iostream>

//������� ����
void mainMenu(char playerField[10][10], char playerFireField[10][10], char botField[10][10], int shipId, int ships[10]);

//���� ����������� ��������
void manualMenu(char playerField[10][10], char playerFireField[10][10], char botField[10][10], int shipId, int ships[10]);

//���������� ���� ���� � �������
void GoToXY(short x, short y);

//���������� �����
void startMap(char playerField[10][10], char playerFireField[10][10], char botField[10][10]);

//�������� ����
void showMap(char playerField[10][10], char playerFireField[10][10], char botField[10][10], int shipId, int ships[10]);

//��������������� ��������
void enterCordinateAuto(char playerField[10][10], char playerFireField[10][10], char botField[10][10], int shipId, int ships[10]);

//�������� ������
void firePlayer(char playerField[10][10], char playerFireField[10][10], char botField[10][10], int shipId, int ships[10]);

//�������� ����
void fireBot(char playerField[10][10], char playerFireField[10][10], char botField[10][10], int shipId, int ships[10]);

void enterCordinate(char playerField[10][10], char playerFireField[10][10], char botField[10][10], int size, int kolvo, int shipId, int ships[10]);

//�������� ������ �� ������
void checkFieldPlayer(char playerField[10][10], char playerFireField[10][10], char botField[10][10]);

//�������� ���� �� ������
void chekFieldBot(char playerField[10][10], char playerFireField[10][10], char botField[10][10]);

//��������������� ��������� �������
void enterShipAuto(char field[10][10], int size, int kolvo, int shipId, int ships[10]);