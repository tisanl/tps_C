/*
 * Informes.c
 *
 *  Created on: 11 dic. 2022
 *      Author: Usuario
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "Seleccion.h"
#include "PedirDatos.h"
#include "Informes.h"

int listar(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno = 0;

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL)
	{
		switch(subMenuListar())
		{
			case 1:
				controller_listarJugadores(pArrayListJugador, pArrayListSeleccion);
				retorno = 1;
				break;
			case 2:
				controller_listarSelecciones(pArrayListSeleccion);
				retorno = 1;
				break;
			case 3:
				if(jug_BuscarConvocado(pArrayListJugador) == 1)
				{
					jug_ImprimirConvocados(pArrayListJugador, pArrayListSeleccion);
				}
				else
				{
					printf("\nNo hay Jugadores Convocados en sistema\n");
				}
				retorno = 1;
				break;
			default:
				retorno = 3;
		}
	}
	else
	{
		printf("\nNo se pudo conseguir espacio en memoria\n");
	}

	return retorno;
}

int subMenuListar() //Submenu que pertenece a la funcion del listado de Jugador
{
    int opcion;

    printf("==============================================================\n");
    printf("*********************** MENU DE LISTADO **********************\n");
    printf("==============================================================\n\n");
    printf("Opcion 1: Todos los Jugadores\n");
    printf("Opcion 2: Todas las Selecciones\n");
    printf("Opcion 3: Jugadores Convocados\n");
    printf("Opcion 4: Salir\n\n");
    if(getIntRange(&opcion, 1, 4, 3, "Ingrese un numero entre las opciones: ", "Dato incorrecto. Ingrese un numero entre el 1 y el 4 segun las opciones: ") == -1) //Si no puede tomarla devolvera una opcion que ira al default
    {
    	opcion = 200;
    }

    return opcion; //Devuelve la opcion
}


//=======================================================================================================================================================//
//============================================================= JUGADORES ===============================================================================//
//=======================================================================================================================================================//

void jug_ImprimirenPantalla(Jugador* this, LinkedList* pArrayListSeleccion)
{
	int id, edad, idSeleccion, auxInt;
	char nombreCompleto[100];
	char posicion[30];
	char nacionalidad[30];
	char pais[30];
	Seleccion* auxSeleccion;

	if(this != NULL && pArrayListSeleccion != NULL)
	{
		jug_getAll(this, &id, nombreCompleto, posicion, nacionalidad, &edad, &idSeleccion);
		printf("|%4d|", id);
		printf("%30s|", nombreCompleto);
		printf("%22s|", posicion);
		printf("%16s|", nacionalidad);
		printf("%6d|", edad);
		if(idSeleccion == 0)
		{
			printf(" No convocado |\n");
		}
		else
		{
			auxInt = selec_FindById(pArrayListSeleccion, idSeleccion);
			if(auxInt != -1)
			{
				auxSeleccion = ll_get(pArrayListSeleccion, auxInt);
				selec_getPais(auxSeleccion, pais);
			}
			printf("%14s|\n", pais);
		}
	}
	else
	{
		printf("\nNo se pudo conseguir espacio en memoria\n");
	}
}

void jug_ImprimirJugadorUnico(Jugador* this, LinkedList* pArrayListSeleccion)
{
	if(this != NULL && pArrayListSeleccion != NULL)
	{//Se genera la estructura para mostrar en pantalla
		printf("\n|=================================================================================================|\n");
		printf("| Id |             Nombre           |       Posicion       |  Nacionalidad  | Edad |   Seleccion  |\n");
		printf("|----|------------------------------|----------------------|----------------|------|--------------|\n");
		jug_ImprimirenPantalla(this, pArrayListSeleccion); //Funcion que imprimira los datos del Jugador en pantalla
		printf("==================================================================================================|\n\n");
	}
	else
	{
		printf("\nNo se pudo conseguir espacio en memoria\n");
	}
}

int jug_ImprimirConvocados(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno = 0;
	int len = ll_len(pArrayListJugador); //Se define el tamaño de la lista para el for
	Jugador* auxJugador = NULL;
	int auxInt;

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL)
	{//Se genera la estructura para mostrar en pantalla
		printf("\n|=================================================================================================|\n");
		printf("| Id |             Nombre           |       Posicion       |  Nacionalidad  | Edad |   Seleccion  |\n");
		printf("|----|------------------------------|----------------------|----------------|------|--------------|\n");
		for(int i = 0; i < len; i++) //Este for recorrera el array de Jugadores
		{
			auxJugador = ll_get(pArrayListJugador, i); //Se obtiene el puntero al Jugador en la posicion I del array
			if(jug_getSIdSeleccion(auxJugador, &auxInt) == 1 && auxInt > 0)
			{
				jug_ImprimirenPantalla(auxJugador, pArrayListSeleccion); //Funcion que imprimira los datos del Jugador en pantalla
				retorno = 1;
			}
		}
		printf("==================================================================================================|\n\n");
	}
	else
	{
		printf("\nNo se pudo conseguir espacio en memoria\n");
	}

	return retorno;
}

int jug_ImprimirNoConvocados(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno = 0;
	int len = ll_len(pArrayListJugador); //Se define el tamaño de la lista para el for
	Jugador* auxJugador = NULL;
	int auxInt;

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL)
	{//Se genera la estructura para mostrar en pantalla
		printf("\n|=================================================================================================|\n");
		printf("| Id |             Nombre           |       Posicion       |  Nacionalidad  | Edad |   Seleccion  |\n");
		printf("|----|------------------------------|----------------------|----------------|------|--------------|\n");
		for(int i = 0; i < len; i++) //Este for recorrera el array de Jugadores
		{
			auxJugador = ll_get(pArrayListJugador, i); //Se obtiene el puntero al Jugador en la posicion I del array
			if(jug_getSIdSeleccion(auxJugador, &auxInt) == 1 && auxInt == 0)
			{
				jug_ImprimirenPantalla(auxJugador, pArrayListSeleccion); //Funcion que imprimira los datos del Jugador en pantalla
				retorno = 1;
			}
		}
		printf("==================================================================================================|\n\n");
	}
	else
	{
		printf("\nNo se pudo conseguir espacio en memoria\n");
	}

	return retorno;
}


//=======================================================================================================================================================//
//========================================================== SELECCIONES ===============================================================================//
//======================================================================================================================================================//

void selec_ImprimirenPantalla(Seleccion* this)
{
	int id, convocados;
	char pais[30];
	char confederacion[30];

	if(this != NULL)
	{
		selec_getAll(this, &id, pais, confederacion, &convocados);
		printf("|%4d|", id);
		printf("%16s|", pais);
		printf("%15s|", confederacion);
		printf("%12d|\n", convocados);
	}
	else
	{
		printf("\nNo se pudo conseguir espacio en memoria\n");
	}
}

//=======================================================================================================================================================//
//========================================================== ORDENAMIENTO ===============================================================================//
//======================================================================================================================================================//

int ordenar(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno = 0;

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL)
	{
		switch(subMenuOrdenar())
		{
			case 1:
				if(controller_ordenarJugadoresNacionalidad(pArrayListJugador) == 1)
				{
					printf("\nLos Jugadores han sido ordenados\n");
					retorno = 1;
				}
				else
				{
					printf("\nNo se pudo ordenar los Jugadores\n");
				}
				break;
			case 2:
				if(controller_ordenarSeleccionesConfederacion(pArrayListSeleccion) == 1)
				{
					printf("\nLas Selecciones han sido ordenadas\n");
					retorno = 1;
				}
				else
				{
					printf("\nNo se pudo ordenar las Selecciones\n");
				}
				break;
			case 3:
				if(controller_ordenarJugadoresEdad(pArrayListJugador) == 1)
				{
					printf("\nLos Jugadores han sido ordenados\n");
					retorno = 1;
				}
				else
				{
					printf("\nNo se pudo ordenar los Jugadores\n");
				}
				break;
			case 4:
				if(controller_ordenarJugadoresNombre(pArrayListJugador) == 1)
				{
					printf("\nLos Jugadores han sido ordenados\n");
					retorno = 1;
				}
				else
				{
					printf("\nNo se pudo ordenar los Jugadores\n");
				}
				break;
			default:
				retorno = 3;
		}
	}
	else
	{
		printf("\nNo se pudo conseguir espacio en memoria\n");
	}

	return retorno;
}

int subMenuOrdenar() //Submenu que pertenece a la funcion de ordenamiento
{
    int opcion;

    printf("==============================================================\n");
    printf("******************** MENU DE ORDENAMIENTO ********************\n");
    printf("==============================================================\n\n");
    printf("Opcion 1: Ordenar Jugadores por Nacionalidad\n");
    printf("Opcion 2: Ordenar Selecciones por confederacion\n");
    printf("Opcion 3: Ordenar Jugadores por Edad\n");
    printf("Opcion 4: Ordenar Jugadores por Nombre\n");
    printf("Opcion 5: Salir\n\n");
    if(getIntRange(&opcion, 1, 5, 3, "Ingrese un numero entre las opciones: ", "Dato incorrecto. Ingrese un numero entre el 1 y el 5 segun las opciones: ") == -1) //Si no puede tomarla devolvera una opcion que ira al default
    {
    	opcion = 200;
    }

    return opcion; //Devuelve la opcion
}

int ordenarJugadoresNacionalidad(void* jugador1, void* jugador2)
{
    int retorno = -1;
    Jugador* auxJugador1 = NULL;
    Jugador* auxJugador2 = NULL;
    char nacionalidadJug1[30];
    char nacionalidadJug2[30];

	if(jugador1 != NULL && jugador2 != NULL)
	{
		auxJugador1 = (Jugador*) jugador1;
		auxJugador2 = (Jugador*) jugador2;

		jug_getNacionalidad(auxJugador1, nacionalidadJug1);
		jug_getNacionalidad(auxJugador2, nacionalidadJug2);

		if(strcmp(nacionalidadJug1, nacionalidadJug2) > 0)
		{
			retorno = 1;
		}
		else
		{
			if(strcmp(nacionalidadJug1, nacionalidadJug2) < 0)
			{
				retorno = 0;
			}
		}
	}

    return retorno;
}

int ordenarJugadoresEdad(void* jugador1, void* jugador2)
{
    int retorno = -1;
    Jugador* auxJugador1 = NULL;
    Jugador* auxJugador2 = NULL;
    int edadJug1, edadJug2;

	if(jugador1 != NULL && jugador2 != NULL)
	{
		auxJugador1 = (Jugador*) jugador1;
		auxJugador2 = (Jugador*) jugador2;

		jug_getEdad(auxJugador1, &edadJug1);
		jug_getEdad(auxJugador2, &edadJug2);

		if(edadJug1 > edadJug2)
		{
			retorno = 1;
		}
		else
		{
			if(edadJug1 < edadJug2)
			{
				retorno = 0;
			}
		}
	}

    return retorno;
}

int ordenarJugadoresNombre(void* jugador1, void* jugador2)
{
    int retorno = -1;
    Jugador* auxJugador1 = NULL;
    Jugador* auxJugador2 = NULL;
    char nombreJug1[30];
    char nombreJug2[30];

	if(jugador1 != NULL && jugador2 != NULL)
	{
		auxJugador1 = (Jugador*) jugador1;
		auxJugador2 = (Jugador*) jugador2;

		jug_getNombreCompleto(auxJugador1, nombreJug1);
		jug_getNombreCompleto(auxJugador2, nombreJug2);

		if(strcmp(nombreJug1, nombreJug2) > 0)
		{
			retorno = 1;
		}
		else
		{
			if(strcmp(nombreJug1, nombreJug2) < 0)
			{
				retorno = 0;
			}
		}
	}

    return retorno;
}

int ordenarSeleccionesConfederacion(void* seleccion1, void* seleccion2)
{
    int retorno = -1;
    Seleccion* auxSeleccion1 = NULL;
    Seleccion* auxSeleccion2 = NULL;
    char confederacionSelec1[30];
    char confederacionSelec2[30];

	if(seleccion1 != NULL && seleccion2 != NULL)
	{
		auxSeleccion1 = (Seleccion*) seleccion1;
		auxSeleccion2 = (Seleccion*) seleccion2;

		selec_getConfederacion(auxSeleccion1, confederacionSelec1);
		selec_getConfederacion(auxSeleccion2, confederacionSelec2);

		if(strcmp(confederacionSelec1, confederacionSelec2) > 0)
		{
			retorno = 1;
		}
		else
		{
			if(strcmp(confederacionSelec1, confederacionSelec2) < 0)
			{
				retorno = 0;
			}
		}
	}

    return retorno;
}

