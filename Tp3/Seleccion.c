#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "Seleccion.h"
#include "Informes.h"

Seleccion* selec_new()
{
	Seleccion* seleccion;

	seleccion = (Seleccion*) malloc(sizeof(Seleccion));

	return seleccion;
}

Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr)
{
	Seleccion* seleccion;

	if(idStr != NULL && paisStr != NULL && confederacionStr != NULL && convocadosStr != NULL)
	{
		seleccion = selec_new();
		if(seleccion != NULL)
		{
			seleccion->id = atoi(idStr);
			strcpy(seleccion->pais, paisStr);
			strcpy(seleccion->confederacion, confederacionStr);
			seleccion->convocados = atoi(convocadosStr);
		}
		else
		{
			printf("\nNo se pudo conseguir espacio en memoria, la Seleccion no fue generada\n");
		}
	}
	else
	{
		printf("\nNo se pudo conseguir espacio en memoria, la Seleccion no fue generada\n");
	}

	return seleccion;
}

void selec_delete(Seleccion* this)
{
	if(this != NULL)
	{
		free(this);
	}
	else
	{
		printf("\nNo se pudo conseguir espacio en memoria\n");
	}
}

int selec_getId(Seleccion* this,int* id)
{
	int retorno = 0;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 1;
	}
	else
	{
		printf("\nNo se pudo obtener el Id de la Seleccion\n");
	}

	return retorno;
}

int selec_getPais(Seleccion* this,char* pais)
{
	int retorno = 0;

	if(this != NULL && pais != NULL)
	{
		strcpy(pais, this->pais);
		retorno = 1;
	}
	else
	{
		printf("\nNo se pudo obtener el pais de la Seleccion\n");
	}

	return retorno;
}

int selec_getConfederacion(Seleccion* this,char* confederacion)
{
	int retorno = 0;

	if(this != NULL && confederacion != NULL)
	{
		strcpy(confederacion, this->confederacion);
		retorno = 1;
	}
	else
	{
		printf("\nNo se pudo obtener la confederacion de la Seleccion\n");
	}

	return retorno;
}

int selec_setConvocados(Seleccion* this,int convocados)
{
	int retorno = 0;

	if(this != NULL && convocados >= 0)
	{
		this->convocados = convocados;
		retorno = 1;
	}
	else
	{
		printf("\nNo se pudo guardar la cantidad de convocados de la Seleccion\n");
	}

	return retorno;
}

int selec_getConvocados(Seleccion* this,int* convocados)
{
	int retorno = 0;

	if(this != NULL && convocados != NULL)
	{
		*convocados = this->convocados;
		retorno = 1;
	}
	else
	{
		printf("\nNo se pudo obtener la cantidad de convocados de la Seleccion\n");
	}

	return retorno;
}

int selec_getAll(Seleccion* this, int* id, char* pais, char* confederacion, int* convocados)
{
	int retorno = 0;

	if(selec_getId(this, id) == 1 &&
		selec_getPais(this, pais) == 1 &&
		selec_getConfederacion(this, confederacion) == 1 &&
		selec_getConvocados(this, convocados) == 1)
	{
		retorno = 1;
	}
	else
	{
		printf("\nNo se pudo obtener los datos del Jugador\n");
	}

	return retorno;
}

int selec_FindById(LinkedList* pArrayListSeleccion, int id)
{
	int len = ll_len(pArrayListSeleccion);
	Seleccion* auxSeleccion = NULL;
	int auxInt;
	int array = -1;

    if(pArrayListSeleccion != NULL)
    {
    	for(int i = 0; i < len; i ++)
    	{
    		auxSeleccion = ll_get(pArrayListSeleccion, i); //Se obtiene el puntero al Jugador en la posicion I del array
    		selec_getId(auxSeleccion, &auxInt); //Se obtiene el valor de su Id
    		if(auxInt == id) //Se busca que los id coincidan
    		{
    			array = i;
    			break;
    		}
    	}
    }
    else
    {
    	printf("No se pudo conseguir espacio en memoria");
    }

    return array; //Devuelve la posicion en el LinkedList
}

//=======================================================================================================================================================//
//===================================================== LIMPIAR MEMORIA ==================================================================================//
//=======================================================================================================================================================//

int selec_clenAll(LinkedList* pArrayListSeleccion)
{
	int retorno = 0;
	int len = ll_len(pArrayListSeleccion);
	Seleccion* auxSeleccion = NULL;

	if(pArrayListSeleccion != NULL && len >= 0)
	{
		for(int i = 0; i < len; i ++)
		{
			auxSeleccion = ll_get(pArrayListSeleccion, i);
			selec_delete(auxSeleccion);
		}

		retorno = 1;
	}

	return retorno;
}


