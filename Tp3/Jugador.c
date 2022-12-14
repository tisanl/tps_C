#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "Seleccion.h"
#include "PedirDatos.h"
#include "Informes.h"

Jugador* jug_new()
{
	Jugador* jugador;

	jugador = (Jugador*) malloc(sizeof(Jugador));

	return jugador;
}

Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr)
{
	Jugador* jugador;

	if(idStr != NULL && nombreCompletoStr != NULL && edadStr != NULL && posicionStr != NULL && nacionalidadStr != NULL && idSelccionStr != NULL)
	{
		jugador = jug_new();
		if(jugador != NULL)
		{
			jugador->id = atoi(idStr);
			strcpy(jugador->nombreCompleto, nombreCompletoStr);
			jugador->edad = atoi(edadStr);
			strcpy(jugador->posicion, posicionStr);
			strcpy(jugador->nacionalidad, nacionalidadStr);
			jugador->idSeleccion = atoi(idSelccionStr);
		}
		else
		{
			printf("\nNo se pudo conseguir espacio en memoria, el Jugador no fue generado\n");
		}
	}
	else
	{
		printf("\nNo se pudo conseguir espacio en memoria, el Jugador no fue generado\n");
	}

	return jugador;
}

void jug_delete(Jugador* this)
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

int jug_setId(Jugador* this,int id)
{
	int retorno = 0;

	if(this != NULL && id > 0)
	{
		this->id = id;
		retorno = 1;
	}
	else
	{
		printf("\nNo se pudo guardar el Id del Jugador\n");
	}

	return retorno;
}

int jug_getId(Jugador* this,int* id)
{
	int retorno = 0;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 1;
	}
	else
	{
		printf("\nNo se pudo obtener el Id del Jugador\n");
	}

	return retorno;
}

int jug_setNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int retorno = 0;

	if(this != NULL && nombreCompleto != NULL)
	{
		strcpy(this->nombreCompleto, nombreCompleto);
		retorno = 1;
	}
	else
	{
		printf("\nNo se pudo guardar el nombre del Jugador\n");
	}

	return retorno;
}

int jug_getNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int retorno = 0;

	if(this != NULL && nombreCompleto != NULL)
	{
		strcpy(nombreCompleto, this->nombreCompleto);
		retorno = 1;
	}
	else
	{
		printf("\nNo se pudo obtener el nombre del Jugador\n");
	}

	return retorno;
}

int jug_setPosicion(Jugador* this,char* posicion)
{
	int retorno = 0;

	if(this != NULL && posicion != NULL)
	{
		strcpy(this->posicion, posicion);
		retorno = 1;
	}
	else
	{
		printf("\nNo se pudo guardar la posicion del Jugador\n");
	}

	return retorno;
}

int jug_getPosicion(Jugador* this,char* posicion)
{
	int retorno = 0;

	if(this != NULL && posicion != NULL)
	{
		strcpy(posicion, this->posicion);
		retorno = 1;
	}
	else
	{
		printf("\nNo se pudo obtener la posicion del Jugador\n");
	}

	return retorno;
}

int jug_setNacionalidad(Jugador* this,char* nacionalidad)
{
	int retorno = 0;

	if(this != NULL && nacionalidad != NULL)
	{
		strcpy(this->nacionalidad, nacionalidad);
		retorno = 1;
	}
	else
	{
		printf("\nNo se pudo guardar la nacionalidad del Jugador\n");
	}

	return retorno;
}

int jug_getNacionalidad(Jugador* this,char* nacionalidad)
{
	int retorno = 0;

	if(this != NULL && nacionalidad != NULL)
	{
		strcpy(nacionalidad, this->nacionalidad);
		retorno = 1;
	}
	else
	{
		printf("\nNo se pudo obtener la nacionalidad del Jugador\n");
	}

	return retorno;
}

