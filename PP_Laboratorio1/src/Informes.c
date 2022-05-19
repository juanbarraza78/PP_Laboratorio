#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Zona.h"
#include "Censista.h"
#include "Informes.h"
#include "entrada_validaciones_datos.h"

/** \brief Calcula el total, el promedio y la cantidad de personas que lo superaron y lo muestra en pantalla
*
* \param list Passenger* se ingresa la array del tipo passenger
* \param len int es la longitud del arra
* \return retorna (0) si funciono y (-1) sino
*/
int MostrarCantidadDeCensitasEnEstadoActivoYZonaPendiente(Zona pArrayZona[], int lenZona,Censista pArrayCensista[], int lenCensista)
{
	int retorno = -1;
	int contador = 0;
	int bufferIndex;

	if(pArrayZona != NULL && lenZona > 0 && pArrayCensista != NULL && lenCensista > 0)
	{
		for(int i = 0; i < lenZona; i++)
		{
			if(pArrayZona[i].estadoZona == 1)
			{
				bufferIndex = EncontrarCensistaPorId(pArrayCensista, lenCensista, pArrayZona[i].idCensista);
				if(bufferIndex > -1 && pArrayCensista[bufferIndex].estadoCensista == 1)
				{
					contador++;
					retorno = 0;
				}
			}
		}
		printf("La cantidad de censistas en estado activo y con zona pendiente es: %d",contador);
	}
	return retorno;
}

int MostrarCensitasDeEtc(Zona pArrayZona[], int lenZona,Censista pArrayCensista[], int lenCensista)
{
	int retorno = -1;
	int bufferIndex;
	int contador = 0;

	Censista bufferCensistaLista[100];
	inicializarCensistas(bufferCensistaLista, 100);

	if(pArrayZona != NULL && lenZona > 0 && pArrayCensista != NULL && lenCensista > 0)
	{
		for(int i = 0; i < lenZona; i++)
		{
			if(pArrayZona[i].estadoZona == 1 && (pArrayZona[i].localidad == 1 || pArrayZona[i].localidad == 2 || pArrayZona[i].localidad == 3 || pArrayZona[i].localidad == 4))
			{
				bufferIndex = EncontrarCensistaPorId(pArrayCensista, lenCensista, pArrayZona[i].idCensista);
				if(bufferIndex > -1)
				{
					bufferCensistaLista[contador] = pArrayCensista[bufferIndex];
					contador++;
				}
			}
		}
		ordenarCensistas(bufferCensistaLista, 100, 1);
		listarCensistas(bufferCensistaLista, 100);
	}
	return retorno;
}

/** \brief ordena un array de passenger
*
* \param list Passenger* es un array de passenger
* \param len int indica la longitud de la array
* \param order int indica [1] si es de forma asendente - [0] de fotma decendente
* \return int retorna un -1 si hay algun error y 0 si funciono correctamente
*/
int ordenarCensistas(Censista* list, int len, int order)
{
	int flagSwap;
	int i;
	int retorno = -1;
	Censista bufferCensista;
	int nuevoLimite;

	if(list != NULL && len >= 0)
	{
		nuevoLimite = len - 1;
		do{
			flagSwap = 0;
			for(i = 0; i < nuevoLimite; i++)
			{
				if(order == 0)
				{
					retorno = 0;
					if(strcmp(list[i].apellido,list[i+1].apellido) < 0)
					{
						flagSwap = 1;
						bufferCensista = list[i];
						list[i] = list[i+1];
						list[i+1] = bufferCensista;
					}
					else if(strcmp(list[i].apellido,list[i+1].apellido) == 0 &&
							list[i].nombre < list[i+1].nombre)
					{
						flagSwap = 1;
						bufferCensista = list[i];
						list[i] = list[i+1];
						list[i+1] = bufferCensista;
					}
				}
				else if(order == 1)
				{
					retorno = 0;
					if(strcmp(list[i].apellido,list[i+1].apellido) > 0)
					{
						flagSwap = 1;
						bufferCensista = list[i];
						list[i] = list[i+1];
						list[i+1] = bufferCensista;
					}
					else if(strcmp(list[i].apellido,list[i+1].apellido) == 0 &&
							list[i].nombre > list[i+1].nombre)
					{
						flagSwap = 1;
						bufferCensista = list[i];
						list[i] = list[i+1];
						list[i+1] = bufferCensista;
					}
				}
				nuevoLimite--;
			}
		}while(flagSwap);
	}
	return retorno;
}

