/*
 * C
 */

#include "utn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * NUMEROS INT
 */

/** \brief se pide al usuario algun dato y lo guarda en un array de caracteres
* \param cadena[] char se ingresa un array donde se guarda lo solicitado
* \param longitud int longitud del array
* \return int retorna un (-1) si hubo un error o (0) si esta ok*
*/
int myGets(char cadena[], int longitud)
{
	int retorno = -1;
	char bufferString[256];
	if(cadena != NULL && longitud > 0)
	{
		setbuf(stdout, NULL);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString)) - 1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString)) - 1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena,bufferString,longitud);
				retorno = 0;
			}
		}
	}
	return retorno;
}

/** \brief pide un numero entero y se lo guarda en una variable si esta entre un rango determinado
* \param pResultado int* array donde se guarda el numero entero
* \param mensaje[] char se ingresa el mensaje para pedir el numero entero
* \param mensajeError[] char se ingresa el mensaje en caso de error
* \param minimo int extremo inferior del rango
* \param maximo int extremo superior del rango
* \param reintentos int se ingresa la cantidad de intentos que tiene el usuario
* \return int retorna un (-1) si hubo un error o (0) si esta ok*
*/
int utn_getNumero(int *pResultado, char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;
	do
	{
		printf("%s",mensaje);
		if(getInt(&bufferInt) == 0 && bufferInt >= minimo && bufferInt <= maximo)
		{
			retorno = 0;
			*pResultado = bufferInt;
			break;
		}
		else
		{
			printf("%s",mensajeError);
		}
		reintentos --;
	}while(reintentos >= 0);
	return retorno;
}

/** \brief se ingresa una cadena y lo convierte en un entero
* \param pResultado int* variable donde se guarda el entero
* \return int retorna un (-1) si hubo un error o (0) si esta ok*
*/
int getInt(int* pResultado)
{
	int retorno = -1;
	char bufferString[50];

	if(pResultado != NULL &&
			myGets(bufferString,sizeof(bufferString)) == 0 &&
			esNumerica(bufferString,sizeof(bufferString)) == 1)
	{
		retorno = 0;
		*pResultado = atoi(bufferString);
	}

	return retorno;
}

