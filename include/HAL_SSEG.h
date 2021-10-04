/*
 * @file    HAL_SSEG.h
 * 
 * @brief   Libreria para uso de 7 segmentos  
 *
 */

/* Funciones */

/*
 *
 * @brief   Funcion mostrar caracter
 * 
 * @param   Caracter a mostrar
 * 
 * @return  Nothing
 * 
 */
void SSEG_Show(char);

/*
 *
 * @brief   Funcion loop SSEG
 * 
 * @param   Array de digitos, numero digitos
 * 
 * @return  Nothing
 * 
 */
void SSEG_Loop(char [],int);