#pragma once

#include "Block.h"
#include "Board.h"
#include "func.h"

#include <iostream>

int block_list[7][4][4][2] = {
	//O�̳� : 0
	{ { {0,0},{1,0},{0,1},{1,1} }, { {0,0},{1,0},{0,1},{1,1} }, { {0,0},{1,0},{0,1},{1,1} }, { {0,0},{1,0},{0,1},{1,1} } },
	//I�̳� : 1
	{ { {0,-1},{0,0},{0,1},{0,2} }, { {0,0},{1,0},{-1,0},{-2,0} }, { {0,-1},{0,0},{0,1},{0,2} }, { {0,0},{1,0},{-1,0},{-2,0} } },
	//Z�̳� : 2
	{ { {0,0},{-1,0},{0,1},{1,1} }, { {0,0},{0,1},{1,0},{1,-1} }, { {0,0},{-1,0},{0,1},{1,1} }, { {0,0},{0,1},{1,0},{1,-1} } },
	//S�̳� : 3
	{ { {0,0},{1,0},{0,1},{-1,1} }, { {0,0},{0,-1},{1,0},{1,1} }, { {0,0},{1,0},{0,1},{-1,1} }, { {0,0},{0,-1},{1,0},{1,1} }  },
	//J�̳� : 4
	{ { {1,0},{1,1},{0,1},{-1,1} }, { {0,0},{-1,0},{0,1},{0,2} }, { {0,1},{1,1},{-1,1},{-1,2} }, { {0,1},{0,0},{0,2},{1,2} } },
	//L�̳� : 5
	{ { {0,0},{1,0},{-1,0},{1,1} }, { {0,0},{0,-1},{0,1},{1,-1} }, { {-1,-1},{-1,0},{0,0},{1,0} }, { {0,0},{0,-1},{0,1},{-1,1} } },
	//T�̳� : 6
	{ { {0,0},{0,1},{-1,1},{1,1} }, { {0,0},{1,0},{1,1},{1,-1} }, { {0,0},{0,-1},{-1,-1},{1,-1} }, { {0,0},{-1,0},{-1,1},{-1,-1} } },
};

bool Block::can_place_on_board()
{
	for (int i = 0; i < 4; i++) {
		int nx = this->x + block_list[this->shape][this->direction][i][1];
		int ny = this->y + block_list[this->shape][this->direction][i][0];

		if (0 != board->board_status(ny, nx)) return false;
	}
	
	return true;;
}

void Block::draw_block()
{
	for (int i = 0; i < 4; i++) {
		int nx = this->x + block_list[this->shape][this->direction][i][1];
		int ny = this->y + block_list[this->shape][this->direction][i][0];

		board->draw_board(ny, nx, shape);
	}
}

void Block::erase_block()
{
	for (int i = 0; i < 4; i++) {
		int nx = this->x + block_list[this->shape][this->direction][i][1];
		int ny = this->y + block_list[this->shape][this->direction][i][0];

		board->erase_board(ny, nx);
	}
}

Block& Block::create_block(int type)
{
	x = 5;
	y = 2;
	shape = type;
	direction = 0;
	stop = false;
	return *this;
}

void Block::rotate_block() 
{

	Block::erase_block();  // �ϴ� �����

	direction = direction + 1;	// ��� ������ 
	if (direction == 4)
		direction = 0;

	if (Block::can_place_on_board())	//true�� ���� ��� �׸���
		Block::draw_block();

	else
	{
		direction = direction - 1;	//false�� �������� ��� �׸���
		Block::draw_block();
	}
}

Block& Block::get_block(Block* block)
{
	this->x = block->x;
	this->y = block->y;
	this->direction = block->direction;
	this->shape = block->shape;
	this->stop = block->stop;

	return *this;
}

void Block::get_keep(Block* after,Block *now)
{
	this->x = now->x;
	this->y = now->y;
	this->direction = 0;
	this->shape = after->shape;
	this->stop = after->stop;

}

void Block::print_block(int y, int x, int print_type, bool valid)
{
	//�׵θ� �׸���
	if (print_type == 1) {
		gotoxy(y, x); std::cout << "���Next���";
	}
	else {
		gotoxy(y, x); std::cout << "���Keep���";
	}
	for (int i = 1; i < 4; i++) {
		gotoxy(y + i, x); std::cout << "��        ��";
	}
	gotoxy(y+4, x); std::cout << "�������";
	//�� �׸���
	if (valid) {
		for (int i = 0; i < 4; i++) {
			gotoxy(y + 2 + block_list[shape][0][i][0], x + 4 + block_list[shape][0][i][1] * 2);
			setColor(shape+1);
			std::cout << "��";
			setColor(0);
		}
	}
	
	
}

void Block::keeping(bool *can_use_keep, bool *is_keeped, Block* next_block, Block* keep_block)
{
	if (*can_use_keep) {
		this->erase_block();
		Block temp(board);
		if (*is_keeped) {
			temp.get_keep(keep_block,this);
		}
		else {
			temp.get_keep(next_block,this);
		}
		
		if (temp.can_place_on_board()) {
			if (*is_keeped) {
				keep_block->get_keep(this, keep_block);

			}
			else {
				next_block->create_block(rand() % 7);
				keep_block->get_keep(this, keep_block);
				*is_keeped = true;
			}
			*can_use_keep = false;
			this->get_block(&temp);
		}

		this->draw_block();
		
	}
}

void Block::move_down() 
{
	erase_block();
	this->y += 1;
	if (can_place_on_board()) {
		draw_block();
	}
	else {
		this->y -= 1;
		Block::stop = true;
		draw_block();
	}
}

void Block::move_left() 
{
	erase_block();
	this->x -= 1;
	if (can_place_on_board()) {
		draw_block();
	}
	else {
		this->x += 1;
		draw_block();
	}
}
//��ä�� �ۼ�
void Block::move_right() 
{
	erase_block();
	this->x += 1;
	if (can_place_on_board()) {
		draw_block();
	}
	else {
		this->x -= 1;
		draw_block();
	}
}

bool Block::is_stop()
{
	if (stop) return true;
	return false;
}
