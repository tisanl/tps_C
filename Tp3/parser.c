#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"

/** \brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 */
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador)
{
	int retorno = 0;
	Jugador* nuevoJugador;
	char id[4];
	char nombreCompleto[100];
	char edad[4];
	char posicion[30];
	char nacionalidad[30];
	char idSeleccion[4];

	if(pFile != NULL && pArrayListJugador != NULL)
	{
		fscanf(pFile, "%[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n", id, nombreCompleto, edad, posicion, nacionalidad, idSeleccion); //Falsa lectura para el header
		while(!feof(pFile))
		{
			if(fscanf(pFile, "%[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n", id, nombreCompleto, edad, posicion, nacionalidad, idSeleccion) == 6)
			{
				nuevoJugador = jug_newParametros(id, nombreCompleto, edad, posicion, nacionalidad, idSeleccion);
				if(nuevoJugador != NULL)
				{
					if(ll_add(pArrayListJugador, nuevoJugador) != -1)
					{
						retorno = 1;
					}
					else
					{
						jug_delete(nuevoJugador);
						printf("\nNo se pudo conseguir espacio en memoria\n");
						break;
					}
				}
			}
			else
			{
				printf("\nNo se pudo leer los datos\n");
				break;
			}
		}
	}
	else
	{
		printf("\nNo se pudo conseguir espacio en memoria\n");
	}

    return retorno;
}

/** \brief Parsea los datos de los jugadores desde el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador)
{
	int retorno = 0;
	Jugador* nuevoJugador;

	if(pFile != NULL && pArrayListJugador != NULL)
	{
		while(!(feof(pFile)))
		{
			nuevoJugador = jug_new();
			if(nuevoJugador != NULL && fread(nuevoJugador, sizeof(Jugador), 1, pFile) == 1)
			{
				if(ll_add(pArrayListJugador, nuevoJugador) != -1)
				{
					retorno = 1;
				}
				else
				{
					printf("\nNo se pudo conseguir espacio en memoria\n");
					jug_delete(nuevoJugador);
				}
			}
		}
	}
	else
	{
		printf("\nNo se pudo conseguir espacio en memoria\n");
	}

    return retorno;
}


/** \brief Parsea los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion)
{
	int retorno = 0;
	Seleccion* nuevaSeleccion;
	char id[4];
	char pais[30];
	char confederacion[30];
	char convocados[4];

	if(pFile != NULL && pArrayListSeleccion != NULL)
	{
		fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", id, pais, confederacion, convocados); //Falsa lectura para el header
		while(!feof(pFile))
		{
			if(fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", id, pais, confederacion, convocados) == 4)
			{
				nuevaSeleccion = selec_newParametros(id, pais, confederacion, convocados);
				if(nuevaSeleccion != NULL)
				{
					if(ll_add(pArrayListSeleccion, nuevaSeleccion) != -1)
					{
						retorno = 1;
					}
					else
					{
						selec_delete(nuevaSeleccion);
						printf("\nNo se pudo conseguir espacio en memoria\n");
						break;
					}
				}
			}
			else
			{
				printf("\nNo se pudo leer los datos\n");
				break;
			}
		}
	}
	else
	{
		printf("\nNo se pudo conseguir espacio en memoria\n");
	}

    return retorno;
}

