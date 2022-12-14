#include "LinkedList.h"

#ifndef jug_H_INCLUDED
#define jug_H_INCLUDED

typedef struct
{
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;
}Jugador;

Jugador* jug_new();
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr);

void jug_delete(Jugador* this);

int jug_setId(Jugador* this,int id);
int jug_getId(Jugador* this,int* id);

int jug_setNombreCompleto(Jugador* this,char* nombreCompleto);
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto);

int jug_setPosicion(Jugador* this,char* posicion);
int jug_getPosicion(Jugador* this,char* posicion);

int jug_setNacionalidad(Jugador* this,char* nacionalidad);
int jug_getNacionalidad(Jugador* this,char* nacionalidad);

int jug_setEdad(Jugador* this,int edad);
int jug_getEdad(Jugador* this,int* edad);

int jug_setIdSeleccion(Jugador* this,int idSeleccion);
int jug_getSIdSeleccion(Jugador* this,int* idSeleccion);


/**
 * @fn int jug_setAll(Jugador*, int, char*, char*, char*, int, int)
 * @brief Funcion que sera un seter de todos los datos del Jugador
 *
 * @param this
 * @param id
 * @param nombreCompleto
 * @param posicion
 * @param nacionalidad
 * @param edad
 * @param idSeleccion
 * @return Retorna 1 si pudo guardar los datos y 0 si no
 */
int jug_setAll(Jugador* this, int id, char* nombreCompleto, char* posicion, char* nacionalidad, int edad, int idSeleccion);

/**
 * @fn int jug_getAll(Jugador*, int*, char*, char*, char*, int*, int*)
 * @brief Funcion que sera un geter de todos los datos del Jugador
 *
 * @param this
 * @param id
 * @param nombreCompleto
 * @param posicion
 * @param nacionalidad
 * @param edad
 * @param idSeleccion
 * @return Retorna 1 si pudo obtener los datos y 0 si no
 */
int jug_getAll(Jugador* this, int* id, char* nombreCompleto, char* posicion, char* nacionalidad, int* edad, int* idSeleccion);

/**
 * @fn int jug_guardarIdMax(int*)
 * @brief Funcion que se encarga de guardar el Id mas grande en un archivo aparte para mantener solides en su asignacion
 *
 * @param id
 * @return Retorna 0 si fallo o 1 si se ejecuto
 */
int jug_guardarIdMax(int* id);

/**
 * @fn int jug_CargarIdMax(int*)
 * @brief Funcion que se encarga de cargar el Id desde su archivo aparte para mantener solides en su asignacion
 *
 * @param id
 * @return Retorna 0 si fallo o 1 si se ejecuto
 */
int jug_CargarIdMax(int* id);

/**
 * @fn Jugador jug_crearJugador*(int)
 * @brief Funcion que se encargara de crear un Jugador, tomar los valores y asignarselos
 *
 * @param Se le pasa el id
 * @return Retorna la direccion de memoria del empleado o NULL si no pudo conseguirla
 */
Jugador* jug_crearJugador(int id);

/**
 * @fn Jugador jug_FindById*(LinkedList*, int)
 * @brief Funcion que buscara un Jugador de la Linkedlist segun su Id
 *
 * @param pArrayListJugador
 * @param id
 * @return Retorna la posicion en el Linkedlist de ese elemento
 */
int jug_FindById(LinkedList* pArrayListJugador, int id);

/**
 * @fn int jug_Modificar(Jugador*, int)
 * @brief Funcion que tiene el switch para modificar los campos del Jugador
 *
 * @param this La direccion de memoria del Jugador
 * @param opcion quee escogio el usuario para modificar
 * @return Retorna 0 si no pudo ejecutarse o 1 si si
 */
int jug_Modificar(Jugador* this, int opcion);

/**
 * @fn int subMenuModificar()
 * @brief Funcion que despliega el submenu de la modificacion del Jugador
 *
 * @return Devuelve la opcion
 */
int subMenuModificar();

/**
 * @fn int jug_ConfirmarBaja()
 * @brief Funcion que preguntara al usuario si quiere confirmar la baja del Jugador
 *
 * @return Retorna 0 en case de que no quiera o 1 en caso de que la confirme
 */
int jug_ConfirmarBaja();

/**
 * @fn int jug_BuscarConvocado(LinkedList*)
 * @brief Funcion que se encarga de buscar si hay algun Jugador convocado
 *
 * @param pArrayListJugador
 * @return Devuelve 0 si no lo hay o 1 si hay
 */
int jug_BuscarConvocado(LinkedList* pArrayListJugador);

