/*
 * FuncionesConfederaciones.c
 *
 *  Created on: 23 oct. 2022
 *      Author: Usuario
 */

#include <stdio.h>
#include <stdlib.h>
#include "FuncionesConfederaciones.h"
#include "PedirDatos.h"

int hardcodeoConfederacion(eConfederacion* vecConfederaciones, int size) //Funcion que hardcodeara las Confederaciones
{
	int retorno = 0;

	eConfederacion harcodeados[6]=
		{
			{100, "CONMEBOL", "SUDAMERICA", 1916},
			{101, "UEFA", "EUROPA", 1954},
			{102, "AFC", "ASIA", 1954},
			{103, "CAF", "AFRICA", 1957},
			{104, "CONCACAF", "NORTE Y CENTRO AMERICA", 1961},
			{105, "OFC", "OCEANIA", 1966},
		};

	if(vecConfederaciones != NULL && size > 0) //Si la direccion de memoria es valida ejecutara el hardcodeo
	{
		for(int i = 0; i < size; i++) //For que transcribe los datos hardcodeados a la variable original
		{
			*(vecConfederaciones + i) = *(harcodeados + i);
		}

		retorno = 1;
	}
	else
	{
		printf("No se pudo conseguir espacio en memoria");
	}

	return retorno;
}

int listarConfederaciones(eConfederacion* vecConfederaciones, int size) //Funcion que lista las Confederaciones
{
	int retorno = 0;
	if(vecConfederaciones != NULL && size > 0)
	{
		printf("\n======================================================|\n");
		printf("  | ID | Nombre |        Region        | Año Creacion |\n");
		printf("--|----|--------|----------------------|--------------|\n");
		for(int i = 0; i < 6; i++)
		{
			printf("%-2d|", i+1); //Para numerarlos se muestra la i que representa la posicion + 1 por estetica para que la cuenta comienze en 1
			printf("%-4d|", (*(vecConfederaciones + i)).id);
			printf("%-8s|", (*(vecConfederaciones + i)).nombre);
			printf("%-22s|", (*(vecConfederaciones + i)).region);
			printf("%-14d|\n", (*(vecConfederaciones + i)).anioCreacion);
		}
		printf("======================================================|\n\n");
		retorno = 1;
	}
	else
	{
		printf("No se pudo conseguir espacio en memoria");
	}
	return retorno;
}

int listarConfederacionUnica(eConfederacion* confederacion) //Funcion que lista las Confederaciones
{
	int retorno = 0;
	if(confederacion != NULL)
	{
		printf("\n====================================================|\n");
		printf("| ID | Nombre |        Region        | Año Creacion |\n");
		printf("|----|--------|----------------------|--------------|\n");
		printf("|%-4d|", (*confederacion).id);
		printf("%-8s|", (*confederacion).nombre);
		printf("%-22s|", (*confederacion).region);
		printf("%-14d|\n", (*confederacion).anioCreacion);
		printf("====================================================|\n\n");
		retorno = 1;
	}
	else
	{
		printf("No se pudo conseguir espacio en memoria");
	}
	return retorno;
}
//====================================================================================================================================================//
//===================================================  FUNCIONES DE ABM PARA CONFEDERACIONES  ========================================================//
//====================================================================================================================================================//
//PARA EL DESARROLLO DE LAS SIGUIENTES FUNCIONES SE DARA POR SUPUESTO QUE LA ESTRUCTURA eConfederaciones CUENTA CON UN CAMPO isEmpty PARA EL CORRECTo
//FUNCIONAMIENTO DE LAS FUNCIONES DEL ABM. Se usara esta variable de tipo entero "confederacionIsEmpty" para sustituirla en el programa a modo de muestra
//====================================================================================================================================================//
//================================================================  ALTA  ============================================================================//
//====================================================================================================================================================//
int validarPosicionLibreConfederaciones(eConfederacion* vecConfederaciones, int size) //Funcion que validara que hay un hueco disponible en el array de Confederaciones
{
   int retorno = 0;
   int confederacionIsEmpty = 0;

   if(vecConfederaciones != NULL && size > 0)  //Si la direccion de memoria es valida buscara un lugar desocupado
   {
	   for(int i = 0; i < size; i++)
		{
			if(confederacionIsEmpty == 0) //Aca a la estructura le falta el (*(vecConfederaciones + i)).isEmpty
			{
				retorno = 1; //Devuelve 1 si hay posicion libre en el array
				break;
			}
	   }
   }
   else
   {
	   printf("No se pudo conseguir espacio en memoria");
   }

   return retorno;
}

