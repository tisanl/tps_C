/*
 * FuncionesInformes.h
 *
 *  Created on: 26 oct. 2022
 *      Author: Usuario
 */

#ifndef FUNCIONESINFORMES_H_
#define FUNCIONESINFORMES_H_



#endif /* FUNCIONESINFORMES_H_ */

/**
 * @fn int subMenuInformes()
 * @brief Funcion que desplegara el submenu de opciones de los Informes
 *
 * @return Devuelve la opcion para que el switch pueda continuar con el programa
 */
int subMenuInformes();

/**
 * @fn int informes(eJugador*, int, eConfederacion*, int)
 * @brief Funcion que se encargara de mostrar el informe que el usuario queire mostrar a traves de un switch
 *
 * @param Vector de Jugadores
 * @param Tamaño del vector de Jugadores
 * @param Vector de Confederaciones
 * @param Tamaño del vector de Confederaciones
 * @return Retorna 0 si no pudo conseguir memoria o 1 si pudo mostrar algun Informe o -1 si el usuario queire volver al Menu Principal
 */
int informes(eJugador* vecJugadores, int sizeJugadores, eConfederacion* vecConfederaciones, int sizeConfederaciones);

/**
 * @fn int ordenarJugadoresAlfConYNom(eJugador*, int, eConfederacion*, int)
 * @brief Funcion que ordenara el array de Jugadores en orden alfabetico con, como primer criterio, el nombbre de la Confedaracion, y segundo, el nombre
 * del Jugador
 * @param Vector de Jugadores
 * @param Tamaño del vector de Jugadores
 * @param Vector de Confederaciones
 * @param Tamaño del vector de Confederaciones
 * @return Retorna 0 si no pudo conseguir memoria o 1 si pudo ordenar el array
 */
int ordenarJugadoresAlfConYNom(eJugador* vecJugadores, int sizeJugadores, eConfederacion* vecConfederaciones, int sizeConfederaciones);

/**
 * @fn int listarConfederacionesConJugadores(eJugador*, int, eConfederacion*, int)
 * @brief Funcion que mostrara las confederaciones y cada Jugador que le pertenece
 *
 * @param Vector de Jugadores
 * @param Tamaño del vector de Jugadores
 * @param Vector de Confederaciones
 * @param Tamaño del vector de Confederaciones
 * @return Retorna 0 si no pudo conseguir memoria o 1 si pudo ordenar el array
 */
int listarConfederacionesConJugadores(eJugador* vecJugadores, int sizeJugadores, eConfederacion* vecConfederaciones, int sizeConfederaciones);

/**
 * @fn int buscarJugadorConfederacion(eJugador*, int, int)
 * @brief Funcion que buscara si hay algun que pertenezca a alguna Confederacion
 *
 * @param Vector de Jugadores
 * @param Tamaño del vector de Jugadores
 * @param El id de la Confederacion de la que se busca al menos 1 jugador
 * @return Retorna 0 si no encontro memoria, -1 si no encontro Jugador o 1 si encontro
 */
int buscarJugadorConfederacion(eJugador* vecJugadores, int sizeJugadores, int idConfederacion);

/**
 * @fn int promedioSalarios(eJugador*, int)
 * @brief Funcion que se encargara de buscar el total y promedio de todos los salarios y cuántos Jugadores cobran más del salario promedio
 *
 * @param Vector de Jugadores
 * @param Tamaño del vector de Jugadores
 * @return Retorna 0 si no pudo mostrarlo o 1 si pudo
 */
int promedioSalarios(eJugador* vecJugadores, int sizeJugadores);

/**
 * @fn int acumularSalario(eJugador*, int, float*, int*)
 * @brief Funcion que se encargara de acumular los salarios y la cantidad de Jugadores para despues calcular el promedio
 *
 * @param Vector de Jugadores
 * @param Tamaño del vector de Jugadores
 * @param Direccion de memoria donde se acumularan los salarios
 * @param Direccion de memoria donde se contaran los Jugadores
 * @return Retorna 0 si no pudo mostrarlo o 1 si pudo
 *
 */
