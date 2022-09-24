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
	int cant;

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
	cant = getIntRange(&opcion, 1, 5, 3, "Ingrese un numero entre las opciones: ", "Dato incorrecto. Ingrese un numero entre el 1 y el 6 segun las opciones: ");
	if(cant == -1) //Si no puede tomarla devolvera una opcion que ira al default
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
		printf("No se pudo conseguir memoriakkkkk\n\n");
	}
}

//=======================================================================================================================================//
//=======================================================================================================================================//
//FUNCIONES DEL PUNTO 1
//Funcion principal del punto 1
int getCostosMantenimiento(float* costoHospedaje, float* costoComida, float* costoTransporte, int* flagHospedaje, int* flagComida, int* flagTransporte, int* flagCalculoValores)
{
	int retorno = 0;
	char letra;
	int cant;
	char confirm = 'y'; //Variable que mantendra el while

	if(costoHospedaje != NULL && costoComida != NULL && costoTransporte != NULL && flagHospedaje != NULL && flagComida != NULL && flagTransporte != NULL && flagCalculoValores != NULL)
	{
		printf("\nIngresar costos\n\n");
		do
		{
			mostrarCostosMantenimiento(*costoHospedaje, *costoComida, *costoTransporte);
			cant = subMenuMantenimiento(&letra); //Se abre la funcion que ejecuta el submenu
			if(cant == 1) //Si pudo tomar una letra valida devolvera 1 (mientras no sea volver al menu) y entrara al if para pedir el costo de lo seleccionado
			{
				cant = pedirCostos(letra, &confirm, costoHospedaje, costoComida, costoTransporte, flagHospedaje, flagComida, flagTransporte, flagCalculoValores);
				if(cant == 1) //Si puede tomar el valor el retorno de esta funcion sera 1
				{
					retorno = 1;
				}
			}
			else if(cant == -1) //Si devuelve -1 es porque no lo pudo tomar y devolvera el siguiente mensaje
			{
				printf("\n\nHa realizado muchos intentos. Intentelo denuevo mas tarde\n\nSera devuelto al menu\n\n");
				retorno = -1;
				confirm = 'n';
			}
			else //Si es 0
			{
				printf("\n\nRevise su equipo\n\n");
				confirm = 'n';
			}
		}while(confirm == 'y');
	}
	else
	{
		printf("\n\nNo se pudo conseguir memoria\n\n");
	}

	system("PAUSE");
	return retorno;
}

int subMenuMantenimiento(char* pLetra) //En esta funcion se solicitara al usuario que ingrese una letra correspondiente al costo que se quiere ingresar o volver al menu
{
	int retorno = 0;
	int cant;
	int i = 0;

	if(pLetra != NULL)
	{
		printf("\nEscoja una letra: 'H' para ingresar el costo del hospedaje, una 'C' para ingresar el costo de la comida, una 'T' para ingresar el costo del transporte o una 'M' para volver al menu:\n");
		cant = getCaracterTolower(pLetra); //Funcion para pedir el caracter
		retorno = 1;
		while(i < 3 && ((*pLetra != 'h' && *pLetra != 'c' && *pLetra != 't' && *pLetra != 'm') || cant == 0)) //Se valida que sea una de las letras pedidas y/o que la cantidad de intentos no sea mayor a 3
		{
			if(cant == 0)
			{
				printf("\n\nNo se pudo conseguir espacio en memoria\n\n");
				retorno = 0;
			}
			else if(*pLetra != 'h' && *pLetra != 'c' && *pLetra != 't' && *pLetra != 'm')
			{
				printf("Dato erroneo\n");
				retorno = 1;
			}
			cant = getCaracterTolower(pLetra);
			i ++;
		}
		if(i == 3 && cant == 1 && (*pLetra != 'h' && *pLetra != 'c' && *pLetra != 't' && *pLetra != 'm'))
		{
			retorno = -1;
		}
	}

	return retorno;
}

