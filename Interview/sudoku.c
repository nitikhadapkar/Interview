lear_arr(int *a)
{
    int i;
    for(i=0;i<9;i++)
        a[i] = 0;
}

int check_sudoku_state(int **board)
{
    int i, j;
    int arr_row[9], arr_col[9];
    
    for(i=0;i<9;i++)
    {
        clear_arr(arr_row);
        clear_arr(arr_col);
        
        for(j=0;j<9;j++)
        {
            if(board[i][j] != 0)
            {
                arr_row[board[i][j] - 1]++;
                
                //if dup in the row
                if(arr_row[board[i][j] - 1]>1)
                    return -1;
            }
                
            if(board[j][i] != 0)
            {
                arr_col[board[j][i] - 1]++;
                
                //if dup in the column
                if(arr_col[board[j][i] - 1]>1)
                    return -1;
            }            
        }
    }
    
    //check for squares
    
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            //dup in squares
            if(check_square(board, i*3, j*3,arr_row))
                return -1;
        }
    }
    
    return 0;
    
}

int check_square(int **board, int x, int y, int *arr)
{
    int i,j;
    clear_arr(arr);
    for(i=x;i<x+3;i++)
    {
        for(j=y;j<y+3;j++)
        {
            if(board[i][j] != 0)
            {
                arr[board[i][j] - 1]++;
                
                //if dup in the row
                if(arr[board[i][j] - 1]>1)
                    return -1;
            }
        }
    }
    
    return 0;
}
