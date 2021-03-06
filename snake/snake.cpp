// snake.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#define UP_KEY 72
#define DOWN_KEY 80
#define RIGHT_KEY 77
#define LEFT_KEY 75

using namespace std;

void startGame();
int Game();
void spawnMatrix();
char mapMatrix[24][64];
void snake();
int head_x = 1, head_y = 1, temp_x, temp_y, _x,_y;
char dir;
void movement();
void turnPoint();
void snake_eat();



int main()
{
	startGame();
    return 0;
}

void startGame() {
	cout << "SNAKE" << endl;
	cout << "1. Game start" << endl;
	cout << "2. Leaderboard" << endl;
	char ch = _getch();
	switch (ch) {
	case '1':
		Game();
		break;
	case '2':
		break;
	}
}

int Game() {
	system("cls");
	mapMatrix[1][1] = char(219);
	spawnMatrix();
	return 0;
}

void spawnMatrix() {
	system("cls");
	for (int i = 1; i < 63; i++) {
		mapMatrix[0][i] = char(205);
		mapMatrix[23][i] = char(205);
	}
	for (int i = 1; i < 23; i++) {
		mapMatrix[i][0] = char(186);
		mapMatrix[i][63] = char(186);
	}
	mapMatrix[0][0] = char(201);
	mapMatrix[0][63] = char(187);
	mapMatrix[23][0] = char(200);
	mapMatrix[23][63] = char(188);
	for (int i = 0; i < 24; i++) {
		for (int j = 0; j < 64; j++) {
			cout << mapMatrix[i][j];
		}
		cout << endl;
	}
	snake();
}

void snake() {
	dir = _getch();
	movement();
}

void movement() {
	switch (dir) {
	case char(UP_KEY) :
		temp_y = head_y;
		head_y = head_y - 1;
		break;
	case char(DOWN_KEY) :
		temp_y = head_y;
		head_y = head_y + 1;
		break;
	case char(LEFT_KEY) :
		temp_x = head_x;
		head_x = head_x - 1;
		break;
	case char(RIGHT_KEY) :
		temp_x = head_x;
		head_x = head_x + 1;
		break;
	}
	snake_eat();
	turnPoint();
	spawnMatrix();
}

void turnPoint() {
	if(mapMatrix[head_y][head_x]=='0')
	mapMatrix[head_y][head_x] = char(219);
	mapMatrix[temp_y][temp_x] = '\0';
t_p:
	if (mapMatrix[temp_y - 1][temp_x] == char(219) && dir != char(UP_KEY)) {
		mapMatrix[temp_y][temp_x] == char(219);
		mapMatrix[temp_y - 1][temp_x] = '\0';
		temp_y = temp_y - 1;
		goto t_p;
	}
	else if (mapMatrix[temp_y + 1][temp_x] == char(219) && dir != char(DOWN_KEY)) {
		mapMatrix[temp_y][temp_x] == char(219);
		mapMatrix[temp_y + 1][temp_x] = '\0';
		temp_y = temp_y + 1;
		goto t_p;
	}
	else if (mapMatrix[temp_y][temp_x-1] == char(219) && dir != char(LEFT_KEY)) {
		mapMatrix[temp_y][temp_x] == char(219);
		mapMatrix[temp_y][temp_x-1] = '\0';
		temp_x = temp_x - 1;
		goto t_p;
	}
	else if (mapMatrix[temp_y][temp_x + 1] == char(219) && dir != char(RIGHT_KEY)) {
		mapMatrix[temp_y][temp_x] == char(219);
		mapMatrix[temp_y][temp_x + 1] = '\0';
		temp_x = temp_x + 1;
		goto t_p;
	}
}

void snake_eat() {
	if (mapMatrix[head_y][head_x] == '0')
}