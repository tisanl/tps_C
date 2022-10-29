/*
 ============================================================================
 Name        : Tp2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "PedirDatos.h"
#include "FuncionesConfederaciones.h"
#include "FuncionesJugadores.h"
#include "FuncionesInformes.h"


#define SIZE 10 //Tamaño del vector de Jugadores
#define TAM 10 //Tamaño del vector de Confederaciones


int main() {
	setbuf(stdout, NULL);

	int id = 1; //Variable que gaurdar el Id que sera autoincremental
	char confirm = 'n'; //Variable que condiciona el do while
	int auxInt; //Auxiliar para sostener datos
	char auxChar; //Auxiliar de char

	eJugador vecJugadores[SIZE];
	eConfederacion vecConfederaciones[TAM];

	hardcodeoConfederacion(vecConfederaciones, TAM);

	if(initJugadores(vecJugadores, SIZE) == 1) //Ejecutara el ABM en caso de que haya podido inicializar el array de Jugadores
	{
		do{
		switch(menuDeOpciones())//Switch que recibira el retorno de la funcion menu
		{
			case 1://Alta Jugador
				altaJugadores(vecJugadores, SIZE, vecConfederaciones, TAM, &id);
				printf("\n");
				system("PAUSE");
				break;
			case 2://Baja Jugador
				do
				{
					if(validarPosicionOcupadaJugadores(vecJugadores, SIZE) == 1) //Primero se valida que haya al menos un jugador cargado
					{
						//En caso de que haya algo cargado mostrara la lista de Jugadores y se pide el Id
						listarJugadores(vecJugadores, SIZE, vecConfederaciones, TAM);
						if(getIntRange(&auxInt, 1, 3000, 3, "Ingrese el Id del Jugador que quiere dar de baja: ", "Id incorrecto. Eliga un Id entre el 1 y el 3000: ") == 1) //Si existe el array
						{
							auxInt = findJugadorById(vecJugadores, SIZE, auxInt); //Se busca el Jugador en el Array y en caso de existir devuelve la posicion
							if(auxInt != -1)
							{
								//En caso de que haya podido tomarlo entrara a la baja y preguntara por otro Jugador
								bajaJugadores(vecJugadores, auxInt, vecConfederaciones, TAM);
								printf("\nIngrese 'Y' si quiere dar de baja otro Jugador o cualquier otra tecla para volver al menu: ");
							}
							else //Si no pudo tomar el Id muestra este mensaje
							{
								//La funcion findJugadorById informa si no existe Jugador con ese Id
								printf("\nIngrese 'Y' si quiere intentar con otro Id o cualquier otra tecla para volver al menu: ");
							}
							getCaracterTolower(&auxChar);
						}
						else
						{
							printf("\nSera devuelto al menu\n"); //Si no pudo tomar el Id muestra este mensaje
							auxChar = 'n';
						}
					}
					else
					{
						printf("\nNo hay ningun Jugador cargado en sistema\n"); //Si no existe ningun Jugador mostrara este mensaje
						auxChar = 'n';
					}
				}while(auxChar == 'y');
				printf("\n");
				system("PAUSE");
				break;
			case 3: //Modificar Jugador
				do
				{
					if(validarPosicionOcupadaJugadores(vecJugadores, SIZE) == 1) //Primero se valida que haya al menos un Jugador cargado
					{
						//En caso de que haya algo cargado mostrara la lista de Jugadores y se pide el Id
						listarJugadores(vecJugadores, SIZE, vecConfederaciones, TAM);
						if(getIntRange(&auxInt, 1, 3000, 3, "Ingrese el Id del Jugador que quiere modificar: ", "Id incorrecto. Eliga un Id entre el 1 y el 3000: ") == 1)
						{
							auxInt = findJugadorById(vecJugadores, SIZE, auxInt); //Se busca el Jugador en el Array y en caso de existir devuelve la posicion
							if(auxInt != -1) //Si existe el array
							{
								//En caso de que haya podido tomarlo entrara a la modificacion y preguntara por otro Jugador
								modificarJugadores(vecJugadores, auxInt, vecConfederaciones, TAM);
								printf("\nIngrese 'Y' si quiere modificar otro Id o cualquier otra tecla para volver al menu: ");
							}
							else //En caso de que no lo haya podido tomar preguntara por otro intento
							{
								printf("\nIngrese 'Y' si quiere intentar con otro Id o cualquier otra tecla para volver al menu: ");
							}
							getCaracterTolower(&auxChar);
						}
						else
						{
							printf("\nSera devuelto al menu\n"); //Si no pudo tomar el Id muestra este mensaje
							auxChar = 'n';
						}
					}
					else
					{
						printf("\nNo hay ningun Jugador cargado en sistema\n"); //Si no existe ningun Jugador mostrara este mensaje
						auxChar = 'n';
					}
				}while(auxChar == 'y');
				printf("\n");
				system("PAUSE");
				break;
			case 4://Informes
				do
				{
					if(validarPosicionOcupadaJugadores(vecJugadores, SIZE) == 1) //Primero se valida que haya al menos un jugador cargado
					{
						if(informes(vecJugadores, SIZE, vecConfederaciones, TAM) == 1) //En el caso que haya mostrado algun Informe
						{
							printf("\nIngrese 'Y' si quiere mostrar otro Informe o cualquier otra tecla para volver al menu: ");
							getCaracterTolower(&auxChar);
						}
						else
						{
							auxChar = 'n';
						}
					}
					else
					{
						printf("\nNo hay ningun Jugador cargado en sistema\n"); //Si no existe ningun Jugador mostrara este mensaje
						auxChar = 'n';
					}
				}while(auxChar == 'y');
				printf("\n");
				system("PAUSE");
				break;
			case 5://Salir del programa
				salirDelPrograma(&confirm);
				if(confirm != 'y')
				{
					printf("\nEl programa no se cerrara. Sera devuelto al menu\n");
				}
				else
				{
					printf("\nEl programa se cerrara.\n");
				}
				system("PAUSE");
				break;
			default: //Este default hace que si la persona no ingresa una opcion valida del menu saldra del while
				confirm = 'y';
				printf("\nEl programa se cerrara. Intente denuevo mas tarde\n");
		}
		}while(confirm != 'y');//condicion de la estructura repetitiva

		printf("\nGracias por haber utilizado el programa.\nHasta luego\n\n");
	}
	else
	{
		printf("No se pudo inicializar los vectores de Articulos y Ventas\nEl programa se cerrara\n\n");
	}

	system("PAUSE");

	return 0;
}
