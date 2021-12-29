#pragma once

#include "Board.h"
#include "func.h"

#include <iostream>
#include <cstdio>
#include <conio.h>
#include <Windows.h>
using namespace std;

#define TABLE_Y 22
#define TABLE_X 12
#define ESC 27
#define CHALLENGE_CLEAR 10

void Board::draw_board(int y, int x, int color)
{
	this->board[y][x] = color + 1;
}

void Board::erase_board(int y, int x)
{
	this->board[y][x] = 0;
}

int Board::board_status(int y, int x)
{
	return this->board[y][x];
}

void Board::print_board()
{
	char b0[4] = { "·" };
	char b1[4] = { "□" };
	char b2[4] = { "■" };

	setColor(0);
	for (int i = 0; i < TABLE_Y; i++) {
		for (int j = 0; j < TABLE_X; j++) {
			if (board[i][j] == -1) {
				gotoxy(i + 1, 2 * j + 26);
				cout << b1;
			}
			else if (board[i][j] == 0) {
				gotoxy(i + 1, 2 * j + 26);
				cout << b0;
			}
			else {
				gotoxy(i + 1, 2 * j + 26);
				setColor(board[i][j]);
				cout << b2;
				setColor(0);
			}
		}
	}
}

void Board::erase_line()
{
	for (int Y = 1; Y < TABLE_Y - 1; Y++) {
		bool isLinear = true;
		for (int X = 1; X < TABLE_X - 1; X++) {
			if (board[Y][X] == 0) isLinear = false;
		}
		//한줄이 꽉 채워졌을때
		if (isLinear) {
			//이펙트
			gotoxy(3, 12);
			static int congratuation = 0;
			if (congratuation == 0) {
				cout << "Great!";
				congratuation++;
			}
			else if (congratuation == 1) {
				cout << "Nice!";
				congratuation++;
			}
			else {
				cout << "Good!";
				congratuation = 0;
			}
			for (int i = 0; i < 3; i++) {
				for (int j = 1; j < TABLE_X - 1; j++) {
					board[Y][j] = 0;
				}
				print_board();
				Sleep(80);
				for (int j = 1; j < TABLE_X - 1; j++) {
					board[Y][j] = 8;
				}
				print_board();
				Sleep(80);
			}
			//줄 지우고 한칸씩 내리기
			for (int i = Y; i > 1; i--) {
				for (int j = 1; j < TABLE_X - 1; j++) {
					board[i][j] = board[i - 1][j];
				}
			}
			print_board();
			//점수추가 및 레벨 조정
			score->score_up();
			*line += 1;
			if(*level != 7){
				if (* challenge == 0) {
					if (*line == 5) { // 라인 몇개당 레벨 올릴지
						*line = 0;
						*level += 1;
						gotoxy(5, 28); cout << "■■■■■■■■■■";
						gotoxy(3, 34); cout << "LEVEL UP!";
						Sleep(1000);
						score->change_speed(level);
					}
				}
				else {
					if (*line == 8) { // 라인 몇개당 레벨 올릴지
						*line = 0;
						*level += 1;
						gotoxy(5, 28); cout << "■■■■■■■■■■";
						gotoxy(3, 34); cout << "SPEED UP!";
						Sleep(1000);
						score->change_speed(level);
					}
				}
			}
			
		}
	}
}

bool Board::check_gameover()
{
	for (int X = 1; X < TABLE_X - 1; X++) {
		if (board[5][X] != 0) {
			//이펙트
			gotoxy(3, 10);
			cout << "GAME OVER!";
			for (int i = 5; i > 0; i--) {
				for (int j = 1; j < TABLE_X - 1; j++) {
					board[i][j] = 8;
				}
				print_board();
				Sleep(80);
			}

			//esc누르면 메인메뉴로 돌아가기
			while (true) {
				char c = _getch();
				if (c == ESC) break;
			}

			return true;
		}
	}
	return false;
}

