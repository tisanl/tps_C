#include "LinkedList.h"

#ifndef selec_H_INCLUDED
#define selec_H_INCLUDED

typedef struct
{
	int id;
	char pais[30];
	char confederacion[30];
	int convocados;
}Seleccion;

Seleccion* selec_new();
Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr);
void selec_delete(Seleccion* this);

int selec_getId(Seleccion* this,int* id);
int selec_getPais(Seleccion* this,char* pais);
int selec_getConfederacion(Seleccion* this,char* confederacion);

int selec_setConvocados(Seleccion* this,int convocados);
int selec_getConvocados(Seleccion* this,int* convocados);

/**
 * @fn int selec_getAll(Seleccion*, int*, char*, char*, int*)
 * @brief Funciono geter de todos los campos de Seleccion
 *
 * @param this
 * @param id
 * @param pais
 * @param confederacion
 * @param convocados
 * @return Retorna 1 si pudo obtenerlo y 0 si no
 */
int selec_getAll(Seleccion* this, int* id, char* pais, char* confederacion, int* convocados);

/**
 * @fn int selec_FindById(LinkedList*, int)
 * @brief Funcion que buscara una Seleccion de la Linkedlist segun su Id
 *
 * @param pArrayListSeleccion
 * @param id
 * @return Retorna la posicion en el Linkedlist de ese elemento
 */
int selec_FindById(LinkedList* pArrayListSeleccion, int id);

/**
 * @fn int selec_clenAll(LinkedList*)
 * @brief Funcion que se encarga de limpiar las Selecciones de memoria
 *
 * @param pArrayListSeleccion
 * @return Retorna 1 si pudo ejecutarse o 0 si fallo
 */
int selec_clenAll(LinkedList* pArrayListSeleccion);

#endif // selec_H_INCLUDED
