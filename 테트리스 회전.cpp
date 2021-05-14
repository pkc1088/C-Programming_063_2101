#include "Block.h"
#include "Board.h" 

void Block::rotate_block()
{
	int i,j;
	
	  	Block::erase_block();  // 일단 지우고 
		   		 
		direction = direction + 1;		// 모양도 돌려놓고 
    	if (direction == 4)
        direction = 0;			
										
        if(Block::can_place_on_board())	 	//true면 돌린 모양 그리고 
		Block::draw_block();
		
		else 
		{
		direction = direction - 1;		//false면 돌리기전 모양 그리고 
		Block::draw_block();
		}
}

