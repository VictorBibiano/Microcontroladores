/*
 *
 * @file  main.cpp
 * 
 * @brief Main program
 * 
 */

/* includes */
#include "Arduino.h"
#include "HAL_GPIO.h"
#include "HAL_Keyboard.h"
#include "HAL_SSEG.h"

/* Defines */

/* Variables */
// Arreglo para guardar caracteres a mostrar
char Digitos[99];
// Contador de digitos
int i;
// Boton presionado
char key;

/* Funciones */
void setup()
{
  // 4 salidas Teclado matricial y 4 entradas
  DDRD = 0xF;
  // Salidas encendidas y entradas en pullup
  PORTD = 0xFF;
  // 6 salidas 6 segmentos del display
  DDRB = 0x3F;
  // Apagar salidas
  PORTB = 0;
  // 1 salida Segmento 7 del display
  DDRC = 3;
  // Apagar salida
  PORTC = 0;
}

void loop()
{
  i = 0;
  while (true)
  {
    // Obtenemos la tecla presionada
    key = Keyboard_Read();
    // Si se presiona algo que no es un digito se termina el registro de digitos
    if (key == 'c' || key == '%' || key == '*' || key == '-' || key == '+' || key == '=')
      break;
    // Si se presiona un digito se registra
    else if (key != 'n')
    {
      // Mostramos la tecla presionada
      Digitos[i] = key;
      // Mostrar key
      SSEG_Show(Digitos[i]);
      // i++
      i++;
    }
    //delay(1000);
  }
  // Borrar display
  SSEG_Show('n');
  delay(1000);
  //Loop de digitos
  SSEG_Loop(Digitos, i);
}

// Trash
/*
 *
 * Trash
 *  
 */