int InformarLocalidadMayorCasasAusentes(Zona pArrayZona[], int lenZona)
{
	int retorno = -1;
	int acomulardorAvellaneda = 0;
	int acomulardorLanus = 0;
	int acomulardorLomasDeZamora = 0;
	int acomulardorBanfield = 0;
	int acomulardorMarmol = 0;

	Censista bufferCensistaLista[100];
	inicializarCensistas(bufferCensistaLista, 100);

	if(pArrayZona != NULL && lenZona > 0)
	{
		retorno= 0;
		for(int i = 0; i < lenZona; i++)
		{
			if(pArrayZona[i].estadoZona == 2)
			{
				if(pArrayZona[i].localidad == 1)
				{
					acomulardorAvellaneda += pArrayZona[i].CantidadAusentes;
				}
				else if(pArrayZona[i].localidad == 2)
				{
					acomulardorLanus += pArrayZona[i].CantidadAusentes;
				}
				else if(pArrayZona[i].localidad == 3)
				{
					acomulardorLomasDeZamora += pArrayZona[i].CantidadAusentes;
				}
				else if(pArrayZona[i].localidad == 4)
				{
					acomulardorBanfield += pArrayZona[i].CantidadAusentes;
				}
				else if(pArrayZona[i].localidad == 5)
				{
					acomulardorMarmol += pArrayZona[i].CantidadAusentes;
				}
			}
		}
		if(acomulardorAvellaneda > acomulardorLanus && acomulardorAvellaneda > acomulardorLomasDeZamora && acomulardorAvellaneda > acomulardorBanfield && acomulardorAvellaneda > acomulardorMarmol)
		{
			printf("La localidad con mas ausentes fue Avellaneda");
		}
		else if(acomulardorLanus > acomulardorAvellaneda && acomulardorLanus > acomulardorLomasDeZamora && acomulardorLanus > acomulardorBanfield && acomulardorLanus > acomulardorMarmol)
		{
			printf("La localidad con mas ausentes fue Lanus");
		}
		else if(acomulardorLomasDeZamora > acomulardorAvellaneda && acomulardorLomasDeZamora > acomulardorLanus && acomulardorLomasDeZamora > acomulardorBanfield && acomulardorLomasDeZamora > acomulardorMarmol)
		{
			printf("La localidad con mas ausentes fue Lomas De Zamora");
		}
		else if(acomulardorBanfield > acomulardorAvellaneda && acomulardorBanfield > acomulardorLanus && acomulardorBanfield > acomulardorLomasDeZamora && acomulardorBanfield > acomulardorMarmol)
		{
			printf("La localidad con mas ausentes fue Banfield");
		}
		else if(acomulardorMarmol > acomulardorAvellaneda && acomulardorMarmol > acomulardorLanus && acomulardorMarmol > acomulardorLomasDeZamora && acomulardorMarmol > acomulardorBanfield)
		{
			printf("La localidad con mas ausentes fue Marmol");
		}
	}
	return retorno;
}

int InformarCensistaCuyaEsLaZonaMasCensada(Zona pArrayZona[], int lenZona,Censista pArrayCensista[], int lenCensista)
{
	int retorno = -1;
	int flag = 0;
	int bufferInt;
	int bufferIndex;
	Censista befferCencista;
	if(pArrayZona != NULL && lenZona > 0 && pArrayCensista != NULL && lenCensista > 0)
	{
		for(int i = 0; i < lenZona; i++)
		{
			if(flag == 0)
			{
				bufferInt = pArrayZona[i].cantidadDeCensadosVirtual + pArrayZona[i].cantidadDeCensadosInSitu;
				befferCencista = pArrayCensista[bufferIndex];
			}
			else if(pArrayZona[i].estadoZona == 2)
			{
				if(bufferInt > pArrayZona[i].cantidadDeCensadosVirtual + pArrayZona[i].cantidadDeCensadosInSitu)
				{
					bufferIndex = EncontrarCensistaPorId(pArrayCensista, lenCensista, pArrayZona[i].idCensista);
					if(bufferIndex > -1)
					{
						bufferInt = pArrayZona[i].cantidadDeCensadosVirtual + pArrayZona[i].cantidadDeCensadosInSitu;
						befferCencista = pArrayCensista[bufferIndex];
					}
				}
			}
		}
		printf("El censista cuya zona fue la mas censada fue: %s %s",befferCencista.nombre, befferCencista.apellido);
	}
	return retorno;
}
