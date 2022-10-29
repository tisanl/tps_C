/*
 * FuncionesInformes.c
 *
 *  Created on: 26 oct. 2022
 *      Author: Usuario
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PedirDatos.h"
#include "FuncionesJugadores.h"
#include "FuncionesConfederaciones.h"
#include "FuncionesInformes.h"

//====================================================================================================================================================//
//===================================================== FUNCIONES PRINCIPALES ========================================================================//
//====================================================================================================================================================//

int subMenuInformes() //SubMenu que corresponde a los informes
{
    int opcion;

    printf("==============================================================\n");
    printf("********************** MENU DE INFORMES **********************\n");
    printf("==============================================================\n\n");
    printf("Opcion 1: Listado de los Jugadores ordenados alfabéticamente por nombre de Confederación y nombre de Jugador.\n");
    printf("Opcion 2: Listado de Confederaciones con sus Jugadores\n");
    printf("Opcion 3: Total y promedio de todos los salarios y cuántos Jugadores cobran más del salario promedio\n");
    printf("Opcion 4: Informar la Confederación con mayor cantidad de años de contratos total\n");
    printf("Opcion 5: Informar porcentaje de Jugadores por cada Confederación\n");
    printf("Opcion 6: Informar cual es la región con más Jugadores y el listado de los mismos\n");
    printf("Opcion 7: Salir\n\n");
    if(getIntRange(&opcion, 1, 7, 3, "Ingrese un numero entre las opciones: ", "Dato incorrecto. Ingrese un numero entre el 1 y el 7 segun las opciones: ") == -1) //Si no puede tomarla devolvera una opcion que ira al default
    {
    	opcion = 200;
    }

    return opcion; //Devuelve la opcion
}

int informes(eJugador* vecJugadores, int sizeJugadores, eConfederacion* vecConfederaciones, int sizeConfederaciones)
{//Esta funcion es la principal de la cual se mostraran los Informes
	int retorno = 0;

	if(vecJugadores != NULL && sizeJugadores > 0 && vecConfederaciones != NULL && sizeConfederaciones > 0)
	{
		retorno = 1;
		switch(subMenuInformes()) //Luego entrara a un submenu donde se solicitara cual Informe desea mostrar y via un switch se ejecutara la funcion correspondiente
		{
			case 1:
				ordenarJugadoresAlfConYNom(vecJugadores, sizeJugadores, vecConfederaciones, sizeConfederaciones);
				listarJugadores(vecJugadores, sizeJugadores, vecConfederaciones, sizeConfederaciones);
				break;
			case 2:
				listarConfederacionesConJugadores(vecJugadores, sizeJugadores, vecConfederaciones, sizeConfederaciones);
				break;
			case 3:
				promedioSalarios(vecJugadores, sizeJugadores);
				break;
			case 4:
				confederacionMasAniosContrato(vecJugadores, sizeJugadores);
				break;
			case 5:
				mostrarPorcentajesPorConfederacion(vecJugadores, sizeJugadores, vecConfederaciones);
				break;
			case 6:
				mostrarJugadoresRegion(vecJugadores, sizeJugadores, vecConfederaciones, sizeConfederaciones);
				break;
			default:
				printf("\nSera devuelto al Menu principal\n\n");
				retorno = -1;
		}
	}
	else
	{
		printf("No se pudo conseguir espacio en memoria");
	}
	return retorno;
}

//====================================================================================================================================================//
//=========================================================== INFORME 1 ==============================================================================//
//====================================================================================================================================================//
int ordenarJugadoresAlfConYNom(eJugador* vecJugadores, int sizeJugadores, eConfederacion* vecConfederaciones, int sizeConfederaciones)
{
    int retorno = 0;
	eJugador jugadorAux;
	char nombreConfederacionI[50];
	char nombreConfederacionJ[50];

	if(vecJugadores != NULL && sizeJugadores > 0 && vecConfederaciones != NULL && sizeConfederaciones > 0)
	{
		for(int i = 0; i < sizeJugadores - 1; i++)
		{
			for(int j = i + 1; j < sizeJugadores; j++) //Se crea un bubble sort con primera condicion comparando el Nombre de la Confederacion del Jugador
			{
				if(((*(vecJugadores + i)).isEmpty == 1 && (*(vecJugadores + j)).isEmpty == 1 &&
						printConfederacion((*(vecJugadores + i)).idConfederacion, vecConfederaciones, sizeConfederaciones, nombreConfederacionI) == 1 &&
						printConfederacion((*(vecJugadores + j)).idConfederacion, vecConfederaciones, sizeConfederaciones, nombreConfederacionJ) == 1 &&
						strcmp(nombreConfederacionI, nombreConfederacionJ) > 0))
				{
					jugadorAux = (*(vecJugadores + i)); //En caso de cumplir la condicion se swapea aprovechando la variable auxiliar
					(*(vecJugadores + i)) = (*(vecJugadores + j));
					(*(vecJugadores + j)) = jugadorAux;
				}
				//En caso de Confederaciones iguales se compara el nombre del Jugador
				if((*(vecJugadores + i)).isEmpty == 1 && (*(vecJugadores + j)).isEmpty == 1 &&
					(*(vecJugadores + i)).idConfederacion == (*(vecJugadores + j)).idConfederacion &&
					strcmp((*(vecJugadores + i)).nombre, (*(vecJugadores + j)).nombre) > 0)
				{
					jugadorAux = (*(vecJugadores + i)); //Si cumple la condicion se swapea aprovechando la variable auxiliar
					(*(vecJugadores + i)) = (*(vecJugadores + j));
					(*(vecJugadores + j)) = jugadorAux;
				}
			}
		}
		retorno = 1;
	}
	else
	{
		printf("No se pudo conseguir espacio en memoria");
	}

    return retorno;
}

//====================================================================================================================================================//
//=========================================================== INFORME 2 ==============================================================================//
//====================================================================================================================================================//
int listarConfederacionesConJugadores(eJugador* vecJugadores, int sizeJugadores, eConfederacion* vecConfederaciones, int sizeConfederaciones)
{
	int retorno = 0;

	if(vecJugadores != NULL && sizeJugadores > 0 && vecConfederaciones != NULL && sizeConfederaciones > 0)
	{
		for(int j = 0; j < sizeConfederaciones; j++)
		{
			if(buscarJugadorConfederacion(vecJugadores, sizeJugadores, (*(vecConfederaciones + j)).id) == 1)//Este for recorrera el array de Jugadores preguntando si alguno corresponde a la Confederacion
			{
				listarConfederacionUnica(vecConfederaciones + j);
				printf("Jugadores: \n");
				printf("| Id |          Nombre         |    Posicion    | N° Camiseta |  Sueldo  | Años de Contrato |\n");
				printf("|----|-------------------------|----------------|-------------|----------|------------------|\n");

				for(int i = 0; i < sizeJugadores; i++) //Este for recorrera el array de Jugadores y mostrara los que esten ocupados
				{
					if((*(vecJugadores + i)).isEmpty == 1 &&
						(*(vecJugadores + i)).idConfederacion == (*(vecConfederaciones + j)).id)
					{
						printf("|%4d|", (*(vecJugadores + i)).id);
						printf("%25s|", (*(vecJugadores + i)).nombre);
						printf("%16s|", (*(vecJugadores + i)).posicion);
						printf("%13hd|", (*(vecJugadores + i)).numeroCamiseta);
						printf("%10.2f|", (*(vecJugadores + i)).salario);
						printf("%18hd|\n", (*(vecJugadores + i)).aniosContrato);
					}
				}
				printf("============================================================================================|\n\n");
			}
		}
		retorno = 1;
	}
	else
	{
		printf("No se pudo conseguir espacio en memoria");
	}

	return retorno;
}

int buscarJugadorConfederacion(eJugador* vecJugadores, int sizeJugadores, int idConfederacion)
{
	int retorno = 0;

	if(vecJugadores != NULL && sizeJugadores > 0)
	{
		retorno = -1;
		for(int i = 0; i < sizeJugadores; i++) //Este for recorrera el array de Jugadores buscando si alguno pertenece a la Confederacion
		{
			if((*(vecJugadores + i)).isEmpty == 1 &&
			(*(vecJugadores + i)).idConfederacion == idConfederacion)
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
//=========================================================== INFORME 3 ==============================================================================//
//====================================================================================================================================================//
int promedioSalarios(eJugador* vecJugadores, int sizeJugadores)
{
	int retorno = 0;
	float acumuladorSalario = 0;
	int contadorJugadores = 0;
	float salarioPromedio;
	int contadorJugadoresCobranMas = 0;

	if(vecJugadores != NULL && sizeJugadores > 0)
	{
		acumularSalario(vecJugadores, sizeJugadores, &acumuladorSalario, &contadorJugadores); //Funcion que acumulara los salarios
		salarioPromedio = acumuladorSalario / contadorJugadores; //Se divide el salario total por la cantidad de Jugadores dados de alta
		jugadoresCobranMas(vecJugadores, sizeJugadores, salarioPromedio, &contadorJugadoresCobranMas); //Se busca los Jugadores que cobran mas que el promedio
		printf("\nEl total de todos los salarios es: %.2f\nEl salario promedio es: %.2f\n"
				"La cantidad de Jugadores que tienen salarios mas grandes que el promedio es: %d\n", acumuladorSalario, salarioPromedio, contadorJugadoresCobranMas);
		retorno = 1; //Se muestran en pantalla
	}
	else
	{
		printf("No se pudo conseguir espacio en memoria");
	}
	return retorno;
}

int acumularSalario(eJugador* vecJugadores, int sizeJugadores, float* acumulador, int* contador)
{
	int retorno = 0;

	if(vecJugadores != NULL && sizeJugadores > 0 && acumulador != NULL && contador != NULL)
	{
		for(int i = 0; i < sizeJugadores; i++) //Se recorrera el vector de Jugadores, se acumulara el salario y contara la cantidad de Jugadores para despues calcular el promedio
		{
			if((*(vecJugadores + i)).isEmpty == 1)
			{
				*acumulador += (*(vecJugadores + i)).salario;
				*contador += 1;
			}
		}
		retorno = 1;
	}
	else
	{
		printf("No se pudo conseguir espacio en memoria");
	}
	return retorno;
}

int jugadoresCobranMas(eJugador* vecJugadores, int sizeJugadores, float salarioPromedio, int* contador)
{
	int retorno = 0;

	if(vecJugadores != NULL && sizeJugadores > 0 && contador != NULL)
	{
		for(int i = 0; i < sizeJugadores; i++) //Se recorrera el vector de Jugadores contando los que cuyo salario es mayor al promedio
		{
			if((*(vecJugadores + i)).isEmpty == 1 && (*(vecJugadores + i)).salario > salarioPromedio)
			{
				*contador += 1;
			}
		}
		retorno = 1;
	}
	else
	{
		printf("No se pudo conseguir espacio en memoria");
	}
	return retorno;
}

//====================================================================================================================================================//
//=========================================================== INFORME 4 ==============================================================================//
//====================================================================================================================================================//
int confederacionMasAniosContrato(eJugador* vecJugadores, int sizeJugadores)
{
	int retorno = 0;
	int acumuladorAnios[6] = {0,0,0,0,0,0}; //Vector donde se acumularan los años de contrato. Cada posicion corresponde a una Confederacion en el mismo orden que estan hardcodeadas
	int maximo;
	int posicion;

	if(vecJugadores != NULL && sizeJugadores > 0)
	{
		acumularAniosContrato(vecJugadores, sizeJugadores, acumuladorAnios); //Esta funcion acumulara la cantidad de años de contrato en el vector
		for(int i = 0; i < 6; i++) //Este for buscara la mayor cantidad de años y guardara la posicion del vector en la que se encuentra
		{
			if(*(acumuladorAnios + i) > maximo || i == 0)
			{
				maximo = *(acumuladorAnios + i);
				posicion = i;
			}
		}
		switch(posicion) //Dependiendo de la posicion donde esta la mayor cantidad de años mostrara un mensaje
		{
			case 0:
				printf("\nLa Confederacion con mas años de contrato es CONMEBOL\n");
				break;
			case 1:
				printf("\nLa Confederacion con mas años de contrato es UEFA\n");
				break;
			case 2:
				printf("\nLa Confederacion con mas años de contrato es AFC\n");
				break;
			case 3:
				printf("\nLa Confederacion con mas años de contrato es CAF\n");
				break;
			case 4:
				printf("\nLa Confederacion con mas años de contrato es CONCACAF\n");
				break;
			case 5:
				printf("\nLa Confederacion con mas años de contrato es OFC\n");
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

int acumularAniosContrato(eJugador* vecJugadores, int sizeJugadores, int* vecAcumulador)
{
	int retorno = 0;

	if(vecJugadores != NULL && sizeJugadores > 0 && vecAcumulador != NULL)
	{
		for(int i = 0; i < sizeJugadores; i++)
		{
			if((*(vecJugadores + i)).isEmpty == 1) //Si el Jugador esta de alta, dependiendo del id de la confederacion, acumulara en una posicion del vector la cantidad de años
			{
				switch((*(vecJugadores + i)).idConfederacion)
				{
					case 100:
						*vecAcumulador += (*(vecJugadores + i)).aniosContrato;
						break;
					case 101:
						*(vecAcumulador + 1) += (*(vecJugadores + i)).aniosContrato;
						break;
					case 102:
						*(vecAcumulador + 2) += (*(vecJugadores + i)).aniosContrato;
						break;
					case 103:
						*(vecAcumulador + 3) += (*(vecJugadores + i)).aniosContrato;
						break;
					case 104:
						*(vecAcumulador + 4) += (*(vecJugadores + i)).aniosContrato;
						break;
					case 105:
						*(vecAcumulador + 5) += (*(vecJugadores + i)).aniosContrato;
						break;
				}
			}
		}
		retorno = 1;
	}
	else
	{
		printf("No se pudo conseguir espacio en memoria");
	}
	return retorno;
}

//====================================================================================================================================================//
//=========================================================== INFORME 5 ==============================================================================//
//====================================================================================================================================================//
int mostrarPorcentajesPorConfederacion(eJugador* vecJugadores, int sizeJugadores, eConfederacion* vecConfederaciones)
{
	int retorno = 0;
	int contadorJugadoresConfederacion[6] = {0,0,0,0,0,0}; //Vector donde se acumularan la cantidad de Jugadores por Confederacion. Cada posicion corresponde a una Confederacion en el mismo orden que estan hardcodeadas
	int contadorJugadoresAlta = 0; //Variable quen guardara la cantidad de Jugadores en total
	float porcentajeConfederacion[6]; //Vector donde se guardara el porcentaje de la cantidad de Jugadores por Confederacion

	if(vecJugadores != NULL && sizeJugadores > 0 && vecConfederaciones != NULL)
	{
		acumularCantidadJugadores(vecJugadores, sizeJugadores, contadorJugadoresConfederacion);
		for(int i = 0; i < sizeJugadores; i++) //Este for contara la cantidad de Jugadores que estan dados de alta
		{
			if((*(vecJugadores + i)).isEmpty == 1)
			{
				contadorJugadoresAlta += 1;
			}
		}
		for(int i = 0; i < 6; i++) //Este for hara el calculo del porcentaje por Confederacion y lo mostrara en pantalla
		{
			*(porcentajeConfederacion + i) = (*(contadorJugadoresConfederacion + i) * 100) / contadorJugadoresAlta;
			printf("El porcentaje de Jugadores de la %s es %.2f porciento\n", (*(vecConfederaciones + i)).nombre, *(porcentajeConfederacion + i));
		}
		retorno = 1;
	}
	else
	{
		printf("No se pudo conseguir espacio en memoria");
	}
	return retorno;
}

int acumularCantidadJugadores(eJugador* vecJugadores, int sizeJugadores, int* vecAcumulador)
{
	int retorno = 0;

	if(vecJugadores != NULL && sizeJugadores > 0 && vecAcumulador != NULL)
	{
		for(int i = 0; i < sizeJugadores; i++)
		{
			if((*(vecJugadores + i)).isEmpty == 1)
			{
				switch((*(vecJugadores + i)).idConfederacion) //Si el Jugador esta dado de alta sumara 1 dependiendo de la Confederacion a la que pertenezca
				{
					case 100:
						*vecAcumulador += 1;
						break;
					case 101:
						*(vecAcumulador + 1) += 1;
						break;
					case 102:
						*(vecAcumulador + 2) += 1;
						break;
					case 103:
						*(vecAcumulador + 3) += 1;
						break;
					case 104:
						*(vecAcumulador + 4) += 1;
						break;
					case 105:
						*(vecAcumulador + 5) += 1;
						break;
				}
			}
		}
		retorno = 1;
	}
	else
	{
		printf("No se pudo conseguir espacio en memoria");
	}
	return retorno;
}
//====================================================================================================================================================//
//=========================================================== INFORME 6 ==============================================================================//
//====================================================================================================================================================//
int mostrarJugadoresRegion(eJugador* vecJugadores, int sizeJugadores, eConfederacion* vecConfederaciones, int sizeConfederaciones)
{
	int retorno = 0;
	int contadorJugadoresRegion[6] = {0,0,0,0,0,0}; //Vector donde se acumularan la cantidad de Jugadores por Region. Cada posicion corresponde a una Region en el mismo orden que estan hardcodeadas
	int idConfederacionMasJugadores;
	char descripcionConfederacion[50];

	if(vecJugadores != NULL && sizeJugadores > 0 && vecConfederaciones != NULL && sizeConfederaciones > 0)
	{
		acumularCantidadJugadores(vecJugadores, sizeJugadores, contadorJugadoresRegion); //Funcion que se encargara de acumular los Jugadores por Region
		buscarRegionMasJugadores(vecJugadores, sizeJugadores, contadorJugadoresRegion, &idConfederacionMasJugadores); //Funcion que buscara la Confederacion con mas Jugadores y guardara el Id

		printf("\n|===========================================================================================================|\n"); //Se genera la estructura para mostrar en pantalla
		printf("| Id |          Nombre         |    Posicion    | N° Camiseta |  Sueldo  | Confederacion | Años de Contrato |\n");
		printf("|----|-------------------------|----------------|-------------|----------|---------------|------------------|\n");
		for(int i = 0; i < sizeJugadores; i++) //Este for recorrera el array de Jugadores y mostrara los que esten ocupados
		{
			if((*(vecJugadores + i)).isEmpty == 1 && (*(vecJugadores + i)).idConfederacion == idConfederacionMasJugadores) //Se mostraran los Jugadores dados de alta y cuyo Id pertenezca a la Region que se quiere mostrar
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

int buscarRegionMasJugadores(eJugador* vecJugadores, int sizeJugadores, int* vecAcumulador, int* idConfederacion)
{
	int retorno = 0;
	int maximo;
	int posicion;

	if(vecJugadores != NULL && sizeJugadores > 0 && vecAcumulador != NULL)
	{
		for(int i = 0; i < 6; i++) //Este for buscara la mayor cantidad de Jugadores y guardara la posicion del vector en la que se encuentra
		{
			if(*(vecAcumulador + i) > maximo || i == 0)
			{
				maximo = *(vecAcumulador + i);
				posicion = i;
			}
		}
		switch(posicion) //Dependiendo de la posicion donde esta la mayor cantidad de Jugadores mostrara un mensaje y guardara el Id de esa Confederacion
		{
			case 0:
				printf("\nLa Region con mas Jugadores es la CONMEBOL\n");
				*idConfederacion = 100;
				break;
			case 1:
				printf("\nLa Region con mas Jugadores es la UEFA\n");
				*idConfederacion = 101;
				break;
			case 2:
				printf("\nLa Region con mas Jugadores es la AFC\n");
				*idConfederacion = 102;
				break;
			case 3:
				printf("\nLa Region con mas Jugadores es la CAF\n");
				*idConfederacion = 103;
				break;
			case 4:
				printf("\nLa Region con mas Jugadores es la CONCACAF\n");
				*idConfederacion = 104;
				break;
			case 5:
				printf("\nLa Region con mas Jugadores es la OFC\n");
				*idConfederacion = 105;
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
