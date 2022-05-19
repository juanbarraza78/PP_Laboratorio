#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Zona.h"
#include "Censista.h"
#include "Informes.h"
#include "entrada_validaciones_datos.h"

///** \brief ordena un array de passenger
//*
//* \param list Passenger* es un array de passenger
//* \param len int indica la longitud de la array
//* \param order int indica [1] si es de forma asendente - [0] de fotma decendente
//* \return int retorna un -1 si hay algun error y 0 si funciono correctamente
//*/
//int sortPassengers(Passenger* list, int len, int order)
//{
//	int flagSwap;
//	int i;
//	int retorno = -1;
//	Passenger bufferPassenger;
//	int nuevoLimite;
//
//	if(list != NULL && len >= 0)
//	{
//		nuevoLimite = len - 1;
//		do{
//			flagSwap = 0;
//			for(i = 0; i < nuevoLimite; i++)
//			{
//				if(order == 0)
//				{
//					retorno = 0;
//					if(strcmp(list[i].lastName,list[i+1].lastName) < 0)
//					{
//						flagSwap = 1;
//						bufferPassenger = list[i];
//						list[i] = list[i+1];
//						list[i+1] = bufferPassenger;
//					}
//					else if(strcmp(list[i].lastName,list[i+1].lastName) == 0 &&
//							list[i].typePassenger < list[i+1].typePassenger)
//					{
//						flagSwap = 1;
//						bufferPassenger = list[i];
//						list[i] = list[i+1];
//						list[i+1] = bufferPassenger;
//					}
//				}
//				else if(order == 1)
//				{
//					retorno = 0;
//					if(strcmp(list[i].lastName,list[i+1].lastName) > 0)
//					{
//						flagSwap = 1;
//						bufferPassenger = list[i];
//						list[i] = list[i+1];
//						list[i+1] = bufferPassenger;
//					}
//					else if(strcmp(list[i].lastName,list[i+1].lastName) == 0 &&
//							list[i].typePassenger > list[i+1].typePassenger)
//					{
//						flagSwap = 1;
//						bufferPassenger = list[i];
//						list[i] = list[i+1];
//						list[i+1] = bufferPassenger;
//					}
//				}
//				nuevoLimite--;
//			}
//		}while(flagSwap);
//	}
//	return retorno;
//}
//
///** \brief ordena la lista segun con respecto al codigo del vuelo
//*
//* \param list Passenger* se ingresa un array de tipo passenger
//* \param len int se ingresa la longitud del array
//* \param order int indica el orden de la lista (1 asendente - 0 decendente)
//* \return int retorna (-1) si hubo algun error o (0) si esta Ok*
//*/
//int sortPassengersByCode(Passenger* list, int len, int order)
//{
//	int flagSwap;
//	int i;
//	int retorno = -1;
//	Passenger bufferPassenger;
//	int nuevoLimite;
//	if(list != NULL && len >= 0)
//	{
//		nuevoLimite = len - 1;
//		do{
//			flagSwap = 0;
//			for(i = 0; i < nuevoLimite; i++)
//			{
//				if(order == 0)
//				{
//					retorno = 0;
//					if(strcmp(list[i].flycode,list[i+1].flycode) < 0)
//					{
//						flagSwap = 1;
//						bufferPassenger = list[i];
//						list[i] = list[i+1];
//						list[i+1] = bufferPassenger;
//					}
//				}
//				else if(order == 1)
//				{
//					retorno = 0;
//					if(strcmp(list[i].flycode,list[i+1].flycode) > 0)
//					{
//						flagSwap = 1;
//						bufferPassenger = list[i];
//						list[i] = list[i+1];
//						list[i+1] = bufferPassenger;
//					}
//				}
//				nuevoLimite--;
//			}
//		}while(flagSwap);
//	}
//	return retorno;
//}
//
///** \brief Calcula el total, el promedio y la cantidad de personas que lo superaron y lo muestra en pantalla
//*
//* \param list Passenger* se ingresa la array del tipo passenger
//* \param len int es la longitud del arra
//* \return retorna (0) si funciono y (-1) sino
//*/
//int MostrarPromedioYTotalDePrecioPasajeros(Passenger* list, int len)
//{
//	int retorno = -1;
//	int contador = 0;
//	float acomulador = 0;
//	float promedio;
//	int contadorPromedioSuperado = 0;
//
//	if(list != NULL && len > 0)
//	{
//		for(int i = 0; i < len; i++)
//		{
//			if(list[i].isEmpty == 0)
//			{
//				contador++;
//				acomulador += list[i].price;
//			}
//		}
//		if(contador != 0)
//		{
//			promedio = acomulador/contador;
//
//			for(int i = 0; i < len; i++)
//			{
//				if(list[i].isEmpty == 0 && list[i].price > promedio)
//				{
//					contadorPromedioSuperado++;
//				}
//			}
//			printf("El total de los precios de los vuelos es: %f\n",acomulador);
//			printf("El promedio de los precios de los vuelos es: %f\n",promedio);
//			printf("La cantidad de personas que superan el promedio de precios es: %d\n",contadorPromedioSuperado);
//			retorno = 0;
//		}
//
//	}
//	return retorno;
//}
//
///** \brief filtra la lista ingresada por el status vuelo y luego la ordena con respecto al codigo de vuelo
//*
//* \param list Passenger* se ingresa la lista de tipo passanger
//* \param len int longitud de la lista
//* \return retorna un -1 si no funciono y un 0 lo hizo correctamente
//*/
//int filtrarYMostrarPorStatusVuelo(Passenger* list, int len)
//{
//	Passenger PassengersList[2000];
//
//	initPassengers(PassengersList, 2000);
//
//	int retorno = -1;
//	int contador = 0;
//	if(list != NULL && len > 0)
//	{
//		for(int i = 0; i < len; i++)
//		{
//			if(list[i].statusFlight == 1 && list[i].isEmpty == 0)
//			{
//				PassengersList[contador] = list[i];
//				contador++;
//
//			}
//		}
//		if(!sortPassengersByCode(PassengersList, 2000, 1) && printPassengers(PassengersList, 2000))
//		{
//			retorno = 0;
//		}
//
//	}
//	return retorno;
//}
