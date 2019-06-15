#include <stdbool.h>

#ifndef FUNCIONES_h
#define FUNCIONES_H
void mostrar_tablero();
void cargar_tablero();
void cargar_minas();
void mostrar_ubicacionMinas();
void comprobar_minas(int x, int y);
bool comprobar_tablero();
void jugar(int x ,int y);
#endif