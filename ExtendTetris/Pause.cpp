#pragma once

#include "Pause.h"
#include "func.h"

#include <conio.h>
#include <iostream>

#define PLAY 0
#define EXIT 1

#define UP 72
#define DOWN 80
#define SELEC 13

using namespace std;

clock_t Pause::print_pause()
{
	system("cls");
	clock_t pause_s = clock();

	char b0[4] = { "　" }; 
	char b1[4] = { "□" }; //-1, 테두리
	char b2[4] = { "■" }; //-2, pause 글씨

	//테두리
	for (int i = 0; i < 17; i++) {
		for (int j = 0; j < 32; j++) {
			if (i == 0 or i == 16 or j == 0 or j == 31) {
				pause[j][i] = -1;
			}
			else {
				pause[j][i] = 9;
			}
		}
	}

	//pause 글씨
	int p[13][2] = { {4, 3}, {5, 3}, {6, 3}, {7, 3}, {4, 4}, {7, 4}, {4, 5}, {5, 5}, {6, 5}, {7, 5}, {4, 6}, {4, 7}, {4, 8} };
	int a[16][2] = { {9, 3}, {10, 3}, {11, 3}, {12, 3}, {9, 4}, {12, 4}, {9, 5}, {10, 5}, {11, 5}, {12, 5}, {9, 6}, {12, 6}, {9, 7}, {12, 7}, {9, 8}, {12, 8} };
	int u[14][2] = { {14, 3}, {17, 3}, {14, 4}, {17, 4}, {14, 5}, {17, 5}, {14, 6}, {17, 6}, {14, 7}, {17, 7}, {14, 8}, {15, 8}, {16, 8}, {17, 8} };
	int s[15][2] = { {19, 3}, {20, 3}, {21, 3}, {22, 3}, {19, 4}, {19, 5}, {20, 5}, {21, 5}, {22, 5}, {22, 6}, {22, 7}, {19, 8}, {20, 8}, {21, 8}, {22, 8} };
	int e[15][2] = { {24, 3}, {25, 3}, {26, 3}, {27, 3}, {24, 4}, {24, 5}, {25, 5}, {26, 5}, {27, 5}, {24, 6}, {24, 7}, {24, 8}, {25, 8}, {26, 8}, {27, 8} };

	for (int i = 0; i < 13; i++) {
		pause[p[i][0]][p[i][1]] = -2;
	}

	for (int i = 0; i < 16; i++) {
		pause[a[i][0]][a[i][1]] = -2;
	}

	for (int i = 0; i < 14; i++) {
		pause[u[i][0]][u[i][1]] = -2;
	}

	for (int i = 0; i < 15; i++) {
		pause[s[i][0]][s[i][1]] = -2;
	}

	for (int i = 0; i < 15; i++) {
		pause[e[i][0]][e[i][1]] = -2;
	}

	//출력 
	gotoxy(1, 0);
	for (int i = 0; i < 17; i++) {
		cout << "　";
		for (int j = 0; j < 32; j++) {

			if (pause[j][i] == -1) {
				cout << b1;
			}
			if (pause[j][i] == 9) {
				cout << b0;
			}
			if (pause[j][i] == -2) {
				cout << b2;
			}
			

		}
		cout << endl;
	}
	gotoxy(12, 28);
	cout << "이어서";
	gotoxy(14, 26);
	cout << "메인메뉴로";

	//선택 커서 컨트롤화면
	int select = 0;
	while (1) {
		if (select == 0) {
			gotoxy(12, 24); cout << "▶";
			gotoxy(12, 36); cout << "◀";
			gotoxy(14, 22); cout << "　";
			gotoxy(14, 38); cout << "　";
		}
		if (select == 1) {
			gotoxy(12, 24); cout << "　";
			gotoxy(12, 36); cout << "　";
			gotoxy(14, 22); cout << "▶";
			gotoxy(14, 38); cout << "◀";
		}

		char c = _getch();
		if (c == SELEC) {
			break;
		}
		con_or_esc(c, &select);
	}
	clock_t pause_f = clock();
	clock_t pause_t = 0;
	//선택했을때
	switch (abs(select)%2)
	{
	case PLAY:
		system("cls");
		pause_f = clock();
		pause_t = pause_f - pause_s;
		break;
	case EXIT:
		system("cls");
		*running = false;
		pause_t = 0;
		break;
	default:
		break;
	}
	return pause_t;
}

void Pause::con_or_esc(char c, int*num) {
	switch (c) {
	case UP:
		if ((*num) > 0) {
			(*num)--;
		}
		else {
			(*num) = 1;
		}
		break;
	case DOWN:
		if ((*num) < 1) {
			(*num)++;
		}
		else {
			(*num) = 0;
		}
		break;
	}
}