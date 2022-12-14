#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "Seleccion.h"
#include "PedirDatos.h"
#include "Informes.h"

int main()
{
	setbuf(stdout,NULL);
    LinkedList* pArrayListJugador = ll_newLinkedList();
    LinkedList* pArrayListSeleccion = ll_newLinkedList();

    char confirm = 'n'; //Variable que condiciona el do while
    char auxChar; //Auxiliar de char
    int cant;
    int flagHuboCambios = 0;
    int id; //De base esta seteado en 371 (en su archivo)

    if(pArrayListJugador != NULL && pArrayListSeleccion != NULL ){
		do{
			switch(menuDeOpciones())
			{
				case 1: //Carga de archivos
					if(ll_isEmpty(pArrayListJugador) == 1)
					{
						if(controller_cargarJugadoresDesdeTexto("jugadores.csv", pArrayListJugador) == 1 &&
							controller_cargarSeleccionesDesdeTexto("selecciones.csv", pArrayListSeleccion) == 1 &&
							jug_CargarIdMax(&id) == 1)
						{
							printf("\nSe han cargado los archivos con exito\n\n");
						}
					}
					else
					{
						printf("\nLos Jugadores ya han sido cargados\n\n");
					}
					system("PAUSE");
					break;
			   case 2: //Alta de Jugador
					if(ll_isEmpty(pArrayListJugador) == 0){
						do{
							if(controller_agregarJugador(pArrayListJugador, &id) != 0){
								printf("\nQuiere agregar otro Jugador?\nIngrese 'Y' si quiere añadir otro Jugador o cualquier otra tecla para volver al menu: ");
										//Una vez ejecutada la funcion (haya podido agregar o no el Jugador) se le preguntara si quiere añadir otro
								getCaracterTolower(&auxChar);
							}
							else{ //En caso de que a la hora de ejecutar las funciones no haya podido conseguir memoria lo devolvera al menu instantaneamente
								printf("\nSera devuelto al menu\n");
								auxChar = 'n';
							}
						}while(auxChar == 'y');
					}
					else{
						printf("\nAntes de agregar Jugadores es necesario cargar los archivos\n");
					}
					flagHuboCambios = 1;
					printf("\n");
					system("PAUSE");
					break;
				case 3: //Modificacion de Jugador
					if(ll_isEmpty(pArrayListJugador) == 0){
						do{
							cant = controller_editarJugador(pArrayListJugador, pArrayListSeleccion);
							if(cant == 1){
								printf("\nQuiere modificar otro Jugador?\nIngrese 'Y' si quiere modificar otro Jugador o cualquier otra tecla para volver al menu: ");
								//Una vez ejecutada la funcion (haya podido modificar o no el Jugador) se le preguntara si quiere modificar otro
								getCaracterTolower(&auxChar);
							}
							else if(cant == -1)
							{
								printf("\nQuiere intentar con otro Id?\nIngrese 'Y' si quiere modificar otro Jugador o cualquier otra tecla para volver al menu: ");
								getCaracterTolower(&auxChar);
							}
							else{ //En caso de que a la hora de ejecutar las funciones no haya podido conseguir memoria lo devolvera al menu instantaneamente
								printf("\nSera devuelto al menu\n");
								auxChar = 'n';
							}
						}while(auxChar == 'y');
					}
					else{
						printf("\nNo hay Jugadores cargados en sistema\n");
					}
					flagHuboCambios = 1;
					printf("\n");
					system("PAUSE");
					break;
				case 4: //Baja de Jugador
					if(ll_isEmpty(pArrayListJugador) == 0){
						do{
							cant = controller_removerJugador(pArrayListJugador, pArrayListSeleccion);
							if(cant == 1){
								printf("\nQuiere dar de baja otro Jugador?\nIngrese 'Y' si quiere dar de baja otro Jugador o cualquier otra tecla para volver al menu: ");
								//Una vez ejecutada la funcion (haya podido dar de baja o no el Jugador) se le preguntara si quiere dar de baja otro
								getCaracterTolower(&auxChar);
							}
							else if(cant == -1)
							{
								printf("\nQuiere intentar con otro Id?\nIngrese 'Y' si quiere dar de baja otro Jugador o cualquier otra tecla para volver al menu: ");
								getCaracterTolower(&auxChar);
							}
							else{ //En caso de que a la hora de ejecutar las funciones no haya podido conseguir memoria lo devolvera al menu instantaneamente
								printf("\nSera devuelto al menu\n");
								auxChar = 'n';
							}
						}while(auxChar == 'y');
					}
					else{
						printf("\nNo hay Jugadores cargados en sistema\n");
					}
					flagHuboCambios = 1;
					printf("\n");
					system("PAUSE");
					break;
				case 5: //Listados
					if(ll_isEmpty(pArrayListJugador) == 0)
					{
						do
						{
							if(listar(pArrayListJugador, pArrayListSeleccion) == 3)
							{
								break;
							}
							printf("\nQuiere mostrar otro informe?\nIngrese 'Y' si quiere ver otro o cualquier otra tecla para volver al menu: ");
							getCaracterTolower(&auxChar);
						}while(auxChar == 'y');
					}
					else
					{
						printf("\nNo hay Jugadores en sistema\n");
					}
					printf("\n");
					system("PAUSE");
					break;
				case 6: //Convocar Jugadores
					if(ll_isEmpty(pArrayListJugador) == 0)
					{
						do
						{
							if(jug_Convocatoria(pArrayListJugador, pArrayListSeleccion) == 3)
							{
								break;
							}
							printf("\nQuiere ingresar a otra opcion?\nIngrese 'Y' si quiere hacer otra modificacion u otra tecla para volver al menu: ");
							getCaracterTolower(&auxChar);
						}while(auxChar == 'y');
					}
					else
					{
						printf("\nNo hay Jugadores en sistema\n");
					}
					flagHuboCambios = 1;
					printf("\n");
					system("PAUSE");
					break;
				case 7: //Ordenar y listar Jugadores
					if(ll_isEmpty(pArrayListJugador) == 0)
					{
						ordenar(pArrayListJugador, pArrayListSeleccion);
					}
					else
					{
						printf("\nNo hay Jugadores en sistema\n");
					}
					printf("\n");
					system("PAUSE");
					break;
				case 8: //Generar archivo binario de convocados
					if(jug_BuscarConvocado(pArrayListJugador) == 1)
					{
						jug_guardarConvocadosConfederacionBinario(pArrayListJugador, pArrayListSeleccion);
					}
					else
					{
						printf("\nNo hay Jugadores en convocados\n");
					}
					printf("\n");
					system("PAUSE");
					break;
				case 9: //Cargar e imprimir archivo binario del punto 8
					if(jug_ImprimirArchivoConvocados(pArrayListSeleccion) == -1)
					{
						printf("\nNo se pudo encontrar el archivo, generelo primero\n");
					}
					printf("\n");
					system("PAUSE");
					break;
				case 10: //Guardar archivos
					if(controller_cargarJugadoresDesdeTexto("jugadores.csv", pArrayListJugador) == 1 &&
						controller_guardarSeleccionesModoTexto("selecciones.csv" , pArrayListSeleccion) == 1 &&
						jug_guardarIdMax(&id) == 1)
					{
						printf("\nLos datos han sido guardados\n");
					}
					else
					{
						printf("\nLos datos no han sido guardados\n");
					}
					printf("\n");
					system("PAUSE");
					break;
				case 11: //salir
					salirDelPrograma(&confirm);
					if(flagHuboCambios == 1)
					{
						printf("\nHay datos sin guardar. Ingrese 'Y' si quiere guardar los cambios o cualquier otra tecla para omitir: \n");
						getCaracterTolower(&auxChar);
						if(auxChar == 'y')
						{
							if(controller_cargarJugadoresDesdeTexto("jugadores.csv", pArrayListJugador) == 1 &&
							controller_guardarSeleccionesModoTexto("selecciones.csv" , pArrayListSeleccion) == 1 &&
							jug_guardarIdMax(&id) == 1)
							{
								printf("\nLos datos han sido guardados\n");
							}
							else
							{
								printf("\nLos datos no han sido guardados\n");
							}
						}
						else
						{
							printf("\nLos datos no seran guardados\n");
						}
					}
					if(confirm == 'y')
					{
						controller_LimpiarMemoria(pArrayListJugador, pArrayListSeleccion);
					}
					break;
			}
		}while(confirm != 'y');
    }
    else
    {
       printf("\nNo se pudo conseguir espacio en memoria\n");
    }

    printf("\nGracias por haber utilizado el programa.\nHasta luego\n\n");
    system("PAUSE");

    return 0;
}

