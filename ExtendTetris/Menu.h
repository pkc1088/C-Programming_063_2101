#pragma once

class Menu {
private:
	int menu[34][7];
public:
	int main_menu(); //메인메뉴
	int challenge_menu(); //챌린지 선택 메뉴
	void control_main(char c, int* num); //메인메뉴 키보드 입력 컨트롤
	void control_chal(char c, int* num); //챌린지 선택메뉴 키보드 입력 컨트롤
}; 