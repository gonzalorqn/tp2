#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"


/*
    char nombre[50];
    int edad;
    int estado;
    int dni;
*/

int ePers_init(ePersona lista[], int limite)
{
    int retorno = -1;
    int i;

    if(limite > 0 && lista != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            lista[i].estado = 0;
            lista[i].dni = 0;
        }
    }
    return retorno;
}

void ePers_hardCode(ePersona lista[])
{
    char nombre[][50]= {"Juan","Maria","Pedro","Vanesa","Jose"};
    int edad[5] = {50,25,17,20,32};
    int dni[5] = {16555123,38023548,42568706,40563874,29687125};

    int i;

    for(i=0; i<5; i++)
    {
        lista[i].estado = 1;
        lista[i].edad = edad[i];
        lista[i].dni = dni[i];
        strcpy(lista[i].nombre, nombre[i]);
    }
}

int ePers_alta(ePersona lista[],int limite)
{
    int retorno = -1;
    int indice;

    if(limite > 0 && lista != NULL)
    {
        retorno = -2;
        indice = ePers_buscarLugarLibre(lista,limite);
        if(indice >= 0)
        {
            retorno = 0;
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(lista[indice].nombre);
            printf("Ingrese edad: ");
            scanf("%d", &lista[indice].edad);
            printf("Ingrese dni: ");
            scanf("%d", &lista[indice].dni);
            lista[indice].estado = 1;
        }
    }
    return retorno;
}

int ePers_buscarLugarLibre(ePersona lista[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && lista != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(lista[i].estado == 0)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int ePers_baja(ePersona lista[],int limite)
{
    int retorno = -1;
    int dni;
    int indice;

    if(limite > 0 && lista != NULL)
    {
        retorno = -2;
        ePers_mostrar(lista,limite);
        printf("Ingrese dni a dar de baja: ");
        scanf("%d", &dni);

        indice = ePers_buscarPorDni(lista,limite,dni);

        if(indice == -2 || indice == -1)
        {

        }

        else
        {
            retorno = 0;
            lista[indice].estado = 0;
        }
    }
    return retorno;
}

int ePers_buscarPorDni(ePersona lista[] ,int limite, int dni)
{
    int retorno = -1;
    int i;
    if(limite > 0 && lista != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(lista[i].estado == 1 && lista[i].dni == dni)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

void ePers_mostrarUno(ePersona lista)
{
    printf("%d %s\n",lista.dni, lista.nombre);
}

void ePers_mostrar(ePersona lista[], int cant)
{
    int i;
    for(i=0;i<cant;i++)
    {
        if(lista[i].estado == 1)
        {
            ePers_mostrarUno(lista[i]);
        }
    }
}

int ePers_mostrarOrdenadoPorNombre(ePersona lista[], int limite)
{
    int retorno = -1;
    int i;
    int j;
    ePersona aux;

    if(limite > 0 && lista != NULL)
    {
        retorno = 0;
        for(i=0;i<limite-1;i++)
        {
            for(j=i+1;j<limite;j++)
            {
                if(strcmp(lista[i].nombre, lista[j].nombre)>0)
                {
                    aux = lista[i];
                    lista[i] = lista[j];
                    lista[j] = aux;
                }
            }
        }
        ePers_mostrar(lista,limite);
    }
    return retorno;
}

int ePers_mostrarGraficoBarras(ePersona lista[],int limite)
{
    int retorno = -1;
    int i;
    int j;
    int contMenores=0;
    int contAdultos=0;
    int contMayores=0;
    int max;

    max = 0;
    if(limite > 0 && lista != NULL)
    {
        retorno = 0;
        for (i=0;i<limite;i++)
        {
            if(lista[i].estado == 1)
            {
                if (lista[i].edad > 35)
                {
                    contMayores++;
                    if(contMayores > max)
                    {
                        max = contMayores;
                    }
                }
                else if(lista[i].edad < 18)
                {
                    contMenores++;
                    if(contMenores > max)
                    {
                        max = contMenores;
                    }
                }
                else
                {
                    contAdultos++;
                    if(contAdultos > max)
                    {
                        max = contAdultos;
                    }
                }
            }

        }

        for (i=max;i>0;i--)
        {
            if (contMenores >= i)
            {
                printf(" *");
            }

            else
            {
                printf("  ");
            }

            if (contAdultos >= i)
            {
                printf("    *");
            }

            else
            {
                printf("     ");
            }

            if (contMayores >= i)
            {
                printf("    *");
            }

            else
            {
                printf("  ");
            }
            putchar('\n');
        }
        printf("<18 18-35 >35\n");
    }
    return retorno;
}

