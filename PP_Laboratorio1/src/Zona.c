/*
 * Zona.c
 *
 *  Created on: 17 may. 2022
 *      Author: juanb
 */
#include "Zona.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Censista.h"
#include "entrada_validaciones_datos.h"

char localidades[5][20] = {"Claypole","Lanus","Florencio varela","Solano","Marmol"};
char estadosZonas[2][20] = {"PENDIENTE","FINALIZADO"};

int inicializarZonas(Zona* list, int len)
{
	int retorno = -1;
	if (list != NULL && len > 0)
	{
		for (int i = 0; i < len; i++)
		{
			list[i].isEmpty = 1;
		}
		retorno = 0;
	}
	return retorno;
}

int cargarZonas(Zona pArray[], int len)
{
	int retorno = -1;
	int i;
	Zona bufferCensista;

	if (pArray != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			if(pArray[i].isEmpty == 1 )
			{
				if(!utn_getNombre(bufferCensista.calleUno, 125, "Ingrese calle N:1 de la zona\n", "Error, calle invalida\n", 2) &&
						!utn_getNombre(bufferCensista.calleDos, 125, "Ingrese calle N:2 de la zona\n", "Error, calle invalida\n", 2) &&
						!utn_getNombre(bufferCensista.calleTres, 125, "Ingrese calle N:3 de la zona\n", "Error, calle invalida\n", 2) &&
						!utn_getNombre(bufferCensista.calleCuatro, 125, "Ingrese calle N:4 de la zona\n", "Error, calle invalida\n", 2) &&
						!utn_getNumero(&bufferCensista.localidad, "[1]Claypole\n[2]Lanus\n[3]Florencio varela\n[4]Solano\n[5]Marmol\nIngrese localidad: (1-5)\n", "Error, opcion invalida", 1, 5, 2))
				{
					retorno = 0;
					pArray[i] = bufferCensista;
					pArray[i].idZona = idIncrementalZona();
					pArray[i].isEmpty = 0; // hay algo
					pArray[i].estadoZona = 1; // pendiente
					pArray[i].idCensista = -1; // todavia no esta asignado
					break;
				}
				else
				{
					break;
				}
			}
		}
	}
	return retorno;
}

int idIncrementalZona()
{
    static int idZona = 200;
    idZona++;
    return idZona;
}

void mostrarZonaPendienteYSinAsignar(Zona element)
{
	if (element.isEmpty == 0 && element.estadoZona == 1 && element.idCensista == -1)
	{
		printf("Id: %d - Calle 1: %s - Calle 2: %s - Calle 3: %s - Calle 4: %s - Localidad: %s - Estado: %s",
				element.idZona, element.calleUno, element.calleDos, element.calleTres, element.calleCuatro, localidades[element.localidad-1], estadosZonas[element.estadoZona-1]);

	}
}

int listarZonasPendientesYSinAsignar(Zona pArray[], int len)
{
	int retorno = -1;
	if (pArray != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			mostrarZonaPendienteYSinAsignar(pArray[i]);
		}
		retorno = 0;
	}
	return retorno;
}

int hayZonaPendienteYSinAsignar(Zona pArray[], int len)
{
	int retorno = 0;
	if (pArray != NULL && len > 0)
	{
		for (int i = 0; i < len; i++)
		{
			if (pArray[i].isEmpty == 0 && pArray[i].estadoZona == 1 && pArray[i].idCensista == -1)
			{
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}

int EncontrarZonaPorId(Zona pArray[], int len,int id)
{
	int retorno = -1;
	if (pArray != NULL && len > 0 && id > 0)
	{
		for (int i = 0; i < len; i++)
		{
			if (pArray[i].idZona == id && pArray[i].isEmpty == 0)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int asignarZonaACensista(Zona pArrayZona[], int lenZona,Censista pArrayCensista[], int lenCensista)
{
	int retorno = -1;
	int bufferIdZona;
	int bufferIdCensista;
	int indexZona;
	int indexCensista;

	if(pArrayZona != NULL && lenZona > 0 && pArrayCensista != NULL && lenCensista > 0)
	{
		listarZonasPendientesYSinAsignar(pArrayZona, lenZona);
		if(!utn_getNumero(&bufferIdZona, "\nIngrese el id de la zona que quiere asignar\n", "Error, id invalido\n", 1, 10000, 0))
		{
			listarCensistasLiberados(pArrayCensista, lenCensista);
			if(!utn_getNumero(&bufferIdCensista, "\nIngrese el id del censista que quiere asignar\n", "Error, id invalido\n", 1, 10000, 0))
			{
				indexZona = EncontrarZonaPorId(pArrayZona, lenZona, bufferIdZona);
				indexCensista = EncontrarCensistaPorId(pArrayCensista, lenCensista, bufferIdCensista);
				if(bufferIdZona > -1 && bufferIdCensista > -1 && pArrayZona[indexZona].estadoZona == 1 && pArrayZona[indexZona].idCensista == -1 && pArrayCensista[indexCensista].estadoCensista == 3)
				{
					pArrayZona[indexZona].idCensista = pArrayCensista[indexCensista].idCensista;
					pArrayCensista[indexCensista].estadoCensista = 1;
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}
