/*
 * MenuDeOpciones.h
 *
 *  Created on: 22 ago. 2022
 *      Author: Usuario
 */

#ifndef MENUDEOPCIONES_H_
#define MENUDEOPCIONES_H_



#endif /* MENUDEOPCIONES_H_ */
/**
 * @fn int menuDeOpciones(float, float, float, int[])
 * @brief Menu de opciones que derivara en el resto de funciones del programa
 *
 * @param Recive el valor del hospedaje para poder mostrar los costos de mantenimiento
 * @param Recive el valor de la comida para poder mostrar los costos de mantenimiento
 * @param Recive el valor del transporte para poder mostrar los costos de mantenimiento
 * @param Recive el vector con el contador de las posiciones de los jugadores para ser mostradas
 * @return Retorna la opcion elegida
 */
int menuDeOpciones(float, float, float, int[]);

/**
 * @fn void mostrarCostosMantenimiento(float, float, float)
 * @brief Mostrara los costos de mantenimiento en pantalla
 *
 * @param Recive el valor del hospedaje para poder mostrar los costos de mantenimiento
 * @param Recive el valor de la comida para poder mostrar los costos de mantenimiento
 * @param Recive el valor del transporte para poder mostrar los costos de mantenimiento
 */
void mostrarCostosMantenimiento(float, float, float);

/**
 * @fn void mostrarJugadores(int[])
 * @brief Mostrara la cantidad de jugadores cargados por posicion
 *
 * @param Recive el vector con el contador de las posiciones de los jugadores para ser mostradas
 */
void mostrarJugadores(int[]);

/**
 * @fn int getCostosMantenimiento(float*, float*, float*, int*, int*, int*, int*)
 * @brief Esta funcion es la principal para cargar los costos de mantenimiento hasta que el ususario queira
 *
 * @param Recive la direccion de memoria de la variable que guarda el valor del hospedaje para poder ser reescrita
 * @param Recive la direccion de memoria de la variable que guarda el valor de la comida para poder ser reescrita
 * @param Recive la direccion de memoria de la variable que guarda el valor del transporte para poder ser reescrita
 * @param Recive la direccion de memoria de la variable que guarda el valor de la flag del hospedaje para poder ser reescrita en caso que el valor se cargue con exito o no
 * @param Recive la direccion de memoria de la variable que guarda el valor de la flag de la comida para poder ser reescrita en caso que el valor se cargue con exito o no
 * @param Recive la direccion de memoria de la variable que guarda el valor de la flag del transporte para poder ser reescrita en caso que el valor se cargue con exito o no
 * @param Recive la direccion de memoria de la variable que guarda el valor de la flag de que los calculos se pueden mostrar porque en caso de sobreescribir mal algun valor evitara que se muestre
 * @return Esta funcion retorna un 1 si pudo cargar el costo de mantenimiento, 0 si no pudo conseguir memoria o -1 en caso de que no haya podido tomar el dato
 */
int getCostosMantenimiento(float*, float*, float*, int*, int*, int*, int*);

/**
 * @fn int subMenuMantenimiento(char*)
 * @brief  Esta funcion ejecutara el submenu del mantenimiento, tanto lo mostrara en pantalla como pedira la opcion
 *
 * @param Recive por parametro la direccion de memoria de el caracter que representa la opcion elegida por el usuario, que sera utilizada en la funcion pedirCostos
 * @return Retornara un 0 si no pudo conseguir memoria, un 1 si pudo tomar la letra o un -1 si eligio una opcion no valida
 */
int subMenuMantenimiento(char*);

/**
 * @fn int pedirCostos(char, char*, float*, float*, float*, int*, int*, int*, int*)
 * @brief Funcion que dependiendo de la opcion elegida en el submenu cargara el dato correspondiente, en caso de ser el menu actualizara la letra para poder salir
 *
 * @param Se le pasara el caracter elegido para que el switch elija que ejecutar
 * @param Se le pasara la direccion de memoria del caracter que controla el while para romperlo en caso de que quiera salir al menu o continuar en caso de que quierea ingresar otro costo
 * @param Recive la direccion de memoria de la variable que guarda el valor del hospedaje para poder ser reescrita
 * @param Recive la direccion de memoria de la variable que guarda el valor de la comida para poder ser reescrita
 * @param Recive la direccion de memoria de la variable que guarda el valor del transporte para poder ser reescrita
 * @param Recive la direccion de memoria de la variable que guarda el valor de la flag del hospedaje para poder ser reescrita en caso que el valor se cargue con exito o no
 * @param Recive la direccion de memoria de la variable que guarda el valor de la flag de la comida para poder ser reescrita en caso que el valor se cargue con exito o no
 * @param Recive la direccion de memoria de la variable que guarda el valor de la flag del transporte para poder ser reescrita en caso que el valor se cargue con exito o no
 * @param Recive la direccion de memoria de la variable que guarda el valor de la flag de que los calculos se pueden mostrar porque en caso de sobreescribir mal algun valor evitara que se muestre
 * @return Retornara un 0 si no pudo conseguir memoria, un 1 si pudo tomar el costo pedido o un 2 si eligio la opcion de volver al menu
 */