bool Board::is_clear()
{
	//남아있는 블럭수 체크
	int left_block = 0;
	for (int i = 1; i < TABLE_Y - 1; i++) {
		for (int j = 1; j < TABLE_X - 1; j++) {
			if (board[i][j] != 0) left_block++;
		}
	}
	score->get_left_block(left_block);
	//클리어 조건
	if (left_block > CHALLENGE_CLEAR) return false;

	//이펙트
	score->print_brick_speed();
	gotoxy(3, 12);
	cout << "CLEAR!";
	for (int i = TABLE_Y - 1 - 1; i > 0; i--) {
		for (int j = 1; j < TABLE_X - 1; j++) {
			board[i][j] = 1;
		}
		print_board();
		Sleep(80);
	}
	//esc누르면 메인메뉴로 돌아가기
	while (true) {
		char c = _getch();
		if (c == ESC) break;
	}

	return true;

}

void Board::clear_board(int challenge)
{
	for (int i = 1; i < TABLE_Y - 1; i++) {
		for (int j = 1; j < TABLE_X - 1; j++) {
			board[i][j] = 0;
		}
	}
	//챌린지 일경우 보드 초기화
	if (challenge == 1) {
		board[TABLE_Y - 1 - 1][1] = board[TABLE_Y - 1 - 1][TABLE_X - 1 - 1] = 1;
		board[TABLE_Y - 1 - 2][2] = board[TABLE_Y - 1 - 2][TABLE_X - 1 - 2] = 1;
		board[TABLE_Y - 1 - 3][3] = board[TABLE_Y - 1 - 3][TABLE_X - 1 - 3] = 1;
		board[TABLE_Y - 1 - 4][4] = board[TABLE_Y - 1 - 4][TABLE_X - 1 - 4] = 1;
		board[TABLE_Y - 1 - 5][3] = board[TABLE_Y - 1 - 5][TABLE_X - 1 - 3] = 1;
		board[TABLE_Y - 1 - 6][2] = board[TABLE_Y - 1 - 6][TABLE_X - 1 - 2] = 1;
		board[TABLE_Y - 1 - 7][1] = board[TABLE_Y - 1 - 7][TABLE_X - 1 - 1] = 1;
		board[TABLE_Y - 1 - 8][1] = board[TABLE_Y - 1 - 8][TABLE_X - 1 - 1] = 1;
		Board::is_clear();
	}
	else if (challenge == 2) {
		board[TABLE_Y - 1 - 1][5] = board[TABLE_Y - 1 - 1][TABLE_X - 1 - 5] = 4;
		board[TABLE_Y - 1 - 2][4] = board[TABLE_Y - 1 - 2][TABLE_X - 1 - 4] = 4;
		board[TABLE_Y - 1 - 3][3] = board[TABLE_Y - 1 - 3][TABLE_X - 1 - 3] = 4;
		board[TABLE_Y - 1 - 4][2] = board[TABLE_Y - 1 - 4][TABLE_X - 1 - 2] = 4;
		board[TABLE_Y - 1 - 5][1] = board[TABLE_Y - 1 - 5][TABLE_X - 1 - 1] = 4;
		board[TABLE_Y - 1 - 6][2] = board[TABLE_Y - 1 - 6][TABLE_X - 1 - 2] = 4;
		board[TABLE_Y - 1 - 7][3] = board[TABLE_Y - 1 - 7][TABLE_X - 1 - 3] = 4;
		board[TABLE_Y - 1 - 8][4] = board[TABLE_Y - 1 - 8][TABLE_X - 1 - 4] = 4;
		Board::is_clear();
	}
	else if (challenge == 3) {
		board[TABLE_Y - 1 - 1][5] = board[TABLE_Y - 1 - 1][TABLE_X - 1 - 5] = 2;
		board[TABLE_Y - 1 - 2][4] = board[TABLE_Y - 1 - 2][TABLE_X - 1 - 4] = 2;
		board[TABLE_Y - 1 - 3][3] = board[TABLE_Y - 1 - 3][TABLE_X - 1 - 3] = 2;
		board[TABLE_Y - 1 - 4][2] = board[TABLE_Y - 1 - 4][TABLE_X - 1 - 2] = 2;
		board[TABLE_Y - 1 - 5][1] = board[TABLE_Y - 1 - 5][TABLE_X - 1 - 1] = 2;
		board[TABLE_Y - 1 - 6][2] = board[TABLE_Y - 1 - 6][TABLE_X - 1 - 2] = 2;
		board[TABLE_Y - 1 - 7][3] = board[TABLE_Y - 1 - 7][TABLE_X - 1 - 3] = 2;
		board[TABLE_Y - 1 - 7][4] = board[TABLE_Y - 1 - 7][TABLE_X - 1 - 4] = 2;
		board[TABLE_Y - 1 - 6][5] = board[TABLE_Y - 1 - 6][TABLE_X - 1 - 5] = 2;
		Board::is_clear();
	}
	else if (challenge == 4) {
		board[TABLE_Y - 1 - 1][1] = board[TABLE_Y - 1 - 3][1] = 5;
		board[TABLE_Y - 1 - 5][1] = board[TABLE_Y - 1 - 7][1] = 5;
		board[TABLE_Y - 1 - 2][4] = board[TABLE_Y - 1 - 4][4] = 5;
		board[TABLE_Y - 1 - 6][4] = board[TABLE_Y - 1 - 1][5] = 5;
		board[TABLE_Y - 1 - 3][5] = board[TABLE_Y - 1 - 5][5] = 5;
		board[TABLE_Y - 1 - 2][8] = board[TABLE_Y - 1 - 4][8] = 5;
		board[TABLE_Y - 1 - 1][9] = board[TABLE_Y - 1 - 3][9] = 5;
		Board::is_clear();
	}
	else if (challenge == 5) {
		board[TABLE_Y - 1 - 1][3] = board[TABLE_Y - 1 - 1][4] = 1;
		board[TABLE_Y - 1 - 1][5] = board[TABLE_Y - 1 - 1][6] = 1;
		board[TABLE_Y - 1 - 1][7] = board[TABLE_Y - 1 - 1][8] = 1;
		board[TABLE_Y - 1 - 2][3] = board[TABLE_Y - 1 - 2][8] = 1;
		board[TABLE_Y - 1 - 3][8] = board[TABLE_Y - 1 - 4][8] = 1;
		board[TABLE_Y - 1 - 5][3] = board[TABLE_Y - 1 - 5][4] = 1;
		board[TABLE_Y - 1 - 5][5] = board[TABLE_Y - 1 - 5][6] = 1;
		board[TABLE_Y - 1 - 5][7] = board[TABLE_Y - 1 - 5][8] = 1;
		board[TABLE_Y - 1 - 6][3] = board[TABLE_Y - 1 - 7][3] = 1;
		board[TABLE_Y - 1 - 8][3] = board[TABLE_Y - 1 - 8][4] = 1;
		board[TABLE_Y - 1 - 8][5] = board[TABLE_Y - 1 - 8][6] = 1;
		board[TABLE_Y - 1 - 8][7] = board[TABLE_Y - 1 - 8][8] = 1;
		Board::is_clear();
	}
}

