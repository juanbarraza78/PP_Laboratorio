/*
 *      Author: juanb
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "informes.h"
#include "utn.h"
#include "Passenger.h"


/**************************************************************************************/ //criterio para ordenar

int Passenger_sortNombre(void* parametro1, void* parametro2)
{
    int retorno = -1;
    char auxNombre1[LEN_NOMBRE];
    char auxNombre2[LEN_NOMBRE];

    if(parametro1 != NULL && parametro2 != NULL)
    {
    	Passenger_getNombre(parametro1, auxNombre1);
    	Passenger_getNombre(parametro2, auxNombre2);

		if(stricmp(auxNombre1,auxNombre2)>0)
		{
			retorno = 1;
		}
    }

    return retorno;
}
int Passenger_sortprecio(void* parametro1, void* parametro2)
{
    int retorno = -1;
    float precio1;
    float precio2;

    if(parametro1!=NULL && parametro2!=NULL)
    {
    	Passenger_getPrecio(parametro1, &precio1);
    	Passenger_getPrecio(parametro2, &precio2);
        if(precio1 > precio2)
        {
        	retorno = 1;
        }

    }
    return retorno;
}

int Passenger_sortApellido(void* parametro1, void* parametro2)
{
    int retorno = -1;
    char auxApellido1[LEN_APELLIDO];
    char auxApellido2[LEN_APELLIDO];

    if(parametro1 != NULL && parametro2 != NULL)
    {
    	Passenger_getApellido(parametro1, auxApellido1);
    	Passenger_getApellido(parametro2, auxApellido2);

		if(stricmp(auxApellido1,auxApellido2)>0)
		{
			retorno = 1;
		}
    }
    return retorno;
}

int Passenger_sortId(void* parametro1, void* parametro2)
{
    int retorno = -1;
    int auxId1;
    int auxId2;

    if(parametro1!=NULL && parametro2!=NULL)
    {
    	Passenger_getId(parametro1, &auxId1);
    	Passenger_getId(parametro2, &auxId2);
        if(auxId1 > auxId2)
        {
        	retorno = 1;
        }

    }
    return retorno;
}

int Passenger_sortTipoPasajero(void* parametro1, void* parametro2)
{
    int retorno = -1;
    int auxTipoPasajero1;
    int auxTipoPasajero2;

    if(parametro1!=NULL && parametro2!=NULL)
    {
    	Passenger_getTipoPasajero(parametro1, &auxTipoPasajero1);
    	Passenger_getTipoPasajero(parametro2, &auxTipoPasajero2);
        if(auxTipoPasajero1 > auxTipoPasajero2)
        {
        	retorno = 1;
        }

    }
    return retorno;
}

int Passenger_sortEstadoVuelo(void* parametro1, void* parametro2)
{
    int retorno = -1;
    int auxEstadoVuelo1;
    int auxEstadoVuelo2;

    if(parametro1!=NULL && parametro2!=NULL)
    {
    	Passenger_getEstadoVuelo(parametro1, &auxEstadoVuelo1);
    	Passenger_getEstadoVuelo(parametro2, &auxEstadoVuelo2);
        if(auxEstadoVuelo1 > auxEstadoVuelo2)
        {
        	retorno = 1;
        }

    }
    return retorno;
}

int Passenger_sortCodigoVuelo(void* parametro1, void* parametro2)
{
    int retorno = -1;
    char auxCodigoVuelo1 [LEN_CODIGO];
    char auxCodigoVuelo2 [LEN_CODIGO];

    if(parametro1 != NULL && parametro2 != NULL)
    {
    	Passenger_getCodigoVuelo(parametro1, auxCodigoVuelo1);
    	Passenger_getCodigoVuelo(parametro2, auxCodigoVuelo2);

		if(strcmp(auxCodigoVuelo1,auxCodigoVuelo2)>0)
		{
			retorno = 1;
		}
    }
    return retorno;
}

