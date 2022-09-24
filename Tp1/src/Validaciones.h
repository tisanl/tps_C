/*
 * Validaciones.h
 *
 *  Created on: 22 ago. 2022
 *      Author: Usuario
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_



#endif /* VALIDACIONES_H_ */

/**
 * @fn int getIntRange(int*, int, int, int, char[], char[])
 * @brief Esta funcion pedira un numero entero dentro de un rango
 *
 * @param Recivira la direciion de memoria donde se guardara el dato pedido
 * @param Valor minimo del rango
 * @param Valor maximo del rango
 * @param Cantidad de repeticiones
 * @param Mensaje para la primera vez que ingresa el dato
 * @param Mensaje si se vuelve a pedir al ser erroneo
 * @return Retorna un 0 si no consiguio memoria, un 1 si pudo tomar el dato y un -1 si es invalido
 */
int getIntRange(int*, int, int, int, char[], char[]);

/**
 * @fn int getIntPositiv(int*, int, char[], char[])
 * @brief Esta funcion pedira un numero entero positivo sin incluir el 0
 *
 * @param Recivira la direcion de memoria donde se guardara el dato pedido
 * @param Cantidad de repeticiones
 * @param Mensaje para la primera vez que ingresa el dato
 * @param Mensaje si se vuelve a pedir al ser erroneo
 * @return Retorna un 0 si no consiguio memoria, un 1 si pudo tomar el dato y un -1 si es invalido
 */
int getIntPositiv(int* , int, char[], char[]);

/**
 * @fn int getFloatPositiv(float*, int, char[], char[])
 * @brief Esta funcion pedira un numero flotante positivo sin incluir el 0
 *
 * @param Recivira la direcion de memoria donde se guardara el dato pedido
 * @param Cantidad de repeticiones
 * @param Mensaje para la primera vez que ingresa el dato
 * @param Mensaje si se vuelve a pedir al ser erroneo
 * @return Retorna un 0 si no consiguio memoria, un 1 si pudo tomar el dato y un -1 si es invalido
 */
int getFloatPositiv(float*, int, char[], char[]);

/**
 * @fn int getCaracterTolower(char*)
 * @brief Funcion que pedira un caracter y lo pondra en minuscula
 *
 * @param Recive la direccion de memoria del caracter a ingresar
 * @return Retorna un 0 si no consiguio memoria o un 1 si pudo tomar el dato
 */
int getCaracterTolower(char*);

/**
 * @fn int salirDelPrograma(char*)
 * @brief Funcion que pedira un caracter y lo pondra en minuscula con el objetivo de mantenerse o salir de un menu de opciones
 *
 * @param Recive la direccion de memoria del caracter a ingresar
 * @return Retorna un 0 si no consiguio memoria o un 1 si pudo tomar el dato
 */
int salirDelPrograma(char*);