void Board::print_how_to(clock_t start_t) {
	gotoxy(9, 6);
	cout << "□□□How to□□□" << endl;
	for (int i = 0; i <= 11; i++) {
		gotoxy(10 + i, 6);
		cout << "□　　　　　　　□";
	}
	gotoxy(22, 6);
	cout << "□□□□□□□□□" << endl;
	gotoxy(12, 10);
	cout << "↑   Rotate" << endl;
	gotoxy(13, 8);
	cout << " ←→  Move" << endl;
	gotoxy(14, 10);
	cout << "↓   Down" << endl;
	gotoxy(17, 10);
	cout << "SPACE: Keep" << endl;
	gotoxy(19, 10);
	cout << "ESC: Pause" << endl;

	gotoxy(1, 6);
	cout << "□□□□□□□□□" << endl;
	for (int i = 0; i <= 4; i++) {
		gotoxy(2 + i, 6);
		cout << "□　　　　　　　□";
	}
	//gotoxy(4, 6);
	//cout << "□□□□□□□□□" << endl;
	gotoxy(7, 6);
	cout << "□□□□□□□□□" << endl;

	//플레이 타임 출력
	clock_t after_t = clock();
	if (pause_o != *pause_t) {
		pause_tt += *pause_t;
		pause_o = *pause_t;
	}
	int play_t = after_t - start_t - pause_tt;
	int play_m = play_t / 60000;
	int play_s = (play_t % 60000) * 0.001;
	gotoxy(5, 14);
	cout << "：";
	gotoxy(5, 12);
	cout << play_m;
	if (play_s < 10) {
		gotoxy(5, 16);
		cout <<"0"<< play_s;
	}
	else {
		gotoxy(5, 16);
		cout << play_s;
	}
	
}

void Board::reset_time()
{
	pause_tt = 0;
	pause_o = 0;
}
