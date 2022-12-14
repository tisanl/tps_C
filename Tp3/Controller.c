#include <stdio.h>
#include <stdlib.h>

#include "Jugador.h"
#include "Seleccion.h"
#include "LinkedList.h"
#include "parser.h"
#include "PedirDatos.h"
#include "Controller.h"
#include "Informes.h"


//=======================================================================================================================================================//
//====================================================== FUNCIONES JUGADORES =============================================================================//
//=======================================================================================================================================================//

/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int Devuelve 0 si no pudo obtener memoria, 1 si pudo realizar la funcion o -1 si no pudo encontrar el archivo
 *
 */
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador)
{
	int retorno = 0;
	FILE* pArchivo;

	if(path != NULL && pArrayListJugador != NULL)
	{
		pArchivo = fopen(path, "r");
		if(pArchivo != NULL)
		{
			parser_JugadorFromText(pArchivo, pArrayListJugador);
			retorno = 1;
			fclose(pArchivo);
		}
		else
		{
			printf("\nNo se pudo encontrar el archivo");
			retorno = -1;
		}
	}
	else
	{
		printf("\nNo se pudo conseguir espacio en memoria\n");
	}

    return retorno;
}

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int Devuelve 0 si no pudo obtener memoria, 1 si pudo realizar la funcion o -1 si no pudo encontrar el archivo
 *
 */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador)
{
	int retorno = 0;
	FILE* pFile;

	if(path != NULL && pArrayListJugador != NULL)
	{
		pFile = fopen(path, "rb");
		if(pFile != NULL)
		{
			parser_JugadorFromBinary(pFile, pArrayListJugador);
			retorno = 1;
			fclose(pFile);
		}
		else
		{
			printf("\nNo se pudo encontrar el archivo");
			retorno = -1;
		}
	}
	else
	{
		printf("\nNo se pudo conseguir espacio en memoria\n");
	}

    return retorno;
}

/** \brief Alta de jugadores
 *
 * \param pArrayListJugador LinkedList*
 * \param Direccion de memoria de la variable que contiene el id autoincremental
 * \return int Retorna 0 si no obtuvo memoria, -1 si no pudo crear al Jugador o 1 si si
 *
 */
int controller_agregarJugador(LinkedList* pArrayListJugador, int* id)
{
	int retorno = 0;
	Jugador* auxJugador = NULL;

	if(pArrayListJugador != NULL && id != NULL)
	{
		auxJugador = jug_crearJugador(*id);
		if(auxJugador != NULL && ll_add(pArrayListJugador, auxJugador) == 0) //Funcion que creara al Jugador
		{
			*id = *id + 1;//Si pudo hacerlo incrementara el Id y dar aviso que se pudo
			printf("\nEl Jugador fue añadido con exito\n");
			retorno = 1;
		}
		else
		{
			printf("\nEl Jugador no ha sido guardado\n");
			retorno = -1;
		}
	}
	else
	{
		printf("\nNo se pudo conseguir espacio en memoria\n");
	}

	return retorno;
}

/** \brief Modificar datos del jugador
 *
 * \param pArrayListJugador LinkedList*
 * \param pArrayListSeleccion LinkedList*
 * \return int Devuelve 0 si no pudo obtener memoria, -1 si fallo o 1 si pudo realizar la funcion
 *
 */
