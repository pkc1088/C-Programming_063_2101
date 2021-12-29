#pragma once

#include "Menu.h"
#include "func.h"
#include <iostream>
#include <conio.h>

#define UP 72
#define DOWN 80
#define SELEC 13

using namespace std;

int Menu::main_menu() {
	system("cls");

	char b0[4] = { "　" }; //0
	char b1[4] = { "■" }; //-1

	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 33; j++) {
			menu[j][i] = 0;
		}
	}

	//TETRIS 글씨
	int t[10][2] = { {3, 1}, {4, 1}, {5, 1}, {6, 1}, {7, 1}, {5, 2}, {5, 3}, {5, 4}, {5, 5}, {5, 6} };
	int e[15][2] = { {9, 1}, {10, 1}, {11, 1}, {12, 1}, {9, 2}, {9, 3}, {10, 3}, {11, 3}, {12, 3}, {9, 4}, {9, 5}, {9, 6}, {10, 6}, {11, 6}, {12, 6} };
	int r[16][2] = { {20, 1}, {21, 1}, {22, 1}, {23, 1}, {20, 2}, {23, 2}, {20, 3}, {21, 3}, {22, 3}, {23, 3}, {20, 4}, {22, 4}, {20, 5}, {23, 5}, {20, 6}, {23, 6} };
	int I[10][2] = { {25, 1}, {26, 1}, {27, 1}, {26, 2}, {26, 3}, {26, 4}, {26, 5}, {25, 6}, {26, 6}, {27, 6} };
	int s[15][2] = { {29, 1}, {30, 1}, {31, 1}, {32, 1}, {29, 2}, {29, 3}, {30, 3}, {31, 3}, {32, 3}, {32, 4}, {32, 5}, {29, 6}, {30, 6}, {31, 6}, {32, 6} };

	for (int i = 0; i < 10; i++) {
		menu[t[i][0] - 1][t[i][1]] = -1;
		menu[t[i][0] + 11 - 1][t[i][1]] = -1;
	}

	for (int i = 0; i < 15; i++) {
		menu[e[i][0] - 1][e[i][1]] = -1;
	}

	for (int i = 0; i < 16; i++) {
		menu[r[i][0] - 1][r[i][1]] = -1;
	}

	for (int i = 0; i < 10; i++) {
		menu[I[i][0] - 1][I[i][1]] = -1;
	}

	for (int i = 0; i < 15; i++) {
		menu[s[i][0] - 1][s[i][1]] = -1;
	}


	//출력
	cout << endl;
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 33; j++) {
			if (menu[j][i] == 0) {
				cout << b0;
			}
			else {
				cout << b1;
			}
		}
		cout << endl;
	}

	cout << endl << endl;
	cout << "　-----------------------------------------------------------------" << endl;
	cout << endl << endl;
	gotoxy(12, 30); cout << "시  작";
	gotoxy(14, 30); cout << "챌린지";
	gotoxy(16, 30); cout << "나가기";
	cout << endl << endl;
	cout << "　-----------------------------------------------------------------" << endl;
	//선택 커서 컨트롤화면
	int ret = 0;
	while (1) {
		if (ret == 0) {
			gotoxy(12, 26); cout << "▶";
			gotoxy(12, 38); cout << "◀";
			gotoxy(14, 26); cout << "　";
			gotoxy(14, 38); cout << "　";
			gotoxy(16, 26); cout << "　";
			gotoxy(16, 38); cout << "　";
		}

		if (ret == 1) {
			gotoxy(12, 26); cout << "　";
			gotoxy(12, 38); cout << "　";
			gotoxy(14, 26); cout << "▶";
			gotoxy(14, 38); cout << "◀";
			gotoxy(16, 26); cout << "　";
			gotoxy(16, 38); cout << "　";
		}

		if (ret == 2) {
			gotoxy(12, 26); cout << "　";
			gotoxy(12, 38); cout << "　";
			gotoxy(14, 26); cout << "　";
			gotoxy(14, 38); cout << "　";
			gotoxy(16, 26); cout << "▶";
			gotoxy(16, 38); cout << "◀";
		}
		char c = _getch();
		if (c == SELEC) {
			break;
		}
		control_main(c, &ret);
	}
	//선택했을때
	return ret;
}

