#pragma once

#include "Board.h"

class Block
{
private:
	int x;
	int y;
	int shape;
	int direction;
	bool stop;
	Board* board;

public:
	Block(Board *board) {
		x = 0;
		y = 0;
		direction = 0;
		shape = 0;
		stop = false;
		this->board = board;
	}
	//¿Ï¼º
	bool can_place_on_board();
	void draw_block(); 
	void erase_block();
	Block& create_block(int type);
	bool is_stop(); 
	void move_left();
	void move_right(); 
	void move_down(); 
	void rotate_block();
	Block& get_block(Block* block);
	void get_keep(Block* after, Block* now); 
	void print_block(int y,int x, int print_type, bool valid);
	void keeping(bool *can_use_keep, bool *is_keeped, Block *next_block, Block *keep_block);
	
};

