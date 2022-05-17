/*
 * C
 */
#include "ArrayPassenger.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entrada_validaciones_datos.h"


char listTypePassenger[3][20] = {"Primera clase","Clase ejecutiva","Clase turista"};
char listStatusFlight[2][20] = {"ACTIVO","INACTIVO"};

/** \brief inicializa una array de passenger (isEmpty = 1)
* \param list Passenger* se ingresa una arry del tipo Passenger
* \param len int se ingresa la longitud del array
* \return int retorna un (-1) si hubo un error o (0) si se puedo inicializar el array
*/
int initPassengers(Passenger* list, int len)
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

/** \brief carga un pasajero en la primera posicion vacia de un array del tipo passenger de forma forzada
* \param list passenger* se ingresa un array del tipo passenger
* \param len int se ingresa la longitud del array
* \param id int* se ingresa el id del pasajero
* \param name[] char se ingresa el nombre del pasajero
* \param lastName[] char se ingresa el apellido del pasajero
* \param price float  se ingresa el precio del vuelo
* \param typePassenger int se ingresa el tipo de pasajero
* \param flycode[] char se ingresa el codigo del vuelo
* \param statusFlight int se ingresa el estado del vuelo
* \return int retorna (-1) si hubo algun error o (0) si se pudo cargar
*/
int addPassengerForzado(Passenger pArray[], int len,int* id,char name[],char lastname[], float price,char flyCode[],int typePassenger, int statusFlight)
{
	int retorno = -1;
	int i;
	if (pArray != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			if(pArray[i].isEmpty == 1)
			{
				(*id)++;
				pArray[i].id = *id;
				strcpy(pArray[i].name,name);
				strcpy(pArray[i].lastName,lastname);
				pArray[i].price = price;
				strcpy(pArray[i].flycode, flyCode);
				pArray[i].typePassenger = typePassenger;
				pArray[i].statusFlight = statusFlight;
				pArray[i].isEmpty = 0;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/** \brief carga un pasajero en la primera posicion vacia de un array del tipo passenger
* \param list passenger* se ingresa un array del tipo passenger
* \param len int se ingresa la longitud del array
* \param id int se ingresa el id del pasajero
* \param name[] char se ingresa el nombre del pasajero
* \param lastName[] char se ingresa el apellido del pasajero
* \param price float  se ingresa el precio del vuelo
* \param typePassenger int se ingresa el tipo de pasajero
* \param flycode[] char se ingresa el codigo del vuelo
* \param statusFlight int se ingresa el estado del vuelo
* \return int retorna (-1) si hubo algun error o (0) si se pudo cargar un pasajero
*/
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[], int statusFlight)
{
	int retorno = -1;
	int i;

	if (list != NULL && len > 0 && name != NULL && lastName != NULL && flycode != NULL)
	{
		for(i = 0; i < len; i++)
		{
			if(list[i].isEmpty == 1)
			{

				list[i].id = id;
				strcpy(list[i].name,name);
				strcpy(list[i].lastName,lastName);
				list[i].price = price;
				strcpy(list[i].flycode,flycode);
				list[i].typePassenger = typePassenger;
				list[i].statusFlight = statusFlight;
				list[i].isEmpty = 0;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/** \brief imprime un pasajero
*
* \param id int* Variable donde se guarda el id
* \param name[] char Variable donde se guarda el nombre
* \param lenName int longitud del array name[]
* \param lastName[] char Variable donde se guarda el apellido
* \param lenLastName int longitud del array lastName[]
* \param price float* Variable donde se guarda el precio del vuelo
* \param typePassanger int* Variable donde se guarda el tipo de pasajero
* \param flyCode[] Variable donde se guarda el codigo del vuelo
* \param lenFlyCode int longitud del array flyCode[]
* \param statusFlight int* Variable donde se guarda el estado del vuelo
* \return int retorna (-1) si hubo algun error o (0) si esta ok*
*
*/
int utn_getDatosPassager(int* id, char name[],int lenName, char lastName[],int lenLastName, float* price, int* typePassanger, char flyCode[], int lenFlyCode, int* statusFlight)
{
	int retorno = -1;
	if(!utn_getNombre(name, lenName, "Ingrese su nombre del pasajero:\n", "Error, Nombre no valido\n", 2) &&
			!utn_getNombre(lastName, lenLastName, "Ingrese su apellido del pasajero:\n", "Error, apellido no valido\n", 2) &&
			!utn_getNumeroFlotante(price, "Ingrese precio del vuelo:\n", "Error, precio no valido\n", 0, 1000000, 2) &&
			!utn_getNumero(typePassanger, "Ingrese tipo de pasajero:\nPrimera clase[1] - Clase ejecutiva[2] - Clase turista[3]\n", "Error, opcion no valida\n", 1, 3, 2) &&
			!utn_getCodigo(flyCode, lenFlyCode, "Ingrese codigo del vuelo:\n", "Error, codigo no valido\n", 2) &&
			!utn_getNumero(statusFlight, "Ingrese estado del vuelo: ACTIVO[1] - INACTIVO[2]\n", "Error, opcion no valida\n", 1, 2, 2))
	{
		retorno = 0;
		(*id)++;
	}
	return retorno;
}
/** \brief imprime un pasajero
*
* \param pasajero Passenger se ingresa una variable tipo passenger
* \return int retorna (-1) si hubo algun error o (0) si se pudo imprimir en pantalla
*
*/
void mostrarPassenger(Passenger pasajero)
{
	if (pasajero.isEmpty == 0)
	{
		printf("Id: %d - Nombre: %s - Apellido: %s -  Precio: %f - Codigo: %s - Tipo %s - Estado %s \n",
				pasajero.id, pasajero.name, pasajero.lastName, pasajero.price, pasajero.flycode, listTypePassenger[pasajero.typePassenger -1], listStatusFlight[pasajero.statusFlight -1]);
	}
}

/** \brief imprime los elementos de una array passenger si esta ocupado
*
* \param list Passenger* se ingresa una array de passenger
* \param len int se ingresa la longitud de la array
* \return int retorna (-1) si hubo algun error o (0) si se pudo imprimir en pantalla
*
*/
int printPassengers(Passenger pArray[], int len)
{
	int retorno = -1;
	if (pArray != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			mostrarPassenger(pArray[i]);
		}
		retorno = 0;
	}
	return retorno;
}

/** \brief busca un pasajero por la array segun su id y se modifica algun campo
* \param list Passenger* se ingresa una array de passenger
* \param len int  se ingresa la longitud de la array
* \param id int se ingresa el id del pasajero solicitado
* \return int retorna un (-1) si hubo algun error o (0) si se modifico correctamente
*
*/
int modificarPasajero(Passenger pArray[], int len, int idPassenger)
{
	int retorno = -1;
	int index;
	int opcionesBuffer;

	if(pArray != NULL && len > 0 && idPassenger > 0)
	{
		index = findPassengerById(pArray, len, idPassenger);
		if(index != -1)
		{
			mostrarPassenger(pArray[index]);
			do{
				if(utn_getNumero(&opcionesBuffer, "Que campo quiere modificar?\nNombre[1] - Apellido[2] - Precio[3] - Tipo de pasajero[4] - codigo de vuelo[5] - salir[6]\n",
									"Opcion no valida\n", 1, 6, 0) == 0)
							{
								switch(opcionesBuffer)
								{
								case 1:
									if(!utn_getNombre(pArray[index].name, 51, "Ingrese el nombre del pasajero:\n", "Error, Nombre no valido\n", 0))
									{
										retorno = 0;
									}
									break;
								case 2:
									if(!utn_getNombre(pArray[index].lastName, 51, "Ingrese el apellido del pasajero:\n", "Error, apellido no valido\n", 0))
									{
										retorno = 0;
									}
									break;
								case 3:
									if(!utn_getNumeroFlotante(&pArray[index].price, "Ingrese el precio del vuelo:\n", "Error, precio no valido\n", 0, 100000, 0))
									{
										retorno = 0;
									}
									break;
								case 4:
									if(!utn_getNumero(&pArray[index].typePassenger, "Ingrese tipo de pasajero:\nPrimera clase[1] - Clase ejecutiva[2] - Clase turista[3]\n", "Error, opcion no valida\n", 1, 3, 0))
									{
										retorno = 0;
									}
									break;
								case 5:
									if(!utn_getCodigo(pArray[index].flycode, 20, "Ingrese codigo del vuelo:\n", "Error, codigo no valido\n", 0))
									{
										retorno = 0;
									}
									break;
								case 6:
									retorno = 0;
									break;
								}
							}
			}while(opcionesBuffer != 6);
		}
	}
	return retorno;
}

/** \brief busca un pasajero por la array segun su id y retorna el index donde se encuentra
* \param list Passenger* se ingresa una array de passenger
* \param len int  se ingresa la longitud de la array
* \param id int se ingresa el id del pasajero solicitado
* \return int retorna un -1 si hubo algun error o el index del pasajero solicitado
*
*/
int findPassengerById(Passenger* list, int len,int id)
{
	int retorno = -1;
	if (list != NULL && len > 0 && id > 0)
	{
		for (int i = 0; i < len; i++)
		{
			if (list[i].id == id && list[i].isEmpty == 0)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

/** \brief elimina a un pasajero ingresando su id
*
* \param list Passenger* se ingresa un array de passenger
* \param len int indica la longitud de la array
* \param id int se ingresa el id del pasajero a eliminar
* \return int retorno un (-1) si hay algun error y (0) si funciono correctamente
*
*/
int removePassenger(Passenger* list, int len, int id)
{
	int retorno = -1;
	int index;
	int opcionesBuffer;
	if(list != NULL && len > 0 && id > 0)
	{
		index = findPassengerById(list, len, id);
		if(index != -1)
		{
			printf("Estas seguro de eliminar a: ");
			mostrarPassenger(list[index]);
			if(!utn_getNumero(&opcionesBuffer, "SI[1] - NO[2]\n", "Opcion no valida\n", 1, 2, 1))
			{
				if(opcionesBuffer == 1)
				{
					list[index].isEmpty = 1;
					retorno = 0;
				}

			}
		}

	}
	return retorno;
}
/** \brief muestra si una lista array tiene algo cargado (is.empty = 0)
*
* \param list Passenger* se ingresa una array de tipo passenger
* \param len int indica la longitud de la array
* \return int retorno un 0 si no hay nada cargado o un 1 si hay algo cargado
*/
int hayAlgoCargado(Passenger pArray[], int len)
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


/** \brief ordena un array de passenger
*
* \param list Passenger* es un array de passenger
* \param len int indica la longitud de la array
* \param order int indica [1] si es de forma asendente - [0] de fotma decendente
* \return int retorna un -1 si hay algun error y 0 si funciono correctamente
*/
int sortPassengers(Passenger* list, int len, int order)
{
	int flagSwap;
	int i;
	int retorno = -1;
	Passenger bufferPassenger;
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
					if(strcmp(list[i].lastName,list[i+1].lastName) < 0)
					{
						flagSwap = 1;
						bufferPassenger = list[i];
						list[i] = list[i+1];
						list[i+1] = bufferPassenger;
					}
					else if(strcmp(list[i].lastName,list[i+1].lastName) == 0 &&
							list[i].typePassenger < list[i+1].typePassenger)
					{
						flagSwap = 1;
						bufferPassenger = list[i];
						list[i] = list[i+1];
						list[i+1] = bufferPassenger;
					}
				}
				else if(order == 1)
				{
					retorno = 0;
					if(strcmp(list[i].lastName,list[i+1].lastName) > 0)
					{
						flagSwap = 1;
						bufferPassenger = list[i];
						list[i] = list[i+1];
						list[i+1] = bufferPassenger;
					}
					else if(strcmp(list[i].lastName,list[i+1].lastName) == 0 &&
							list[i].typePassenger > list[i+1].typePassenger)
					{
						flagSwap = 1;
						bufferPassenger = list[i];
						list[i] = list[i+1];
						list[i+1] = bufferPassenger;
					}
				}
				nuevoLimite--;
			}
		}while(flagSwap);
	}
	return retorno;
}

/** \brief ordena la lista segun con respecto al codigo del vuelo
*
* \param list Passenger* se ingresa un array de tipo passenger
* \param len int se ingresa la longitud del array
* \param order int indica el orden de la lista (1 asendente - 0 decendente)
* \return int retorna (-1) si hubo algun error o (0) si esta Ok*
*/
int sortPassengersByCode(Passenger* list, int len, int order)
{
	int flagSwap;
	int i;
	int retorno = -1;
	Passenger bufferPassenger;
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
					if(strcmp(list[i].flycode,list[i+1].flycode) < 0)
					{
						flagSwap = 1;
						bufferPassenger = list[i];
						list[i] = list[i+1];
						list[i+1] = bufferPassenger;
					}
				}
				else if(order == 1)
				{
					retorno = 0;
					if(strcmp(list[i].flycode,list[i+1].flycode) > 0)
					{
						flagSwap = 1;
						bufferPassenger = list[i];
						list[i] = list[i+1];
						list[i+1] = bufferPassenger;
					}
				}
				nuevoLimite--;
			}
		}while(flagSwap);
	}
	return retorno;
}