int Passenger_sortApellidoNombre(void * parametro1, void * parametro2) // doble
{
	int retorno = -1;
	char auxCadena1[LEN_APELLIDO];
	char auxCadena2[LEN_APELLIDO];

	if(parametro1 != NULL && parametro2 != NULL)
	{

		Passenger_getApellido((Passenger*)parametro1, auxCadena1);
		Passenger_getApellido((Passenger*)parametro2, auxCadena2);

		if(stricmp(auxCadena1, auxCadena2) > 0)
		{
			retorno = 1;
		}
		else if(stricmp(parametro1, parametro2) == 0)
		{
			retorno = Passenger_sortNombre(parametro1, parametro2);
		}
	}
	return retorno;
}

/**************************************************************************************/ // criterio para filtrar

int Passenger_filtrarEstadoVuelo(void* parametro, int estadoVuelo)
{
	int retorno = -1;
	int auxEstadoVuelo;
	if(parametro != NULL)
	{
		Passenger_getEstadoVuelo(parametro, &auxEstadoVuelo);
		if(auxEstadoVuelo == estadoVuelo)
		{
			retorno = 0;
		}
	}
	return retorno;
}

int Passenger_filtrarTipoPasagero(void* parametro, int tipoPasagero)
{
	int retorno = -1;
	int auxTipoPasagero;
	if(parametro != NULL)
	{
		Passenger_getTipoPasajero(parametro, &auxTipoPasagero);
		if(auxTipoPasagero == tipoPasagero)
		{
			retorno = 0;
		}
	}
	return retorno;
}

/**************************************************************************************/

int Passenger_filtrarYMostrar(LinkedList* this, int (*pFunc)(void*,int)) // filtra de a una
{
	int retorno = -1;
    LinkedList* auxLinkedList = ll_newLinkedList(); // creo una lista auxiliar
    int longitud;
    Passenger* auxPassenger = NULL;

    if(this != NULL && pFunc != NULL)
    {
    	longitud = ll_len(this);
    	if(longitud >= 0)
    	{
    		for(int i = 0; i<longitud; i++)
    		{
    			auxPassenger = ll_get(this, i);
    			if(pFunc(auxPassenger,1) == 0 ) // cambiar el numero
    			{
    				ll_add(auxLinkedList, auxPassenger);
    			}
    		}
            Passenger_imprimirArray(auxLinkedList);
            retorno = ll_len(auxLinkedList);
    	}
    }
    ll_deleteLinkedList(auxLinkedList);
    return retorno;
}

int Passenger_filtrarMostrar2(LinkedList* this, int (*pFunc)(void*,int), int (*pFunc2)(void*,int)) // filtra de a dos
{
	int retorno = -1;
    LinkedList* auxLinkedList = ll_newLinkedList();
    int longitud;
    Passenger* auxPassenger = NULL;

    if(this != NULL && pFunc != NULL)
    {
    	longitud = ll_len(this);
    	if(longitud >= 0)
    	{
    		for(int i = 0; i<longitud; i++)
    		{
    			auxPassenger = ll_get(this, i);
    			if(pFunc(auxPassenger,4) == 0 && pFunc2(auxPassenger, 2) == 0)
    			{
    				ll_add(auxLinkedList, auxPassenger);
    			}
    		}
    	    Passenger_imprimirArray(auxLinkedList);
    	    retorno = ll_len(auxLinkedList);
    	}
    }
    ll_deleteLinkedList(auxLinkedList);
    return retorno;
}

int Passenger_filtrarOrdenar(LinkedList* this, int (*pFunc)(void*,int))
{
	int retorno = -1;
	int len;
	LinkedList* auxLinkedList = ll_newLinkedList();
	Passenger* auxPassenger;

	if(this != NULL && pFunc != NULL)
	{
		len = ll_len(this);
		if(len >= 0)
		{
			for(int i = 0; i<len; i++)
			{
				auxPassenger = ll_get(this, i);
				if(pFunc(auxPassenger, 1) == 0 && !ll_add(auxLinkedList, auxPassenger)) //tengo q poner el numero
				{
					retorno = 0;
				}
			}
			ll_sort(auxLinkedList, Passenger_sortApellidoNombre, 1); // si quiero que se ordene de otra manera lo tengo que cambiar
			Passenger_imprimirArray(auxLinkedList);
		}
	}
	ll_deleteLinkedList(auxLinkedList);
	return retorno;
}

