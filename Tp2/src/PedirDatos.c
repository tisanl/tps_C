/*
 * Validaciones.c
 *
 *  Created on: 22 ago. 2022
 *      Author: Usuario
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "PedirDatos.h"
#define AUX 200

int menuDeOpciones()
{
	int opcion;

	printf("=====================================================================\n");
	printf("*************************  MENU DE OPCIONES *************************\n");
	printf("=====================================================================\n\n");
	printf("1. Alta de Jugador\n");
	printf("2. Baja de Jugador\n");
	printf("3. Modificacion de Jugador\n");
	printf("4. Informes\n");
	printf("5. Salir\n");

	//Funcion que pide la opcion, se detalla en su desarrollo
	if(getIntRange(&opcion, 1, 9, 3, "Ingrese un numero entre las opciones: ", "Dato incorrecto. Ingrese un numero entre el 1 y el 8 segun las opciones: ") == -1) //Si no puede tomarla devolvera una opcion que ira al default
	{
		opcion = 200;
	}
	return opcion; //devuelve la opcion
}

int getIntRange(int* pNumero, int minimo, int maximo, int i, char mensajePrimero[200], char mensajeError[200]) //Funcion que pide un numero entero entre un rango
{
	int retorno = 0;
	int cant;

	if(pNumero != NULL && mensajePrimero != NULL && mensajeError != NULL)
	{
		printf("%s", mensajePrimero); //Se pedira el dato por primera vez
		fflush(stdin);
		cant = scanf("%d", pNumero);
		retorno = 1;
		if(i == 0 && (cant == 0 || *pNumero < minimo || *pNumero > maximo)) //Se evaluara si se pudo pedir o si esta dentro del rango, If especifico si no hay repeticion
		{
			printf("Dato erroneo\n");
			retorno = -1;
		}
		else
		{
			while(i != 0 && (cant == 0 || *pNumero < minimo || *pNumero > maximo)) //Se evaluara si se pudo pedir o si esta dentro del rango, If especifico si  hay repeticion
			{
				printf("%s", mensajeError);
				fflush(stdin);
				cant = scanf("%d", pNumero);
				i --;
			}
			retorno = 1;
			if(i == 0 && (cant == 0 || *pNumero < minimo || *pNumero > maximo)) //Si el dato sigue siendo no valido y gasto los intentos
			{
				printf("\nHa realizado muchos intentos\n");
				retorno = -1;
			}
		}
	}
	return retorno;
}

int getIntPositiv(int* pNumero, int i, char mensajePrimero[200], char mensajeError[200]) //Funcion que pide un numero entero positivo (sin el 0)
{
	int retorno = 0;
	int cant;

	if(pNumero != NULL && mensajePrimero != NULL && mensajeError != NULL) //Se pedira el dato por primera vez
	{
		printf("%s", mensajePrimero);
		fflush(stdin);
		cant = scanf("%d", pNumero);
		retorno = 1;
		if(i == 0 && (cant == 0 || *pNumero <= 0)) //Se evaluara si se pudo pedir o si esta dentro del rango, If especifico si no hay repeticion
		{
			printf("\nDato erroneo\n");
			retorno = -1;
		}
		else
		{
			while(i != 0 && (cant == 0 || *pNumero <= 0)) //Se evaluara si se pudo pedir o si esta dentro del rango, If especifico si  hay repeticion
			{
				printf("%s", mensajeError);
				fflush(stdin);
				cant = scanf("%d", pNumero);
				i --;
			}
			retorno = 1;
			if(i == 0 && (cant == 0 || *pNumero < 0)) //Si el dato sigue siendo no valido y gasto los intentos
			{
				printf("\nHa realizado muchos intentos\n");
				retorno = -1;
			}
		}
	}
	return retorno;
}

int getShortIntRange(short* pNumero, int minimo, int maximo, int i, char mensajePrimero[200], char mensajeError[200]) //Funcion que pide un numero entero entre un rango
{
	int retorno = 0;
	int cant;

	if(pNumero != NULL && mensajePrimero != NULL && mensajeError != NULL)
	{
		printf("%s", mensajePrimero); //Se pedira el dato por primera vez
		fflush(stdin);
		cant = scanf("%hd", pNumero);
		retorno = 1;
		if(i == 0 && (cant == 0 || *pNumero < minimo || *pNumero > maximo)) //Se evaluara si se pudo pedir o si esta dentro del rango, If especifico si no hay repeticion
		{
			printf("Dato erroneo\n");
			retorno = -1;
		}
		else
		{
			while(i != 0 && (cant == 0 || *pNumero < minimo || *pNumero > maximo)) //Se evaluara si se pudo pedir o si esta dentro del rango, If especifico si  hay repeticion
			{
				printf("%s", mensajeError);
				fflush(stdin);
				cant = scanf("%hd", pNumero);
				i --;
			}
			retorno = 1;
			if(i == 0 && (cant == 0 || *pNumero < minimo || *pNumero > maximo)) //Si el dato sigue siendo no valido y gasto los intentos
			{
				printf("\nHa realizado muchos intentos\n");
				retorno = -1;
			}
		}
	}
	return retorno;
}

int getShortIntPositiv(short* pNumero, int i, char mensajePrimero[200], char mensajeError[200]) //Funcion que pide un numero entero positivo (sin el 0)
{
	int retorno = 0;
	int cant;

	if(pNumero != NULL && mensajePrimero != NULL && mensajeError != NULL) //Se pedira el dato por primera vez
	{
		printf("%s", mensajePrimero);
		fflush(stdin);
		cant = scanf("%hd", pNumero);
		retorno = 1;
		if(i == 0 && (cant == 0 || *pNumero <= 0)) //Se evaluara si se pudo pedir o si esta dentro del rango, If especifico si no hay repeticion
		{
			printf("\nDato erroneo\n");
			retorno = -1;
		}
		else
		{
			while(i != 0 && (cant == 0 || *pNumero <= 0)) //Se evaluara si se pudo pedir o si esta dentro del rango, If especifico si  hay repeticion
			{
				printf("%s", mensajeError);
				fflush(stdin);
				cant = scanf("%hd", pNumero);
				i --;
			}
			retorno = 1;
			if(i == 0 && (cant == 0 || *pNumero < 0)) //Si el dato sigue siendo no valido y gasto los intentos
			{
				printf("\nHa realizado muchos intentos\n");
				retorno = -1;
			}
		}
	}
	return retorno;
}

int getFloatPositiv(float* pNumero, int i, char mensajePrimero[200], char mensajeError[200]) //Funcion que pide un numero flotante positivo (sin el 0)
{
	int retorno = 0;
	int cant;

	if(pNumero != NULL && mensajePrimero != NULL && mensajeError != NULL) //Se pedira el dato por primera vez
	{
		printf("%s", mensajePrimero);
		fflush(stdin);
		cant = scanf("%f", pNumero);
		retorno = 1;
		if(i == 0 && (cant == 0 || *pNumero <= 0)) //Se evaluara si se pudo pedir o si esta dentro del rango, If especifico si no hay repeticion
		{
			printf("Dato erroneo\n");
			retorno = -1;
		}
		else
		{
			while(i != 0 && (cant == 0 || *pNumero <= 0)) //Se evaluara si se pudo pedir o si esta dentro del rango, If especifico si  hay repeticion
			{
				printf("%s", mensajeError);
				fflush(stdin);
				cant = scanf("%f", pNumero);
				i --;
			}
			retorno = 1;
			if(i == 0 && (cant == 0 || *pNumero < 0)) //Si el dato sigue siendo no valido y gasto los intentos
			{
				printf("\nHa realizado muchos intentos\n");
				retorno = -1;
			}
		}
	}
	return retorno;
}

int getCaracterTolower(char* pCaracter) //Funcion que pide un caracter y lo pasa a minuscula
{
	int retorno = 0;

	if(pCaracter != NULL)
	{
		printf("\nIngrese una letra: ");
		fflush(stdin);
		scanf("%c", pCaracter);
		*pCaracter =  tolower(*pCaracter);
		retorno = 1;
	}

	return retorno;
}

int salirDelPrograma(char* confirm) //Funcion muy similar a la anterior pero agrega el mensaje de salida
{
	int retorno = 0;

	if(confirm != NULL)
	{
		printf("\nDesea salir del programa?\nIngrese una 'Y' para confirmar o cualquier otra letra para volver al menu: ");
		getCaracterTolower(confirm);
		retorno = 1;
	}
	else
	{
		printf("\nNo se pudo conseguir memoria");
	}

	return retorno;
}

int getStringValidarTamanio(char* string, int size, int i, char mensaje[200], char mensajeError[200])
{
	char auxCad[AUX]; //se crea una variable auxiliar para evitar problemas de desbordamiento
	int retorno = 0;

	if(string != NULL && size > 0 && mensaje != NULL && mensajeError != NULL)
	{
		printf("%s", mensaje); //La primera vez que intente tomarla mostrara el primer mensaje
		fflush(stdin);
		gets(auxCad);
		if(strlen(auxCad) < size) //En caso de que el tamaño sea correcto guardara la cadena tomada
		{
			strcpy(string, auxCad);
			retorno = 1;
		}
		else if(i == 0) //En caso de que no haya reintentos mostrara este mensaje
		{
			printf("El texto ingresado es demasiado largo");
		}
		else //En caso de que las hay entrara en bucle hasta que se agoten las repeticiones
		{
			while(i != 0 && strlen(auxCad) > size) //Se mantendra en bucle mientras haya repeticiones y la cadena auxiliar sea mayor al tamaño de la strin que se quiere tomar
			{
				printf("%s", mensajeError);
				fflush(stdin);
				gets(auxCad);
				i--;
			}
			if(i == 0 && strlen(auxCad) > size) //Si el dato sigue siendo no valido y gasto los intentos mostrara el siguiente mensaje
			{
				printf("\nEl texto ingresado es demasiado largo y ha realizado muchos intentos\n");
				retorno = -1;
			}
			else //Si pudo tomar una string en los intentos asignados la guardara
			{
				strcpy(string, auxCad);
				retorno = 1;
			}
		}
    }
	else
	{
    	printf("\nNo se pudo conseguir memoria");
    }

	return retorno;
}


int getStringAlphaYTam(char* string, int size, int i, char mensaje[200], char mensajeError[200])
{
	char auxCad[AUX]; //se crea una variable auxiliar para evitar problemas de desbordamiento
	int retorno = 0;

	if(string != NULL && size > 0 && mensaje != NULL && mensajeError != NULL)
	{
		printf("%s", mensaje); //La primera vez que intente tomarla mostrara el primer mensaje
		fflush(stdin);
		gets(auxCad);
		if(strlen(auxCad) < size && validarTodoAlphaConSpaceBar(auxCad) == 1) //En caso de que el tamaño sea correcto y los caracteres letras guardara la cadena tomada
		{
			strcpy(string, auxCad);
			retorno = 1;
		}
		else if(i == 0) //En caso de que no haya reintentos mostrara este mensaje
		{
			printf("\nEl texto ingresado es demasiado largo y/o tiene un caracter que no es una letra\n");
			retorno = -1;
		}
		else //En caso de que las haya entrara en bucle hasta que se agoten las repeticiones
		{	//Se mantendra en bucle mientras haya repeticiones, la cadena auxiliar sea mayor al tamaño de la string que se quiere tomar o algun caracter no sea una letra
			while(i != 0 && (strlen(auxCad) > size || validarTodoAlphaConSpaceBar(auxCad) != 1))
			{
				printf("%s", mensajeError);
				fflush(stdin);
				gets(auxCad);
				i--;
			}
			if(i == 0 && (strlen(auxCad) > size || validarTodoAlphaConSpaceBar(auxCad) != 1)) //Si el dato sigue siendo no valido y gasto los intentos mostrara el siguiente mensaje
			{
				printf("\nEl texto ingresado es demasiado largo y/o tiene un caracter que no es una letra\nHa realizado muchos intentos\n");
				retorno = -1;
			}
			else //Si pudo tomar una string en los intentos asignados la guardara
			{
				strcpy(string, auxCad);
				retorno = 1;
			}
		}
    }
	else
	{
    	printf("\nNo se pudo conseguir memoria");
    }

	return retorno;
}

int validarTodoAlphaConSpaceBar(char* auxCad)
{
    int retorno = 0; //Retorna 0 si no pudo conseguir memoria

    if(auxCad != NULL)
    {
    	retorno = 1; //Retornara 1 en caso de que toda la cadena sea letra
		for(int i = 0; i < AUX -1; i++)
		{
			if(*(auxCad + i) == '\0') //Evaluara hasta que el for se encuentre con el \0
			{
				break;
			}
			else if(isalpha(*(auxCad + i)) == 0 && *(auxCad + i) != 32) //Entrara si el valor del caracter no es una letra y no es un caracter de espacio
			{
				retorno = -1; //Retorna -1 si el caracter no es una letra ni un spaceBar
				break;
			}
		}
    }
    else
    {
        printf("\nNo se pudo conseguir memoria");
    }

    return retorno;
}

