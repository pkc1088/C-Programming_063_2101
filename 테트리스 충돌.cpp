void check_crush()
{ 
    int i,j;
    
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(block_list[shape][direction][i][j] && board[y+i][x+j] == -1)  // ����� �� ��ġ�� false, -1�� �׵θ��̴ϱ� 
			return false;
        }
    }    
    return true; 
};