int pedirCostos(char, char*, float*, float*, float*, int*, int*, int*, int*);

/**
 * @fn int getJugadores(int[], int[], int[], int[], int[])
 * @brief Esta funcion es la principal del ingreso de los datos de los jugadores
 *
 * @param Recive el vector donde se guardan las posiciones de los jugadores para ser modificadas
 * @param Recive el vector donde se guardan las camisetas de los jugadores para ser modificadas
 * @param Recive el vector donde se guardan las confederaciones de los jugadores para ser modificadas
 * @param Recive el vector donde se guardan el isEmpty de los jugadores para ser modificado
 * @param Recive el vector con el contador de las posiciones de los jugadores para ser mostradas y actualizadas segun se cargue
 * @return Retornara un 0 si no pudo conseguir memoria, un 1 si pudo tomar el jugador pedido o un -1 si no
 */
int getJugadores(int[], int[], int[], int[], int[]);

/**
 * @fn int getPosicion(int[], int[], int)
 * @brief Esta funcion se encargara de pedir la posicion del jugador evaluando si es posible hacerlo, es decir, si hay lugar disponible
 *
 * @param Recive el vector donde se guardan las posiciones de los jugadores para ser modificadas
 * @param Recive el vector con el contador de las posiciones de los jugadores para evaluar si es posible cargar mas en una posicion determinada
 * @param Recive el indice del vector en donde deberia ser cargada la posicion
 * @return Retornara un 0 si no pudo conseguir memoria, un 1 si pudo tomar el jugador pedido, un -1 si no o un -2 si en esa posicion ya estan todos los jugadores ocupados
 */
int getPosicion(int[], int[], int);

/**
 * @fn int preguntarIsEmpty(int[], int*)
 * @brief Esta funcion se encargara de evaluar si hay lugar para cargar un jugador y devolvera la posicion disponible en el vector
 *
 * @param Recive el vector donde se guardan el isEmpty de los jugadores para ser evaluado
 * @param Recive la direccion de memoria donde se guardara el indice a modificar
 * @return Retornara un 0 si no pudo conseguir memoria, un 1 si encontro una posicion disponible o un 2 si ya estan todas ocupadas
 */
int preguntarIsEmpty(int[], int*);

/**
 * @fn int validarCalculos(int[], int, int)
 * @brief Funcion que se encargara de evaluar si es posible hacer los calculos
 *
 * @param Recive el vector donde se guardan el isEmpty de los jugadores para saber si esta lleno
 * @param El tamaño del vector para limitar el for
 * @param Y la suma de las flags correspondientes a los costos de mantenimiento
 * @return Retornara un -1 si no pudo conseguir memoria, un 1 si se puede calcular o un 0 si falta algun dato
 */
int validarCalculos(int[], int, int);

/**
 * @fn int calcularPorcentajeConf(int[], float[], int, int, int*)
 * @brief Funcion que se encarga de hacer el calculo del porcentaje de las confederaciones
 *
 * @param Recive el vector donde se guardan las confederaciones de los jugadores para ser evaluadas
 * @param Recive el vector donde se guardara el porcentaje de las confederaciones
 * @param El tamaño del vector de las confederaciones de cada jugador para limitar el for
 * @param El tamaño del vector del porcentaje de las confederaciones para limitar el for
 * @param Se le pasa la direccion de memoria donde se guardara la posicicon a la que corresponda la confederacion con mas porcentaje para poder sobreescribirla
 * @return Retornara un 0 si no pudo conseguir memoria o un 1 si se pudo calcular
 */
int calcularPorcentajeConf(int[], float[], int, int, int*);

/**
 * @fn int calcularMantenimiento(int, float*, float*, float*, float, float, float)
 * @brief Funcion que se encargara de calcular los costos de mantenimiento y si tiene aumento o no
 *
 * @param Se le pasa el valor de la posicion de la confederacion con mas porcentaje para calcular el aumento si coresponde
 * @param Se le pasa la direccion de memoria donde se guardara la suma de hospedaje, comida y transporte
 * @param Se le pasa la direccion de memoria donde se guardara el aumento si es que corresponde
 * @param Se le pasa la direccion de memoria donde se guardara el monto total del mantenimiento con aumento
 * @param Recive el valor del hospedaje para calcular el total del mantenimiento
 * @param Recive el valor de la comida para calcular el total del mantenimiento
 * @param Recive el valor del transporte para calcular el total del mantenimiento
 * @return Retornara un 0 si no pudo conseguir memoria o un 1 si se pudo calcular
 */
int calcularMantenimiento(int, float*, float*, float*, float, float, float);

/**
 * @fn int mostrarResultados(float[], float, float, float, int)
 * @brief Funcion que se encarga de mostrar los resultados en pantalla
 *
 * @param Recive el vector donde se guardara el porcentaje de las confederaciones
 * @param Recive el valor del mantenimiento
 * @param Recive el valor del aumento
 * @param Recive el valor del mantenimiento total con aumento
 * @param Se le pasa el valor de la posicion de la confederacion con mas porcentaje para mostrar el aumento si coresponde
 * @return Retornara un 0 si no pudo conseguir memoria o un 1 si se pudo mostrar
 */
int mostrarResultados(float[], float, float, float, int);
