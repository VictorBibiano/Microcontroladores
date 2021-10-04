/*
 *
 * @file  HAL_Keyboard.cpp
 * 
 * @brief Control de teclado matricial
 * 
 */

/* includes */
#include "Arduino.h"
#include "HAL_GPIO.h"
#include "HAL_Keyboard.h"

/* Variables */
// Caracter a devolver
int btnpress;
// Auxiliar busqueda boton presionado
bool termino;
// Fila y columna de boton presionado
int fila, columna;
// Matriz de caracteres de teclado [fila][columna]
char Teclado[4][4] = {
    {'7', '8', '9', '%'},
    {'4', '5', '6', '*'},
    {'1', '2', '3', '-'},
    {'c', '0', '=', '+'}};


/* Funciones */

char Keyboard_Read()
{
    // Iniciamos con el termino en false para buscar
    termino = false;
    // Para cada fila
    for (int fil = 0; fil < 4; fil++)
    {
        // Apagamos la fila para poder leer las columnas de dicha fila
        HAL_Reset(PORTD, fil);
        // Para cada columna
        for (int col = 0; col < 4; col++)
        {
            // si el boton de la columna actual esta presionado (+4 por el puerto)
            if ((~PIND & (1 << (col + 4))))
            {
                HAL_Set(PORTC, 1);
                // Columna igual a columna actual
                columna = col;
                // Fila igual a fila actual
                fila = fil;
                // Bandera de termino busqueda
                termino = true;
                // Mientras siga presionado el boton
                while ((~PIND & (1 << (col + 4))))
                    ;
                HAL_Reset(PORTC, 1);
                // Si ya encontro el boton termina el for secundario
                break;
            }
        }
        // Encendemos nuevamente la fila
        HAL_Set(PORTD, fil);
        // Si ya encontro el boton termina el for principal
        if (termino)
            break;
    }
    if (termino)
        // Se selecciona el boton de la matriz con la fila y columna encontrados
        btnpress = Teclado[fila][columna];
    else
        btnpress = 'n';
    // Se retorna el caracter del boton presionado
    return btnpress;
}