int altaConfederaciones(eConfederacion* vecConfederaciones, int size, int* id)
{
	int retorno = 0;
	char confirm = 'n';
	int confederacionIsEmpty = 0;

	if(vecConfederaciones != NULL && size > 0 && id != NULL)
	{
		do{//Primero se valida que haya lugar para agregar una confederacion
			if(validarPosicionLibreConfederaciones(vecConfederaciones, size) == 1) //En caso de que haya se ejecuta la alta
			{
				for(int i = 0; i < size; i ++)
				{
					if(confederacionIsEmpty == 0) //En la primera posicion libre que se encuentre tomara y guardara los datos
					{
						//Se asigna el id a la Confederacion
						(*(vecConfederaciones + i)).id = *id;

						//Se piden los datos de la Confederacion
						if(
						getStringAlphaYTam((*(vecConfederaciones + i)).nombre, 50, 3, "\nIngrese el nombre de la Confederacion: ", "El Nombre es muy largo y/o algun caracter no es una letra. Intente nuevamente: ") == 1 &&
						getStringAlphaYTam((*(vecConfederaciones + i)).region, 50, 3, "\nIngrese la region de la Confederacion: ", "La posicion es muy larga y/o algun caracter no es una letra. Intente nuevamente: ") == 1 &&
						getIntRange(&(*(vecConfederaciones + i)).anioCreacion, 0, 2022, 3, "\nIngrese el año de creacion de la Confederacion: ", "Dato incorrecto. Ingrese un numero entre el 0 y el 2022: ") == 1)
						//En caso de que haya podido tomar todos los datos los guardara en sistema
						{
							printf("\nLa Confederacion se ha guardado con exito\n");
							confederacionIsEmpty = 1; //Se guardan los datos de forma logica
							*id = *id + 1; //Se incrementa el id
							retorno = 1;
							printf("\nDesea ingresar otra Confederacion?\nIngrese 'Y' para confirmar o cualquier otra tecla para volver al menu: ");
						}
						else //En caso de que no haya podido tomar el dato mostrara el siguiente mensaje
						{
							printf("\nNo se han podido tomar los datos. No se han guardado\n");
							printf("\nDesea ingresar otra Confederacion?\nIngrese 'Y' para confirmar o cualquier otra tecla para volver al menu: ");
							retorno = -1;
						}
					}
					getCaracterTolower(&confirm); //Se preguntara al usuario si quiere ingresar otra Confederacion haya podido igresar el anterior o no
					break;
				}
			}
			else
			{
				printf("\nNo hay lugar disponible para agregar una nueva Confederacion\n");
				retorno = -2;
			}
		}while(confirm == 'y');
	}
	else
	{
		printf("No se pudo conseguir espacio en memoria");
	}
	return retorno;
}

int findConfederacionById(eConfederacion* vecConfederaciones, int size, int id) //Funcion bara buscar la posicion en el vector a la que pertenece un Id
{
	int array = -1; //Se inicializa la funcion que guardara la posicion en -1
	int confederacionIsEmpty = 0;

    if(vecConfederaciones != NULL && size > 0)
    {
    	for(int i = 0; i < size; i++)
    	{
    		if(confederacionIsEmpty == 1 && (*(vecConfederaciones + i)).id == id)
    	    {
    			array = i; //Si encuentra el Id guardara la posicion
    			printf("\nLa Confederacion ha sido encontrada.\n");
   	            break;
    	    }
   	    }
    	if(array == -1)
    	{
    		printf("\nNo hay una Confederacion con ese Id\n");
    	}
    }
    else
    {
    	printf("No se pudo conseguir espacio en memoria");
    }

    return array; //Devuelve la posicion en el array, devolvera -1 si no existe o no pudo buscarla
}