int acumularSalario(eJugador* vecJugadores, int sizeJugadores, float* acumulador, int* contador);

/**
 * @fn int jugadoresCobranMas(eJugador*, int, float, int*)
 * @brief Funcion que buscara la cantidad de Jugadores que superen el salario promedio
 *
 * @param Vector de Jugadores
 * @param Tamaño del vector de Jugadores
 * @param Valor del salario promedio
 * @param Direccion de memoria donde se guardara la cantidad de Jugadores cuyo salario supera el promedio
 * @return Retorna 0 si no pudo mostrarlo o 1 si pudo
 */
int jugadoresCobranMas(eJugador* vecJugadores, int sizeJugadores, float salarioPromedio, int* contador);

/**
 * @fn int confederacionMasAniosContrato(eJugador*, int)
 * @brief Funcion que se encarga de mostrar la Confederacion que tiene mas anios de contrato
 *
 * @param Vector de Jugadores
 * @param Tamaño del vector de Jugadores
 * @return Retorna 0 si no pudo mostrarlo o 1 si pudo
 */
int confederacionMasAniosContrato(eJugador* vecJugadores, int sizeJugadores);

/**
 * @fn int acumularAniosContrato(eJugador*, int, int*)
 * @brief Funcion que se encargara de cargar un vector con la cantidad de anios de contrato por Confederacion
 *
 * @param Vector de Jugadores
 * @param Tamaño del vector de Jugadores
 * @param Vector donde se acumularan los anios de contrato por Confederacion
 * @return Retorna 0 si no puso cargarlo o 1 si pudo
 */
int acumularAniosContrato(eJugador* vecJugadores, int sizeJugadores, int* vecAcumulador);

/**
 * @fn int mostrarPorcentajesPorConfederacion(eJugador*, int, eConfederacion*)
 * @brief Funcion que se encargara de calcular y mostrar el porcentaje de la cantidad de Jugadores por Confederacion
 *
 * @param Vector de Jugadores
 * @param Tamaño del vector de Jugadores
 * @param Vector de Confederaciones
 * @return Retorna 0 si no pudo ejecutarse o 1 si pudo
 */
int mostrarPorcentajesPorConfederacion(eJugador* vecJugadores, int sizeJugadores, eConfederacion* vecConfederaciones);

/**
 * @fn int acumularCantidadJugadores(eJugador*, int, int*)
 * @brief Funcion que se encargara de contar la cantidad de Jugadores en cada Confederacion y guardarlo en un vector
 *
 * @param Vector de Jugadores
 * @param Tamaño del vector de Jugadores
 * @param Vector donde se acumularan la cantidad de Jugadores por Confederacion
 * @return Retorna 0 si no pudo ejecutarse o 1 si pudo
 */
int acumularCantidadJugadores(eJugador* vecJugadores, int sizeJugadores, int* vecAcumulador);

/**
 * @fn int mostrarJugadoresRegion(eJugador*, int, eConfederacion*, int)
 * @brief Funcion que se encarga de mostrar los Jugadores que pertenezen a la Region que posee mas
 *
 * @param Vector de Jugadores
 * @param Tamaño del vector de Jugadores
 * @param Vector de Confederaciones
 * @param Tamaño del vector de Confederaciones
 * @return Retorna 0 si no pudo ejecutarse o 1 si pudo
 */
int mostrarJugadoresRegion(eJugador* vecJugadores, int sizeJugadores, eConfederacion* vecConfederaciones, int sizeConfederaciones);

/**
 * @fn int buscarRegionMasJugadores(eJugador*, int, int*, int*)
 * @brief  Funcion que buscara la Region que posee mas Jugadores
 *
 * @param Vector de Jugadores
 * @param Tamaño del vector de Jugadores
 * @param Vector donde esta guardado la cantidad de Jugadores por Region
 * @param Direccion de memoria donde se guardara el Id que corresponde a la Region con mas Jugadores
 * @return Retorna 0 si no pudo ejecutarse o 1 si pudo
 */
int buscarRegionMasJugadores(eJugador* vecJugadores, int sizeJugadores, int* vecAcumulador, int* idConfederacion);
