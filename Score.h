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

	void score_up(); //점수+
	void print_score_level(); //점수,레벨 콘솔 출력
	void print_brick_speed();
	void change_speed(int* level); //level에 따른 speed조절
	void get_left_block(int num);
	void reset_score();
};