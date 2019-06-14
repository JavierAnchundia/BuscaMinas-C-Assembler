
#include <stdio.h>

void cargar_tablero(){
    int tablero[10][10];
    for (int i = 0; i < 10; i++)
    {

        for (int j = 0; j < 10; j++)
        {
            tablero[i][j]=220;
        }
        
    }
    for (int i = 0; i < 10; i++)
    {
        if(i==0)
            printf("   0 1 2 3 4 5 6 7 8 9 \n");
        printf("%i  ",i);
        

        for (int j = 0; j < 10; j++)
        {
            printf("%c ",tablero[i][j]);
        }
        printf("\n");
        
    }
    
}