#pragma once
#include <iostream>

//���������� ���� ���� � �������
void GoToXY(short x, short y);
//���������� �����
void startMap(char arr1[10][10], char arr2[10][10], char arr3[10][10]);
//�������� ����
void showMap(char arr1[10][10], char arr2[10][10], char arr3[10][10]);
//��������������� ��������
void enterCoordinateAuto(char field[10][10]);
//�������� ������
void firePlayer(char arr1[10][10], char arr2[10][10], char arr3[10][10]);
//�������� ����
void fireBot(char arr1[10][10], char arr2[10][10], char arr3[10][10]);

void manualPlace(char arr1[10][10], char arr2[10][10], char arr3[10][10]);

void enterCoordinate(char field1[10][10], char field2[10][10], char field3[10][10], int size, int kolvo);
//�������� ������ �� ������
void checkFieldPlayer(char field[10][10]);
//�������� ���� �� ������
void chekFieldBot(char field[10][10]);