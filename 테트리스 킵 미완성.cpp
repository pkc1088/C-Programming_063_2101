//block.cpp 

void Block::keepLoad_block(Block* now, Block* keep, Block* next)
{
	int temp;
	int x = 5, y = 4;

	if (!keep->stop)	//킵한적 없으면 즉 false면
	{
		keep->x = now->x;
		keep->y = now->y;
		now->x = next->x;
		now->y = next->y;
		this->direction = now->direction; // 이거 위로 한번에 초기 
		this->shape = now->shape;
		keep->stop = true;
	}

	else //킵한적 있으면
	{
		temp = keep->x;
		temp = keep->y;
		keep->x = next->x;
		keep->y = next->y;
		this->direction = now->direction;
		this->shape = now->shape;
	}
}
	
//tetris.cpp
	
	#define CTRL 17

	case CTRL:
		block.keepLoad_block(&block, &keep_block, &next_block);
		break;

		
//block.h
	void keepLoad_block(Block* now, Block* keep, Block* next);


