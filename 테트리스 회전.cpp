#include "Block.h"
#include "Board.h" 

void Block::rotate_block()
{
	int i,j;
	
	  	Block::erase_block();  // �ϴ� ����� 
		   		 
		direction = direction + 1;		// ��絵 �������� 
    	if (direction == 4)
        direction = 0;			
										
        if(Block::can_place_on_board())	 	//true�� ���� ��� �׸��� 
		Block::draw_block();
		
		else 
		{
		direction = direction - 1;		//false�� �������� ��� �׸��� 
		Block::draw_block();
		}
}

