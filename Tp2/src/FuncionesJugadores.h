/*
 * FileJugadores.h
 *
 *  Created on: 23 oct. 2022
 *      Author: Usuario
 */

#ifndef FUNCIONESJUGADORES_H_
#define FUNCIONESJUGADORES_H_

#include "FuncionesConfederaciones.h"

typedef struct{
	int id;
	char nombre[50];
	char posicion[50];
	short numeroCamiseta;
	int idConfederacion;
	float salario;
	short aniosContrato;
	short isEmpty;
}eJugador;

#endif /* FUNCIONESJUGADORES_H_ */

/**
 * @fn int initJugadores(eJugador*, int)
 * @brief Funcion que iniciliazira el campo isEmpty de las estructuras Jugador del vector en 0
 *
 * @param Se da el vector de Jugadores
 * @param El tamaño del vector
 * @return Devuelve 0 si no pudo inicializarla o 1 si pudo
 */
int initJugadores(eJugador* vecJugadores, int size);

/**
 * @fn int validarPosicionLibreJugadores(eJugador*, int)
 * @brief Funcion que validara que haya una posicion libre en el array
 *
 * @param Vector de Jugadores
 * @param Tamaño del vector
 * @return Devuelvo 1 si encontro una posicion libre o 0 si no encontro ninguna
 */
int validarPosicionLibreJugadores(eJugador* vecJugadores, int size);

/**
 * @fn int validarPosicionOcupadaJugadores(eJugador*, int)
 * @brief Funcion que validara que haya una posicion ocupada en el array
 *
 * @param Vector de Jugadores
 * @param Tamaño del vector
 * @return Devuelvo 1 si encontro una posicion ocupada o 0 si no encontro ninguna
 */
int validarPosicionOcupadaJugadores(eJugador* vecJugadores, int size);

/**
 * @fn int altaJugadores(eJugador*, int, eConfederacion*, int, int*)
 * @brief Funcion que se encargara de pedir los datos del Jugador y en caso de poder hacerlo dar la alta logica en el sistema
 *
 * @param Vector de Jugadores
 * @param Tamaño del vector de Jugadores
 * @param Vector de Confederaciones
 * @param Tamaño del vector de Confederaciones
 * @param Direccion de memoria de la variable que guarda el valor del Id autoincremental
 * @return Retorna 0 en caso de que no haya podido conseguir memoria, -2 si no hay lugar en el array, -1 si no pudo dar la alta o 1 si pudo dar la alta
 */
int altaJugadores(eJugador* vecJugadores, int sizeJugadores, eConfederacion* vecConfederaciones, int sizeConfederaciones, int* id);

/**
 * @fn int pedirConfederacion(eConfederacion*, int, int*)
 * @brief Funcion que se encargara de pedir la Confederacion, mostrara en pantalla las Confederaciones y pedira al usuario que seleccione 1
 *
 * @param Vector de Confederaciones
 * @param Tamaño del vector de Confederaciones
 * @param La direccion de memoria del campo idConfederacion de la estructura sobre la que se piden los datos para ser transcripta
 * @return Retorna 0 si no pudo tomarla o 1 si pudo
 */
int pedirConfederacion(eConfederacion* vecConfederaciones, int size, int* id);

/**
 * @fn int findJugadorById(eJugador*, int, int)
 * @brief Funcion que se encargara de buscar la posicion en el vector de un Jugador segun su Id
 *
 * @param Vector de Jugadores
 * @param Tamaño del vector de Jugadores
 * @param Se le da por valor el Id que debe buscar
 * @return Retorna -1 si no pudo encontrarlo o un numero igual o mayor a 0 segun la posicion
 */
int findJugadorById(eJugador* vecJugadores, int size, int id);

/**
 * @fn int bajaJugadores(eJugador*, int, eConfederacion*, int)
 * @brief Funcion que se encargara de dar la baja logica al Jugador que pertenezca al Id pedido previamente
 *
 * @param Vector de Jugadores
 * @param La posicion del Jugador con el que se quiere trabajar
 * @param Vector de Confederaciones para mostrar el Jugador que se quiere dar de baja en pantalla
 * @param Tamaño del vector de Confederaciones
 * @return Retorna 0 si no pudo conseguir memoria, -1 si no dio la baja o 1 si la hizo
 */
int bajaJugadores(eJugador* vecJugadores, int i, eConfederacion* vecConfederaciones, int sizeConfederaciones);

/**
 * @fn int modificarJugadores(eJugador*, int, eConfederacion*, int)
 * @brief Funcion que se encarga de modificar los datos de un Jugador, permitiendo seleccionar a traves de un submenu los campos de la estructura
 *
 * @param Vector de Jugadores
 * @param La posicion del Jugador con el que se quiere trabajar
 * @param Vector de Confederaciones para mostrar el Jugador que se quiere dar de baja en pantalla
 * @param Tamaño del vector de Confederaciones
 * @return Retorna 0 si no pudo conseguir memoria o 1 si pudo ejecutar la funcion de forma correcta
 */
int modificarJugadores(eJugador* vecJugadores, int i, eConfederacion* vecConfederaciones, int sizeConfederaciones);

/**
 * @fn int subMenuModificar()
 * @brief Funcion que se encarga de mostrar el submenu de la modificacion y pedir la opcion para el switch
 *
 * @return Retorna la opcion elegida por el usuario
 */
int subMenuModificar();

/**
 * @fn int listarJugadores(eJugador*, int, eConfederacion*, int)
 * @brief Funcion que lista el vector de Jugadores en pantalla
 *
 * @param Vector de Jugadores
 * @param Tamaño del vector de Jugadores
 * @param Vector de Confederaciones, se da para poder mostrar el nombre de la Confederacion en pantalla
 * @param Tamaño del vector de Confederaciones
 * @return Retorna 0 si no pudo mostrarlos o 1 si pudo
 */
int listarJugadores(eJugador* vecJugadores, int sizeJugadores, eConfederacion* vecConfederaciones, int sizeConfederaciones);

/**
 * @fn int listarJugadorUnico(eJugador*, int, eConfederacion*, int)
 * @brief Funcion que lista un Jugador en pantalla
 *
 * @param Vector de Jugadores
 * @param Se le da la posicion que ocupa ese Jugador en el array para poder mostrar ese
 * @param Vector de Confederaciones, se da para poder mostrar el nombre de la Confederacion en pantalla
 * @param Tamaño del vector de Confederaciones
 * @return Retorna 0 si no pudo mostrarlos o 1 si pudo
 */
int listarJugadorUnico(eJugador* vecJugadores, int i, eConfederacion* vecConfederaciones, int sizeConfederaciones);

/**
 * @fn int printConfederacion(int, eConfederacion*, int, char*)
 * @brief
 *
 * @param Se brinda el valor del campo idConfederacion para poder comparar con el vector de Confederaciones y buscar la descripcion
 * @param Vector de Confederaciones
 * @param Tamaño del vector de Confederaciones
 * @param Vector de caracteres donde se guardara la descripcion de la Confederacion, se devolvera a la funcion para listar el Jugador para imprimirla
 * @return Retora 0 si no pudo hacerlo o 1 si pudo
 */
int printConfederacion(int id, eConfederacion* vecConfederaciones, int sizeConfederaciones, char descripcionConfederacion[30]);