int Menu::challenge_menu() {
	system("cls");

	char b0[4] = { "　" }; //0
	char b1[4] = { "■" }; //-1

	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 31; j++) {
			menu[j][i] = 0;
		}
	}

	//TETRIS 글씨
	int t[10][2] = { {3, 1}, {4, 1}, {5, 1}, {6, 1}, {7, 1}, {5, 2}, {5, 3}, {5, 4}, {5, 5}, {5, 6} };
	int e[15][2] = { {9, 1}, {10, 1}, {11, 1}, {12, 1}, {9, 2}, {9, 3}, {10, 3}, {11, 3}, {12, 3}, {9, 4}, {9, 5}, {9, 6}, {10, 6}, {11, 6}, {12, 6} };
	int r[16][2] = { {20, 1}, {21, 1}, {22, 1}, {23, 1}, {20, 2}, {23, 2}, {20, 3}, {21, 3}, {22, 3}, {23, 3}, {20, 4}, {22, 4}, {20, 5}, {23, 5}, {20, 6}, {23, 6} };
	int I[10][2] = { {25, 1}, {26, 1}, {27, 1}, {26, 2}, {26, 3}, {26, 4}, {26, 5}, {25, 6}, {26, 6}, {27, 6} };
	int s[15][2] = { {29, 1}, {30, 1}, {31, 1}, {32, 1}, {29, 2}, {29, 3}, {30, 3}, {31, 3}, {32, 3}, {32, 4}, {32, 5}, {29, 6}, {30, 6}, {31, 6}, {32, 6} };

	for (int i = 0; i < 10; i++) {
		menu[t[i][0] - 1][t[i][1]] = -1;
		menu[t[i][0] + 11 - 1][t[i][1]] = -1;
	}

	for (int i = 0; i < 15; i++) {
		menu[e[i][0] - 1][e[i][1]] = -1;
	}

	for (int i = 0; i < 16; i++) {
		menu[r[i][0] - 1][r[i][1]] = -1;
	}

	for (int i = 0; i < 10; i++) {
		menu[I[i][0] - 1][I[i][1]] = -1;
	}

	for (int i = 0; i < 15; i++) {
		menu[s[i][0] - 1][s[i][1]] = -1;
	}


	//출력
	cout << endl;
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 33; j++) {
			if (menu[j][i] == 0) {
				cout << b0;
			}
			else {
				cout << b1;
			}
		}
		cout << endl;
	}

	cout << endl << endl;
	cout << "　-----------------------------------------------------------------";

	gotoxy(12, 28);
	cout << "챌린지 1";
	gotoxy(14, 28);
	cout << "챌린지 2";
	gotoxy(16, 28);
	cout << "챌린지 3";
	gotoxy(18, 28);
	cout << "챌린지 4";
	gotoxy(20, 28);
	cout << "챌린지 5";
	gotoxy(22, 28);
	cout << " 나가기 ";
	cout << "\n\n　-----------------------------------------------------------------";
	int ret = 0;

	//선택 커서 컨트롤화면
	while (1) {
		if (ret == 0) {
			gotoxy(12, 24); cout << "▶"; gotoxy(12, 37); cout << "◀";
			gotoxy(14, 24); cout << "　"; gotoxy(14, 37); cout << "　";
			gotoxy(16, 24); cout << "　"; gotoxy(16, 37); cout << "　";
			gotoxy(18, 24); cout << "　"; gotoxy(18, 37); cout << "　";
			gotoxy(20, 24); cout << "　"; gotoxy(20, 37); cout << "　";
			gotoxy(22, 24); cout << "　"; gotoxy(22, 37); cout << "　";
		}
		else if (ret == 1) {
			gotoxy(12, 24); cout << "  "; gotoxy(12, 37); cout << "  ";
			gotoxy(14, 24); cout << "▶"; gotoxy(14, 37); cout << "◀";
			gotoxy(16, 24); cout << "　"; gotoxy(16, 37); cout << "　";
			gotoxy(18, 24); cout << "　"; gotoxy(18, 37); cout << "　";
			gotoxy(20, 24); cout << "　"; gotoxy(20, 37); cout << "　";
			gotoxy(22, 24); cout << "　"; gotoxy(22, 37); cout << "　";
		}
		else if (ret == 2) {
			gotoxy(12, 24); cout << "  "; gotoxy(12, 37); cout << "  ";
			gotoxy(14, 24); cout << "　"; gotoxy(14, 37); cout << "　";
			gotoxy(16, 24); cout << "▶"; gotoxy(16, 37); cout << "◀";
			gotoxy(18, 24); cout << "　"; gotoxy(18, 37); cout << "　";
			gotoxy(20, 24); cout << "　"; gotoxy(20, 37); cout << "　";
			gotoxy(22, 24); cout << "　"; gotoxy(22, 37); cout << "　";
		}
		else if (ret == 3) {
			gotoxy(12, 24); cout << "  "; gotoxy(12, 37); cout << "  ";
			gotoxy(14, 24); cout << "　"; gotoxy(14, 37); cout << "　";
			gotoxy(16, 24); cout << "　"; gotoxy(16, 37); cout << "　";
			gotoxy(18, 24); cout << "▶"; gotoxy(18, 37); cout << "◀";
			gotoxy(20, 24); cout << "　"; gotoxy(20, 37); cout << "　";
			gotoxy(22, 24); cout << "　"; gotoxy(22, 37); cout << "　";
		}
		else if (ret == 4) {
			gotoxy(12, 24); cout << "  "; gotoxy(12, 37); cout << "  ";
			gotoxy(14, 24); cout << "　"; gotoxy(14, 37); cout << "　";
			gotoxy(16, 24); cout << "　"; gotoxy(16, 37); cout << "　";
			gotoxy(18, 24); cout << "　"; gotoxy(18, 37); cout << "　";
			gotoxy(20, 24); cout << "▶"; gotoxy(20, 37); cout << "◀";
			gotoxy(22, 24); cout << "　"; gotoxy(22, 37); cout << "　";
		}
		else if (ret == 5) {
			gotoxy(12, 24); cout << "  "; gotoxy(12, 37); cout << "  ";
			gotoxy(14, 24); cout << "　"; gotoxy(14, 37); cout << "　";
			gotoxy(16, 24); cout << "　"; gotoxy(16, 37); cout << "　";
			gotoxy(18, 24); cout << "　"; gotoxy(18, 37); cout << "　";
			gotoxy(20, 24); cout << "　"; gotoxy(20, 37); cout << "　";
			gotoxy(22, 24); cout << "▶"; gotoxy(22, 37); cout << "◀";
		}

		char c = _getch();
		if (c == SELEC) {
			break;
		}
		control_chal(c, &ret);
	}
	//선택했을때
	return ret + 1;
}

void Menu::control_chal(char c, int* num) {
	switch (c) {
	case UP:
		if ((*num) > 0) {
			(*num)--;
		}
		else {
			(*num) = 5;
		}
		break;
	case DOWN:
		if ((*num) < 5) {
			(*num)++;
		}
		else {
			(*num) = 0;
		}
		break;
	}
}

void Menu::control_main(char c, int* num) {
	switch (c) {
	case UP:
		if ((*num) > 0) {
			(*num)--;
		}
		else {
			(*num) = 2;
		}
		break;
	case DOWN:
		if ((*num) < 2) {
			(*num)++;
		}
		else {
			(*num) = 0;
		}
		break;
	}
}