int controller_editarJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno = 0;
	char confirm = 'n';
	int id;
	int auxInt;
	Jugador* auxJugador = NULL;

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL)
	{
		controller_listarJugadores(pArrayListJugador, pArrayListSeleccion);

		if(getIntPositiv(&id, 3, "Ingrese el Id del Jugador que quiere modificar: ", "Id incorrecto. Elija un numero positivo: ") == 1)
		{
			auxInt =  jug_FindById(pArrayListJugador, id); //Funcion que buscara la posicion en el array del Jugador dependiendo el Id y la devolvera
	    	if(auxInt != -1)
	    	{
	    		auxJugador = ll_get(pArrayListJugador, auxInt); //Se obtiene el puntero al Jugador en la posicion I del array
	    		jug_ImprimirJugadorUnico(auxJugador, pArrayListSeleccion);//Muestra el Jugador con el cual se trabajara
	    		do{
	    			auxInt = subMenuModificar(); //Se desplegara el submenu para seleccionar la opcion que quiera el usuario
	    			if(auxInt > 4)
	    			{
	    				printf("\nSera devuelto al menu\n"); //En caso de que no haya podido ingresar una opcion o eliga salir al menu
	    				break;
	    			}
	    			else
	    			{
						jug_Modificar(auxJugador, auxInt);
						printf("Ingrese 'Y' si quiere modificar otro dato o cualquier otra tecla para volver al menu:");
						getCaracterTolower(&confirm);
	    			}
	    		}while(confirm == 'y');
	    		retorno = 1;
	    	}
	    	else{
	    		printf("\nNo hay un Jugador con ese Id\n");
	    		retorno = -1;
	    	}
		}
		else{
			retorno = -1;
		}
	}
	else
	{
		printf("\nNo se pudo conseguir espacio en memoria\n");
	}

	return retorno;
}

/** \brief Baja del jugador
 *
 * \param pArrayListJugador LinkedList*
 * \param pArrayListSeleccion LinkedList*
 * \return int Devuelve 0 si no pudo obtener memoria, -1 si fallo o 1 si pudo realizar la funcion
 *
 */
int controller_removerJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno = 0;
	int id, idSeleccion;
	Jugador* auxJugador = NULL;
	int auxInt;

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL)
	{
		controller_listarJugadores(pArrayListJugador, pArrayListSeleccion);

		if(getIntPositiv(&id, 3, "Ingrese el Id del Jugador que quiere dar de Baja: ", "Id incorrecto. Elija un numero positivo: ") == 1)
		{
			auxInt = jug_FindById(pArrayListJugador, id); //Funcion que buscara la posicion en el array del Jugador dependiendo el Id y la devolvera
	    	if(auxInt != -1)
	    	{
	    		auxJugador = ll_get(pArrayListJugador, auxInt); //Se obtiene el puntero al Jugador en la posicion I del array
	    		jug_ImprimirJugadorUnico(auxJugador, pArrayListSeleccion);//Muestra el Jugador con el cual se trabajara
	    		if(jug_ConfirmarBaja() == 1)
	    		{
	    			jug_getSIdSeleccion(auxJugador, &idSeleccion); //En caso que este convocado se recucira en 1
	    			if(idSeleccion != 0)
	    			{
	    				jug_ReducirConvocados(pArrayListSeleccion, idSeleccion);
	    			}
	    			jug_delete(auxJugador); //Se borra el Jugador
	    			ll_remove(pArrayListJugador, auxInt); //Se borra la posicion en el LinkedList
	    			printf("\nEl Jugador se ha dado de baja con exito.\n");
	    		}
	    		else{
	    			printf("\nEl Jugador no se ha dado de baja.\n");
	    		}
	    		retorno = 1;
	    	}
	    	else{
	    		printf("\nNo hay un Jugador con ese Id\n");
	    		retorno = -1;
	    	}
		}
		else{
			retorno = -1;
		}
	}
	else
	{
		printf("\nNo se pudo conseguir espacio en memoria\n");
	}

	return retorno;
}

/** \brief Listar jugadores
 *
 * \param pArrayListJugador LinkedList*
 * \param pArrayListSeleccion LinkedList*
 * \return int Devuelve 0 si no pudo obtener memoria o 1 si pudo realizar la funcion
 *
 */
int controller_listarJugadores(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno = 0;
	int len = ll_len(pArrayListJugador); //Se define el tamaño de la lista para el for
	Jugador* auxJugador = NULL;

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL)
	{//Se genera la estructura para mostrar en pantalla
		printf("\n|=================================================================================================|\n");
		printf("| Id |             Nombre           |       Posicion       |  Nacionalidad  | Edad |   Seleccion  |\n");
		printf("|----|------------------------------|----------------------|----------------|------|--------------|\n");
		for(int i = 0; i < len; i++) //Este for recorrera el array de Jugadores
		{
			auxJugador = ll_get(pArrayListJugador, i); //Se obtiene el puntero al Jugador en la posicion I del array
			jug_ImprimirenPantalla(auxJugador, pArrayListSeleccion); //Funcion que imprimira los datos del Jugador en pantalla
		}
		printf("==================================================================================================|\n\n");
		retorno = 1;
	}
	else
	{
		printf("\nNo se pudo conseguir espacio en memoria\n");
	}

	return retorno;
}

