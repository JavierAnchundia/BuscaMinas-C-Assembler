
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <Windows.h>

void Color(int Background, int Text);   

enum Colors { // Listado de colores (La letra "L" al inicio, indica que es un color más claro que su antecesor).
 BLACK = 0,
 BLUE = 1,
 GREEN = 2,
 CYAN = 3,
 RED = 4,
 MAGENTA = 5,
 BROWN = 6,
 LGREY = 7,
 DGREY = 8,
 LBLUE = 9,
 LGREEN = 10,
 LCYAN = 11,
 LRED = 12,
 LMAGENTA = 13,
 YELLOW = 14,
 WHITE = 15
};
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

void mostrar_ubicacionMinas(bool m){
    if(m){  
        printf("\n");
        printf("Coordenadas de las ubicaciones de las minas dentro del juego: \n");
        for(int i=0; i<10; i++){
             printf("- (%i,%i) ",minas_x[i],minas_y[i]);
        }
        printf("\n");
    }
}
void mostrar_tablero(){
    for (int i = 0; i < 10; i++){
        if(i==0)
            printf("   0 1 2 3 4 5 6 7 8 9 \n");
        printf("%i  ",i);
        for (int j = 0; j < 10; j++){
            if(tablero[i][j]==48) Color(BLACK, YELLOW);
            if(tablero[i][j]==49) Color(BLACK, LGREEN);
            if(tablero[i][j]==50) Color(BLACK, LBLUE);
            if(tablero[i][j]==51) Color(BLACK, CYAN);
            if(tablero[i][j]==52) Color(BLACK, LCYAN);
            if(tablero[i][j]==53) Color(BLACK, LMAGENTA);
            if(tablero[i][j]==54) Color(BLACK, LGREY);
            if(tablero[i][j]==55) Color(BLACK, BLUE);
            if(tablero[i][j]==157) Color(BLACK, LRED);
            printf("%c ",tablero[i][j]);
            Color(BLACK, WHITE);
        }
        printf("\n"); 
    }      
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

//Codigo para cambio de Colores, Autor: Thiamatt
void Color(int Background, int Text){ 
 HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
 int    New_Color= Text + (Background * 16); 
 SetConsoleTextAttribute(Console, New_Color);
}