int pedirCostos(char opcion, char* confirm, float* costoHospedaje, float* costoComida, float* costoTransporte, int* flagHospedaje, int* flagComida, int* flagTransporte, int* flagCalculoValores)
{	//Esta funcion se ejecutara en caso de que el usuario haya podido utilizar el submenu de forma correcta
	//Dependiendo de la letra que haya elegido ingresara el valor
	int cant = 0;
	int retorno = 0;

	printf("\n");

	if(confirm != NULL && costoHospedaje != NULL && costoComida != NULL && costoTransporte != NULL && flagHospedaje != NULL && flagComida != NULL && flagTransporte != NULL && flagCalculoValores != NULL)
	{
		switch(opcion)
		{
			case 'h':
				cant = getFloatPositiv(costoHospedaje, 3, "Ingrese el costo de Hospedaje: " , "Dato erroneo. Ingrese un numero positivo: ");
				if(cant == 1)
				{
					*flagHospedaje = 1; //Si pudo ingresar el costo la flag se levantara
				}
				else
				{
					printf("\nEl costo del Hospedaje fue reeestablecido en 0\nSera devuelto al submenu\n\n");
					*costoHospedaje = 0;  //Si el usuario falla los valores y flags se reseataran para evitar que pueda ingresar a pasos anteriores si es que tanto falla la primera vez como intenta reescribirlos
					*flagHospedaje = 0;
					*flagCalculoValores = 0;
				}
				break;
			case 'c':
				cant = getFloatPositiv(costoComida, 3, "Ingrese el costo de Comida: " , "Dato erroneo. Ingrese un numero positivo: ");
				if(cant == 1)
				{
					*flagComida = 1;
				}
				else
				{
					printf("\nEl costo de la Comida fue reeestablecido en 0\nSera devuelto al submenu\n\n");
					*costoComida = 0;
					*flagComida = 0;
					*flagCalculoValores = 0;
				}
				break;
			case 't':
				cant = getFloatPositiv(costoTransporte, 3, "Ingrese el costo de Transporte: " , "Dato erroneo. Ingrese un numero positivo: ");
				if(cant == 1)
				{
					*flagTransporte = 1;
				}
				else
				{
					printf("\nEl costo del Transporte fue reeestablecido en 0\nSera devuelto al submenu\n\n");
					*costoTransporte = 0;
					*flagTransporte = 0;
					*flagCalculoValores = 0;
				}
				break;
			case 'm': //En este caso se limitara a cambiar la letra que mantiene activo el while para romperlo
				*confirm = 'n';
				printf("Sera devuelto al menu\n\n");
				retorno = 2;
				break;
		}
		if(cant == 1)//Si se pudo tomar el valor y el usuario desea ingresar otro, se le brinda la posibilidad
		{
			printf("\nEl precio se cargo con exito\n\nDesea ingresar otro valor?\nIngrese 'Y' para confirmar o cualquier otra tecla para volver al menu: ");
			cant = getCaracterTolower(confirm);
			printf("\n");
			retorno = 1;
		}
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
int getJugadores(int vecPosicion[], int vecCamiseta[], int vecConfederacion[], int isEmpty[], int contadorJugadores[])
{
	int retorno = 0;
	int cant;
	char confirm;
	int i = 0;

	if(vecPosicion != NULL && vecCamiseta != NULL && vecConfederacion != NULL && isEmpty != NULL && contadorJugadores != NULL)
	{
		printf("\n");
		do
		{
			mostrarJugadores(contadorJugadores); //Mostrara los jugadores primero que nada
			cant = preguntarIsEmpty(isEmpty, &i); //Preguntara si hay lugar
			if(cant == 2) //En caso de que haya ingresado todos el while se cortara directamente
			{
				printf("\n\nYa ha ingresado todos los jugadores. Sera devuelto al menu\n\n");
				break;
			}
			else if(cant == 1)
			{
				cant = getPosicion(vecPosicion, contadorJugadores, i); //Si hay lugar en el vector tomara el dato, primero la posicion
				if(cant == 1) //En caso de que haya podido tomar la posicion pedira la camiseta
				{
					cant = getIntRange(&vecCamiseta[i], 1, 99, 3,
								"\nSeleccione la camiseta del nuevo jugador, del 1 al 99: ",
								"Dato erroneo. Ingrese un numero del 1 al 99: ");
					if(cant == 1) //En caso de que haya podido tomar la camiseta pedira la confederacion
					{
						cant = getIntRange(&vecConfederacion[i], 1, 6, 3,
									"\nSeleccione la confederacion a la que pertenece el nuevo jugador. \nIngrese 1 para AFC en Asia; 2 para CAF en África; 3 para CONCACAF en zona del Norte; "
									"4 para CONMEBOL en Sudamérica; 5 para UEFA en Europa; o 6 para OFC en Oceanía: ",
									"Dato erroneo. Ingrese un numero del 1 al 6 segun las opciones: ");
						if(cant == 1) //En caso de que haya podido tomar la confederacion actualizara el contador y cambiara el estado de isEmpty ocupando el indice del vector
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
							printf("\n\nQuiere ingresar otro jugador? Ingrese la letra 'Y' para ingresar otro o cualquier otra tecla para volver al menu: ");
							getCaracterTolower(&confirm); 	//Lo mismo que en funciones anteriores. Se pregunta por ingresar otra, la validacion de isEmpty funciona igual
															//Si ingreso el ultimo jugador y quiere ingresar otro, el usuario no podra y sera devuelto al menu
						}
					}
				}
			}
			if(cant == -1 || cant == -2) //Si no pudo tomar algun dato
			{
				printf("Intentelo denuevo mas tarde.\nLos datos del ultimo intento no han sido cargados\n\nSera devuelto al menu\n\n");
				confirm = 'n';
				retorno = -1;
			}
			if(cant == 0)
			{
				printf("\n\nNo se pudo conseguir memoria\n\n");
				confirm = 'n';
			}
		}while(confirm == 'y');
	}
	else
	{
		printf("\n\nNo se pudo conseguir memoria\n\n");
	}

	system("PAUSE");
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

//Funcion para saber si hay lugar en el vector de jugadores y en caso de haberlo devolver la posicion vacia
int preguntarIsEmpty(int isEmpty[], int* i)
{
    int retorno = 0;

    if(isEmpty != NULL && i != NULL)
    {
        for(int j = 0; j < 22; j++) //El for recorrera el vector bbuscando un lugar vacion
    	{
    		if(isEmpty[j] == 0) //Si lo encuentra devolvera el indice que esta vacio, y corta el for
    		{
    			*i = j;
    			retorno = 1;
    			break;
    		}
    		if(j == 21 && isEmpty[j] == 1) //En caso de que llegue a la ultima posicion y este ocupada retornara un 2 y cortara el recorrido del for
    		{
    			retorno = 2;
    			break;
    		}
    	}
    }
	return retorno;
}

//=======================================================================================================================================//
//=======================================================================================================================================//
//PUNTO 3
int validarCalculos(int isEmpty[], int tam, int sumaFlagsMantenimiento) //Esta primera funcion validara si es posibble hacer los calculos, si ya ingreso los datos necesarios
{
	int retorno = 1;

	if(isEmpty != NULL)
	{
		for(int i = 0; i < tam; i ++) //Este for recorrera el vector preguntando si hay alguna posicion vacia. Si lo hay quiere decir que faltan jugadores
		{
			if(isEmpty[i] == 0)
			{
				printf("\nNo se han cargado todos los jugadores.\n");
				retorno = 0;
				break;
			}
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

int calcularPorcentajeConf(int vecConfederacion[], float vecPromedio[], int tam, int conf, int* confeConMasJugadores)
{//Esta funcion calculara el porcentaje que corresponda a cada confederacion
	int retorno = 0;
	float maximo;

	if(vecConfederacion != NULL && vecPromedio != NULL && confeConMasJugadores != NULL)
	{
		for(int i = 0; i < tam; i++) //Primero que nada este for recorrera el vector que tiene cargada la confederacion de cada jugador y la ubbicara en el vector que contara cuantos jugadores hay en cada confederacion
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
		for(int i = 0; i < conf; i++) //Una vez acomodado el contador hara el calculo del promedio aprovechando el mismo vector
		{
			vecPromedio[i] = (vecPromedio[i] * 100) / 22;
		}
		for(int i = 0; i < conf; i++) //Por ultimo este for preguntara cual es el mayor porcentaje
		{
			if(vecPromedio[i] >= maximo || i == 0)
			{
				maximo = vecPromedio[i];
				*confeConMasJugadores = i; //La variable I representa ademas de un indice una confedaracion por lo que esa posicion es la que tendra el mayor porcentaje
				if(vecPromedio[i] == maximo) //En caso de que haya dos con el mismo porcentaje se guardara la primera posicion para no afectar el costo de mantenimiento, ya que literalmente, no habri aun mayor porcentaje
				{
					*confeConMasJugadores = 0;
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

int calcularMantenimiento(int confeConMasJugadores, float* totalMantenimiento, float* aumento, float* totalMantenimientoAumento, float hospedaje, float comida, float transporte)
{ //Esta funcion calculara el mantenimietno
	int retorno = 0;

	if(totalMantenimiento != NULL && aumento != NULL)
	{
		*totalMantenimiento = hospedaje + comida + transporte; //Simples cuentas guardando cada valor en su variable correspondiente
		if(confeConMasJugadores == 4) //Si la posicion es la numero 4, UEFA, se aplicara el aumetno
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
		printf("Porcentaje UEFA: %.2f\n", vecPromedio[4]);
		printf("Porcentaje CONMEBOL: %.2f\n", vecPromedio[3]);
		printf("Porcentaje CONCACAF: %.2f\n", vecPromedio[2]);
		printf("Porcentaje AFC: %.2f\n", vecPromedio[0]);
		printf("Porcentaje OFC: %.2f\n", vecPromedio[5]);
		printf("Porcentaje CAF: %.2f\n", vecPromedio[1]);

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











