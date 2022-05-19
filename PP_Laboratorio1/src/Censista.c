/*
 * Censista.c
 *
 *  Created on: 17 may. 2022
 *      Author: juanb
 */
#include "Censista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entrada_validaciones_datos.h"

char estadoCencistas[3][20] = {"ACTIVO","INACTIVO","LIBERADO"};
// ACTIVO = ya se le asigno una zona
// INACTIVO = se le dio de baja (pero el .isEmpty sigue en 0 significa que no se va a reemplazar por otro en la memoria)
// LUBERADO = no se le asigno una zona

/** \brief inicializa una array de censistas (isEmpty = 1)
*
* \param list Censista* se ingresa una arry del tipo Censista
* \param len int se ingresa la longitud del array
* \return int retorna un (-1) si hubo un error o (0) si se puedo inicializar el array
*/
int inicializarCensistas(Censista* list, int len)
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

/** \brief carga datos a una array de censistas
*
* \param pArray[] Censista* se ingresa una arry del tipo Censista
* \param len int se ingresa la longitud del array
* \return int retorna un (-1) si hubo un error o (0) si se pudo cargar correctamente
*/
int CargarCensista(Censista pArray[], int len)
{
	int retorno = -1;
	int i;
	Censista bufferCensista;

	if (pArray != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			if(pArray[i].isEmpty == 1 )
			{
				if(!utn_getNombre(bufferCensista.nombre, 125, "Ingrese nombre del censista\n", "Error, nombre invalido\n", 2) &&
						!utn_getNombre(bufferCensista.apellido, 125, "Ingrese apellido del censista\n", "Error, apellido invalido\n", 2) &&
						!utn_getNumero(&bufferCensista.fechaNacimiento.dia, "Ingrese el dia de nacimiento del censista\n", "Error, dia invalido\n", 1, 31, 2) &&
						!utn_getNumero(&bufferCensista.fechaNacimiento.mes, "Ingrese el mes de nacimiento del censista\n", "Error, mes invalido\n", 1, 12, 2) &&
						!utn_getNumero(&bufferCensista.fechaNacimiento.anio, "Ingrese año de nacimiento del censista\n", "Error, año invalido\n", 1903, 2021, 2) &&
						!utn_getNumero(&bufferCensista.edad, "Ingrese edad del censista\n", "Error, edad invalida\n", 1, 99, 2) &&
						!utn_getNombre(bufferCensista.direccion.calle, 125, "ingrese calle donde vive el censita\n", "Error, calle invalida\n", 2) &&
						!utn_getNumero(&bufferCensista.direccion.altura, "Ingrese altura de la calle\n", "Error, altura invalida\n", 1, 10000, 2) &&
						!utn_getNombre(bufferCensista.direccion.localidad, 125, "ingrese localidad donde vive el censita\n", "Error, localidad invalida\n", 2))
				{
					retorno = 0;
					pArray[i] = bufferCensista;
					pArray[i].idCensista = idIncrementalCensista();
					pArray[i].isEmpty = 0;
					pArray[i].estadoCensista = 3; // liberado (que todavia no fue asignado a ninguna zona)
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
int idIncrementalCensista()
{
    static int idCensista = 100;
    idCensista++;
    return idCensista;
}

/** \brief muestra si una lista array tiene algo cargado (is.empty = 0)
*
* \param pArray[] Censista se ingresa una array de tipo Censista
* \param len int indica la longitud de la array
* \return int retorno un 0 si no hay nada cargado o un 1 si hay algo cargado
*/
int hayAlgoCargado(Censista pArray[], int len)
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

/** \brief imprime un censista
*
* \param element Censista se ingresa una variable tipo Censista
* \return void
*
*/
void mostrarCensista(Censista element)
{
	if (element.isEmpty == 0)
	{
		printf("Id: %d - Nombre: %s - Apellido: %s",element.idCensista,element.nombre,element.apellido);
		printf(" - Direccion: %s %d, %s - edad: %d", element.direccion.calle, element.direccion.altura, element.direccion.localidad, element.edad);
		printf(" - Fecha de nacimiento: %d/%d/%d - Estado %s\n",element.fechaNacimiento.dia,element.fechaNacimiento.mes,element.fechaNacimiento.anio,estadoCencistas[element.estadoCensista-1]);
	}
}

/** \brief imprime los elementos de una array Censista si esta ocupado
*
* \param pArray[] Censista se ingresa una array de Censista
* \param len int se ingresa la longitud de la array
* \return int retorna (-1) si hubo algun error o (0) si se pudo imprimir en pantalla
*
*/
int listarCensistas(Censista pArray[], int len)
{
	int retorno = -1;
	if (pArray != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			mostrarCensista(pArray[i]);
		}
		retorno = 0;
	}
	return retorno;
}

/** \brief busca un Censista por la array segun su id y retorna el index donde se encuentra
 *
* \param pArray[] Censista se ingresa una array de Censista
* \param len int  se ingresa la longitud de la array
* \param id int se ingresa el id del cencista solicitado
* \return int retorna un -1 si hubo algun error o el index del Censista solicitado
*
*/
int EncontrarCensistaPorId(Censista pArray[], int len,int id)
{
	int retorno = -1;
	if (pArray != NULL && len > 0 && id > 0)
	{
		for (int i = 0; i < len; i++)
		{
			if (pArray[i].idCensista == id && pArray[i].isEmpty == 0)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

/** \brief busca un Censista por la array segun su id y se modifica algun campo
* \param pArray[] Censista* se ingresa una array de Censista
* \param len int  se ingresa la longitud de la array
* \param idCencista int se ingresa el id del pasajero solicitado
* \return int retorna un (-1) si hubo algun error o (0) si se modifico correctamente
*
*/
int modificarCensista(Censista pArray[], int len, int idCencista)
{
	int retorno = -1;
	int opcionesBuffer;
	int opcionesBufferFecha;
	int opcionesBufferDireccion;
	int bufferIndex;

	if(pArray != NULL && len > 0 && idCencista > 0)
	{
		bufferIndex = EncontrarCensistaPorId(pArray, len, idCencista);
		if(bufferIndex > -1)
		{
			mostrarCensista(pArray[bufferIndex]);
			do{
				if(utn_getNumero(&opcionesBuffer, "Que campo quiere modificar?\nNombre[1] - Apellido[2] - Fecha de nacimiento[3] - Edad[4] - Direccion[5] - salir[6]\n",
									"Opcion no valida\n", 1, 6, 0) == 0)
							{
								switch(opcionesBuffer)
								{
								case 1:
									if(!utn_getNombre(pArray[bufferIndex].nombre, 125, "Ingrese nombre del censista\n", "Error, nombre invalido\n", 2))
									{
										retorno = 0;
									}
									break;
								case 2:
									if(!utn_getNombre(pArray[bufferIndex].apellido, 125, "Ingrese apellido del censista\n", "Error, apellido invalido\n", 2))
									{
										retorno = 0;
									}
									break;
								case 3:
									do
									{
										if(utn_getNumero(&opcionesBufferFecha, "Que campo quiere modificar?\nDia[1] - Mes[2] - Año[3] - Salir[4]\n",
												"Opcion no valida\n", 1, 4, 0) == 0)
										{
											switch(opcionesBufferFecha)
											{
											case 1:
												if(!utn_getNumero(&pArray[bufferIndex].fechaNacimiento.dia, "Ingrese el dia de nacimiento del censista\n", "Error, dia invalido\n", 1, 31, 2))
												{
													retorno = 0;
												}
												break;
											case 2:
												if(!utn_getNumero(&pArray[bufferIndex].fechaNacimiento.mes, "Ingrese el mes de nacimiento del censista\n", "Error, mes invalido\n", 1, 12, 2))
												{
													retorno = 0;
												}
												break;
											case 3:
												if(!utn_getNumero(&pArray[bufferIndex].fechaNacimiento.anio, "Ingrese año de nacimiento del censista\n", "Error, año invalido\n", 1903, 2021, 2))
												{
													retorno = 0;
												}
												break;
											}
										}
									}while(opcionesBufferFecha != 4);
									break;
								case 4:
									if(!utn_getNumero(&pArray[bufferIndex].edad, "Ingrese edad del censista\n", "Error, edad invalida\n", 1, 99, 2))
									{
										retorno = 0;
									}
									break;
								case 5:
									do
									{
										if(utn_getNumero(&opcionesBufferDireccion, "Que campo quiere modificar?\nCalle[1] - Altura[2] - Localidad[3] - Salir[4]\n",
												"Opcion no valida\n", 1, 4, 0) == 0)
										{
											switch(opcionesBufferDireccion)
											{
											case 1:
												if(!utn_getNombre(pArray[bufferIndex].direccion.calle, 125, "ingrese calle donde vive el censita\n", "Error, calle invalida\n", 2))
												{
													retorno = 0;
												}
												break;
											case 2:
												if(!utn_getNumero(&pArray[bufferIndex].direccion.altura, "Ingrese altura de la calle\n", "Error, altura invalida\n", 1, 10000, 2))
												{
													retorno = 0;
												}
												break;
											case 3:
												if(!utn_getNombre(pArray[bufferIndex].direccion.localidad, 125, "ingrese localidad donde vive el censita\n", "Error, localidad invalida\n", 2))
												{
													retorno = 0;
												}
												break;
											}
										}
									}while(opcionesBufferDireccion != 4);
									break;
								}
							}
			}while(opcionesBuffer != 6);
		}
	}
	return retorno;
}

/** \brief elimina a un Cencista ingresando su id
*
* \param list Cencista* se ingresa un array de Cencista
* \param len int indica la longitud de la array
* \param id int se ingresa el id del Cencista a eliminar
* \return int retorno un (-1) si hay algun error y (0) si funciono correctamente
*
*/
int bajaCensistas(Censista* list, int len, int id)
{
	int retorno = -1;
	int index;
	int opcionesBuffer;
	if(list != NULL && len > 0 && id > 0)
	{
		index = EncontrarCensistaPorId(list, len, id);

		if(index != -1 && list[index].estadoCensista == 3)
		{
			printf("Estas seguro de eliminar a: \n");
			mostrarCensista(list[index]);
			if(!utn_getNumero(&opcionesBuffer, "SI[1] - NO[2]\n", "Opcion no valida\n", 1, 2, 1))
			{
				if(opcionesBuffer == 1)
				{
					list[index].estadoCensista = 2; // ahora esta inactivo (ya no se le puede asignar a una zona nunca mas)
					retorno = 0;
				}

			}
		}

	}
	return retorno;
}

/** \brief imprime un censista si su estado es "liberado"
*
* \param element Censista se ingresa una variable tipo Censista
* \return void
*
*/
void mostrarCensistaLiberado(Censista element)
{
	if (element.isEmpty == 0 && element.estadoCensista == 3)
	{
		printf("Id: %d - Nombre: %s - Apellido: %s",element.idCensista,element.nombre,element.apellido);
		printf(" - Direccion: %s %d, %s - edad: %d", element.direccion.calle, element.direccion.altura, element.direccion.localidad, element.edad);
		printf(" - Fecha de nacimiento: %d/%d/%d - Estado %s\n",element.fechaNacimiento.dia,element.fechaNacimiento.mes,element.fechaNacimiento.anio,estadoCencistas[element.estadoCensista-1]);
	}
}

/** \brief imprime los elementos de una array Censista si esta ocupado
*
* \param pArray[] Censista se ingresa una array de Censista
* \param len int se ingresa la longitud de la array
* \return int retorna (-1) si hubo algun error o (0) si se pudo imprimir en pantalla
*
*/
int listarCensistasLiberados(Censista pArray[], int len)
{
	int retorno = -1;
	if (pArray != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			mostrarCensistaLiberado(pArray[i]);
		}
		retorno = 0;
	}
	return retorno;
}

/** \brief muestra si una lista array tiene algun censista liberado (.estadoCensista = 3)
*
* \param pArray[] Censista se ingresa una array de tipo Censista
* \param len int indica la longitud de la array
* \return int retorno un 0 si no hay nada cargado o un 1 si hay algo cargado
*
*/
int hayCensistaLiberado(Censista pArray[], int len)
{
	int retorno = 0;
	if (pArray != NULL && len > 0)
	{
		for (int i = 0; i < len; i++)
		{
			if (pArray[i].isEmpty == 0 && pArray[i].estadoCensista == 3)
			{
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}

/** \brief carga datos a una array de censistas (isEmpty = 1)
*
* \param pArray[] Censista* se ingresa una arry del tipo Censista
* \param len int se ingresa la longitud del array
* \param nombre[] char se ingresa el nombre del censista
* \param apellido[] char se ingresa el apellido del censista
* \param calle[] char se ingresa la calle donde vive el censista
* \param altura int se ingresa la altura de la calle
* \param localidad[] char se ingresa la localidad donde vive el censista
* \param edad int se ingresa la edad del censista
* \param dia int se ingresa el dia de su fecha de nacimiento
* \param mes int se ingresa  el mes de su fecha de nacimiento
* \param anio int se ingresa  el año de su fecha de nacimiento
* \return int retorna un (-1) si hubo un error o (0) si se pudo cargar correctamente
*
*/
int cargarCensistaForzado(Censista pArray[], int len, char nombre[], char apellido[], char calle[], int altura, char localidad[],
		int edad, int dia , int mes, int anio)
{
	int retorno = -1;
	int i;
	if (pArray != NULL && len > 0)
	{
		for(i = 0; i < len; i++)
		{
			if(pArray[i].isEmpty == 1 )
			{
				retorno = 0;
				strcpy(pArray[i].nombre,nombre);
				strcpy(pArray[i].apellido,apellido);
				strcpy(pArray[i].direccion.calle,calle);
				pArray[i].direccion.altura = altura;
				strcpy(pArray[i].direccion.localidad,localidad);
				pArray[i].edad = edad;
				pArray[i].fechaNacimiento.dia = dia;
				pArray[i].fechaNacimiento.mes = mes;
				pArray[i].fechaNacimiento.anio = anio;
				pArray[i].idCensista = idIncrementalCensista();
				pArray[i].isEmpty = 0;
				pArray[i].estadoCensista = 3; // liberado (que todavia no fue asignado a ninguna zona)
				break;
			}
		}
	}
	return retorno;
}