/** \brief Ordenar jugadores por nacionalidad
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int Devuelve 0 si no pudo ejecutrarse o 1 si si
 *
 */
int controller_ordenarJugadoresNacionalidad(LinkedList* pArrayListJugador)
{
	int retorno = 0;
	if(pArrayListJugador != NULL)
	{
		ll_sort(pArrayListJugador, ordenarJugadoresNacionalidad, 1);
		retorno = 1;
	}
    return retorno;
}

/** \brief Ordenar jugadores por edad
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int int Devuelve 0 si no pudo ejecutrarse o 1 si si
 *
 */
int controller_ordenarJugadoresEdad(LinkedList* pArrayListJugador)
{
	int retorno = 0;
	if(pArrayListJugador != NULL)
	{
		ll_sort(pArrayListJugador, ordenarJugadoresEdad, 1);
		retorno = 1;
	}
    return retorno;
}

/** \brief Ordenar jugadores por condeferacion
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int int Devuelve 0 si no pudo ejecutrarse o 1 si si
 *
 */
int controller_ordenarJugadoresNombre(LinkedList* pArrayListJugador)
{
	int retorno = 0;
	if(pArrayListJugador != NULL)
	{
		ll_sort(pArrayListJugador, ordenarJugadoresNombre, 1);
		retorno = 1;
	}
    return retorno;
}

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int Devuelve 0 si no pudo obtener memoria o 1 si pudo realizar la funcion
 *
 */
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador)
{
	int retorno = 0;
	FILE* pArchivo = fopen(path, "w");
	Jugador* auxJugador;
	int id, edad, idSeleccion;
	char nombreCompleto[100];
	char posicion[30];
	char nacionalidad[30];
	int len = ll_len(pArrayListJugador);

	if(path != NULL && pArrayListJugador != NULL && pArchivo != NULL)
	{
		fprintf(pArchivo, "id,nombreCompleto,edad,posicion,nacionalidad,idSelecion\n");
		for(int i = 0; i < len; i ++)
		{
			auxJugador = ll_get(pArrayListJugador, i);
			if(auxJugador != NULL && jug_getAll(auxJugador, &id, nombreCompleto, posicion, nacionalidad, &edad, &idSeleccion) == 1)
			{
				fprintf(pArchivo, "%d, %s, %d, %s, %s, %d\n", id, nombreCompleto, edad, posicion, nacionalidad, idSeleccion);
			}
		}
		fclose(pArchivo);
		retorno = 1;
	}
	else
	{
		printf("\nNo se pudo conseguir espacio en memoria\n");
	}

    return retorno;
}

/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int Devuelve 0 si no pudo obtener memoria o 1 si pudo realizar la funcion
 *
 */
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador)
{
	int retorno = 0;
	FILE* pArchivo = fopen(path, "wb");
	int len = ll_len(pArrayListJugador);
	Jugador* auxJugador;

	if(path != NULL && pArrayListJugador != NULL && pArchivo != NULL)
	{
		fprintf(pArchivo, "id,nombreCompleto,edad,posicion,nacionalidad,idSelecion\n");
		for(int i = 0; i < len; i ++)
		{
			auxJugador = ll_get(pArrayListJugador, i);
			if(fwrite(auxJugador, sizeof(Jugador), 1, pArchivo) == 1)
			{
				retorno = 1;
			}
			else
			{
				printf("\nNo se pudo guardar el dato\n");
				retorno = -1;
			}
		}
		fclose(pArchivo);
	}
	else
	{
		printf("\nNo se pudo conseguir espacio en memoria\n");
	}

    return retorno;
}

//=======================================================================================================================================================//
//==================================================== FUNCIONES SELECCIONES =============================================================================//
//=======================================================================================================================================================//

