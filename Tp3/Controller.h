int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador);
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador);
int controller_agregarJugador(LinkedList* pArrayListJugador, int* id);
int controller_editarJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int controller_removerJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int controller_listarJugadores(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador);
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador);
int controller_ordenarJugadoresNacionalidad(LinkedList* pArrayListJugador);
int controller_ordenarJugadoresEdad(LinkedList* pArrayListJugador);
int controller_ordenarJugadoresNombre(LinkedList* pArrayListJugador);

int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion);
int controller_listarSelecciones(LinkedList* pArrayListSeleccion);
int controller_ordenarSeleccionesConfederacion(LinkedList* pArrayListSeleccion);
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion);

/**
 * @fn int controller_LimpiarMemoria(LinkedList*, LinkedList*)
 * @brief Funcion que se encargara de limpiar la memoria pedida al sistema operativo
 *
 * @param pArrayListJugador
 * @param pArrayListSeleccion
 * @return Retorna 1 si pudo ejecutarse o 0 si fallo
 */
int controller_LimpiarMemoria(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