float hacerPromedio(LinkedList* list, int(*pFunc)(void*, int))
{
    int longitud;
    int contador = 0;
    float acumulador = 0;
    float auxPrecio;
    float promedio = 0;
    Passenger* pPasajero = NULL;

    if(list != NULL && pFunc != NULL)
    {
    	longitud = ll_len(list);
        for(int i = 0; i < longitud; i++)
        {
            pPasajero = ll_get(list, i);
            if(pFunc(pPasajero, 1) == 0) // tengo q cambiar porque tipo lo tengo q hacer
            {
                Passenger_getPrecio(pPasajero, &auxPrecio);
                acumulador += auxPrecio;
                contador++;
            }
        }
        if(contador > 0)
        {
            promedio = acumulador / contador;
        }
    }
    return promedio;
}

/**************************************************************************************/

//Prototipo de la función: int ll_count(LinkedList* this, int (*fn)(void* element))
//La función “ll_count” recibirá una lista y una función “fn”. Se deberá iterar todos los elementos
//de la lista y pasárselos a la funcion “fn”. La función “fn” devolverá la cantidad que debe
//contarse. La función “ll_count” almacenará un acumulador al cual sumará el valor de retorno
//de “fn” en cada iteración. Al finalizar las iteraciones, la función “ll_count” devolverá el valor
//acumulado.

int ll_count(LinkedList* this, int (*fn)(void* element))
{
	int longitud;
	int acomulador = 0;
    Passenger* pPasajero = NULL;

	if(fn!= NULL && fn != NULL)
	{
		longitud = ll_len(this);
		if(longitud >= 0)
		{
			for(int i = 0; i < longitud; i++)
			{
				pPasajero = ll_get(this, i);
				if(pPasajero != NULL)
				{
					acomulador += fn(pPasajero);
				}
			}
		}
	}
	return acomulador;
}

int Passenger_acomularEconomico(void* parametro)
{
	int retorno = 0;
	int auxTipoPasagero;
	if(parametro != NULL)
	{
		Passenger_getTipoPasajero(parametro, &auxTipoPasagero);
		if(auxTipoPasagero == 3)
		{
			retorno = 1;
		}
	}
	return retorno;
}

int Passenger_acomularEjecutivo(void* parametro)
{
	int retorno = 0;
	int auxTipoPasagero;
	if(parametro != NULL)
	{
		Passenger_getTipoPasajero(parametro, &auxTipoPasagero);
		if(auxTipoPasagero == 2)
		{
			retorno = 1;
		}
	}
	return retorno;
}

int Passenger_acomularPrimera(void* parametro)
{
	int retorno = 0;
	int auxTipoPasagero;
	if(parametro != NULL)
	{
		Passenger_getTipoPasajero(parametro, &auxTipoPasagero);
		if(auxTipoPasagero == 1)
		{
			retorno = 1;
		}
	}
	return retorno;
}

//Prototipo de la función: LinkedList* ll_filter(LinkedList* this, void (*fn)(void* element))
//La función “ll_filter” recibirá una lista y una función “fn”. Se deberá iterar todos los elementos
//de la lista y pasárselos a la función “fn”. La función “fn” analizará el elemento recibido e
//informará si cumple o no con el criterio establecido. Al finalizar la iteración, la nueva lista
//estará conformada sólo por los elementos que corresponden.

LinkedList* ll_filter(LinkedList* this, int (*fn)(void* element))
{
	LinkedList* auxLinkedList = ll_newLinkedList();
    Passenger* pPasajero = NULL;
	int longitud;

	if(this != NULL && fn != NULL && auxLinkedList != NULL)
	{
		longitud = ll_len(this);
		for(int i = 0; i < longitud; i++)
		{
			pPasajero = ll_get(this, i);
			if(pPasajero != NULL)
			{
				if(fn(pPasajero) == 0)
				{
					ll_add(auxLinkedList, pPasajero);
				}
			}
		}
	}
	return auxLinkedList;
}

