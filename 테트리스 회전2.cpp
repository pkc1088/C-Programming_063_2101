#include "Block.h"
#include "Board.h" 

void Block::roate_block()
{
	int i,j
	
	if(Block::can_place_on_board())			// 회전시 보드와 충돌 생기는지 체크		
	{           
		if(block_list[shape][direction][i][j]) 
		Block::erase_block();			// 기존 블록 삭제해 빈공간만들기 
            	   		 
        direction = direction + 1;		
    	if (direction == 4)
        direction = 0;				// 기존 블록에 회전넣기, 회전4번되면 원래모양으로 
                          		
    	if(block_list[shape][direction][i][j]) 
		Block::draw_block();		// 회전된 블록 보드에 나타내기 
    }
}

