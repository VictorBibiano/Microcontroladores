/*
 *
 * @file    : HAL_GPIO.h
 * 
 * @brief   : Definicion de funciones para set, reset y lectura de pines
 *
*/

// Calculo pin
#define numpin(pin) int(pow(2, pin))
// Funcion set pin
#define HAL_Set(port, pin) port |= (1 << pin)
// Funcion reset pin
#define HAL_Reset(port, pin) port &= ~(1 << pin)
// Funcion read pin
#define HAL_Read(port, pin) (port & numpin(pin)) >> pin
// Funcion read pin con pull up
#define HAL_ReadPU(port, pin) !((port & numpin(pin)) >> pin)