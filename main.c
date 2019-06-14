#include "funciones.h"
#include <stdio.h>
#include <stdbool.h>
int main(){
    bool exit = true;
    int x, y;
    cargar_tablero();
    cargar_minas();
    mostrar_tablero();
    do{
        printf("Ingrese coordenada en x debe ser 0 - 9:\n");
        scanf("%i",&x);
        printf("Ingrese coordenada en y debe ser 0 - 9:\n");
        scanf("%i",&y);
        if(x<10 && x>-1 && x<10 && x>-1){
            jugar(x,y);
            mostrar_tablero();
            printf("\n");
            exit = comprobar_tablero();
        }
        else
            printf("No son coordenadas correctas, digite de nuevo.\n");
        
    }while(exit!=false);
    return 0;
}