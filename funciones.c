
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


void cargar_tablero(){
    int tablero[10][10];
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            tablero[i][j]=220;
        } 
    }
    for (int i = 0; i < 10; i++){
        if(i==0)
            printf("   0 1 2 3 4 5 6 7 8 9 \n");
        printf("%i  ",i);
        for (int j = 0; j < 10; j++){
            printf("%c ",tablero[i][j]);
        }
        printf("\n"); 
    } 
}
int minas_x[10];
int minas_y[10];

bool comprobar(int x, int y){
    for(int i=0; i<10; i++){
        if(minas_x[i]==x && minas_y[i]==y){
            return true;
        }
    }
    return false;
}
void cargar_minas(){
    srand(time(NULL));
    int j,cx,cy;
    j=0;
    cx=0;
    cy=0;
    while(j<10){
        cx = rand()%10;
        cy = rand()%10;
        if(comprobar(cx,cy)==false){
            minas_x[j]=cx;
            minas_y[j]=cy;
            j++;
        }
    }
}