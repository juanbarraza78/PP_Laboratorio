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

int idIncrementalCensista()
{
    static int idCensista = 100;
    idCensista++;
    return idCensista;
}

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

void mostrarCensista(Censista element)
{
	if (element.isEmpty == 0)
	{
		printf("Id: %d - Nombre: %s - Apellido: %s",element.idCensista,element.nombre,element.apellido);
		printf(" - Direccion: %s %d, %s - edad: %d", element.direccion.calle, element.direccion.altura, element.direccion.localidad, element.edad);
		printf(" - Fecha de nacimiento: %d/%d/%d - Estado %s\n",element.fechaNacimiento.dia,element.fechaNacimiento.mes,element.fechaNacimiento.anio,estadoCencistas[element.estadoCensista-1]);
	}
}

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
			printf("Estas seguro de eliminar a: ");
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

void mostrarCensistaLiberado(Censista element)
{
	if (element.isEmpty == 0 && element.estadoCensista == 3)
	{
		printf("Id: %d - Nombre: %s - Apellido: %s",element.idCensista,element.nombre,element.apellido);
		printf(" - Direccion: %s %d, %s - edad: %d", element.direccion.calle, element.direccion.altura, element.direccion.localidad, element.edad);
		printf(" - Fecha de nacimiento: %d/%d/%d - Estado %s\n",element.fechaNacimiento.dia,element.fechaNacimiento.mes,element.fechaNacimiento.anio,estadoCencistas[element.estadoCensista-1]);
	}
}

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
