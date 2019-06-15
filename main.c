#include "funciones.h"
#include <stdio.h>
#include <stdbool.h>
int main(int argc, char *argv[]){
    bool mflag =false;
    int opt;
    while ((opt = getopt (argc, argv, "hm")) != -1)
    {
		switch(opt)
		{
			case 'h':
			
             			fprintf(stderr, "proyecto [option]\n");
                                fprintf(stderr,"-h: ayuda,muestra este mensaje\n");
                                fprintf(stderr,"-m: muestra una lista con las ubicaciones de las minas mientras se juega,\n util para comprobacion del correcto funcionamiento del juego\n");
				return 0;
				break;
			
			case 'm': 
			     mflag=true;
			     break;
	
			case '?': //Por si se ingresa un caracter desconocido
			default:
				break;

        }
    }
    bool exit = true;
    int x, y;
    cargar_tablero();
    cargar_minas();
    mostrar_tablero();
    mostrar_ubicacionMinas(mflag);

    do{
        printf("Ingrese coordenada en x debe ser 0 - 9:\n");
        scanf("%i",&x);
        printf("Ingrese coordenada en y debe ser 0 - 9:\n");
        scanf("%i",&y);
        
        if(x<10 && x>-1 && y<10 && y>-1){
            jugar(x,y);
            mostrar_tablero();
            mostrar_ubicacionMinas(mflag);
            printf("\n");
            exit = comprobar_tablero();
            if(!exit) 
            {printf("BOOM!!\n");
            printf("  ____     __     _    _     ___         ___            ___   ____\n");
            printf(" |        /  \\   | \\  / |   |           |   |  \\    /  |     |   |    \n");
            printf(" |  __   /____\\  |  \\/  |   |---        |   |   \\  /   |---  |___|    \n");
            printf(" |____| /      \\ |      |   |___        |___|    \\/    |___  |   \\    \n");    
            }                                                         
        }   
        else
            printf("No son coordenadas correctas, digite de nuevo.\n");
        
    }while(exit);
    return 0;
}