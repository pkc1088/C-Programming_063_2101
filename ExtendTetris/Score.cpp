#pragma once

#include "Score.h"
#include "func.h"

#include <iostream>

using namespace std;

namespace SPEED {
	enum {
		LEVEL1 = 7, LEVEL2 = 6, LEVEL3 = 5, LEVEL4 = 4, LEVEL5 = 3, LEVEL6 = 2, LEVEL7 = 1
	};
}

void Score::score_up() {
	score += 200 / *speed;
}

void Score::print_score_level() {
	//테두리
	gotoxy(14, 52);
	cout << "□□레벨□□";
	for (int i = 0; i <= 3; i++) {
		gotoxy(15 + i, 52);
		cout << "□　　　　□";
	}
	
	gotoxy(18, 52);
	cout << "□□점수□□";
	for (int i = 0; i <= 3; i++) {
		gotoxy(19 + i, 52);
		cout << "□　　　　□";
	}
	gotoxy(22, 52);
	cout << "□□□□□□";

	//내용
	gotoxy(16, 58);
	cout << *level;
	if (score != 0) {
		gotoxy(20, 56);
	}
	else {
		gotoxy(20, 58);
	}
	cout << score;
}

void Score::print_brick_speed() {
	//테두리
	gotoxy(14, 52);
	cout << "□□속도□□";
	for (int i = 0; i <= 3; i++) {
		gotoxy(15 + i, 52);
		cout << "□　　　　□";
	}

	gotoxy(18, 52);
	cout << "□남은블럭□";
	for (int i = 0; i <= 3; i++) {
		gotoxy(19 + i, 52);
		cout << "□　　　　□";
	}
	gotoxy(22, 52);
	cout << "□□□□□□";

	//내용
	gotoxy(16, 58);
	cout << *level;
	gotoxy(20, 54);
	cout << " "<< left_block<<"/10";
}

void Score::change_speed(int* level) {
	if (*level == 1) {
		*speed = SPEED::LEVEL1;
	}
	if (*level == 2) {
		*speed = SPEED::LEVEL2;
	}
	if (*level == 3) {
		*speed = SPEED::LEVEL3;
	}
	if (*level == 4) {
		*speed = SPEED::LEVEL4;
	}
	if (*level == 5) {
		*speed = SPEED::LEVEL5;
	}
	if (*level == 6) {
		*speed = SPEED::LEVEL6;
	}
	if (*level == 7) {
		*speed = SPEED::LEVEL7;
	}
}

void Score::get_left_block(int num)
{
	left_block = num;
}

void Score::reset_score()
{
	score = 0;
	*line = 0;
	*level = SPEED::LEVEL7;
	change_speed(level);
}
