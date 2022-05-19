/*
 * Zona.h
 *
 *  Created on: 17 may. 2022
 *      Author: juanb
 */

#ifndef ZONA_H_
#define ZONA_H_

#include "Censista.h"

typedef struct
{
	int idZona;
	int isEmpty;
	char calleUno[125];
	char calleDos[125];
	char calleTres[125];
	char calleCuatro[125];
	int localidad;
	int estadoZona; // PENDIENTE/FINALIZADO
	int idCensista; // (=

} Zona;

int inicializarZonas(Zona* list, int len);
int cargarZonas(Zona pArray[], int len);
int idIncrementalZona();
void mostrarZonaPendienteYSinAsignar(Zona element);
int listarZonasPendientesYSinAsignar(Zona pArray[], int len);
int hayZonaPendienteYSinAsignar(Zona pArray[], int len);
int asignarZonaACensista(Zona pArrayZona[], int lenZona,Censista pArrayCensista[], int lenCensista);
int EncontrarZonaPorId(Zona pArray[], int len,int id);


#endif /* ZONA_H_ */
