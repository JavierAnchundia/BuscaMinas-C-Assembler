
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int tablero[10][10];
int minas_x[10];
int minas_y[10];

void cargar_tablero(){
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            tablero[i][j]=254;
        } 
    }
}

void mostrar_ubicacionMinas(){

for(int i=0; i<10; i++){
        printf("%i,%i  ",minas_x[i],minas_y[i]);
     }
}
void mostrar_tablero(){
    for (int i = 0; i < 10; i++){
        if(i==0)
            printf("   0 1 2 3 4 5 6 7 8 9 \n");
        printf("%i  ",i);
        for (int j = 0; j < 10; j++){
            printf("%c ",tablero[i][j]);
        }
        printf("\n"); 
    } 
    mostrar_ubicacionMinas();
     
}



bool comprobar_minas(int x, int y){
    if(x<10 && x>-1 && y<10 && y>-1){
    for(int i=0; i<10; i++){
        if(minas_x[i]==x && minas_y[i]==y){
            return true;
        }
    }
    return false;
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
        if(comprobar_minas(cx,cy)==false){
            minas_x[j]=cx;
            minas_y[j]=cy;
            j++;
        }
    }
    /*
    for (int i = 0; i < 10; i++)
    {
        printf("(%i,%i)",minas_x[i],minas_y[i]);
    }
    */
    
}
void jugar(int x ,int y){
    for (int i = 0; i < 10; i++){
        if(minas_x[i]==x && minas_y[i]==y){
            tablero[x][y]=157;
            break;
        }   
        else{
            int contador=0;   
            if(comprobar_minas(x-1,y))  contador++; //Arriba
            if(comprobar_minas(x+1,y))  contador++; //Abajo
            if(comprobar_minas(x,y-1))  contador++;  //Izquierda
            if(comprobar_minas(x,y+1))  contador++;  //Derecha

            if(comprobar_minas(x-1,y-1)) contador++;  //Esquina Superior Izquierda
            if(comprobar_minas(x-1,y+1)) contador++;  //Esquina Superior Derecha
            if(comprobar_minas(x+1,y-1)) contador++; //Esquina Inferior Izquierda
            if(comprobar_minas(x+1,y+1)) contador++; //Esquina Inferior Derecha


            tablero[x][y]=48+contador;
        }
    }
}
bool comprobar_tablero(){
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if(tablero[i][j]==157)
                return false;
        }
    }
    return true;
    
}
