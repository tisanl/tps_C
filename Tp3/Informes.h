/*
 * Informes.h
 *
 *  Created on: 11 dic. 2022
 *      Author: Usuario
 */

#ifndef INFORMES_H_
#define INFORMES_H_


/**
 * @fn int listar(LinkedList*, LinkedList*)
 * @brief Funcion principal del punto 5 Listar
 *
 * @param pArrayListJugador
 * @param pArrayListSeleccion
 * @return Retorna 1 en mayoria de casos o 3 si el usuario queire volver al menu principal
 */
int listar(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

/**
 * @fn int subMenuListar()
 * @brief Funcion submenu de la opcion listar
 *
 * @return devuelve la opcion ingresada por el usuario
 */
int subMenuListar();

/**
 * @fn void jug_ImprimirenPantalla(Jugador*, LinkedList*)
 * @brief  Funcion que imprimira a un Jugador en la pantalla
 *
 * @param this
 * @param pArrayListSeleccion
 */
void jug_ImprimirenPantalla(Jugador* this, LinkedList* pArrayListSeleccion);

/**
 * @fn void jug_ImprimirJugadorUnico(Jugador*, LinkedList*)
 * @brief Funcion destinada a mostrar un unico Jugador en pantalla
 *
 * @param this
 * @param pArrayListSeleccion
 */
void jug_ImprimirJugadorUnico(Jugador* this, LinkedList* pArrayListSeleccion);

/**
 * @fn int jug_ImprimirConvocados(LinkedList*, LinkedList*)
 * @brief Funcion que imprimira los Jugadores convocados
 *
 * @param pArrayListJugador
 * @param pArrayListSeleccion
 * @return Devuelve 0 si no pudo ejecutarse o 1 si pudo
 */
int jug_ImprimirConvocados(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

/**
 * @fn int jug_ImprimirNoConvocados(LinkedList*, LinkedList*)
 * @brief Funcion que imprimira los Jugadores no convocados
 *
 * @param pArrayListJugador
 * @param pArrayListSeleccion
 * @return Devuelve 0 si no pudo ejecutarse o 1 si pudo
 */
int jug_ImprimirNoConvocados(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

/**
 * @fn void selec_ImprimirenPantalla(Seleccion*)
 * @brief Funcion que imprimira en pantalla una Seleccion
 *
 * @param this la direccion de memoria con la Seleccion a imprimir
 */
void selec_ImprimirenPantalla(Seleccion* this);

/**
 * @fn int ordenar(LinkedList*, LinkedList*)
 * @brief Fuancion principal para ordenar las listas de Jugadores o Selecciones
 *
 * @param pArrayListJugador
 * @param pArrayListSeleccion
 * @return Retorna 1 si pudo ejecutarse o 0 si fallo
 */
int ordenar(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

/**
 * @fn int subMenuOrdenar()
 * @brief Funcion que ejecuta el subbmenu de ordenar
 *
 * @return Retorna la opcion
 */
int subMenuOrdenar();

/**
 * @fn int ordenarJugadoresNacionalidad(void*, void*)
 * @brief Funcion criterio de Jugadores por nacionalidad
 *
 * @param jugador1
 * @param jugador2
 * @return Retorna -1 si la ejecucion fallo, 1 si es el parametro 2 es mayor al 1, -1 al reves o 0 si son iguales
 */
int ordenarJugadoresNacionalidad(void* jugador1, void* jugador2);

/**
 * @fn int ordenarJugadoresEdad(void*, void*)
 * @brief Funcion criterio de Jugadores por edad
 *
 * @param jugador1
 * @param jugador2
 * @return Retorna -1 si la ejecucion fallo, 1 si es el parametro 2 es mayor al 1, -1 al reves o 0 si son iguales
 */
int ordenarJugadoresEdad(void* jugador1, void* jugador2);

/**
 * @fn int ordenarJugadoresNombre(void*, void*)
 * @brief Funcion criterio de Jugadores por nombre
 *
 * @param jugador1
 * @param jugador2
 * @return Retorna -1 si la ejecucion fallo, 1 si es el parametro 2 es mayor al 1, -1 al reves o 0 si son iguales
 */
int ordenarJugadoresNombre(void* jugador1, void* jugador2);

/**
 * @fn int ordenarSeleccionesConfederacion(void*, void*)
 * @brief Funcion criterio de Selecciones por Confederacion
 *
 * @param seleccion1
 * @param seleccion2
 * @return Retorna -1 si la ejecucion fallo, 1 si es el parametro 2 es mayor al 1, -1 al reves o 0 si son iguales
 */
int ordenarSeleccionesConfederacion(void* seleccion1, void* seleccion2);
#endif /* INFORMES_H_ */
