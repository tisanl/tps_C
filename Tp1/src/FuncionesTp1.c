/*
 * MenuDeOpciones.c
 *
 *  Created on: 22 ago. 2022
 *      Author: Usuario
 */

#include <stdio.h>
#include <stdlib.h>
#include "Validaciones.h"
#include "FuncionesTp1.h"

//FUNCION DEL MENU. Recibe los costos de mantenimiento y el contador de los jugadores por posicion para poder mostrarlos
int menuDeOpciones(float costoHospedaje, float costoComida, float costoTransporte, int contadorJugadores[])
{
	int opcion;

	printf("=====================================================================\n");
	printf("*************************  MENU DE OPCIONES *************************\n");
	printf("=====================================================================\n\n");
	printf("1. Ingresar los costos de Mantenimiento:\n");
	mostrarCostosMantenimiento(costoHospedaje, costoComida, costoTransporte); //Detallada en su desarrollo
	printf("2. Carga de Jugadores\n");
	mostrarJugadores(contadorJugadores); //Detallada en su desarrollo
	printf("3. Calcular todos los costos\n");
	printf("4. Informar resultados\n");
	printf("5. Salir\n");

	//Funcion que pide la opcion, se detalla en su desarrollo
	if(getIntRange(&opcion, 1, 5, 3, "Ingrese un numero entre las opciones: ", "Dato incorrecto. Ingrese un numero entre el 1 y el 5 segun las opciones: ") == -1) //Si no puede tomarla devolvera una opcion que ira al default
	{
		opcion = 6;
	}
	return opcion; //devuelve la opcion
}

//=======================================================================================================================================//
//=======================================================================================================================================//
//FUNCIONES PARA MOSTRAR MANTENIMIENTO Y JUGADORES
void mostrarCostosMantenimiento(float costoHospedaje, float costoComida, float costoTransporte) //Recibe los valores a ser mostrados, no devuelve nada porque es muy basica
{
	printf(".Costo de hospedaje  -> %.2f\n", costoHospedaje);
	printf(".Costo de comida     -> %.2f\n", costoComida);
	printf(".Costo de transporte -> %.2f\n", costoTransporte);
}

void mostrarJugadores(int contadorJugadores[]) //Recibe los valores a ser mostrados, no devuelve nada porque es muy basica
{
	if(contadorJugadores != NULL) //Se ejecutara si pudo conseguir memoria, sino se le informara
	{
		printf("Arqueros       -> %d\n", contadorJugadores[0]);
		printf("Defensores     -> %d\n", contadorJugadores[1]);
		printf("Mediocampistas -> %d\n", contadorJugadores[2]);
		printf("Delanteros     -> %d\n", contadorJugadores[3]);
	}
	else
	{
		printf("No se pudo conseguir memoria\n\n");
	}
}

//=======================================================================================================================================//
//=======================================================================================================================================//
//FUNCIONES DEL PUNTO 1
//Funcion principal del punto 1
int getCostosMantenimiento(float* costoHospedaje, float* costoComida, float* costoTransporte, int* flagIngresoHospedaje, int* flagIngresoComida, int* flagIngresoTransporte, int* flagCalculoValores)
{
	int retorno = 0;

	if(costoHospedaje != NULL && costoComida != NULL && costoTransporte != NULL && flagIngresoHospedaje != NULL && flagIngresoComida != NULL && flagIngresoTransporte != NULL && flagCalculoValores != NULL)
	{
		retorno = 1;
		switch(subMenuMantenimiento())
		{
			case 1:
				if(getFloatPositiv(costoHospedaje, 3, "Ingrese el costo de Hospedaje: " , "Dato erroneo. Ingrese un numero positivo: ") == 1)
				{
					*flagIngresoHospedaje = 1; //Si pudo ingresar el costo la flag se levantara
					printf("\nEl precio se cargo con exito\n");
				}
				else
				{
					setCostoYFlagsA0("\nEl costo del Hospedaje fue reestablecido en 0\nSera devuelto al submenu\n\n", costoHospedaje, flagIngresoHospedaje, flagCalculoValores);
					//Si el usuario falla los valores y flags se reseataran para evitar que pueda ingresar a pasos anteriores si es que tanto falla la primera vez como intenta reescribirlos
				}
				break;
			case 2:
				if(getFloatPositiv(costoComida, 3, "Ingrese el costo de Comida: " , "Dato erroneo. Ingrese un numero positivo: ") == 1)
				{
					*flagIngresoComida = 1;
					printf("\nEl precio se cargo con exito\n");
				}
				else
				{
					setCostoYFlagsA0("\nEl costo de la Comida fue reestablecido en 0\nSera devuelto al submenu\n\n", costoComida, flagIngresoComida, flagCalculoValores);
				}
				break;
			case 3:
				if(getFloatPositiv(costoTransporte, 3, "Ingrese el costo de Transporte: " , "Dato erroneo. Ingrese un numero positivo: ") == 1)
				{
					*flagIngresoTransporte = 1;
					printf("\nEl precio se cargo con exito\n");
				}
				else
				{
					setCostoYFlagsA0("\nEl costo del Transporte fue reestablecido en 0\nSera devuelto al submenu\n\n", costoTransporte, flagIngresoTransporte, flagCalculoValores);
				}
				break;
			default:
				retorno = 2;
			}
	}
	else
	{
		printf("\n\nNo se pudo conseguir memoria\n\n");
	}
	return retorno;
}