int jug_setEdad(Jugador* this,int edad)
{
	int retorno = 0;

	if(this != NULL && edad > 0)
	{
		this->edad = edad;
		retorno = 1;
	}
	else
	{
		printf("\nNo se pudo guardar la edad del Jugador\n");
	}

	return retorno;
}

int jug_getEdad(Jugador* this,int* edad)
{
	int retorno = 0;

	if(this != NULL && edad != NULL)
	{
		*edad = this->edad;
		retorno = 1;
	}
	else
	{
		printf("\nNo se pudo obtener la edad del Jugador\n");
	}

	return retorno;
}

int jug_setIdSeleccion(Jugador* this,int idSeleccion)
{
	int retorno = 0;

	if(this != NULL && idSeleccion > -1)
	{
		this->idSeleccion = idSeleccion;
		retorno = 1;
	}
	else
	{
		printf("\nNo se pudo guardar el Id de la Seleccion del Jugador\n");
	}

	return retorno;
}

int jug_getSIdSeleccion(Jugador* this,int* idSeleccion)
{
	int retorno = 0;

	if(this != NULL && idSeleccion != NULL)
	{
		*idSeleccion = this->idSeleccion;
		retorno = 1;
	}
	else
	{
		printf("\nNo se pudo obtener el Id de la seleccion del Jugador\n");
	}

	return retorno;
}

int jug_setAll(Jugador* this, int id, char* nombreCompleto, char* posicion, char* nacionalidad, int edad, int idSeleccion)
{
	int retorno = 0;

	if(jug_setId(this, id) == 1 &&
		jug_setNombreCompleto(this, nombreCompleto) == 1 &&
		jug_setPosicion(this, posicion) == 1 &&
		jug_setNacionalidad(this, nacionalidad) == 1 &&
		jug_setEdad(this, edad) == 1 &&
		jug_setIdSeleccion(this, idSeleccion) == 1)
	{
		retorno = 1;
	}
	else
	{
		printf("\nNo se pudo guardar los datos del Jugador\n");
	}

	return retorno;
}

int jug_getAll(Jugador* this, int* id, char* nombreCompleto, char* posicion, char* nacionalidad, int* edad, int* idSeleccion)
{
	int retorno = 0;

	if(jug_getId(this, id) == 1 &&
		jug_getNombreCompleto(this, nombreCompleto) == 1 &&
		jug_getPosicion(this, posicion) == 1 &&
		jug_getNacionalidad(this, nacionalidad) == 1 &&
		jug_getEdad(this, edad) == 1 &&
		jug_getSIdSeleccion(this, idSeleccion) == 1)
	{
		retorno = 1;
	}
	else
	{
		printf("\nNo se pudo obtener los datos del Jugador\n");
	}

	return retorno;
}

//=======================================================================================================================================================//
//========================================================= Settear Id ==================================================================================//
//=======================================================================================================================================================//
int jug_guardarIdMax(int* id)
{
	int retorno = 0;
	FILE* pArchivo = fopen("idMaximo", "wb");

	if(id != NULL && pArchivo != NULL)
	{
		if(fwrite(id, sizeof(int), 1, pArchivo) == 1)
		{
			retorno = 1;
		}
		fclose(pArchivo);
	}
	else
	{
		printf("\nNo se pudo conseguir espacio en memoria\n");
	}

    return retorno;
}

int jug_CargarIdMax(int* id)
{
	int retorno = 0;
	FILE* pArchivo = fopen("idMaximo", "rb");

	if(id != NULL && pArchivo != NULL)
	{
		if(fread(id, sizeof(int), 1, pArchivo) == 1)
		{
			retorno = 1;
		}
		fclose(pArchivo);
	}
	else
	{
		if(pArchivo == NULL)
		{
			retorno = -1;
		}
		printf("\nNo se pudo conseguir espacio en memoria\n");
	}

    return retorno;
}
//=======================================================================================================================================================//
//======================================================== Alta Jugador =================================================================================//
//=======================================================================================================================================================//