/** \brief Calcula el total, el promedio y la cantidad de personas que lo superaron y lo muestra en pantalla
*
* \param list Passenger* se ingresa la array del tipo passenger
* \param len int es la longitud del arra
* \return retorna (0) si funciono y (-1) sino
*/
int MostrarPromedioYTotalDePrecioPasajeros(Passenger* list, int len)
{
	int retorno = -1;
	int contador = 0;
	float acomulador = 0;
	float promedio;
	int contadorPromedioSuperado = 0;

	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == 0)
			{
				contador++;
				acomulador += list[i].price;
			}
		}
		if(contador != 0)
		{
			promedio = acomulador/contador;

			for(int i = 0; i < len; i++)
			{
				if(list[i].isEmpty == 0 && list[i].price > promedio)
				{
					contadorPromedioSuperado++;
				}
			}
			printf("El total de los precios de los vuelos es: %f\n",acomulador);
			printf("El promedio de los precios de los vuelos es: %f\n",promedio);
			printf("La cantidad de personas que superan el promedio de precios es: %d\n",contadorPromedioSuperado);
			retorno = 0;
		}

	}
	return retorno;
}

/** \brief filtra la lista ingresada por el status vuelo y luego la ordena con respecto al codigo de vuelo
*
* \param list Passenger* se ingresa la lista de tipo passanger
* \param len int longitud de la lista
* \return retorna un -1 si no funciono y un 0 lo hizo correctamente
*/
int filtrarYMostrarPorStatusVuelo(Passenger* list, int len)
{
	Passenger PassengersList[2000];

	initPassengers(PassengersList, 2000);

	int retorno = -1;
	int contador = 0;
	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].statusFlight == 1 && list[i].isEmpty == 0)
			{
				PassengersList[contador] = list[i];
				contador++;

			}
		}
		if(!sortPassengersByCode(PassengersList, 2000, 1) && printPassengers(PassengersList, 2000))
		{
			retorno = 0;
		}

	}
	return retorno;
}
