/*
 ============================================================================
 Name        : Tp1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "FuncionesTp1.h"
#include "Validaciones.h"

#define TAM 22 //tamaño de los vectores que guardan los datos de los jugadores
#define CONT 4 //tamaño del vector que guardara la cantidad de los jugadores ingresados por posicion
#define CONF 6 //tamaño del vector que guardara el promedio de las confederaciones

int main(void){
	setbuf(stdout, NULL);

	//costos de mantenimiento
	float costoHospedaje = 0;
	float costoComida = 0;
	float costoTransporte = 0;
	//flags de los costos de mantenimiento
	int flagIngresoHospedaje = 0;
	int flagIngresoComida = 0;
	int flagIngresoTransporte = 0;
	int sumaFlagsMantenimiento;
	//precios Aerolineas
	int vecPosicion[TAM]; //guardara la posicion a la que pertenece cada jugador
	int vecCamiseta[TAM]; //guardara la camiseta de cada jugador
	int vecConfederacion[TAM];  //guardara la confederacion a la que pertenece cada jugador
	float vecPromedioConfe[CONF] = {0, 0, 0, 0, 0, 0}; //guardara el promedio de cada confederacion sobre el total de jugadores. Respectivamente con las posiciones es: AFC; CAF; CONCACAF; CONMEBOL; UEFA; OFC
	int isEmpty[TAM]; //servira para evitar superponer los jugadores a la hora de tomar los datos y evaluar si se ingresaron todos
	int contadorJugadores[CONT] = {0, 0, 0, 0}; //guardara la cantidad de jugadores por posicion. Respectivaemnte Arqueros, Defensores, Mediocampistas y Delanteros
	//calculos
	int confeConMasJugadores;
	float totalMantenimiento; //la suma del hospedaje, comida y transporte
	float aumento; //el valor del aumento si la mayoria de los jugadores es de la UEFA
	float totalMantenimientoAumento; //la suma del mantenimiento mas el aumento
	//utilidades
	int flagCalculoValores = 0;
	char confirm = 'n'; //variable que controla el while principal
	char auxChar;

	initJugadores(isEmpty, TAM);

	do //el menu se repetira hasta que el usuario decida salir o falle en la cantidad de intentos al pedir la opcion del menu
	{
	switch(menuDeOpciones(costoHospedaje, costoComida, costoTransporte, contadorJugadores))//switch que recibbira el retorno de la fuincion menu
	{
		case 1://pedir costos de mantenimiento
			do{
				mostrarCostosMantenimiento(costoHospedaje, costoComida, costoTransporte);
				if(getCostosMantenimiento(&costoHospedaje, &costoComida, &costoTransporte, &flagIngresoHospedaje, &flagIngresoComida, &flagIngresoTransporte, &flagCalculoValores) == 1)
				{
					printf("\nDesea ingresar otro valor?\nIngrese 'Y' para confirmar o cualquier otra tecla para volver al menu: ");
					getCaracterTolower(&auxChar);
				}
				else
				{
					auxChar = 'n';
					printf("Sera devuelto al menu\n\n");
				}
			}while(auxChar == 'y');
			printf("\n\n");
			system("PAUSE");
			break;
		case 2://pedir datos de jugadores
			do{
				if(validarPosicionLibreJugadores(isEmpty, TAM) == 1) //Preguntara si hay lugar
				{
					printf("\n");
					mostrarJugadores(contadorJugadores);
					getJugadores(vecPosicion, vecCamiseta, vecConfederacion, isEmpty, contadorJugadores, TAM);
					printf("\nQuiere ingresar otro jugador? Ingrese la letra 'Y' para ingresar otro o cualquier otra tecla para volver al menu: ");
					getCaracterTolower(&auxChar);
				}
				else
				{
					printf("\nYa ha ingresado todos los jugadores. Sera devuelto al menu\n\n");
					auxChar = 'n';
				}
			}while(auxChar == 'y');
			printf("\n\n");
			system("PAUSE");
			break;
		case 3://calcular los costos y el porcentaje de las confederaciones
			sumaFlagsMantenimiento = flagIngresoHospedaje + flagIngresoComida + flagIngresoTransporte; //sumara las flags de mantenimiento
			if(validarCalculos(isEmpty, TAM, sumaFlagsMantenimiento) == 1) //validara si los datos han sido cargados como para hacer los calculos
			{
				calcularPromedioConf(vecConfederacion, vecPromedioConfe, TAM, CONF, &confeConMasJugadores, isEmpty);
				calcularMantenimiento(confeConMasJugadores, &totalMantenimiento, &aumento, &totalMantenimientoAumento, costoHospedaje, costoComida, costoTransporte);
				printf("\nLos calculos se han realizado con exito!\n\n");
				flagCalculoValores = 1;
			}
			printf("\n\n");
			system("PAUSE");
			break;
		case 4://mostrar los resultados
			if(flagCalculoValores == 1) //lo hara si previamente se calcularon los costos
			{
				mostrarResultados(vecPromedioConfe, totalMantenimiento, aumento, totalMantenimientoAumento, confeConMasJugadores);
			}
			else
			{
				printf("\nNo ha realizado los calculos. Es la opcion 3\n");
			}
			printf("\n\n");
			system("PAUSE");
			break;
		case 5://salir del programa
			salirDelPrograma(&confirm);
			if(confirm != 'y')
			{
				printf("\nEl programa no se cerrara. Sera devuelto al menu\n\n");
			}
			else
			{
				printf("\nEl programa se cerrara.\n\n");
			}
			system("PAUSE");
			break;
		default: //este default hace que si la persona no ingresa una opcion valida del menu saldra del while
			confirm = 'y';
			printf("\nEl programa se cerrara. Intente denuevo mas tarde\n");
	}
	}while(confirm != 'y');//condicion de la estructura repetitiva

	printf("\nGracias por haber utilizado el programa.\nHasta luego\n\n");
	system("PAUSE");

	return 0;
}
