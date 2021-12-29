#pragma once

class Score
{
private:
	int score;
	int* speed;
	int* line;
	int* level;
	int left_block;

public:
	Score(int* speed, int* line, int* level) {
		score = 0;
		this->speed = speed;
		this->line = line;
		this->level = level;
		left_block = 0;
	}

	void score_up(); //����+
	void print_score_level(); //����,���� �ܼ� ���
	void print_brick_speed();
	void change_speed(int* level); //level�� ���� speed����
	void get_left_block(int num);
	void reset_score();
};