#include "Block.h"
#include "Board.h" 

void Block::roate_block()
{
	int i,j;
	
	case SPACE :
				if(check_crush()==1)			// ȸ���� ����� �浹 ������� üũ		
	 		{
            	for(i=0;i<4;i++)
				{  
                	for(j=0;j<4;j++)
					{                
					if(block_list[shape][direction][i][j]==1) 
					board[y+i][x+j]=0;			// ���� ��� ������ ���������� 
               		}
           		 }	
           		 
         	    direction = direction + 1;		
 
    			if (direction == 4)
        		direction = 0;				// ���� ��Ͽ� ȸ���ֱ�, ȸ��4���Ǹ� ����������� 
            
				for(i=0;i<4;i++)
				{ 
                	for(j=0;j<4;j++)
					{                		
                    if(block_list[shape][direction][i][j]==1) 
					board[y+i][x+j]=1;				// ȸ���� ��� ���忡 ��Ÿ���� 
                	}
           		 }
     		}
            break;
}