/** \brief verifica si una cadena de caracteres es un entero
* \param cadena char* se ingresa la cadena a verificar
* \param limite int se ingresa la longitud de la cadena
*\\return int retorna un (1) si es verdadero (0) si es falso
*/
int esNumerica(char* cadena, int limite)
{
	int retorno = 1;
	if(cadena != NULL)
	{
		for(int i = 0; i<limite && cadena[i] != '\0'; i++ )
		{
			if(cadena[0] == '-' || cadena[0] == '+')
			{
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}


/*
 * NUMEROS FLOAT
 */
/** \brief pide un numero flotante y se lo guarda en una variable si esta entre un rango determinado
* \param pResultado int* array donde se guarda el numero flotante
* \param mensaje[] char se ingresa el mensaje para pedir el numero flotante
* \param mensajeError[] char se ingresa el mensaje en caso de error
* \param minimo float extremo inferior del rango
* \param maximo float extremo superior del rango
* \param reintentos int se ingresa la cantidad de intentos que tiene el usuario
* \return int retorna un (-1) si hubo un error o (0) si esta ok*
*/
int utn_getNumeroFlotante(float *pResultado, char mensaje[], char mensajeError[], float minimo, float maximo, int reintentos)
{
	int retorno = -1;
	float bufferfloat;
	do
	{
		printf("%s",mensaje);
		if(getFloat(&bufferfloat) == 0 && bufferfloat >= minimo && bufferfloat <= maximo)
		{
			retorno = 0;
			*pResultado = bufferfloat;
			break;
		}
		else
		{
			printf("%s",mensajeError);
		}
		reintentos --;
	}while(reintentos >= 0);
	return retorno;
}

/** \brief se ingresa una cadena y lo convierte en un numero flotante
* \param pResultado float* variable donde se guarda el numero flotante
* \return int retorna un (-1) si hubo un error o (0) si esta ok*
*/
int getFloat(float* pResultado)
{
	int retorno = -1;
	char bufferString[50];

	if(pResultado != NULL &&
			myGets(bufferString,sizeof(bufferString)) == 0 &&
			esNumeroFlotante(bufferString,sizeof(bufferString)) == 1)
	{
		retorno = 0;
		*pResultado = atof(bufferString);
	}
	return retorno;
}

/** \brief verifica si una cadena de caracteres es un numero flotante
* \param cadena char* se ingresa la cadena a verificar
* \param limite int se ingresa la longitud de la cadena
*\return int retorna un (1) si es verdadero (0) si es falso
*/
int esNumeroFlotante(char* cadena, int limite)
{
	int retorno = 1;
	int contadorComa = 0;
	if(cadena != NULL)
	{
		for(int i = 0; i<limite && cadena[i] != '\0'; i++ )
		{
			if(cadena[0] == '-' || cadena[0] == '+')
			{
				continue;
			}
			if(cadena[i] == '.')
			{
				contadorComa++;
				if(contadorComa >= 2)
				{
					retorno = 0;
					break;
				}
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/*
 * EMAIL
 */

/** \brief pide un mail y se guarda en un array
* \param email[] array donde se guarda el mail
* \param len longitud del array mail
* \param mensaje[] char se ingresa el mensaje para pedir el mail
* \param mensajeError[] char se ingresa el mensaje en caso de error
* \param reintentos int se ingresa la cantidad de intentos que tiene el usuario
* \return int retorna un (-1) si hubo un error o (0) si esta ok*
*/
int utn_getEmail(char email[], int len, char mensaje[], char mensajeError[], int reintentos)
{
	int retorno = -1;
	char bufferString[256];
	do
		{
			printf("%s",mensaje);
			if(getEmail(bufferString,sizeof(bufferString)) == 0)
			{
				strncpy(email,bufferString,len);
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
			}
			reintentos --;
		}while(reintentos >= 0);
	return retorno;
}

/** \brief pide un mail , lo verifica y luego lo guarda en un array
* \param email[] char se ingresa un array de caracteres
* \param len int se ingresa la longitud del array
* \return int retorna un (-1) si hubo un error o (0) si esta ok*
*/
int getEmail(char email[], int len)
{
	int retorno = -1;
	char bufferString[256];

	if(email != NULL &&
			len > 0 &&
			myGets(bufferString,sizeof(bufferString)) == 0 &&
			esMail(bufferString,sizeof(bufferString)) == 1 )
	{
		retorno = 0;
		strncpy(email,bufferString,len);
	}
	return retorno;
}

/** \brief verifica si una cadena de caracteres es un mail
* \param cadena char* se ingresa la cadena a verificar
* \param limite int se ingresa la longitud de la cadena
*\return int retorna un (1) si es verdadero (0) si es falso
*/
int esMail(char* cadena, int limite)
{
	int retorno = 1;
	int contadorArobas = 0;
	if(cadena != NULL && limite > 0)
	{
		for(int i = 0; i<limite && cadena[i] != '\0'; i++ )
		{
			if(cadena[i] == '@')
			{
				contadorArobas++;
				if(contadorArobas>1)
				{
					retorno = 0;
					break;
				}
			}
			if((cadena[i] < 'a' || cadena[i] > 'z') &&
					(cadena[i] < 'A' || cadena[i] > 'Z') &&
					(cadena[i] < '0' || cadena[i] > '9') &&
					cadena[i] !='.' &&
					cadena[i] !='@' &&
					cadena[i] !='_' &&
					cadena[i] !='-' )
			{
				retorno = 0;
				break;
			}

		}
	}
	return retorno;
}
/*
 * NOMBRE
 */
/** \brief pide un nombre y se guarda en un array
* \param nombre[] array donde se guarda el nombre
* \param len longitud del array nombre
* \param mensaje[] char se ingresa el mensaje para pedir el nombre
* \param mensajeError[] char se ingresa el mensaje en caso de error
* \param reintentos int se ingresa la cantidad de intentos que tiene el usuario
* \return int retorna un (-1) si hubo un error o (0) si esta ok*
*/
int utn_getNombre(char nombre[], int len, char mensaje[], char mensajeError[], int reintentos)
{
	int retorno = -1;
	char bufferString[256];
	do
		{
			printf("%s",mensaje);
			if(getNombre(bufferString,sizeof(bufferString)) == 0)
			{
				strncpy(nombre,bufferString,len);
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
			}
			reintentos --;
		}while(reintentos >= 0);
	return retorno;
}

/** \brief pide un nombre , lo verifica y luego lo guarda en un array
* \param nombre[] char se ingresa un array de caracteres
* \param len int se ingresa la longitud del array
* \return int retorna un (-1) si hubo un error o (0) si esta ok*
*/
int getNombre(char nombre[], int len)
{
	int retorno = -1;
	char bufferString[256];

	if(nombre != NULL &&
			len > 0 &&
			myGets(bufferString,sizeof(bufferString)) == 0 &&
			esNombre(bufferString,sizeof(bufferString)) == 1 )
	{
		retorno = 0;
		strncpy(nombre,bufferString,len);
	}
	return retorno;
}

/** \brief verifica si una cadena de caracteres es un nombre
* \param cadena char* se ingresa la cadena a verificar
* \param limite int se ingresa la longitud de la cadena
*\return int retorna un (1) si es verdadero (0) si es falso
*/
int esNombre(char* cadena, int limite)
{
	int retorno = 1;
	if(cadena != NULL && limite > 0)
	{
		for(int i = 0; i<limite && cadena[i] != '\0'; i++ )
		{
			if((cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z') && cadena[i] != ' ' && cadena[i] != 'ñ' && cadena[i] != 'Ñ' &&
					cadena[i] != 'á' && cadena[i] != 'é' && cadena[i] != 'í' && cadena[i] != 'ó' && cadena[i] != 'ú' &&
					cadena[i] != 'Á' && cadena[i] != 'É' && cadena[i] != 'Í' && cadena[i] != 'Ó' && cadena[i] != 'Ú')
			{
				retorno = 0;
				break;
			}

		}
	}
	return retorno;
}

/*
 * CODIGO
 */

/** \brief pide un codigo que puede ser alfanumerico
* \param codigo[] array donde se guarda el codigo
* \param len longitud del array codigo
* \param mensaje[] char se ingresa el mensaje para pedir el codigo
* \param mensajeError[] char se ingresa el mensaje en caso de error
* \param reintentos int se ingresa la cantidad de intentos que tiene el usuario
* \return int retorna un (-1) si hubo un error o (0) si esta ok*
*/
int utn_getCodigo(char codigo[], int len, char mensaje[], char mensajeError[], int reintentos)
{
	int retorno = -1;
	char bufferString[256];
	do
		{
			printf("%s",mensaje);
			if(getCodigo(bufferString,sizeof(bufferString)) == 0)
			{
				strncpy(codigo,bufferString,len);
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
			}
			reintentos --;
		}while(reintentos >= 0);
	return retorno;
}

/** \brief pide un codigo , lo verifica y luego lo guarda en un array
* \param codigo[] char se ingresa un array de caracteres
* \param len int se ingresa la longitud del array
* \return int retorna un (-1) si hubo un error o (0) si esta ok*
*/
int getCodigo(char codigo[], int len)
{
	int retorno = -1;
	char bufferString[256];

	if(codigo != NULL &&
			len > 0 &&
			myGets(bufferString,sizeof(bufferString)) == 0 &&
			esCodigo(bufferString,sizeof(bufferString)) == 1 )
	{
		retorno = 0;
		strncpy(codigo,bufferString,len);
	}
	return retorno;
}

/** \brief verifica si una cadena de caracteres es un codigo
* \param cadena char* se ingresa la cadena a verificar
* \param limite int se ingresa la longitud de la cadena
*\return int retorna un (1) si es verdadero (0) si es falso
*/
int esCodigo(char* cadena, int limite) // alfa numerico y se le permite espacio
{
	int retorno = 1;
	if(cadena != NULL && limite > 0)
	{
		for(int i = 0; i<limite && cadena[i] != '\0'; i++ )
		{
			if((cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i] < '0' || cadena[i] > '9') && cadena[i] != ' ')
			{
				retorno = 0;
				break;
			}

		}
	}
	return retorno;
}

/** \brief pide un path que puede ser alfanumerico
* \param path[] array donde se guarda el codigo
* \param len longitud del array codigo
* \param mensaje[] char se ingresa el mensaje para pedir el codigo
* \param mensajeError[] char se ingresa el mensaje en caso de error
* \param reintentos int se ingresa la cantidad de intentos que tiene el usuario
* \return int retorna un (-1) si hubo un error o (0) si esta ok*
*/
int utn_getPath(char path[], int len, char mensaje[], char mensajeError[], int reintentos)
{
	int retorno = -1;
	char bufferString[256];
	do
		{
			printf("%s",mensaje);
			if(esPath(bufferString,sizeof(bufferString)) == 0)
			{
				strncpy(path,bufferString,len);
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
			}
			reintentos --;
		}while(reintentos >= 0);
	return retorno;
}

/** \brief pide un path , lo verifica y luego lo guarda en un array
* \param path[] char se ingresa un array de caracteres
* \param len int se ingresa la longitud del array
* \return int retorna un (-1) si hubo un error o (0) si esta ok*
*/
int getPath(char path[], int len)
{
	int retorno = -1;
	char bufferString[256];

	if(path != NULL &&
			len > 0 &&
			myGets(bufferString,sizeof(bufferString)) == 0 &&
			esPath(bufferString,sizeof(bufferString)) == 1 )
	{
		retorno = 0;
		strncpy(path,bufferString,len);
	}
	return retorno;
}

/** \brief verifica si una cadena de caracteres es un path
* \param path char* se ingresa la cadena a verificar
* \param limite int se ingresa la longitud de la cadena
*\return int retorna un (1) si es verdadero (0) si es falso
*/
int esPath(char* cadena, int limite) // alfa numerico y permite .
{
	int retorno = 1;
	int contadorComa = 0;
	if(cadena != NULL && limite > 0)
	{
		for(int i = 0; i<limite && cadena[i] != '\0'; i++ )
		{
			if(cadena[i] == '.')
			{
				contadorComa++;
				if(contadorComa >= 2)
				{
					retorno = 0;
					break;
				}
				continue;
			}
			if((cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i] < '0' || cadena[i] > '9') && cadena[i] != '/')
			{
				retorno = 0;
				break;
			}

		}
	}
	return retorno;
}