int subMenuMantenimiento() //En esta funcion se solicitara al usuario que ingrese una letra correspondiente al costo que se quiere ingresar o volver al menu
{
	int opcion;

	printf("\n==========================================================================\n");
	printf("************************* MENU DE MANTENIMIENTO **************************\n");
	printf("==========================================================================\n\n");
	printf("1. Ingresar costo de Hospedaje\n");
	printf("2. Ingresar costo de Comida\n");
	printf("3. Ingresar costo de Transporte\n");
	printf("4. Salir\n");

	//Funcion que pide la opcion, se detalla en su desarrollo
	if(getIntRange(&opcion, 1, 4, 3, "Ingrese un numero entre las opciones: ", "Dato incorrecto. Ingrese un numero entre el 1 y el 4 segun las opciones: ") == -1) //Si no puede tomarla devolvera una opcion que ira al default
	{
		opcion = 200;
	}

	return opcion; //devuelve la opcion
}

int setCostoYFlagsA0(char mensaje[200], float* costo, int* flagCosto, int* flagCalculoValores)
{
	int retorno = 0;
	if(mensaje != NULL && costo != NULL && flagCosto != NULL && flagCalculoValores != NULL)
	{
		printf("%s", mensaje);
		*costo = 0;
		*flagCosto = 0;
		*flagCalculoValores = 0;
		retorno = 1;
	}
	else
	{
		printf("\n\nNo se pudo conseguir memoria\n\n");
	}

	return retorno;
}
//=======================================================================================================================================//
//=======================================================================================================================================//
//PUNTO 2
//Funcion principal del punto 2
//Funcion para inicializar el vector isEmpty en 0
int initJugadores(int* isEmpty, int size)
{
    int retorno = 0;

    if(isEmpty != NULL && size > 0)
    {
    	for(int i = 0; i < size; i++) //Un for que recorre el vector y cambia el valor a 0
    	{
    		*(isEmpty + i)= 0;
    	}
    	retorno = 1;
    }
    else
    {
    	printf("No se pudo conseguir espacio en memoria");
    }
    return retorno;
}

