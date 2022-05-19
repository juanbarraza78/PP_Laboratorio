/*
 * Zona.c
 *
 *  Created on: 17 may. 2022
 *      Author: juanb
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Zona.h"
#include "Censista.h"
#include "entrada_validaciones_datos.h"

char localidades[5][20] = {"Claypole","Lanus","Florencio varela","Solano","Marmol"};
char estadosZonas[2][20] = {"PENDIENTE","FINALIZADO"};

/** \brief inicializa una array de zonas (isEmpty = 1)
*
* \param list Zona* se ingresa una arry del tipo Zona
* \param len int se ingresa la longitud del array
* \return int retorna un (-1) si hubo un error o (0) si se puedo inicializar el array
*/
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

/** \brief carga datos a una array de Zona
*
* \param pArray[] Zona se ingresa una arry del tipo Zona
* \param len int se ingresa la longitud del array
* \return int retorna un (-1) si hubo un error o (0) si se pudo cargar correctamente
*/
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
						!utn_getNumero(&bufferCensista.localidad, "[1]Claypole\n[2]Lanus\n[3]Florencio varela\n[4]Solano\n[5]Marmol\nIngrese localidad: (1-5)\n", "Error, opcion invalida\n", 1, 5, 2))
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

/** \brief incrementa el id en 1 cada vez que se castea
 *
* \return int retorna el id
*/
int idIncrementalZona()
{
    static int idZona = 200;
    idZona++;
    return idZona;
}

/** \brief imprime una Zona solamente si esta sin asignar y en estado pendiente
*
* \param element Zona se ingresa una variable tipo Zona
* \return void
*
*/
void mostrarZonaPendienteYSinAsignar(Zona element)
{
	if (element.isEmpty == 0 && element.estadoZona == 1 && element.idCensista == -1)
	{
		printf("Id: %d - Calle 1: %s - Calle 2: %s - Calle 3: %s - Calle 4: %s - Localidad: %s - Estado: %s\n",
				element.idZona, element.calleUno, element.calleDos, element.calleTres, element.calleCuatro, localidades[element.localidad-1], estadosZonas[element.estadoZona-1]);

	}
}

/** \brief imprime los elementos de una array Zona si esta ocupado
*
* \param pArray[] Zona se ingresa una array de Zona
* \param len int se ingresa la longitud de la array
* \return int retorna (-1) si hubo algun error o (0) si se pudo imprimir en pantalla
*
*/
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

/** \brief muestra si una lista array tiene una zona pendiente y sin asignar (pArray[i].estadoZona = 1 && pArray[i].idCensista = -1)
*
* \param pArray[] Zona se ingresa una array de tipo Zona
* \param len int indica la longitud de la array
* \return int retorno un 0 si no hay nada cargado o un 1 si hay algo cargado
*/
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

/** \brief busca una Zona por una array segun su id y retorna el index donde se encuentra
 *
* \param pArray[] Zona se ingresa una array de Zona
* \param len int  se ingresa la longitud de la array
* \param id int se ingresa el id de la Zona solicitada
* \return int retorna un -1 si hubo algun error o el index de la Zona solicitada
*
*/
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

/** \brief pide dos id: uno de un censista y uno de una zona y se vinculan por medio del idCensista
 *
* \param pArrayZona[] Zona se ingresa una array de Zona
* \param lenZona int  se ingresa la longitud de la array zona
* \param pArrayCensista[] Censista se ingresa una array de censista
* \param lenCensista int se ingresa la longitud de la array censista
* \return int retorna un -1 si hubo algun error o el index del Censista solicitado
*
*/
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

