#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "Controller.h"
#include "parser.h"
#include "utn.h"
#include "informes.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{

	int retorno = -1;
	FILE *pFile = NULL;
	if(path != NULL && pArrayListPassenger != NULL)
	{
		pFile = fopen(path, "r"); // nombre del archivo y el modo de abrirlo
		if(pFile != NULL)
		{
			if(!parser_PassengerFromText(pFile, pArrayListPassenger))
			{
				retorno = 0;
				printf("Se cargo correctamente.\n");
			}
			fclose(pFile);
		}
		else
		{
			printf("El archivo no existe");
		}

	}
    return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	FILE *pFile = NULL;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		pFile = fopen(path, "rb");
		if(pFile != NULL)
		{
			if(!parser_PassengerFromBinary(pFile, pArrayListPassenger))
			{
				retorno = 0;
				printf("Se cargo correctamente.\n");
			}
			fclose(pFile);
		}
		else
		{
			printf("El archivo no existe\n");
		}
	}
    return retorno;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;

	int auxId;
	char auxNombre[LEN_NOMBRE];
	char auxApellido[LEN_APELLIDO];
	float auxPrecio;
	int auxTipoPasajero;
	char auxCodigoVuelo[LEN_CODIGO];
	int auxEstadoVuelo;

	if(pArrayListPassenger != NULL)
	{
		if( !utn_getNombre(auxNombre, LEN_NOMBRE, "Ingrese el nombre del pasajero:\n", "Error, Nombre no valido\n", 2) &&
			!utn_getNombre(auxApellido, LEN_APELLIDO, "Ingrese el apellido del pasajero:\n", "Error, apellido no valido\n", 2) &&
			!utn_getNumeroFlotante(&auxPrecio, "Ingrese el precio del vuelo:\n", "Error, precio no valido\n", 0, 100000, 2) &&
			!utn_getNumero(&auxTipoPasajero, "Ingrese tipo de pasajero:\nFirst Class[1] - Executive Class[2] - Economy Class[3]\n", "Error, opcion no valida\n", 1, 3, 2) &&
			!utn_getCodigo(auxCodigoVuelo, LEN_CODIGO, "Ingrese codigo del vuelo:\n", "Error, codigo no valido\n", 2) &&
			!utn_getNumero(&auxEstadoVuelo, "Ingrese el estado del vuelo:\nAterrizado[1] - En Horario[2] - En Vuelo[3] - Demorado[4]\n", "Error, codigo no valido\n", 1, 4, 2))
		{
			auxId = Passenger_idMaximo("id.csv"); // como obtengo el id
			if(auxId >= 0 && !Passenger_agregarArray(pArrayListPassenger,auxId, auxNombre, auxApellido, auxPrecio, auxTipoPasajero, auxCodigoVuelo, auxEstadoVuelo))
			{
				retorno = 0;
			}
		}
	}
	return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int auxDni;
	if(pArrayListPassenger != NULL)
	{
		Passenger_imprimirArray(pArrayListPassenger);
		if(!utn_getNumero(&auxDni, "Ingrese Dni de la persona a modificar\n", "Error, Dni no valido\n", 1, 10000, 1) &&
		   !Passenger_modificarPorIdArray(pArrayListPassenger, auxDni))
		{
			retorno = 0;
		}


	}
	return retorno;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int auxDni;
	if(pArrayListPassenger != NULL)
	{
		Passenger_imprimirArray(pArrayListPassenger);
		if(!utn_getNumero(&auxDni, "Ingrese Dni de la persona a remover\n", "Error, Dni no valido\n", 1, 10000, 1) &&
		   !Passenger_borrarPorIdArray(pArrayListPassenger, auxDni))
		{
			retorno = 0;
		}

	}
	return retorno;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	if(pArrayListPassenger != NULL)
	{
		Passenger_imprimirArray(pArrayListPassenger);
	}
    return retorno;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	if(pArrayListPassenger != NULL)
	{
		if(!ll_sort(pArrayListPassenger, Passenger_sortNombre, 1))
		{
			retorno = 0;
			printf("Se ordeno correctamenten");
		}
	}
	return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile = NULL;
	Passenger* auxPasageroPuntero = NULL;

	int auxId;
	char auxNombre[LEN_NOMBRE];
	char auxApellido[LEN_APELLIDO];
	float auxPrecio;
	int auxTipoPasajero;
	char auxCodigoVuelo[LEN_CODIGO];
	int auxEstadoVuelo;
	char auxTipoPasajeroStr[50];
	char auxEstadoVueloStr[50];

	int len;
	int contador = -1;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		pFile = fopen(path,"w");
		len = ll_len(pArrayListPassenger);
		if(pFile != NULL)
		{
			for(int i=0; i<len; i++)
			{
				auxPasageroPuntero= ll_get(pArrayListPassenger, i);
				if(auxPasageroPuntero != NULL)
				{
					if(!Passenger_getId(auxPasageroPuntero, &auxId) &&
						!Passenger_getNombre(auxPasageroPuntero, auxNombre) &&
						!Passenger_getApellido(auxPasageroPuntero, auxApellido) &&
						!Passenger_getPrecio(auxPasageroPuntero, &auxPrecio) &&
						!Passenger_getTipoPasajero(auxPasageroPuntero, &auxTipoPasajero) &&
						!Passenger_getCodigoVuelo(auxPasageroPuntero, auxCodigoVuelo) &&
						!Passenger_getEstadoVuelo(auxPasageroPuntero, &auxEstadoVuelo) &&
						!Passenger_convertirTipoPasajeroStr(auxTipoPasajero, auxTipoPasajeroStr) &&
						!Passenger_convertirEstadoVueloStr(auxEstadoVuelo, auxEstadoVueloStr))
					{
						fprintf(pFile,"%d,%s,%s,%f,%s,%s,%s\n",auxId,auxNombre,auxApellido,auxPrecio,auxCodigoVuelo,auxTipoPasajeroStr,auxEstadoVueloStr);
						contador = i+1;
					}
				}
			}
			fclose(pFile);
		}
	}
    return contador;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile = NULL;
	Passenger* auxPasageroPuntero = NULL;
	int len;
	int contador = -1;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		pFile = fopen(path,"wb");
		len = ll_len(pArrayListPassenger);
		if(pFile != NULL)
		{
			for(int i=0; i<len; i++)
			{
				auxPasageroPuntero= ll_get(pArrayListPassenger, i);
				if(auxPasageroPuntero != NULL)
				{
					fwrite(auxPasageroPuntero,sizeof(Passenger),1,pFile);
					contador = i+1;
				}
			}
			fclose(pFile);
		}
	}
    return contador;
}