int validarPosicionLibreJugadores(int* isEmpty, int size) //Funcion que validara que hay un hueco disponible para agregar el Jugador
{
   int retorno = 0;

   if(isEmpty != NULL && size > 0)  //Si la direccion de memoria es valida buscara un lugar desocupado
   {
	   for(int i = 0; i < size; i++)
		{
			if((*(isEmpty + i)) == 0)
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

int getJugadores(int vecPosicion[], int vecCamiseta[], int vecConfederacion[], int isEmpty[], int contadorJugadores[], int size)
{
	int retorno = 0;

	if(vecPosicion != NULL && vecCamiseta != NULL && vecConfederacion != NULL && isEmpty != NULL && contadorJugadores != NULL)
	{
		//Si hay lugar en el vector tomara el dato, primero la posicion
		for(int i = 0; i < size; i ++)
		{
			if(isEmpty[i] == 0)
			{
				if(getPosicion(vecPosicion, contadorJugadores, i) == 1 &&
				   getIntRange(&vecCamiseta[i], 1, 99, 3, "\nSeleccione la camiseta del nuevo jugador, del 1 al 99: ", "Dato erroneo. Ingrese un numero del 1 al 99: ") == 1 &&
				   getIntRange(&vecConfederacion[i], 1, 6, 3, "\nSeleccione la confederacion a la que pertenece el nuevo jugador. \nIngrese 1 para AFC en Asia; 2 para CAF en África; 3 para CONCACAF en zona del Norte; 4 para CONMEBOL en Sudamérica; 5 para UEFA en Europa; o 6 para OFC en Oceanía: ", "Dato erroneo. Ingrese un numero del 1 al 6 segun las opciones: ") == 1)
				{
					isEmpty[i] = 1;
					switch(vecPosicion[i])
					{
						case 1:
							contadorJugadores[0] ++;
							break;
						case 2:
							contadorJugadores[1] ++;
							break;
						case 3:
							contadorJugadores[2] ++;
							break;
						case 4:
							contadorJugadores[3] ++;
							break;
						retorno = 1;
					}
				}
				else //Si no pudo tomar algun dato
				{
					printf("\nLos datos del ultimo intento no han sido cargados\n\n");
					retorno = -1;
				}
				break;
			}
		}
	}
	else
	{
		printf("\n\nNo se pudo conseguir memoria\n\n");
	}

	return retorno;
}

int getPosicion(int vecPosicion[], int contadorJugadores[], int i) //Funcion que toma la posicion del jugador
{
	int cant = -2;
	int j = 0;

	if(vecPosicion != NULL && contadorJugadores != NULL)
	{
		while(j < 3 && cant == -2) //Se mantendra el while mientras no se pueda ingresar la posicion por ya estar ocupada hasta 3 intentos
		{
			cant = getIntRange(&vecPosicion[i], 1, 4, 3,
								"\nSeleccione la posicion del nuevo jugador. \nIngrese 1 para Arquero, 2 para Defensor, 3 para Mediocampista y 4 para Delantero: ",
								"Dato erroneo. Ingrese un numero del 1 al 4 segun las opciones: ");
			//Se pedira la posicion. El switch siguiente evaluara si esa posicion que el usuario intenta ingresar esta disponibble
			if(cant == 1)
			{
				switch(vecPosicion[i])
				{
					case 1:
						if(contadorJugadores[0] == 2)
						{
							printf("\nYa se han ingresado todos los Arqueros del equipo. Intente con otra posicion\n");
							cant = -2;
						}
						break;
					case 2:
						if(contadorJugadores[1] == 8)
						{
							printf("\nYa se han ingresado todos los Defensores del equipo. Intente con otra posicion\n");
							cant = -2;
						}
						break;
					case 3:
						if(contadorJugadores[2] == 8)
						{
							printf("\nYa se han ingresado todos los Mediocampistas del equipo. Intente con otra posicion\n");
							cant = -2;
						}
						break;
					case 4:
						if(contadorJugadores[3] == 4)
						{
							printf("\nYa se han ingresado todos los Delanteros del equipo. Intente con otra posicion\n");
							cant = -2;
						}
						break;
				}
			}
			j ++;
		}
		if(j == 3 && cant == -2) //Mensaje final en caso de que no haya podido cargarlo
		{
			printf("\nHa realizado muchos intentos. ");
		}
	}

	return cant;
}
//=======================================================================================================================================//
//=======================================================================================================================================//
//PUNTO 3
int validarCalculos(int isEmpty[], int tam, int sumaFlagsMantenimiento) //Esta primera funcion validara si es posibble hacer los calculos, si ya ingreso los datos necesarios
{
	int retorno = 1;

	if(isEmpty != NULL && tam > 0)
	{
		if(contarJugadores(isEmpty, tam) < 1) //Buscara que haya algun jugador cargado en sistema
		{
			printf("\nNo hay Jugadores cargados.\n");
			retorno = 0;
		}
		if(sumaFlagsMantenimiento != 3) //Lo mismo con este if. Si la suma de las flags es 3 quiere decir que estan todos los costos de mantenimiento cargado, si es distinto falta alguno.
		{
			printf("\nFaltan cargar costos de mantenimiento.\n");
			retorno = 0;
		}
		printf("\n");
	}
	else
	{
		printf("\n\nNo se pudo conseguir memoria\n\n");
		retorno = -1;
	}
	return retorno;
}

int contarJugadores(int* isEmpty, int size)
{
	int contadorJugadores = 0;

	if(isEmpty != NULL && size > 0)
	{
		for(int i = 0; i < size; i ++) //Este for recorrera el vector preguntando si hay alguna posicion vacia. Si lo hay quiere decir que faltan jugadores
		{
			if(isEmpty[i] == 1)
			{
				contadorJugadores ++;
			}
		}
	}
	else
	{
		printf("\n\nNo se pudo conseguir memoria\n\n");
		contadorJugadores = -1;
	}

	return contadorJugadores;
}

int calcularPromedioConf(int vecConfederacion[], float vecPromedio[], int tam, int conf, int* confeConMasJugadores, int* isEmpty)
{//Esta funcion calculara el porcentaje que corresponda a cada confederacion
	int retorno = 0;
	int auxInt;

	if(vecConfederacion != NULL && vecPromedio != NULL && confeConMasJugadores != NULL && tam > 0 && conf > 0)
	{
		contarJugadoresXConfe(vecConfederacion, tam, vecPromedio, isEmpty);
		auxInt = contarJugadores(isEmpty, tam);
		for(int i = 0; i < conf; i++) //Una vez acomodado el contador hara el calculo del promedio aprovechando el mismo vector
		{
			vecPromedio[i] = vecPromedio[i] / auxInt;
		}
		calcularMayorPromedio(vecPromedio, conf, confeConMasJugadores);

		retorno = 1;
	}
	else
	{
		printf("\n\nNo se pudo conseguir espacio en memoria\n\n");
	}

	return retorno;
}

int contarJugadoresXConfe(int* vecConfederacion, int size, float* vecPromedio, int* isEmpty)
{
	int retorno = 0;

	if(vecConfederacion != NULL && vecPromedio != NULL && size > 0 && isEmpty != NULL)
	{
		for(int i = 0; i < size; i++) //Este for recorrera el vector que tiene cargada la confederacion de cada jugador y la ubicara en el vector que contara cuantos jugadores hay en cada confederacion
		{
			if(isEmpty[i] == 1)
			{
				switch(vecConfederacion[i])
				{
					case 1: //AFC, ASIA
						vecPromedio[0] ++;
						break;
					case 2: //CAF, AFRICA
						vecPromedio[1] ++;
						break;
					case 3: //CONCACAF, ZONA NORTE
						vecPromedio[2] ++;
						break;
					case 4: //CONMEBOL, SUDAMERICA
						vecPromedio[3] ++;
						break;
					case 5: //UEFA, EUROPA
						vecPromedio[4] ++;
						break;
					case 6: //OFC, OCEANIA
						vecPromedio[5] ++;
						break;
				}
			}
		}
		retorno = 1;
	}
	else
	{
		printf("\n\nNo se pudo conseguir espacio en memoria\n\n");
	}

	return retorno;
}

int calcularMayorPromedio(float* vecPromedio, int size, int* confeConMasJugadores)
{
	int retorno = 0;
	float maximo;

	if(vecPromedio != NULL && confeConMasJugadores != NULL && size > 0)
	{
		for(int i = 0; i < size; i++) //Por ultimo este for preguntara cual es el mayor promedio
		{
			if(vecPromedio[i] > maximo || i == 0)
			{
				maximo = vecPromedio[i];
				*confeConMasJugadores = i; //La variable I representa ademas de un indice una confedaracion por lo que esa posicion es la que tendra el mayor porcentaje
			}
			else if(vecPromedio[i] == maximo) //En caso de que haya dos con el mismo porcentaje se guardara una posicion inexistente para no afectar el costo de mantenimiento, ya que literalmente, no habria un mayor porcentaje
			{
				*confeConMasJugadores = 7;
			}
		}
	}
	else
	{
		printf("\n\nNo se pudo conseguir espacio en memoria\n\n");
	}

	return retorno;
}

int calcularMantenimiento(int confeConMasJugadores, float* totalMantenimiento, float* aumento, float* totalMantenimientoAumento, float hospedaje, float comida, float transporte)
{ //Esta funcion calculara el mantenimietno
	int retorno = 0;

	if(totalMantenimiento != NULL && aumento != NULL)
	{
		*totalMantenimiento = hospedaje + comida + transporte; //Simples cuentas guardando cada valor en su variable correspondiente
		if(confeConMasJugadores == 4) //Si la posicion es la numero 4, UEFA, se aplicara el aumento
		{
			*aumento =(35 * *totalMantenimiento) / 100;
			*totalMantenimientoAumento = *totalMantenimiento + * aumento;
		}
		retorno = 1;
	}
	else
	{
		printf("\n\nNo se pudo conseguir espacio en memoria\n\n");
	}

	return retorno;
}

//=======================================================================================================================================//
//=======================================================================================================================================//
//PUNTO 4 MOSTRAR EN PANTALLA
int mostrarResultados(float vecPromedio[], float totalMantenimiento, float aumento, float totalMantenimientoAumento, int confeConMasJugadores)
{
	int retorno = 0;

	if(vecPromedio != NULL) //Imprime los datos en pantalla
	{
		printf("\n		INFORME\n\n");
		printf("Promedio UEFA: %.2f\n", vecPromedio[4]);
		printf("Promedio CONMEBOL: %.2f\n", vecPromedio[3]);
		printf("Promedio CONCACAF: %.2f\n", vecPromedio[2]);
		printf("Promedio AFC: %.2f\n", vecPromedio[0]);
		printf("Promedio OFC: %.2f\n", vecPromedio[5]);
		printf("Promedio CAF: %.2f\n", vecPromedio[1]);

		printf("El costo de mantenimiento es de: %.2f\n", totalMantenimiento);
		if(confeConMasJugadores == 4) //Si el porcentaje de la confedearacion es mas alto en la posicion 4, corresponde a la UEFA le aplicara el aumento al costo de mantenimiento
		{
			printf("Como la mayoria de jugadores es de la UEFA recibio un aumento de: %.2f\n", aumento);
			printf("El costo de mantenimiento total es de: %.2f\n", totalMantenimientoAumento);
		}
		retorno = 1;
	}
	else
	{
		printf("\n\nNo se pudo conseguir espacio en memoria\n\n");
	}

	return retorno;
}