Jugador* jug_crearJugador(int id) //Funcion que creara al Jugador y pedira los datos
{
	Jugador* auxJugador = NULL;
	char nombreCompleto[100];
	char posicion[30];
	char nacionalidad[30];
	int edad;

	if(getStringAlphaYTam(nombreCompleto, 100, 3, "\nIngrese el nombre del Jugador: ", "El Nombre es muy largo y/o algun caracter no es una letra. Intente nuevamente: ") == 1 &&
		getStringAlphaYTam(posicion, 30, 3, "\nIngrese la posicion: ", "La posicion es muy larga y/o algun caracter no es una letra. Intente nuevamente: ") == 1 &&
		getStringAlphaYTam(nacionalidad, 30, 3, "\nIngrese la nacionalidad: ", "La nacionalidad es muy larga y/o algun caracter no es una letra. Intente nuevamente: ") == 1 &&
		getIntPositiv(&edad, 3, "\nIngrese la edad: ", "Error, Debe ingresar un numero positivo. Intente nuevamente: ") == 1)
	{//En caso de que el usuario haya podido ingresarlos creara al Jugador
		auxJugador = jug_new();
		if(auxJugador != NULL) //Si pudo crearse se guardaran los datos
		{
			if(jug_setAll(auxJugador, id, nombreCompleto, posicion, nacionalidad, edad, 0) == 0)
			{
				jug_delete(auxJugador);
				auxJugador = NULL;
			}
		}
	}

	return auxJugador;
}


//=======================================================================================================================================================//
//========================================================= Editar y Baja ===============================================================================//
//=======================================================================================================================================================//

