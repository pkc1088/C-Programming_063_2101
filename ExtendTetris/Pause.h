#pragma once

#include <time.h>

class Pause {
private:
	int pause[32][17];
	bool* running;
public:
	Pause(bool* running) {
		this->running = running;
	}

	clock_t print_pause(); //pauseȭ�� �ܼ� ���
	void con_or_esc(char c, int* num); //pauseȭ�� Ű�Է� ��Ʈ��
};