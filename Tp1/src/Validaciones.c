/*
 * Validaciones.c
 *
 *  Created on: 22 ago. 2022
 *      Author: Usuario
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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
		printf("Ingrese una letra: ");
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
