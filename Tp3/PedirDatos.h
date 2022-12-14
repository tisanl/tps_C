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
 * @fn int menuDeOpciones()
 * @brief Funcion que desplegara el menu de opciones
 *
 * @return Devuelve la opcion para que el switch pueda continuar con el programa
 */
int menuDeOpciones();

/**
 * @fn int getIntRange(int*, int, int, int, char*, char*)
 * @brief Esta funcion pedira un numero entero dentro de un rango
 *
 * @param Recivira la direcion de memoria donde se guardara el dato pedido
 * @param Valor minimo del rango
 * @param Valor maximo del rango
 * @param Cantidad de repeticiones
 * @param Mensaje para la primera vez que ingresa el dato
 * @param Mensaje si se vuelve a pedir al ser erroneo
 * @return Retorna un 0 si no consiguio memoria, un 1 si pudo tomar el dato y un -1 si es invalido
 */
int getIntRange(int*, int, int, int, char*, char*);

/**
 * @fn int getIntPositiv(int*, int, char*, char*)
 * @brief Esta funcion pedira un numero entero positivo sin incluir el 0
 *
 * @param Recivira la direcion de memoria donde se guardara el dato pedido
 * @param Cantidad de repeticiones
 * @param Mensaje para la primera vez que ingresa el dato
 * @param Mensaje si se vuelve a pedir al ser erroneo
 * @return Retorna un 0 si no consiguio memoria, un 1 si pudo tomar el dato y un -1 si es invalido
 */
int getIntPositiv(int* , int, char*, char*);

/**
 * @fn int getShortIntRange(short*, int, int, int, char*, char*)
 * @brief Esta funcion pedira un numero entero corto dentro de un rango
 *
 * @param Recivira la direcion de memoria donde se guardara el dato pedido
 * @param Valor minimo del rango
 * @param Valor maximo del rango
 * @param Cantidad de repeticiones
 * @param Mensaje para la primera vez que ingresa el dato
 * @param Mensaje si se vuelve a pedir al ser erroneo
 * @return Retorna un 0 si no consiguio memoria, un 1 si pudo tomar el dato y un -1 si es invalido
 */
int getShortIntRange(short*, int, int, int, char*, char*);

/**
 * @fn int getShortIntPositiv(short*, int, char*, char*)
 * @brief Esta funcion pedira un numero entero corto positivo sin incluir el 0
 *
 * @param Recivira la direcion de memoria donde se guardara el dato pedido
 * @param Cantidad de repeticiones
 * @param Mensaje para la primera vez que ingresa el dato
 * @param Mensaje si se vuelve a pedir al ser erroneo
 * @return Retorna un 0 si no consiguio memoria, un 1 si pudo tomar el dato y un -1 si es invalido
 */
int getShortIntPositiv(short*, int, char*, char*);

/**
 * @fn int getFloatPositiv(float*, int, char*, char*)
 * @brief Esta funcion pedira un numero flotante positivo sin incluir el 0
 *
 * @param Recivira la direcion de memoria donde se guardara el dato pedido
 * @param Cantidad de repeticiones
 * @param Mensaje para la primera vez que ingresa el dato
 * @param Mensaje si se vuelve a pedir al ser erroneo
 * @return Retorna un 0 si no consiguio memoria, un 1 si pudo tomar el dato y un -1 si es invalido
 */
int getFloatPositiv(float*, int, char*, char*);

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

/**
 * @fn int getStringValidarTamanio(char*, int, int, char*, char*)
 * @brief Esta funcion pedira al usuario una string. La unica validacion que se hara es que no supere el tamaño de la string que se busca guardar
 *
 * @param El vector de la string que se quiere tomar
 * @param El tamaño de ese vector
 * @param La cantidad de reintentos
 * @param El mensaje para la primera vez que se toma el dato
 * @param El mensaje si se debbe reintentar
 * @return Retorna un 0 si no consiguio memoria, un 1 si pudo tomar el dato o un -1 si exedio el tamaño y supero los intentos
 */
int getStringValidarTamanio(char*, int, int, char*, char*);

/**
 * @fn int getStringAlphaYTam(char*, int, int, char*, char*)
 * @brief Funcion que pedira una cadena de caracteres que solo admite letras y caracteres de espacio
 *
 * @param La cadena a pedir
 * @param El tamaño de la cadena
 * @param La cantidad de intentos que tendra el usuario para ingresar la cadena
 * @param Parametro con la cadena con el primer mensaje
 * @param Parametro con la cadena con el mensaje de error
 * @return Retorna 0 si no pudo conseguir memoria, -1 si no pudo tomar la string o 1 si pudo hacerlo
 */
int getStringAlphaYTam(char* , int, int i, char*, char*);

/**
 * @fn int validarTodoAlphaConSpaceBar(char*)
 * @brief Funcion que recive una cadena de caracteres para validar si son todas letras
 *
 * @param Recive el vector de la cadena a evaluar
 * @return Devuelve 0 si no pudo conseguir memoria, -1 si hay un caracter invalido o 1 si la cadena es correcta
 */
int validarTodoAlphaConSpaceBar(char*);
