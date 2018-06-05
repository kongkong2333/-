#include <stdio.h>
#define End 7
#define Start 0


int Visit_Maze(int maze[][8],int i,int j)
{
    int end=0;
    maze[i][j]=2;
    if(i==End && j==End){
        end=1;
    }
    if(end !=1 && j+1 <=End && maze[i][j+1]==0)  //右
    {
        if(Visit_Maze(maze,i,j+1)==1)
            return 1;
    }
    if(end !=1 && i+1 <=End && maze[i+1][j]==0)  //下
    {
        if(Visit_Maze(maze,i+1,j)==1)
            return 1;
    }
    if(end !=1 && j-1 >Start && maze[i][j-1]==0) //左
    {
        if(Visit_Maze(maze,i,j-1)==1)
            return 1;
    }
    if(end !=1 && i-1 > Start && maze[i-1][j]==0) //上
    {
        if(Visit_Maze(maze,i-1,j)==1)
            return 1;
    }
    if (end!=1)
    {
        maze[i][j] = 0;                           //不通,回去
    }

    return end;
}


int main()
{   int maze[8][8]={{0,0,1,0,0,0,1,0},
                    {0,0,1,0,0,0,1,0},
                    {0,0,0,0,1,1,0,0},
                    {0,1,1,1,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,1,0,0,1,1,0,0},
                    {0,1,1,1,0,1,1,0},
                    {1,0,0,0,0,0,0,0}};
    int i,j;
   printf("maze：\n");
    for(i = 0; i <= 9; i++)
        printf("-");
    printf("\n");
    for (i = 0; i < 9; i++){
        printf("|");
        for (j = 0; j < 8; j++){
            if (maze[i][j] == 1)
                printf("#");
            else
                printf(" ");
        }
        printf("|\n");
    }
    for(i = 0; i <= 9; i++)
        printf("-");
    printf("\n");

    if (Visit_Maze(maze, 0, 0) == 0){
        printf("noway\n");
        exit(0);
    }


    printf("maze_way：\n");
    for(i = 0; i <= 9; i++)
        printf("-");
    printf("\n");
    for (i = 0; i < 9; i++){
        printf("|");
        for (j = 0; j < 8; j++){
            if (maze[i][j] == 1)
                printf("#");
            else if (maze[i][j] == 2)
                printf("?");
            else
                printf(" ");
        }
        printf("|\n");
    }
    for(i = 0; i <= 9; i++)
        printf("-");
    printf("\n");

    return 0;
}


