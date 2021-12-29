#pragma once

#include "Tetris.h"
#include "Block.h"
#include "Pause.h"
#include "func.h"

#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include <iostream>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define KEEP 107
#define SPACE 32
#define ESC 27
#define CLOCK_PER_SEC 100

void Tetris::run(int challenge_num)
{
	srand((unsigned int)time(NULL));
	count_time = clock();
	
	//���� �ʱ�ȭ
	challenge = challenge_num;
	running = true;
	is_keeped = false;
	can_use_keep = true;
	
	score.reset_score(); //�������ú� �ʱ�ȭ

	board.clear_board(challenge); //���� ���� �ʱ�ȭ

	//�� ���� �� �ʱ�ȭ
	block.create_block(rand() % 7).draw_block(); 
	next_block.create_block(rand() % 7); 

	//�ð��ʱ�ȭ
	start_t = clock();
	pause_t = 0;
	board.reset_time();
	while (running) {
		//Ű�Է��� ������ Ű�Է� ó��
		if (_kbhit()) {
			char c = _getch();
			process_key(c);
			if(running)	print_screen();
		}
		//Ű�Է��� ������ �����ð����� �� ��������
		else {
			if (time_difference() / CLOCK_PER_SEC > speed) {
				block.move_down();

				count_time = clock();

				print_screen();
			}
		}
		//���� �ٴڿ� �����Դٸ�
		if (block.is_stop()) {
			board.erase_line();
			//���ӿ����ΰ�?
			if (board.check_gameover()) {
				running = false;
				break;
			}
			//ç�����ϰ�� Ŭ��������Ȯ��
			if (challenge!=0) {
				if (board.is_clear()) {
					running = false;
					break;
				}
			}
			//����������
			block.get_block(&next_block).draw_block();
			next_block.create_block(rand() % 7);
			can_use_keep = true;

			print_screen();
		}
	}

}

double Tetris::time_difference()
{
	clock_t now_time = clock();
	return now_time - count_time;
}

void Tetris::process_key(char c)
{
	switch (c)
	{
	case UP: 
		block.rotate_block();
		break;
	case DOWN: 
		block.move_down();
		break;
	case LEFT:
		block.move_left();
		break;
	case RIGHT:
		block.move_right();
		break;
	case ESC: 
		pause_t = pause.print_pause();
		break;
	case SPACE: 
		block.keeping(&can_use_keep, &is_keeped, &next_block, &keep_block);
		break;
	default:
		break;
	}
}

void Tetris::print_screen()
{
	board.print_board();
	next_block.print_block(1, 52, 1, true);
	keep_block.print_block(7, 52, 2, is_keeped);
	if (challenge==0) {
		score.print_score_level();
	}
	else {
		score.print_brick_speed(); 
	}
	gotoxy(0, 0);
	board.print_how_to(start_t);
}

clock_t Tetris::get_pause_t() {
	return pause_t;
}