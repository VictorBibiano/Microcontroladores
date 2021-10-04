/*
 *
 * @file           : main.cpp
 * 
 * @brief          : Main program
 * 
 */

/* includes */
#include <Arduino.h>
#include "HAL_GPIO.h"

/* Defines */
// Tiempo retentivo
#define TOFF 5000

/* Variables */
// Variables lectura pines
uint8_t SEL, SEN, BTN;
// Variable tiempo de referencia
long t;

/* Setup */
void setup()
{
  // PD0=SEL, PD1=SEN, PD2=BTN, PD3=LED, PD4=FOCO, T=5SEG
  // Primeros 3 entradas, demas salidas
  DDRD = 0xF8;
  // Apagamos salidas y ponemos entradas en pullup
  PORTD = 0x07;
}

/* Loop */
void loop()
{
  // Lectura btn1
  SEL = HAL_ReadPU(PIND, 0);
  // Lectura btn2
  SEN = HAL_ReadPU(PIND, 1);
  // Lectura btn3
  BTN = HAL_ReadPU(PIND, 2);

  // Selector modo auto
  if (SEL)
  {
    // Led Auto/Manual
    HAL_Set(PORTD, 3);
    // Si el sensor esta activado
    if (SEN)
    {
      // Encender foco
      HAL_Set(PORTD, 4);
      // Tiempo de referencia igual a 0
      t = millis();
    }
    // Si el sensor no esta
    else
    {
      // Si han pasado 5 segundos desde el tiempo de referencia
      if ((millis() - t) >= TOFF)
        // Apagar foco
        HAL_Reset(PORTD, 4);
    }
  }
  // Selector modo manual
  else
  {
    // Led Auto/Manual
    HAL_Reset(PORTD, 3);
    // Si esta el boton presionado enciende el foco, si no, lo apaga
    BTN ? HAL_Set(PORTD, 4) : HAL_Reset(PORTD, 4);
  }
}

// Trash