int jug_FindById(LinkedList* pArrayListJugador, int id)
{
	int len = ll_len(pArrayListJugador);
	Jugador* auxJugador = NULL;
	int auxInt;
	int array = -1;

    if(pArrayListJugador != NULL)
    {
    	for(int i = 0; i < len; i ++)
    	{
    		auxJugador = ll_get(pArrayListJugador, i); //Se obtiene el puntero al Jugador en la posicion I del array
    		jug_getId(auxJugador, &auxInt); //Se obtiene el valor de su Id
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

    return array; //Devuelve la posicion el el LinkedList
}

int jug_Modificar(Jugador* this, int opcion)
{
    int retorno = 0;
    char nombreCompleto[100];
    char posicion[30];
    char nacionalidad[30];
    int edad;

    if(this != NULL)
    {
		switch(opcion)
		{
			case 1: //Modificar el nombre
				if(getStringAlphaYTam(nombreCompleto, 100, 3, "\nIngrese el nombre del Jugador: ", "El Nombre es muy largo y/o algun caracter no es una letra. Intente nuevamente: ") == 1)
				{
					jug_setNombreCompleto(this, nombreCompleto);
					printf("\nSe ha cambiado el nombre del Jugador\n");
				}
				else{
					printf("\nEl nombre no se ha modificado\n");
				}
				break;
			case 2: //Modificar la posicion
				if(getStringAlphaYTam(posicion, 30, 3, "\nIngrese la posicion: ", "La posicion es muy larga y/o algun caracter no es una letra. Intente nuevamente: ") == 1)
				{
					jug_setPosicion(this, posicion);
					printf("\nSe ha cambiado la posicion del Jugador\n");
				}
				else{
					printf("\nLa posicion no se ha modificado\n");
				}
				break;
			case 3: //Modificar la nacionalidad
				if(getStringAlphaYTam(nacionalidad, 30, 3, "\nIngrese la nacionalidad: ", "La nacionalidad es muy larga y/o algun caracter no es una letra. Intente nuevamente: ") == 1)
				{
					jug_setNacionalidad(this, nacionalidad);
					printf("\nSe ha cambiado la nacionalidad del Jugador\n");
				}
				else{
					printf("\nLa nacionalidad no se ha modificado\n");
				}
				break;
			case 4: //Modificar la edad
				if(getIntPositiv(&edad, 3, "\nIngrese la edad: ", "Error, Debe ingresar un numero positivo. Intente nuevamente: ") == 1)
				{
					jug_setEdad(this, edad);
					printf("\nSe ha cambiado la edad del Jugador\n");
				}
				else{
					printf("\nLa edad no se ha modificado\n");
				}
				break;
		}
		retorno = 1;
    }
    else
    {
       	printf("No se pudo conseguir espacio en memoria");
    }
    return retorno;
}

int subMenuModificar() //Submenu que pertenece a la funcion de modificar Jugador
{
    int opcion;

    printf("==============================================================\n");
    printf("******************** MENU DE MODIFICACION ********************\n");
    printf("==============================================================\n\n");
    printf("Opcion 1: Modificar el nombre\n");
    printf("Opcion 2: Modificar la posicion\n");
    printf("Opcion 3: Modificar la nacionalidad\n");
    printf("Opcion 4: Modificar la edad\n");
    printf("Opcion 5: Salir\n\n");
    if(getIntRange(&opcion, 1, 5, 3, "Ingrese un numero entre las opciones: ", "Dato incorrecto. Ingrese un numero entre el 1 y el 5 segun las opciones: ") == -1) //Si no puede tomarla devolvera una opcion que ira al default
    {
    	opcion = 200;
    }

    return opcion; //Devuelve la opcion
}

int jug_ConfirmarBaja() //Baja Jugador
{
	int retorno = 0;
	char confirmacionBaja;

	printf("Ingrese 'Y' si quiere confirmar dar de baja al Jugador: ");
	getCaracterTolower(&confirmacionBaja);
	if(confirmacionBaja == 'y')
	{
		retorno = 1; //Si confirma la baja retornara 1
	}

	return retorno;
}

//=======================================================================================================================================================//
//========================================================= Convocatoria ================================================================================//
//=======================================================================================================================================================//

int jug_BuscarConvocado(LinkedList* pArrayListJugador)
{
	int retorno = 0;
	int len = ll_len(pArrayListJugador); //Se define el tamaño de la lista para el for
	Jugador* auxJugador = NULL;
	int auxInt;

	if(pArrayListJugador != NULL)
	{
		for(int i = 0; i < len; i++) //Este for recorrera el array de Jugadores
		{
			auxJugador = ll_get(pArrayListJugador, i); //Se obtiene el puntero al Jugador en la posicion I del array
			if(jug_getSIdSeleccion(auxJugador, &auxInt) == 1 && auxInt > 0)
			{
				retorno = 1;
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

int jug_BuscarNoConvocado(LinkedList* pArrayListJugador)
{
	int retorno = 0;
	int len = ll_len(pArrayListJugador); //Se define el tamaño de la lista para el for
	Jugador* auxJugador = NULL;
	int auxInt;

	if(pArrayListJugador != NULL)
	{
		for(int i = 0; i < len; i++) //Este for recorrera el array de Jugadores
		{
			auxJugador = ll_get(pArrayListJugador, i); //Se obtiene el puntero al Jugador en la posicion I del array
			if(jug_getSIdSeleccion(auxJugador, &auxInt) == 1 && auxInt == 0)
			{
				retorno = 1;
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

int jug_Convocatoria(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno = 0;
	char auxChar;

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL)
	{
		switch(subMenuConvocatoria())
		{
			case 1:
				do
				{
					if(jug_BuscarNoConvocado(pArrayListJugador) == 1)
					{
						jug_Convocar(pArrayListJugador, pArrayListSeleccion);
					}
					else
					{
						printf("\nNo hay Jugadores libres\n");
					}
					printf("\nQuiere Convocar otro Jugador?\nIngrese 'Y' si quiere añadir otro o cualquier otra tecla para volver al submenu: ");
					getCaracterTolower(&auxChar);
				}while(auxChar == 'y');
				break;
			case 2:
				do{
					if(jug_BuscarConvocado(pArrayListJugador) == 1)
					{
						jug_QuitarDeSeleccion(pArrayListJugador, pArrayListSeleccion);
					}
					else
					{
						printf("\nNo hay Jugadores Convocados\n");
					}
					printf("\nQuiere quitar otro Jugador?\nIngrese 'Y' si quiere quitar otro o cualquier otra tecla para volver al submenu: ");
					getCaracterTolower(&auxChar);
				}while(auxChar == 'y');
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

int subMenuConvocatoria() //Submenu que pertenece a la funcion de convocar Jugador
{
    int opcion;

    printf("==============================================================\n");
    printf("******************** MENU DE CONVOCATORIA ********************\n");
    printf("==============================================================\n\n");
    printf("Opcion 1: Convocar Jugadores\n");
    printf("Opcion 2: Quitar de convocatoria\n");
    printf("Opcion 3: Salir\n\n");
    if(getIntRange(&opcion, 1, 3, 3, "Ingrese un numero entre las opciones: ", "Dato incorrecto. Ingrese un numero entre el 1 y el 3 segun las opciones: ") == -1) //Si no puede tomarla devolvera una opcion que ira al default
    {
    	opcion = 200;
    }

    return opcion; //Devuelve la opcion
}

int jug_Convocar(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
	int id;
	int idSeleccion;
	Jugador* auxJugador = NULL;
	int auxInt;

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL)
	{
		jug_ImprimirNoConvocados(pArrayListJugador, pArrayListSeleccion);
		if(getIntPositiv(&id, 3, "Ingrese el Id del Jugador que quiere Convocar: ", "Id incorrecto. Elija un numero positivo: ") == 1)
		{
			auxInt = jug_FindById(pArrayListJugador, id); //Funcion que buscara la posicion en el array del Jugador dependiendo el Id y la devolvera
			if(auxInt != -1)
			{
				auxJugador = ll_get(pArrayListJugador, auxInt); //Se obtiene el puntero al Jugador en la posicion I del array
				jug_ImprimirJugadorUnico(auxJugador, pArrayListSeleccion);//Muestra el Jugador con el cual se trabajara
				jug_getSIdSeleccion(auxJugador , &auxInt);
				if(auxInt == 0)
				{
					if(jug_elegirSeleccion(pArrayListSeleccion, &idSeleccion) == 1)
					{
						jug_setIdSeleccion(auxJugador, idSeleccion);
						printf("\nEl Jugador ha sido Convocado\n");
						retorno = 1;
					}
				}
				else{
					printf("\nEl Jugador ya esta Convocado por otra Seleccion\n");
				}
			}
			else{
				printf("\nNo hay un Jugador con ese Id\n");
			 }
		}
	}
	else
	{
		printf("\nNo se pudo conseguir espacio en memoria\n");
		retorno = 0;
	}

	return retorno;
}

int jug_elegirSeleccion(LinkedList* pArrayListSeleccion, int* idSeleccion)
{
	int retorno = -1;
	int id;
	Seleccion* auxSeleccion = NULL;
	int auxInt;

	if(idSeleccion != NULL && pArrayListSeleccion != NULL)
	{
		controller_listarSelecciones(pArrayListSeleccion);
		if(getIntPositiv(&id, 3, "Ingrese el Id de la Seleccion a la cual quiere convocar al Jugador: ", "Id incorrecto. Elija un numero positivo: ") == 1)
		{
			auxInt = selec_FindById(pArrayListSeleccion, id); //Funcion que buscara la posicion en el array de la Seleccion dependiendo el Id y la devolvera
			if(auxInt != -1)
			{
				auxSeleccion = ll_get(pArrayListSeleccion, auxInt); //Se obtiene el puntero a la Seleccion en la posicion I del array
				selec_getConvocados(auxSeleccion, &auxInt);
				if(auxInt < 22)
				{
					selec_setConvocados(auxSeleccion, (auxInt + 1));
					*idSeleccion = id;
					retorno = 1;
				}
				else{
					printf("\nLa Seleccion ya tiene todos los Convocados, no se hara ningun cambio\n");
				}
			}
			else{
				printf("\nNo hay una Seleccion con ese Id\n");
			 }
		}
	}
	else
	{
		printf("\nNo se pudo conseguir espacio en memoria\n");
		retorno = 0;
	}

	return retorno;
}

int jug_QuitarDeSeleccion(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
	int id;
	Jugador* auxJugador = NULL;
	int auxInt;

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL)
	{
		jug_ImprimirConvocados(pArrayListJugador, pArrayListSeleccion);
		if(getIntPositiv(&id, 3, "Ingrese el Id del Jugador que quiere quitar de la Convocatoria: ", "Id incorrecto. Elija un numero positivo: ") == 1)
		{
			auxInt = jug_FindById(pArrayListJugador, id); //Funcion que buscara la posicion en el array del Jugador dependiendo el Id y la devolvera
			if(auxInt != -1)
			{
				auxJugador = ll_get(pArrayListJugador, auxInt); //Se obtiene el puntero al Jugador en la posicion I del array
				jug_ImprimirJugadorUnico(auxJugador, pArrayListSeleccion);//Muestra el Jugador con el cual se trabajara
				jug_getSIdSeleccion(auxJugador , &auxInt);
				if(auxInt != 0)
				{
					jug_ReducirConvocados(pArrayListSeleccion, auxInt); //Se reduce los convocados en 1
					jug_setIdSeleccion(auxJugador, 0); //Se setea el idSeleccion en 0
					printf("\nEl Jugador ha sido quitado de la Convocatoria\n");
					retorno = 1;
				}
				else{
					printf("\nEl Jugador no esta Convocado por ninguna Seleccion, no se hara ningun cambio\n");
				}
			}
			else{
				printf("\nNo hay un Jugador con ese Id\n");
			 }
		}
	}
	else
	{
		printf("\nNo se pudo conseguir espacio en memoria\n");
		retorno = 0;
	}

	return retorno;
}

int jug_ReducirConvocados(LinkedList* pArrayListSeleccion, int idSeleccion)
{
	int retorno = 0;
	Seleccion* auxSeleccion = NULL;
	int auxInt;

	if(pArrayListSeleccion != NULL)
	{
		auxInt = selec_FindById(pArrayListSeleccion, idSeleccion); //Funcion que buscara la posicion en el array de la Seleccion dependiendo el Id y la devolvera
		if(auxInt != -1)
		{
			auxSeleccion = ll_get(pArrayListSeleccion, auxInt); //Se obtiene el puntero a la Seleccion en la posicion I del array
			selec_getConvocados(auxSeleccion, &auxInt);
			if(auxInt != 0)
			{
				selec_setConvocados(auxSeleccion, (auxInt - 1)); //Se reduce los convocados en 1
				retorno = 1;
			}
		}
	}
	else
	{
		printf("\nNo se pudo conseguir espacio en memoria\n");
	}

	return retorno;
}

//=======================================================================================================================================================//
//========================================================= Punto 8 y 9 ==================================================================================//
//=======================================================================================================================================================//

int jug_guardarConvocadosConfederacionBinario(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno = 0;
	FILE* pArchivo = fopen("convocados", "wb");
	int len = ll_len(pArrayListJugador);
	Jugador* auxJugador;
	Seleccion* auxSeleccion;
	char confederacion[30];
	char auxConfederacion[30];
	int idSeleccion, auxInt;

	if(pArrayListSeleccion != NULL && pArrayListJugador != NULL && pArchivo != NULL)
	{
		if(copiarConfederacion(confederacion, elejirConfederacion()) == 1)
		{
			for(int i = 0; i < len; i ++)
			{
				auxJugador = ll_get(pArrayListJugador, i);
				jug_getSIdSeleccion(auxJugador, &idSeleccion);
				if(idSeleccion != 0)
				{
					auxInt = selec_FindById(pArrayListSeleccion, idSeleccion);
					if(auxInt != -1)
					{
						auxSeleccion = ll_get(pArrayListSeleccion, auxInt);
						selec_getConfederacion(auxSeleccion, auxConfederacion);
						if(strcmp(confederacion, auxConfederacion) == 0)
						{
							if(fwrite(auxJugador, sizeof(Jugador), 1, pArchivo) == 1)
							{
								retorno = 1;
							}
						}
					}
				}
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

int elejirConfederacion() //Pertenece a la funcion de guardar convocados
{
    int opcion;

    printf("==============================================================\n");
    printf("*********************** CONFEDERACIONES **********************\n");
    printf("==============================================================\n\n");
    printf("Opcion 1: AFC\n");
    printf("Opcion 2: CAF\n");
    printf("Opcion 3: CONCACAF\n");
    printf("Opcion 4: CONMEBOL\n");
    printf("Opcion 5: UEFA\n");
    if(getIntRange(&opcion, 1, 5, 3, "Los convocados de que confederacion queire guardar?:  ", "Dato incorrecto. Ingrese un numero entre el 1 y el 5 segun las opciones: ") == -1) //Si no puede tomarla devolvera una opcion que ira al default
    {
    	opcion = 200;
    }

    return opcion; //Devuelve la opcion
}

int copiarConfederacion(char confederacion[30], int opcion)
{
	int retorno = 0;
	if(confederacion != NULL)
	{
		switch(opcion)
		{
			case 1:
				strcpy(confederacion, "AFC");
				break;
			case 2:
				strcpy(confederacion, "CAF");
				break;
			case 3:
				strcpy(confederacion, "CONCACAF");
				break;
			case 4:
				strcpy(confederacion, "CONMEBOL");
				break;
			case 5:
				strcpy(confederacion, "UEFA");
				break;
		}
		retorno = 1;
	}
	else
	{
		printf("\nNo se pudo conseguir espacio en memoria\n");
	}

	return retorno;
}

int jug_ImprimirArchivoConvocados(LinkedList* pArrayListSeleccion)
{
	int retorno = 0;
	FILE* pArchivo = fopen("convocados", "rb");
	Jugador auxJugador;

	if(pArrayListSeleccion != NULL && pArchivo != NULL)
	{
		printf("\n|=================================================================================================|\n");
		printf("| Id |             Nombre           |       Posicion       |  Nacionalidad  | Edad |   Seleccion  |\n");
		printf("|----|------------------------------|----------------------|----------------|------|--------------|\n");
		while(!(feof(pArchivo)))
		{
			if(fread(&auxJugador, sizeof(Jugador), 1, pArchivo) == 1)
			{
				jug_ImprimirenPantalla(&auxJugador, pArrayListSeleccion);
				retorno = 1;
			}
		}
		printf("==================================================================================================|\n\n");
		fclose(pArchivo);
	}
	else
	{
		if(pArchivo == NULL)
		{
			retorno = -1;
		}
		printf("\nNo se pudo conseguir espacio en memoria\n");
	}

    return retorno;
}

//=======================================================================================================================================================//
//===================================================== LIMPIAR MEMORIA ==================================================================================//
//=======================================================================================================================================================//

int jug_clenAll(LinkedList* pArrayListJugador)
{
	int retorno = 0;
	int len = ll_len(pArrayListJugador);
	Jugador* auxJugador = NULL;

	if(pArrayListJugador != NULL && len >= 0)
	{
		for(int i = 0; i < len; i ++)
		{
			auxJugador = ll_get(pArrayListJugador, i);
			jug_delete(auxJugador);
		}

		retorno = 1;
	}

	return retorno;
}












