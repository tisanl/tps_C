/*
 * FileJugadores.c
 *
 *  Created on: 23 oct. 2022
 *      Author: Usuario
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PedirDatos.h"
#include "FuncionesJugadores.h"
#include "FuncionesConfederaciones.h"

int initJugadores(eJugador* vecJugadores, int size) //Funcion que inicializara la variable isEmpty de las estructuras del vector de Jugadores en 0
{
    int retorno = 0;

    if(vecJugadores != NULL && size > 0)
    {
        for(int i = 0; i < size; i++) //Un for que recorre el vector y cambia el estado del valor isEmpty
        {
        	(*(vecJugadores + i)).isEmpty = 0;
            retorno = 1;
        }
    }
    else
    {
    	printf("No se pudo conseguir espacio en memoria");
    }

    return retorno;
}

int validarPosicionLibreJugadores(eJugador* vecJugadores, int size) //Funcion que validara que hay un hueco disponible en el array de Jugadores
{
   int retorno = 0;

   if(vecJugadores != NULL && size > 0)  //Si la direccion de memoria es valida buscara un lugar desocupado
   {
	   for(int i = 0; i < size; i++)
		{
			if((*(vecJugadores + i)).isEmpty == 0)
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

int validarPosicionOcupadaJugadores(eJugador* vecJugadores, int size) //Funcion que validara que haya una posicion ocupada en el array
{
   int retorno = 0;

   if(vecJugadores != NULL && size > 0) //Si la direccion de memoria es valida buscara un lugar ocupado
   {
	   for(int i = 0; i < size; i++)
		{
			if((*(vecJugadores + i)).isEmpty == 1) //En caso de que haya alguna posicion ocupada la funcion devolvera 1
			{
				retorno = 1;
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
//====================================================================================================================================================//
//================================================================  ALTA  ============================================================================//
//====================================================================================================================================================//
int altaJugadores(eJugador* vecJugadores, int sizeJugadores, eConfederacion* vecConfederaciones, int sizeConfederaciones, int* id)
{
	int retorno = 0;
	char confirm = 'n';

	if(vecJugadores != NULL && sizeJugadores > 0 && vecConfederaciones != NULL && sizeConfederaciones > 0 && id != NULL)
	{
		do{//Primero se valida que haya lugar para agregar un Jugador
			if(validarPosicionLibreJugadores(vecJugadores, sizeJugadores) == 1) //En caso de que haya se ejecuta la alta
			{
				for(int i = 0; i < sizeJugadores; i ++)
				{
					if((*(vecJugadores + i)).isEmpty == 0) //En la primera posicion libre que se encuentre tomara y guardara los datos
					{
						//Se asigna el id al Jugador
						(*(vecJugadores + i)).id = *id;

						//Se piden los datos del Jugador
						if(
						getStringAlphaYTam((*(vecJugadores + i)).nombre, 50, 3, "\nIngrese el nombre del Jugador: ", "El Nombre es muy largo y/o algun caracter no es una letra. Intente nuevamente: ") == 1 &&
						getStringAlphaYTam((*(vecJugadores + i)).posicion, 50, 3, "\nIngrese la posicion del Jugador: ", "La posicion es muy larga y/o algun caracter no es una letra. Intente nuevamente: ") == 1 &&
						getShortIntRange(&(*(vecJugadores + i)).numeroCamiseta, 1, 99, 3, "\nIngrese la camiseta del Jugador: ", "Dato incorrecto. Ingrese un numero entre el 1 y el 99: ") == 1 &&
						pedirConfederacion(vecConfederaciones, sizeConfederaciones, &(*(vecJugadores + i)).idConfederacion) == 1 &&
						getFloatPositiv(&(*(vecJugadores + i)).salario, 3, "\nIngrese el salario del Jugador: ", "Dato erroneo. Ingrese un numero positivo mayor a 0: ") == 1 &&
						getShortIntPositiv(&(*(vecJugadores + i)).aniosContrato, 3, "\nIngrese los años de contrato del Jugador: ", "Dato incorrecto. Ingrese un numero positivo mayor a 0: ") == 1)
						//En caso de que haya podido tomar todos los datos los guardara en sistema
						{
							printf("\nEl Jugador se ha guardado con exito\n");
							(*(vecJugadores + i)).isEmpty = 1; //Se guardan los datos de forma logica
							*id = *id + 1; //Se incrementa el id
							retorno = 1;
							printf("\nDesea ingresar otro Jugador?\nIngrese 'Y' para confirmar o cualquier otra tecla para volver al menu: ");
						}
						else //En caso de que no haya podido tomar el dato mostrara el siguiente mensaje
						{
							printf("\nNo se han podido tomar los datos. No se han guardado\n");
							printf("\nDesea ingresar otro Jugador?\nIngrese 'Y' para confirmar o cualquier otra tecla para volver al menu: ");
							retorno = -1;
						}
						getCaracterTolower(&confirm); //Se preguntara al usuario si quiere ingresar otro Jugador haya podido igresar el anterior o no
						break;
					}
				}
			}
			else
			{
				printf("\nNo hay lugar disponible para agregar un nuevo Jugador\n");
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

int pedirConfederacion(eConfederacion* vecConfederaciones, int size, int* id) //Funcion que pedira el Id de la Confederacion para el Jugador
{
	int retorno = 0;
	int opcion;

	if(vecConfederaciones != NULL && size > 0 && id != NULL)
	{
		listarConfederaciones(vecConfederaciones, size); //Se listan las Confederaciones para mostrarselas al usuario y se pide la opcion
		if(getIntRange(&opcion, 1, 6, 3, "Ingrese el numero de la Confederacion a la que corresponda el Jugador: ", "Dato incorrecto. Ingrese un numero entre el 1 y el 6 segun las opciones: ") == 1) //Si pudo tomarla guardar la Confederacion en el campo de la estructura del Jugador
		{
			opcion --;
			*id = (*(vecConfederaciones + opcion)).id;
			retorno = 1;
		}
	}
	else
	{
		printf("No se pudo conseguir espacio en memoria");
	}

	return retorno;
}

//=====================================================================================================================================================//
//===================================================  MODIFICACION y BAJA  ===========================================================================//
//=====================================================================================================================================================//
int findJugadorById(eJugador* vecJugadores, int size, int id) //Funcion bara buscar la posicion en el vector a la que pertenece un Id
{
	int array = -1; //Se inicializa la funcion que guardara la posicion en -1

    if(vecJugadores != NULL && size > 0)
    {
    	for(int i = 0; i < size; i++)
    	{
    		if((*(vecJugadores + i)).isEmpty == 1 && (*(vecJugadores + i)).id == id)
    	    {
    			array = i; //Si encuentra el Id guardara la posicion
    			printf("\nEl Jugador ha sido encontrado.\n");
   	            break;
    	    }
   	    }
    	if(array == -1)
    	{
    		printf("\nNo hay un Jugador con ese Id\n");
    	}
    }
    else
    {
    	printf("No se pudo conseguir espacio en memoria");
    }

    return array; //Devuelve la posicion en el array, devolvera -1 si no existe o no pudo buscarla
}

int bajaJugadores(eJugador* vecJugadores, int i, eConfederacion* vecConfederaciones, int sizeConfederaciones) //Baja Jugador
{
	int retorno = 0;
	char confirmacionBaja;

	if(vecJugadores != NULL && vecConfederaciones != NULL && sizeConfederaciones > 0) //Una vez elegido el id y encontrada la posicion en el vector se le pedira al usuario que confirme la baja
	{
		listarJugadorUnico(vecJugadores, i, vecConfederaciones, sizeConfederaciones); //Muestra el Jugador con el cual se trabajara
		printf("Ingrese 'Y' si quiere confirmar dar de baja al Jugador: ");
		getCaracterTolower(&confirmacionBaja);
		if(confirmacionBaja == 'y') //Si confirma cambiara el estado IsEmpty para que la baja sea efectiva logicamente
		{
			(*(vecJugadores + i)).isEmpty = 0;
			printf("\nEl Jugador se ha dado de baja con exito.\n");
			retorno = 1;
		}
		else
		{
			printf("\nEl Jugador no se ha dado de baja\n"); //Muestra este mensaje si no quiere realizar el cambio
		}
		retorno = -1;
	}
	else
    {
       	printf("\nNo se pudo conseguir espacio en memoria\n");
	}

	return retorno;
}

int modificarJugadores(eJugador* vecJugadores, int i, eConfederacion* vecConfederaciones, int sizeConfederaciones) //Funcion para modificar un Jugador
{
    int retorno = 0;
    char confirm;

    if(vecJugadores != NULL && vecConfederaciones != NULL && sizeConfederaciones > 0)
    {
		do
		{
			listarJugadorUnico(vecJugadores, i, vecConfederaciones, sizeConfederaciones); //Muestra el Jugador con el cual se trabajara
			//Primero se desplegara el submenu para seleccionar la opcion que quiera el usuario
			switch(subMenuModificar())
			{
				case 1: //Modificar el nombre
					if(getStringAlphaYTam((*(vecJugadores + i)).nombre, 50, 3, "\nIngrese el nombre del Jugador: ", "El Nombre es muy largo y/o algun caracter no es una letra. Intente nuevamente: ") == 1)
					{
						printf("\nSe ha cambiado el nombre del Jugador\nIngrese 'Y' si quiere modificar otro dato o cualquier otra tecla para volver al menu:");
					}
					else
					{
						printf("\nEl nombre no se ha modificado\nIngrese 'Y' si quiere modificar otro dato o cualquier otra tecla para volver al menu:");
					}
					getCaracterTolower(&confirm);
					break;
				case 2: //Modificar la posicion
					if(getStringAlphaYTam((*(vecJugadores + i)).posicion, 50, 3, "\nIngrese la posicion del Jugador: ", "La posicion es muy larga y/o algun caracter no es una letra. Intente nuevamente: ") == 1)
					{
						printf("\nSe ha cambiado la posicion del Jugador\nIngrese 'Y' si quiere modificar otro dato o cualquier otra tecla para volver al menu:");
					}
					else
					{
						printf("\nLa posicion no se ha modificado\nIngrese 'Y' si quiere modificar otro dato o cualquier otra tecla para volver al menu:");
					}
					getCaracterTolower(&confirm);
					break;
				case 3: //Modificar el numero de camiseta
					if(getShortIntRange(&(*(vecJugadores + i)).numeroCamiseta, 1, 99, 3, "Ingrese la camiseta del jugador: ", "Dato incorrecto. Ingrese un numero entre el 1 y el 99: ") == 1)
					{
						printf("\nSe ha cambiado el numero de camiseta del Jugador\nIngrese 'Y' si quiere modificar otro dato o cualquier otra tecla para volver al menu:");
					}
					else
					{
						printf("\nEl numero de camiseta no se ha modificado\nIngrese 'Y' si quiere mmodificar otro dato o cualquier otra tecla para volver al menu:");
					}
					getCaracterTolower(&confirm);
					break;
				case 4: //Modificar la confederacion (id)
					if(pedirConfederacion(vecConfederaciones, sizeConfederaciones, &(*(vecJugadores + i)).idConfederacion) == 1)
					{
						printf("\nSe ha cambiado la confederacion del Jugador\nIngrese 'Y' si quiere modificar otro dato o cualquier otra tecla para volver al menu:");
					}
					else
					{
						printf("\nLa confederacion no se ha modificado\nIngrese 'Y' si quiere modificar otro dato o cualquier otra tecla para volver al menu:");
					}
					getCaracterTolower(&confirm);
					break;
				case 5: //Modificar el salario
					if(getFloatPositiv(&(*(vecJugadores + i)).salario, 3, "\nIngrese el salario del jugador: ", "Dato erroneo. Ingrese un numero positivo mayor a 0: ") == 1)
					{
						printf("\nSe ha cambiado el salario del Jugador\nIngrese 'Y' si quiere modificar otro dato o cualquier otra tecla para volver al menu:");
					}
					else
					{
						printf("\nEl salario no se ha modificado\nIngrese 'Y' si quiere modificar otro dato o cualquier otra tecla para volver al menu:");
					}
					getCaracterTolower(&confirm);
					break;
				case 6: //Modificar los anios de contrato
					if(getShortIntPositiv(&(*(vecJugadores + i)).aniosContrato, 3, "Ingrese los años de contrato del Jugador: ", "Dato incorrecto. Ingrese un numero positivo mayor a 0: ") == 1)
					{
						printf("\nSe ha cambiado la cantidad de años de contrato del Jugador\nIngrese 'Y' si quiere modificar otro dato o cualquier otra tecla para volver al menu:");
					}
					else
					{
						printf("\nEl contrato no se ha modificado\nIngrese 'Y' si quiere modificar otro dato o cualquier otra tecla para volver al menu:");
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

int subMenuModificar() //Submenu que pertenece a la funcion de modificar
{
    int opcion;

    printf("==============================================================\n");
    printf("******************** MENU DE MODIFICACION ********************\n");
    printf("==============================================================\n\n");
    printf("Opcion 1: Modificar el nombre\n");
    printf("Opcion 2: Modificar la posicion\n");
    printf("Opcion 3: Modificar el numero de la camiseta\n");
    printf("Opcion 4: Modificar la confederacion\n");
    printf("Opcion 5: Modificar el salario\n");
    printf("Opcion 6: Modificar los años de contrato\n");
    printf("Opcion 7: Salir\n\n");
    if(getIntRange(&opcion, 1, 7, 3, "Ingrese un numero entre las opciones: ", "Dato incorrecto. Ingrese un numero entre el 1 y el 7 segun las opciones: ") == -1) //Si no puede tomarla devolvera una opcion que ira al default
    {
    	opcion = 200;
    }

    return opcion; //Devuelve la opcion
}
//========================================================================================================================================================//
//================================================================== LISTAR ==============================================================================//
//========================================================================================================================================================//
int listarJugadores(eJugador* vecJugadores, int sizeJugadores, eConfederacion* vecConfederaciones, int sizeConfederaciones)
{
	int retorno = 0;
	char descripcionConfederacion[30];

	if(vecJugadores != NULL && sizeJugadores > 0 && vecConfederaciones != NULL && sizeConfederaciones > 0)
	{
		printf("\n|===========================================================================================================|\n"); //Se genera la estructura para mostrar en pantalla
		printf("| Id |          Nombre         |    Posicion    | N° Camiseta |  Sueldo  | Confederacion | Años de Contrato |\n");
		printf("|----|-------------------------|----------------|-------------|----------|---------------|------------------|\n");
		for(int i = 0; i < sizeJugadores; i++) //Este for recorrera el array de Jugadores y mostrara los que esten ocupados
		{
			if((*(vecJugadores + i)).isEmpty == 1)
			{
				printf("|%4d|", (*(vecJugadores + i)).id);
				printf("%25s|", (*(vecJugadores + i)).nombre);
				printf("%16s|", (*(vecJugadores + i)).posicion);
				printf("%13hd|", (*(vecJugadores + i)).numeroCamiseta);
				printf("%10.2f|", (*(vecJugadores + i)).salario);
				printConfederacion((*(vecJugadores + i)).idConfederacion, vecConfederaciones, sizeConfederaciones, descripcionConfederacion); //Esta funcion transcribe la descripcion de la confederacion segun el Id cargado en la estructura
				printf("%15s|", descripcionConfederacion);
				printf("%18hd|\n", (*(vecJugadores + i)).aniosContrato);
			}
		}
		printf("============================================================================================================|\n\n");
		retorno = 1;
	}
	else
	{
		printf("No se pudo conseguir espacio en memoria");
	}

    return retorno;
}

int listarJugadorUnico(eJugador* vecJugadores, int i, eConfederacion* vecConfederaciones, int sizeConfederaciones)
{
	int retorno = 0;
	char descripcionConfederacion[50];

	if(vecJugadores != NULL && vecConfederaciones != NULL && sizeConfederaciones > 0)
	{
		printf("\n|===========================================================================================================|\n"); //Se genera la estructura para mostrar en pantalla
		printf("| Id |          Nombre         |    Posicion    | N° Camiseta |  Sueldo  | Confederacion | Años de Contrato |\n");
		printf("|----|-------------------------|----------------|-------------|----------|---------------|------------------|\n");
		printf("|%4d|", (*(vecJugadores + i)).id);
		printf("%25s|", (*(vecJugadores + i)).nombre);
		printf("%16s|", (*(vecJugadores + i)).posicion);
		printf("%13hd|", (*(vecJugadores + i)).numeroCamiseta);
		printf("%10.2f|", (*(vecJugadores + i)).salario);
		printConfederacion((*(vecJugadores + i)).idConfederacion, vecConfederaciones, sizeConfederaciones, descripcionConfederacion); //Esta funcion transcribe la descripcion de la confederacion segun el Id cargado en la estructura
		printf("%15s|", descripcionConfederacion);
		printf("%18hd|\n", (*(vecJugadores + i)).aniosContrato);
		printf("============================================================================================================|\n\n");
		retorno = 1;
	}
	else
	{
		printf("No se pudo conseguir espacio en memoria");
	}

    return retorno;
}

int printConfederacion(int id, eConfederacion* vecConfederaciones, int sizeConfederaciones, char descripcionConfederacion[50]) //Funcion para mostrar la Confederacion en pantalla, la guardara en una variable
{
	int retorno = 0;

	if(vecConfederaciones != NULL && sizeConfederaciones > 0 && descripcionConfederacion != NULL)
	{
		for(int i = 0; i < sizeConfederaciones; i++) //Recorrera el vector de Confederaciones buscando el que coincida con el Id del vector y lo transcribira
		{
			if(id == (*(vecConfederaciones + i)).id)
			{
				strcpy(descripcionConfederacion, (*(vecConfederaciones + i)).nombre);
				retorno = 1;
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

