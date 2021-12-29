#pragma once

#include "Tetris.h"
#include "func.h"
#include "Menu.h"

#include <iostream>
#include <conio.h>
#include <Windows.h>

#define RE 114
#define ESC 27

#define UP 72
#define DOWN 80
#define SELEC 13

#define NORMAL 0
#define CHALLENGE 1
#define EXIT 2

using namespace std;

void Console_control();

int main() {

	Console_control();
	Tetris tetris;
	Menu menu;
	int loop = true;

	while (loop) {
		system("cls");
		
		int challenge = 0;
		int select = 0;
		select= menu.main_menu();

		switch (select) {
		case NORMAL:
			system("cls");
			tetris.run(0); //Normal Mode
			break;
		case CHALLENGE:
			challenge = menu.challenge_menu();
			system("cls");
			if (challenge == 6) break;
			tetris.run(challenge); //Challenge Mode
			break;
		case EXIT:
			system("cls");
			std::cout << "See you again" << std::endl;
			loop = false;
			break;
		default:
			break;
		}
	}
	


}

void Console_control()
{
	system("title Tetris"); //Ÿ��Ʋ
	system("color F0"); //����
	system("mode con: cols=70 lines=26"); //�ܼ�â ũ��

	
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = 0; //Ŀ�� �����
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}