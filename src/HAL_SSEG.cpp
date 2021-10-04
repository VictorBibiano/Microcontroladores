/*
 *
 * @file  HAL_SSSEG.cpp
 * 
 * @brief Control de sseg y loop de mostrado
 * 
 */

/* includes */
#include "Arduino.h"
#include "HAL_GPIO.h"
#include "HAL_Keyboard.h"
#include "HAL_SSEG.h"

/* Variables */
// Boton presionado
char btn;
// Auxiliar boton presionado
bool br;

/* Funciones */

void SSEG_Show(char car)
{
    // Buscamos el caso que aplique
    switch (car)
    {
    //
    //     |a|
    //  |f|   |b|
    //     |g|
    //  |e|   |c|
    //     |d|
    //
    // PORTC[0] = [g] PORTB[5:0] = [f,e,d,c,b,a]
    // El bit 0 del puerto c sera la g, los bits del 5 al 0 del
    // puerto B seran f,e,d,c,b,a respectivamente
    case '0':
        PORTB = 0x3F;
        HAL_Reset(PORTC, 0);
        break;
    case '1':
        PORTB = 6;
        HAL_Reset(PORTC, 0);
        break;
    case '2':
        PORTB = 0x1B;
        HAL_Set(PORTC, 0);
        break;
    case '3':
        PORTB = 0xF;
        HAL_Set(PORTC, 0);
        break;
    case '4':
        PORTB = 0x26;
        HAL_Set(PORTC, 0);
        break;
    case '5':
        PORTB = 0x2D;
        HAL_Set(PORTC, 0);
        break;
    case '6':
        PORTB = 0x3D;
        HAL_Set(PORTC, 0);
        break;
    case '7':
        PORTB = 7;
        HAL_Reset(PORTC, 0);
        break;
    case '8':
        PORTB = 0x3F;
        HAL_Set(PORTC, 0);
        break;
    case '9':
        PORTB = 0x2F;
        HAL_Set(PORTC, 0);
        break;
    // En caso de default borra el display
    default:
        PORTB = 0;
        HAL_Reset(PORTC, 0);
        break;
    }
}

void SSEG_Loop(char Digit[], int i)
{
    // Variable para break
    br = false;
    // loop principal
    while (true)
    {
        // Para cada digito en el array
        for (int j = 0; j < i; j++)
        {
            // Mostrar digito
            SSEG_Show(Digit[j]);
            // Leer caracter
            btn = Keyboard_Read();
            // Si se lee un caracter
            if (btn == 'c' || btn == '%' || btn == '*' || btn == '-' || btn == '+' || btn == '=')
            {
                // Break for
                br = true;
                break;
            }
            delay(500);
        }
        // Borrar display
        SSEG_Show('n');
        delay(500);
        // Break de loop principal
        if (br)
            break;
    }
}