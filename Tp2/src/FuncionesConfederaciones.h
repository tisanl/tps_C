/*
 * FuncionesConfederaciones.h
 *
 *  Created on: 23 oct. 2022
 *      Author: Usuario
 */

#ifndef FUNCIONESCONFEDERACIONES_H_
#define FUNCIONESCONFEDERACIONES_H_

typedef struct{
	int id;
	char nombre[50];
	char region[50];
	int anioCreacion;
}eConfederacion;

#endif /* FUNCIONESCONFEDERACIONES_H_ */

/**
 * @fn int hardcodeoConfederacion(eConfederacion*, int)
 * @brief Funcion que se encarga de hardcodear los valores de las Confederaciones en el vector de Confederaciones
 *
 * @param Vector de Confederaciones
 * @param Tamaño del vector de Confederaciones
 * @return Retorna 0 si pudo hacerlo o 1 si no
 */
int hardcodeoConfederacion(eConfederacion* vecConfederaciones, int size);

/**
 * @fn int listarConfederaciones(eConfederacion*, int)
 * @brief Funcion que se encarga de listar el vector de Confederaciones en pantalla
 *
 * @param Vector de Confederaciones
 * @param Tamaño del vector de Confederaciones
 * @return Retorna 0 si pudo hacerlo o 1 si no
 */
int listarConfederaciones(eConfederacion* vecConfederaciones, int size);

/**
 * @fn int listarConfederacionUnica(eConfederacion*)
 * @brief Funcion que muestra en pantalla una Confederacion
 *
 * @param La direccion de memoria de la estructura de la Confederacion
 * @return Retorna 0 si no pudo o 1 si pudo mostrarlo
 */
int listarConfederacionUnica(eConfederacion* confederacion);

//================================ FUNCIONES ABM DE CONFEDERACIONES =================================================================//

/**
 * @fn int validarPosicionLibreConfederaciones(eConfederacion*, int)
 * @brief Funcion que validara que haya una posicion libre en el array
 *
 * @param Vector de Confederaciones
 * @param Tamaño del vector de Confederaciones
 * @return Devuelvo 1 si encontro una posicion libre o 0 si no encontro ninguna
 */
int validarPosicionLibreConfederaciones(eConfederacion* vecConfederaciones, int size);

/**
 * @fn int altaConfederaciones(eConfederacion*, int, int*)
 * @brief Funcion que se encargara de tomar los datos de una nueva Confederacion en caso de que haya lugar en sistema
 *
 * @param Vector de Confederaciones
 * @param Tamaño del vector de Confederaciones
 * @param Direccion de memoria de la variable que guarda el valor del Id autoincremental
 * @return Retorna 0 en caso de que no haya podido conseguir memoria, -2 si no hay lugar en el array, -1 si no pudo dar la alta o 1 si pudo dar la alta
 */
int altaConfederaciones(eConfederacion* vecConfederaciones, int size, int* id);

/**
 * @fn int findConfederacionById(eConfederacion*, int, int)
 * @brief Funcion que se encargara de buscar la posicion en el vector de una Confederacion segun su Id
 *
 * @param Vector de Confederaciones
 * @param Tamaño del vector
 * @param Id solicitada previamente
 * @return Retorna -1 si no pudo encontrarlo o un numero igual o mayor a 0 segun la posicion
 */
int findConfederaacionById(eConfederacion* vecConfederaciones, int size, int id);

/**
 * @fn int bajaConfederaciones(eConfederacion*, int)
 * @brief Funcion que se encargara de dar la baja logica a una Conferderacion del vector
 *
 * @param Vector de Confederaciones
 * @param Posicion en el array de la Confederacion que se quiere dar la baja
 * @return Retorna 0 si no pudo conseguir memoria, -1 si no dio la baja o 1 si la hizo
 */
int bajaConfederaciones(eConfederacion* vecConfederaciones, int i);

/**
 * @fn int modificarConfederaciones(eConfederacion*, int)
 * @brief Funcion que se encargara de pedir al usuario que campo desea modificar y tomar el dato
 *
 * @param Vector de Confederaciones
 * @param Posicion en el array de la Confederacion que se quiere modificar
 * @return Retorna 0 si no pudo hacerla o 1 si pudo ejecutar la funcion de forma correcta
 */
int modificarConfederaciones(eConfederacion* vecConfederaciones, int i);

/**
 * @fn int subMenuModificarConfederaciones()
 * @brief Funcion que se encarga de mostrar el submenu de la modificacion de Confederaciones y pedir la opcion para el switch
 *
 * @return Retorna la opcion elegida por el usuario
 */
int subMenuModificarConfederaciones();













