void check_crush()
{ 
    int i,j;
    
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(block_list[shape][direction][i][j] && board[y+i][x+j] == -1)  // 보드와 블럭 겹치면 false, -1이 테두리이니까 
			return false;
        }
    }    
    return true; 
};

