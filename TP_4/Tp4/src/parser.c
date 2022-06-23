#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int cantidadLeida;

	char auxIdStr[1024];
	char auxNombre[1024];
	char auxApellido[1024];
	char auxPrecioStr[1024];
	char auxTipoPasajeroStr[1024];
	char auxCodigoVuelo[1024];
	char auxEstadoVueloStr[1024];

	Passenger* pAuxPassager = NULL;

	if(pArrayListPassenger != NULL && pFile != NULL)
	{
		cantidadLeida = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxIdStr,auxNombre,auxApellido,auxPrecioStr,auxCodigoVuelo,auxTipoPasajeroStr,auxEstadoVueloStr);
		do
		{
			cantidadLeida = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxIdStr,auxNombre,auxApellido,auxPrecioStr,auxCodigoVuelo,auxTipoPasajeroStr,auxEstadoVueloStr);
			if(cantidadLeida == 7)
			{
				if(!Passenger_convertirTipoPasajeroint(auxTipoPasajeroStr) && !Passenger_convertirEstadoVueloSint(auxEstadoVueloStr))
				{
					pAuxPassager = Passenger_newParametrosStr(auxIdStr, auxNombre, auxApellido, auxPrecioStr, auxTipoPasajeroStr, auxCodigoVuelo, auxEstadoVueloStr);
					if(pAuxPassager != NULL)
					{
						ll_add(pArrayListPassenger, pAuxPassager);
						retorno = 0;
					}
				}
			}
			else
			{
				retorno = -1;
				printf("No se pudo cargar los datos correctamente");
				break;
			}
		}while(!feof(pFile));
	}
	return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = -1;

	Passenger auxPassager;
	Passenger* pAuxPassager;

	int cantidad = 0;
	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		do
		{
			cantidad = fread(&auxPassager,sizeof(Passenger),1,pFile); // destino,  sizeof tamaño del elemento , cantidad que quiero , origen
			if(cantidad == 1)
			{
				pAuxPassager = Passenger_newParametros(auxPassager.id, auxPassager.nombre, auxPassager.apellido, auxPassager.precio, auxPassager.tipoPasajero, auxPassager.codigoVuelo, auxPassager.estadoVuelo);
				if(pAuxPassager != NULL)
				{
					ll_add(pArrayListPassenger, pAuxPassager);
					retorno = 0;
				}
			}
		}while(!feof(pFile));
	}
	return retorno;
}
