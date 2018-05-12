#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TAM 20


int main()
{
    char seguir='s';
    int opcion=0;
    int index;

    ePersona listaDePersonas[TAM];

    index = ePers_init(listaDePersonas,TAM);
    ePers_hardCode(listaDePersonas);

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                index = ePers_alta(listaDePersonas, TAM);
                if(index == 0)
                {
                    printf("Persona ingresada\n\n");
                }
                else
                {
                    printf("No hay lugar\n\n");
                }
                break;

            case 2:
                index = ePers_baja(listaDePersonas,TAM);
                if(index == 0)
                {
                    printf("Persona dada de baja\n\n");
                }
                else
                {
                    printf("DNI incorrecto\n\n");
                }
                break;

            case 3:
                index = ePers_mostrarOrdenadoPorNombre(listaDePersonas,TAM);
                if(index == -1)
                {
                    printf("Error\n\n");
                }
                break;

            case 4:
                index = ePers_mostrarGraficoBarras(listaDePersonas,TAM);
                if(index == -1)
                {
                    printf("Error\n\n");
                }
                break;

            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