int bajaConfederaciones(eConfederacion* vecConfederaciones, int i) //Baja Confederacion
{
	int retorno = 0;
	char confirmacionBaja;
	//int confederacionIsEmpty = 1;

	if(vecConfederaciones != NULL) //Una vez elegido el id y encontrada la posicion en el vector se le pedira al usuario que confirme la baja
	{
		printf("Ingrese 'Y' si quiere confirmar dar de baja al Jugador: ");
		getCaracterTolower(&confirmacionBaja);
		if(confirmacionBaja == 'y') //Si confirma cambiara el estado IsEmpty para que la baja sea efectiva logicamente
		{
			//confederacionIsEmpty = 0;
			printf("\nLa Confederacion se ha dado de baja con exito.\n");
			retorno = 1;
		}
		else
		{
			printf("\nLa Confederacion no se ha dado de baja\n"); //Muestra este mensaje si no quiere realizar el cambio
		}
		retorno = -1;
	}
	else
    {
       	printf("\nNo se pudo conseguir espacio en memoria\n");
	}

	return retorno;
}

int modificarConfederaciones(eConfederacion* vecConfederaciones, int i) //Funcion para modificar una Confederacion
{
    int retorno = 0;
    char confirm;

    if(vecConfederaciones != NULL)
    {
		do
		{
			//Primero se desplegara el submenu para seleccionar la opcion que quiera el usuario
			switch(subMenuModificarConfederaciones())
			{
				case 1: //Modificar el nombre
					if(getStringAlphaYTam((*(vecConfederaciones + i)).nombre, 50, 3, "\nIngrese el nombre de la Confederacion: ", "El Nombre es muy largo y/o algun caracter no es una letra. Intente nuevamente: ") == 1)
					{
						printf("\nSe ha cambiado el nombre de la Confederacionr\nIngrese 'Y' si quiere modificar otro dato o cualquier otra tecla para volver al menu:");
					}
					else
					{
						printf("\nEl nombre no se ha modificado\nIngrese 'Y' si quiere modificar otro dato o cualquier otra tecla para volver al menu:");
					}
					getCaracterTolower(&confirm);
					break;
				case 2: //Modificar la posicion
					if(getStringAlphaYTam((*(vecConfederaciones + i)).region, 50, 3, "\nIngrese la region de la Confederacion: ", "La region es muy larga y/o algun caracter no es una letra. Intente nuevamente: ") == 1)
					{
						printf("\nSe ha cambiado la region de la Confederacion\nIngrese 'Y' si quiere modificar otro dato o cualquier otra tecla para volver al menu:");
					}
					else
					{
						printf("\nLa region de la Confederacion\nIngrese 'Y' si quiere modificar otro dato o cualquier otra tecla para volver al menu:");
					}
					getCaracterTolower(&confirm);
					break;
				case 3: //Modificar el numero de camiseta
					if(getIntRange(&(*(vecConfederaciones + i)).anioCreacion, 0, 2022, 3, "\nIngrese el año de creacion de la Confederacion: ", "Dato incorrecto. Ingrese un numero entre el 0 y el 2022: ") == 1)
					{
						printf("\nSe ha cambiado el año de creacion de la Confederacion\nIngrese 'Y' si quiere modificar otro dato o cualquier otra tecla para volver al menu:");
					}
					else
					{
						printf("\nEl año de creacion de la Confederacion no se ha modificado\nIngrese 'Y' si quiere mmodificar otro dato o cualquier otra tecla para volver al menu:");
					}
					getCaracterTolower(&confirm);
					break;
				default:
					printf("\nSera devuelto al menu\n"); //En caso de que no haya podido ingresar una opcion o eliga salir al menu
					confirm = 'n';
			}
		}while(confirm == 'y');
		retorno = 1;
    }
    else
    {
       	printf("No se pudo conseguir espacio en memoria");
    }
    return retorno;
}

int subMenuModificarConfederaciones() //Submenu que pertenece a la funcion de modificar
{
    int opcion;

    printf("==============================================================\n");
    printf("******************** MENU DE MODIFICACION ********************\n");
    printf("==============================================================\n\n");
    printf("Opcion 1: Modificar el nombre\n");
    printf("Opcion 2: Modificar la region\n");
    printf("Opcion 3: Modificar el año de creacion\n");
    printf("Opcion 4: Salir\n\n");
    if(getIntRange(&opcion, 1, 4, 3, "Ingrese un numero entre las opciones: ", "Dato incorrecto. Ingrese un numero entre el 1 y el 7 segun las opciones: ") == -1) //Si no puede tomarla devolvera una opcion que ira al default
    {
    	opcion = 200;
    }

    return opcion; //Devuelve la opcion
}


