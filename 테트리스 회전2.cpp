#include "Block.h"
#include "Board.h" 

void Block::rotate_block()
{
	int i,j
	
	if(Block::can_place_on_board())			// ȸ���� ����� �浹 ������� üũ		
	{           
		Block::erase_block();			// ���� ��� ������ ���������� 
            	   		 
        direction = direction + 1;		
    	if (direction == 4)
        direction = 0;				// ���� ��Ͽ� ȸ���ֱ�, ȸ��4���Ǹ� ����������� 
                          		
		Block::draw_block();		// ȸ���� ��� ���忡 ��Ÿ���� 
    }
}

