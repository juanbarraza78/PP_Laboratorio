/*
 * Censista.h
 *
 *  Created on: 17 may. 2022
 *      Author: juanb
 */

#ifndef CENSISTA_H_
#define CENSISTA_H_

#include "Direccion.h"
#include "FechaDeNacimiento.h"

typedef struct
{
	int idCensista;
	int isEmpty;
	char nombre[125];
	char apellido[125];
	Direccion direccion;
	int edad;
	FechaDeNacimiento fechaNacimiento;
	int estadoCensista; // ACTIVO-INACTIVO-LIBERADO

} Censista;

int inicializarCensistas(Censista* list, int len);
int CargarCensista(Censista pArray[], int len);
int idIncrementalCensista();
int hayAlgoCargado(Censista pArray[], int len);
void mostrarCensista(Censista element);
int listarCensistas(Censista pArray[], int len);
int EncontrarCensistaPorId(Censista pArray[], int len,int id);
int modificarCensista(Censista pArray[], int len, int idCencista);
int bajaCensistas(Censista* list, int len, int id);
void mostrarCensistaLiberado(Censista element);
int listarCensistasLiberados(Censista pArray[], int len);
int hayCensistaLiberado(Censista pArray[], int len);


#endif /* CENSISTA_H_ */
