#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}ePersona;

/**
 * Obtiene el primer indice libre del array.
 * \param lista el array se pasa como parametro.
 * \param limite El limite del array se pasa como parametro.
 * \return el primer indice disponible
 */
int ePers_buscarLugarLibre(ePersona lista[],int limite);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * \param lista el array se pasa como parametro.
 * \param dni el dni a ser buscado en el array.
 * \return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int ePers_buscarPorDni(ePersona lista[] ,int limite, int dni);

/**
 * Inicializa dni y estado del array de estructura en 0.
 * \param lista[] ePersona El array se pasa como parametro.
 * \param limite int El limite del array se pasa como parametro.
 * \return int Numero de verificacion.
 *
 */
int ePers_init(ePersona lista[], int limite);

/**
 * Hardcodea 5 personas
 * \param lista[] ePersona El array se pasa como parametro.
 * \return void
 *
 */
void ePers_hardCode(ePersona lista[]);

/**
 * Busca si hay lugar libre en el array, si lo hay agrega una persona.
 * \param lista[] ePersona El array se pasa como parametro.
 * \param limite int El limite del array se pasa como parametro.
 * \return int Numero de verificacion.
 *
 */
int ePers_alta(ePersona lista[],int limite);

/**
 * Pide un dni y lo busca, si lo encuentra lo da de baja.
 * \param lista[] ePersona El array se pasa como parametro.
 * \param limite int El limite del array se pasa como parametro.
 * \return int Numero de verificacion.
 *
 */
int ePers_baja(ePersona lista[],int limite);

/**
 * Recorre el array muestra las personas y su respectivo dni de las que esten de alta.
 * \param lista[] ePersona El array se pasa como parametro.
 * \param cant int El limite del array se pasa como parametro.
 * \return void
 *
 */
void ePers_mostrar(ePersona lista[], int cant);

/**
 * Muestra una persona y su dni.
 * \param lista ePersona La posicion en el array se pasa como parametro.
 * \return void
 *
 */
void ePers_mostrarUno(ePersona lista);

/**
 * Ordena alfabeticamente segun nombre a las personas y las muestra.
 * \param lista[] ePersona El array se pasa como parametro.
 * \param limite int El limite del array se pasa como parametro.
 * \return int Numero de verificacion.
 *
 */
int ePers_mostrarOrdenadoPorNombre(ePersona lista[], int limite);


/**
 * Muestra un grafico de barras segun edades.
 * \param lista[] ePersona El array se pasa como parametro.
 * \param limite int El limite del array se pasa como parametro.
 * \return int Numero de verificacion.
 *
 */
int ePers_mostrarGraficoBarras(ePersona lista[],int limite);

#endif // FUNCIONES_H_INCLUDED
