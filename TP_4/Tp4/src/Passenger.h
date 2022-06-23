 /*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

#include "LinkedList.h"

#define LEN_NOMBRE 50
#define LEN_APELLIDO 50
#define LEN_CODIGO 10

typedef struct
{
	int id;
	char nombre[LEN_NOMBRE];
	char apellido[LEN_APELLIDO];
	float precio;
	int tipoPasajero;
	char codigoVuelo[LEN_CODIGO];
	int estadoVuelo;
	float millas;
}Passenger;

//char listTypePassenger[3][20] = {"FirstClass","ExecutiveClass","EconomyClass"};
//char listStatusFlight[2][20] = {"Aterrizado","En Horario","En Vuelo","Demorado"};

Passenger* Passenger_new();
Passenger* Passenger_newParametrosStr(char* idStr, char* nombre, char* apellido, char* precioStr, char* tipoPasajeroStr, char* codigoVuelo, char* estadoVueloStr);
Passenger* Passenger_newParametros(int id, char* nombre, char* apellido, float precio, int tipoPasajero, char* codigoVuelo, int estadoVuelo);
void Passenger_delete(Passenger* this);

/**************************************************************************************/

int  Passenger_loadId(char* path);
int Passenger_saveId(char* path,int id);
int  Passenger_idMaximo(char* path);

/**************************************************************************************/

int Passenger_deleteIndexArray(LinkedList* listaPasajeros, int index);
int Passenger_convertirTipoPasajeroStr(int tipoPasajero, char* tipoPasajeroStr);
int Passenger_convertirEstadoVueloStr(int estadoVuelo, char* estadoVueloStr);
void Passenger_imprimirUno(Passenger* punteroPasagero);
int Passenger_imprimirArray(LinkedList* listaPasajeros);
int Passenger_buscarPorIdArray(LinkedList* listaPasajeros, int id);
int Passenger_agregarArray(LinkedList* listaPasajeros, int id, char* nombre, char* apellido, float precio, int tipoPasajero, char* codigoVuelo, int estadoVuelo);
int Passenger_borrarPorIdArray(LinkedList* listaPasajeros, int id);
int Passenger_modificarPorIdArray(LinkedList* listaPasajeros, int id);
int Passenger_convertirTipoPasajeroint(char* tipoPasajeroStr);
int Passenger_convertirEstadoVueloSint(char* estadoVueloStr);

/**************************************************************************************/

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setEstadoVuelo(Passenger* this,int estadoVuelo);
int Passenger_getEstadoVuelo(Passenger* this,int* estadoVuelo);

int Passenger_setMillas(Passenger* this,float millas);
int Passenger_getMillas(Passenger* this,float* millas);

int Passenger_setIdStr(Passenger* this,char* id);
int Passenger_setPrecioStr(Passenger* this,char* precio);
int Passenger_setTipoPasajeroStr(Passenger* this,char* tipoPasajero);
int Passenger_setEstadoVueloStr(Passenger* this,char* estadoVuelo);

#endif /* PASSENGER_H_ */
