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
	int cantidadDeCensadosInSitu;
	int cantidadDeCensadosVirtual;
	int CantidadAusentes;
} Zona;

int inicializarZonas(Zona* list, int len);
int cargarZonas(Zona pArray[], int len);
int idIncrementalZona();
void mostrarZonaPendienteYSinAsignar(Zona element);
int listarZonasPendientesYSinAsignar(Zona pArray[], int len);
int hayZonaPendienteYSinAsignar(Zona pArray[], int len);
int asignarZonaACensista(Zona pArrayZona[], int lenZona,Censista pArrayCensista[], int lenCensista);
int EncontrarZonaPorId(Zona pArray[], int len,int id);
int cargarZonasForzada(Zona pArray[], int len, char calleUno[], char calleDos[], char calleTres[], char calleCuatro[], int localidad);
int finalizarZonas(Zona pArrayZona[], int lenZona,Censista pArrayCensista[], int lenCensista);
void mostrarZonaPendienteYAsignadas(Zona element);
int listarZonasPendientesYAsignadas(Zona pArray[], int len);
int hayZonaPendienteYAsignadas(Zona pArray[], int len);
void mostrarZona(Zona element);
int listarZonas(Zona pArray[], int len);
int listarTodosLosTiposDeZonas(Zona pArrayZona[], int lenZona,Censista pArrayCensista[], int lenCensista);
int hayZona(Zona pArray[], int len);

#endif /* ZONA_H_ */