/** \brief carga datos a una array de censistas de manera forzada
*
* \param pArray[] Zona* se ingresa una arry del tipo Zona
* \param len int se ingresa la longitud del array
* \param calleUno[] char se ingresa el nombre de la calle n1
* \param calleDos[] char se ingresa el nombre de la calle n2
* \param calleTres[] char se ingresa el nombre de la calle n3
* \param calleCuatro[] char se ingresa el nombre de la calle n4
* \param localidad int se ingresa la localidad de la zona
* \return int retorna un (-1) si hubo un error o (0) si se pudo cargar correctamente
*
*/
int cargarZonasForzada(Zona pArray[], int len, char calleUno[], char calleDos[], char calleTres[], char calleCuatro[], int localidad)
{
	int retorno = -1;
	int i;

	if (pArray != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			if(pArray[i].isEmpty == 1 )
			{
				strcpy(pArray[i].calleUno,calleUno);
				strcpy(pArray[i].calleDos,calleDos);
				strcpy(pArray[i].calleTres,calleTres);
				strcpy(pArray[i].calleCuatro,calleCuatro);
				pArray[i].localidad = localidad;
				pArray[i].idZona = idIncrementalZona();
				pArray[i].isEmpty = 0; // hay algo
				pArray[i].estadoZona = 1; // pendiente
				pArray[i].idCensista = -1; // todavia no esta asignado
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}


/** \brief pido el id de una zona pendiente y asignada y luego completo los datos faltantes (cantidad: is situ, virtual , ausente) y luego cambio su estado a finalizado
*
* \param pArrayZona[] Zona se ingresa una array del tipo Zona
* \param lenZona int se ingresa la longitud del array zona
* \param pArrayCensista[] Censista se ingresa una array del tipo censista
* \param lenCensista int se ingresa la longitud del array censista
* \return int retorna un (-1) si hubo un error o (0) si se pudo cargar correctamente
*
*/
int finalizarZonas(Zona pArrayZona[], int lenZona,Censista pArrayCensista[], int lenCensista)
{
	int retorno = -1;
	int bufferId;
	int bufferIndexZona;
	int bufferIndexCensista;

	if (pArrayZona != NULL && lenZona > 0 && pArrayCensista != NULL && lenCensista > 0)
	{
		listarZonasPendientesYAsignadas(pArrayZona, lenZona);
		if(!utn_getNumero(&bufferId, "\nIngrese el id de zona que quiere finalizar\n", "Error, id invalido\n", 1, 10000, 0))
		{
			bufferIndexZona = EncontrarZonaPorId(pArrayZona, lenZona, bufferId);
			if(bufferIndexZona > -1 && pArrayZona[bufferIndexZona].estadoZona == 1 && pArrayZona[bufferIndexZona].idCensista != -1 &&
					!utn_getNumero(&pArrayZona[bufferIndexZona].cantidadDeCensadosInSitu, "Ingrese cantidad de personas que completaron el formulario in situ en la zona\n", "Error, cantidad invalida\n", 0, 10000, 2) &&
					!utn_getNumero(&pArrayZona[bufferIndexZona].cantidadDeCensadosVirtual, "Ingrese cantidad de personas que completaron el formulario de forma vitual en la zona\n", "Error, cantidad invalida\n", 0, 10000, 2) &&
					!utn_getNumero(&pArrayZona[bufferIndexZona].CantidadAusentes, "Ingrese cantidad de personas ausentes en la zona\n", "Error, cantidad invalida\n", 0, 10000, 2))
			{
				bufferIndexCensista = EncontrarCensistaPorId(pArrayCensista, lenCensista, pArrayZona[bufferIndexZona].idCensista);
				if(bufferIndexCensista > -1 && pArrayCensista[bufferIndexCensista].estadoCensista == 1)
				{
					pArrayCensista[bufferIndexCensista].estadoCensista = 3; // Censista en estado LIBERADO
					pArrayZona[bufferIndexZona].estadoZona = 2; // Zona en estado FINALIZADO
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}

/** \brief imprime una Zona solamente si esta asignada y en estado pendiente
*
* \param element Zona se ingresa una variable tipo Zona
* \return void
*
*/
void mostrarZonaPendienteYAsignadas(Zona element)
{
	if (element.isEmpty == 0 && element.estadoZona == 1 && element.idCensista != -1)
	{
		printf("Id: %d - Calle 1: %s - Calle 2: %s - Calle 3: %s - Calle 4: %s - Localidad: %s - Estado: %s\n",
				element.idZona, element.calleUno, element.calleDos, element.calleTres, element.calleCuatro, localidades[element.localidad-1], estadosZonas[element.estadoZona-1]);
	}
}

/** \brief imprime los elementos de una array Zona si esta ocupado
*
* \param pArray[] Zona se ingresa una array de Zona
* \param len int se ingresa la longitud de la array
* \return int retorna (-1) si hubo algun error o (0) si se pudo imprimir en pantalla
*
*/
int listarZonasPendientesYAsignadas(Zona pArray[], int len)
{
	int retorno = -1;
	if (pArray != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			mostrarZonaPendienteYAsignadas(pArray[i]);
		}
		retorno = 0;
	}
	return retorno;
}

/** \brief muestra si una lista array tiene una zona pendiente y sin asignar (pArray[i].estadoZona = 1 && pArray[i].idCensista = -1)
*
* \param pArray[] Zona se ingresa una array de tipo Zona
* \param len int indica la longitud de la array
* \return int retorno un 0 si no hay nada cargado o un 1 si hay algo cargado
*/
int hayZonaPendienteYAsignadas(Zona pArray[], int len)
{
	int retorno = 0;
	if (pArray != NULL && len > 0)
	{
		for (int i = 0; i < len; i++)
		{
			if (pArray[i].isEmpty == 0 && pArray[i].estadoZona == 1 && pArray[i].idCensista != -1)
			{
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}

/** \brief imprime una Zona
*
* \param element Zona se ingresa una variable tipo Zona
* \return void
*
*/
void mostrarZona(Zona element)
{
	if (element.isEmpty == 0)
	{
		printf("Id: %d - Calle 1: %s - Calle 2: %s - Calle 3: %s - Calle 4: %s - Localidad: %s - Estado: %s\n",
				element.idZona, element.calleUno, element.calleDos, element.calleTres, element.calleCuatro, localidades[element.localidad-1], estadosZonas[element.estadoZona-1]);
	}
}

/** \brief imprime los elementos de una array Censista si esta ocupado
*
* \param pArray[] Zona se ingresa una array de Zona
* \param len int se ingresa la longitud de la array
* \return int retorna (-1) si hubo algun error o (0) si se pudo imprimir en pantalla
*
*/
int listarZonas(Zona pArray[], int len)
{
	int retorno = -1;
	if (pArray != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			mostrarZona(pArray[i]);
		}
		retorno = 0;
	}
	return retorno;
}

/** \brief se muestra en pantalla todos los tipos de zona que tiene el programa con sus respectivos datos
*
* \param pArrayZona[] Zona se ingresa una array de tipo Zona
* \param lenZona int indica la longitud de la array
* \param pArrayCensista[] Censista se ingresa  un array de tipo censista
* \param lenCensista int se ingresa la longitud del arra censista
* \return int retorno un 0 si no hay nada cargado o un 1 si hay algo cargado
*/
int listarTodosLosTiposDeZonas(Zona pArrayZona[], int lenZona,Censista pArrayCensista[], int lenCensista)
{
	int retorno = -1;
	int bufferIndexCensista;
	if(pArrayZona != NULL && lenZona > 0 && pArrayCensista != NULL && lenCensista > 0)
	{
		for(int i = 0;i < lenZona ; i++)
		{
			if(pArrayZona[i].estadoZona == 1 && pArrayZona[i].idCensista == -1)
			{
				printf("Id: %d - Calle 1: %s - Calle 2: %s - Calle 3: %s - Calle 4: %s - Localidad: %s - Estado: %s",
						pArrayZona[i].idZona, pArrayZona[i].calleUno, pArrayZona[i].calleDos, pArrayZona[i].calleTres, pArrayZona[i].calleCuatro, localidades[pArrayZona[i].localidad-1], estadosZonas[pArrayZona[i].estadoZona-1]);
				printf(" - Todavia no se le asigno un censista\n");
			}
			else if(pArrayZona[i].estadoZona == 1 && pArrayZona[i].idCensista != -1)
			{
				bufferIndexCensista = EncontrarCensistaPorId(pArrayCensista, lenCensista, pArrayZona[i].idCensista);
				printf("Id: %d - Calle 1: %s - Calle 2: %s - Calle 3: %s - Calle 4: %s - Localidad: %s - Estado: %s",
						pArrayZona[i].idZona, pArrayZona[i].calleUno, pArrayZona[i].calleDos, pArrayZona[i].calleTres, pArrayZona[i].calleCuatro, localidades[pArrayZona[i].localidad-1], estadosZonas[pArrayZona[i].estadoZona-1]);
				printf(" - Nombre del censista asignado: %s - Apellido del censista asignado: %s\n", pArrayCensista[bufferIndexCensista].nombre, pArrayCensista[bufferIndexCensista].apellido);
			}
			else if(pArrayZona[i].estadoZona == 2)
			{
				bufferIndexCensista = EncontrarCensistaPorId(pArrayCensista, lenCensista, pArrayZona[i].idCensista);
				printf("Id: %d - Calle 1: %s - Calle 2: %s - Calle 3: %s - Calle 4: %s - Localidad: %s - Estado: %s",
						pArrayZona[i].idZona, pArrayZona[i].calleUno, pArrayZona[i].calleDos, pArrayZona[i].calleTres, pArrayZona[i].calleCuatro, localidades[pArrayZona[i].localidad-1], estadosZonas[pArrayZona[i].estadoZona-1]);
				printf(" - Nombre del censista asignado: %s - Apellido del censista asignado: %s", pArrayCensista[bufferIndexCensista].nombre, pArrayCensista[bufferIndexCensista].apellido);
				printf(" - Cantidad censados in situ: %d - Cantidad censados virtual: %d - Cantidad ausentes: %d\n",pArrayZona[i].cantidadDeCensadosInSitu, pArrayZona[i].cantidadDeCensadosVirtual, pArrayZona[i].CantidadAusentes);
			}
		}

	}
	return retorno;
}

/** \brief muestra si una lista array tiene una zona
*
* \param pArray[] Zona se ingresa una array de tipo Zona
* \param len int indica la longitud de la array
* \return int retorno un 0 si no hay nada cargado o un 1 si hay algo cargado
*/
int hayZona(Zona pArray[], int len)
{
	int retorno = 0;
	if (pArray != NULL && len > 0)
	{
		for (int i = 0; i < len; i++)
		{
			if (pArray[i].isEmpty == 0)
			{
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}