int Passenger_filtrarTipoPasageroFirstClass(void* parametro)
{
	int retorno = -1;
	int auxTipoPasagero;
	if(parametro != NULL)
	{
		Passenger_getTipoPasajero(parametro, &auxTipoPasagero);
		if(auxTipoPasagero == 1)
		{
			retorno = 0;
		}
	}
	return retorno;
}

//Prototipo de la función: LinkedList* ll_map(LinkedList* this, void (*fn)(void* element))
//La función “ll_map” recibirá una lista y una función “fn”. Se deberá iterar todos los elementos
//de la lista y pasárselos a la función “fn”. La función “fn” podrá realizar un cálculo con el
//elemento recibido y modificar alguno de sus campos si es necesario. Al finalizar la iteración,
//los elementos de la lista quedarán modificados.

LinkedList* ll_map(LinkedList* this, void (*fn)(void* element))
{
    Passenger* pPasajero = NULL;
	int longitud;

	if(this != NULL && fn != NULL)
	{
		longitud = ll_len(this);
		for(int i = 0; i < longitud; i++)
		{
			pPasajero = ll_get(this, i);
			if(pPasajero != NULL)
			{
				fn(pPasajero);
			}
		}
	}
	return NULL;
}

void Passenger_imprimirConMIllas(void* parametro)
{
	float millas;
	float precio;
	int tipoPasajero;
	if(parametro != NULL)
	{
		Passenger_getTipoPasajero(parametro, &tipoPasajero);
		switch(tipoPasajero)
		{
		case 3:
			Passenger_getPrecio(parametro, &precio);
			millas = precio/100;
			break;
		case 2:
			Passenger_getPrecio(parametro, &precio);
			millas = precio/50;
			break;
		case 1:
			Passenger_getPrecio(parametro, &precio);
			millas = precio*3/100;

			break;
		}
		Passenger_setMillas(parametro, millas);
		Passenger_imprimirUnoConMillas(parametro);

	}
}

void Passenger_imprimirUnoConMillas(Passenger* punteroPasagero)
{
	int auxId;
	char auxNombre[LEN_NOMBRE];
	char auxApellido[LEN_APELLIDO];
	float auxPrecio;
	int auxTipoPasajero;
	char auxCodigoVuelo[LEN_CODIGO];
	int auxEstadoVuelo;
	float auxMillas;

	char auxTipoPasajeroStr[50];
	char auxEstadoVueloStr[50];

	if(punteroPasagero != NULL)
	{
		if(	!Passenger_getId(punteroPasagero, &auxId) &&
			!Passenger_getNombre(punteroPasagero, auxNombre) &&
			!Passenger_getApellido(punteroPasagero, auxApellido) &&
			!Passenger_getPrecio(punteroPasagero, &auxPrecio) &&
			!Passenger_getTipoPasajero(punteroPasagero, &auxTipoPasajero) &&
			!Passenger_getCodigoVuelo(punteroPasagero, auxCodigoVuelo) &&
			!Passenger_getEstadoVuelo(punteroPasagero, &auxEstadoVuelo) &&
			!Passenger_convertirTipoPasajeroStr(auxTipoPasajero, auxTipoPasajeroStr) &&
			!Passenger_convertirEstadoVueloStr(auxEstadoVuelo, auxEstadoVueloStr) &&
			!Passenger_getMillas(punteroPasagero, &auxMillas))
		{
			printf("id:%d - Nombre:%s - Apellido:%s - Precio:%f - Tipo:%s - Codigo:%s - Estado:%s - Millas:%f\n",auxId,auxNombre,auxApellido,auxPrecio,auxTipoPasajeroStr,auxCodigoVuelo,auxEstadoVueloStr,auxMillas);
		}
	}
}
