#include "Block.h"
#include "Board.h" 

void Block::roate_block()
{
	int i,j
	
	if(Block::can_place_on_board())			// ȸ���� ����� �浹 ������� üũ		
	{
        for(i=0;i<4;i++)
		{  
            for(j=0;j<4;j++)
			{                
			if(block_list[shape][direction][i][j]) 
			Block::erase_block();			// ���� ��� ������ ���������� 
            }
        }	
           		 
        direction = direction + 1;		
 
    	if (direction == 4)
        direction = 0;				// ���� ��Ͽ� ȸ���ֱ�, ȸ��4���Ǹ� ����������� 
            
		for(i=0;i<4;i++)
		{ 
        	for(j=0;j<4;j++)
			{                		
            if(block_list[shape][direction][i][j]) 
			Block::draw_block();		// ȸ���� ��� ���忡 ��Ÿ���� 
            }
        }
    }
}

