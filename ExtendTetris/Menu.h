#pragma once

class Menu {
private:
	int menu[34][7];
public:
	int main_menu(); //���θ޴�
	int challenge_menu(); //ç���� ���� �޴�
	void control_main(char c, int* num); //���θ޴� Ű���� �Է� ��Ʈ��
	void control_chal(char c, int* num); //ç���� ���ø޴� Ű���� �Է� ��Ʈ��
}; 