/**
 * @fn int jug_BuscarConvocado(LinkedList*)
 * @brief Funcion que se encarga de buscar si hay algun Jugador que no este convocado
 *
 * @param pArrayListJugador
 * @return Devuelve 0 si no lo hay o 1 si hay
 */
int jug_BuscarNoConvocado(LinkedList* pArrayListJugador);

/**
 * @fn int jug_Convocatoria(LinkedList*, LinkedList*)
 * @brief Funcion principal del punto 6 convocatoria
 *
 * @param pArrayListJugador
 * @param pArrayListSeleccion
 * @return Retorna 0 si no pudo ejecutarse, 1 si si o 3 si quiere volver al menu principal
 */
int jug_Convocatoria(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

/**
 * @fn int subMenuConvocatoria()
 * @brief Funcion subbmenu de Convocar
 *
 * @return Devuelve la opcion elegida por el usuario
 */
int subMenuConvocatoria();

/**
 * @fn int jug_Convocar(LinkedList*, LinkedList*)
 * @brief Funcion que se encargara de Convocar un Jugador
 *
 * @param pArrayListJugador
 * @param pArrayListSeleccion
 * @return Retorna -1 si hubo algun error, 0 si no pudo ejecutarse o 1 si el Jugador fue convocado
 */
int jug_Convocar(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

/**
 * @fn int jug_elegirSeleccion(LinkedList*, LinkedList*, int*)
 * @brief Funcion auxiliar de jug_Convocar. Pedira la Seleccion al usuario, la buscara y aumentara el contador de convocados en 1
 *
 * @param pArrayListJugador
 * @param pArrayListSeleccion
 * @param idSeleccion Aca se guardara el Id de la Seleccion para asignarlo al Jugador
 * @return Retorna -1 si hubo algun error, 0 si no pudo ejecutarse o 1 si se encontro la Seleccion
 */
int jug_elegirSeleccion(LinkedList* pArrayListSeleccion, int* idSeleccion);

/**
 * @fn int jug_QuitarDeSeleccion(LinkedList*, LinkedList*)
 * @brief Funcion que se encargara de quitar un Jugador de la Convocatoria
 *
 * @param pArrayListJugador
 * @param pArrayListSeleccion
 * @return Retorna -1 si hubo algun error, 0 si no pudo ejecutarse o 1 si pudo quitarse
 */
int jug_QuitarDeSeleccion(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

/**
 * @fn int jug_ReducirConvocados(LinkedList*, int)
 * @brief Funcion auxiliar de jug_QuitarDeSeleccion. Reducira en 1 el contador de convocados de la seleccion
 *
 * @param pArrayListSeleccion
 * @param idSeleccion
 * @return Retorna 0 si no pudo ejecutarse o 1 si pudo reducirse
 */
int jug_ReducirConvocados(LinkedList* pArrayListSeleccion, int idSeleccion);

/**
 * @fn int jug_guardarConvocadosConfederacionBinario(LinkedList*, LinkedList*)
 * @brief  Funcion principal del punto 8. Guardar los convocados en un archivo binario
 *
 * @param pArrayListJugador
 * @param pArrayListSeleccion
 * @return retorna 1 si pudo ejecutarse o 0 si no
 */
int jug_guardarConvocadosConfederacionBinario(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

/**
 * @fn int subMenuConfederaciones()
 * @brief Funcion auxiliar de la principal del punto 8. Permite elegir al usuario la confedearacion que quiere guardar
 *
 * @return Devuelve la opcion
 */
int elejirConfederacion();

/**
 * @fn int copiarConfederacion(char[], int)
 * @brief Funcion que dependiendo de la eleccion del usuario copiara en la variable confederacion la confederacion seleccionada
 *
 * @param confederacion
 * @param opcion
 * @return retorna 1 si pudo ejecutarse o 0 si no
 */
int copiarConfederacion(char confederacion[30], int opcion);

/**
 * @fn int jug_ImprimirArchivoConvocados(LinkedList*)
 * @brief Funcion que leera del archivo de combocados los jugadores y los imprimera en pantalla
 *
 * @param pArrayListSeleccion
 * @return retorna 1 si pudo ejecutarse o 0 si no o -1 si no pudo abrir el archivo
 */
int jug_ImprimirArchivoConvocados(LinkedList* pArrayListSeleccion);

/**
 * @fn int jug_clenAll(LinkedList*)
 * @brief Funcion que se encarga de eliminar los Jugadores de sistema
 *
 * @param pArrayListJugador
 * @return Retorna 1 si se pudo ejecutar o 0 si no
 */
int jug_clenAll(LinkedList* pArrayListJugador);

#endif // jug_H_INCLUDED