/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int Devuelve 0 si no pudo obtener memoria, 1 si pudo realizar la funcion o -1 si no pudo encontrar el archivo
 *
 */
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion)
{
	int retorno = 0;
	FILE* pArchivo;

	if(path != NULL && pArrayListSeleccion != NULL)
	{
		pArchivo = fopen(path, "r");
		if(pArchivo != NULL)
		{
			parser_SeleccionFromText(pArchivo, pArrayListSeleccion);
			retorno = 1;
			fclose(pArchivo);
		}
		else
		{
			printf("\nNo se pudo encontrar el archivo");
			retorno = -1;
		}
	}
	else
	{
		printf("\nNo se pudo conseguir espacio en memoria\n");
	}

    return retorno;
}

/** \brief Listar selecciones
 *
 * \param pArrayListSeleccion LinkedList*
 * \return int Devuelve 0 si no pudo obtener memoria o 1 si pudo realizar la funcion
 *
 */
int controller_listarSelecciones(LinkedList* pArrayListSeleccion)
{
	int retorno = 0;
	int len = ll_len(pArrayListSeleccion); //Se define el tamaño de la lista para el for
	Seleccion* auxSeleccion = NULL;

	if(pArrayListSeleccion != NULL)
	{//Se genera la estructura para mostrar en pantalla
		printf("\n|==================================================|\n");
		printf("| Id |      Pais      | Confederacion | Convocados |\n");
		printf("|----|----------------|---------------|------------|\n");
		for(int i = 0; i < len; i++) //Este for recorrera el array de Selecciones
		{
			auxSeleccion = ll_get(pArrayListSeleccion, i); //Se obtiene el puntero de la Seleccion en la posicion I del array
			selec_ImprimirenPantalla(auxSeleccion); //Funcion que imprimira los datos de la Seleccion en pantalla
		}
		printf("|==================================================|\n\n");
		retorno = 1;
	}
	else
	{
		printf("\nNo se pudo conseguir espacio en memoria\n");
	}

	return retorno;
}

/** \brief Ordenar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_ordenarSeleccionesConfederacion(LinkedList* pArrayListSeleccion)
{
	int retorno = 0;
	if(pArrayListSeleccion != NULL)
	{
		ll_sort(pArrayListSeleccion, ordenarSeleccionesConfederacion, 1);
		retorno = 1;
	}
    return retorno;
}

/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int Devuelve 0 si no pudo obtener memoria o 1 si pudo realizar la funcion
 *
 */
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion)
{
	int retorno = 0;
	FILE* pArchivo = fopen(path, "w");
	int id, convocados;
	char pais[30];
	char confederacion[30];
	int len = ll_len(pArrayListSeleccion); //Se define el tamaño de la lista para el for
	Seleccion* auxSeleccion = NULL;

	if(path != NULL && pArrayListSeleccion != NULL && pArchivo != NULL)
	{
		fprintf(pArchivo, "id,pais,confederacion,convocados\n");
		for(int i = 0; i < len; i ++)
		{
			auxSeleccion = ll_get(pArrayListSeleccion, i);
			if(auxSeleccion != NULL && selec_getAll(auxSeleccion, &id, pais, confederacion, &convocados) == 1)
			{
				fprintf(pArchivo, "%d, %s, %s, %d\n", id, pais, confederacion, convocados);
			}
		}
		fclose(pArchivo);
		retorno = 1;
	}
	else
	{
		printf("\nNo se pudo conseguir espacio en memoria\n");
	}

    return retorno;
}

//=======================================================================================================================================================//
//====================================================== LIMPIAR MEMORIA ===============================================================================//
//=======================================================================================================================================================//
int controller_LimpiarMemoria(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno = 0;

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL)
	{
		jug_clenAll(pArrayListJugador);
		selec_clenAll(pArrayListSeleccion);
		ll_deleteLinkedList(pArrayListJugador);
		ll_deleteLinkedList(pArrayListSeleccion);
		retorno = 1;
	}
	else
	{
		printf("\nNo se pudo conseguir espacio en memoria\n");
	}

	return retorno;
}
