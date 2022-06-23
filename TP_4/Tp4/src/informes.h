/*
 * informes.h
 *
 *  Created on: 23 jun. 2022
 *      Author: juanb
 */

#ifndef INFORMES_H_
#define INFORMES_H_

#include "Passenger.h"

int Passenger_sortNombre(void* parametro1, void* parametro2);
int Passenger_sortprecio(void* parametro1, void* parametro2);
int Passenger_sortApellido(void* parametro1, void* parametro2);
int Passenger_sortId(void* parametro1, void* parametro2);
int Passenger_sortTipoPasajero(void* parametro1, void* parametro2);
int Passenger_sortEstadoVuelo(void* parametro1, void* parametro2);
int Passenger_sortCodigoVuelo(void* parametro1, void* parametro2);
int Passenger_sortApellidoNombre(void * parametro1, void * parametro2); // doble criterio

/**************************************************************************************/

int Passenger_filtrarYMostrar(LinkedList* this, int (*pFunc)(void*,int));
int Passenger_filtrarMostrar2(LinkedList* this, int (*pFunc)(void*,int), int (*pFunc2)(void*,int));
int Passenger_filtrarOrdenar(LinkedList* this, int (*pFunc)(void*,int));
float hacerPromedio(LinkedList* list, int(*pFunc)(void*, int));

/**************************************************************************************/

int Passenger_filtrarEstadoVuelo(void* parametro, int estadoVuelo);
int Passenger_filtrarTipoPasagero(void* parametro, int tipoPasagero);

/**************************************************************************************/

int ll_count(LinkedList* this, int (*fn)(void* element));
int Passenger_acomularEconomico(void* parametro);
int Passenger_acomularEjecutivo(void* parametro);
int Passenger_acomularPrimera(void* parametro);

LinkedList* ll_filter(LinkedList* this, int (*fn)(void* element));
int Passenger_filtrarTipoPasageroFirstClass(void* parametro);

LinkedList* ll_map(LinkedList* this, void (*fn)(void* element));
void Passenger_imprimirUnoConMillas(Passenger* punteroPasagero);
void Passenger_imprimirConMIllas(void* parametro);

#endif /* INFORMES_H_ */
