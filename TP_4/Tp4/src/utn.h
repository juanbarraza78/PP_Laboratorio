/*
 * H
 */

#ifndef UTN_H_
#define UTN_H_

int myGets(char cadena[], int longitud);

int getInt(int* pResultado);
int esNumerica(char* cadena, int limite);
int utn_getNumero(int *pResultado, char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos);

int getFloat(float* pResultado);
int esNumeroFlotante(char* cadena, int limite);
int utn_getNumeroFlotante(float *pResultado, char mensaje[], char mensajeError[], float minimo, float maximo, int reintentos);

int getEmail(char email[], int len);
int esMail(char* cadena, int limite);
int utn_getEmail(char email[], int len, char mensaje[], char mensajeError[], int reintentos);

int getNombre(char nombre[], int len);
int esNombre(char* cadena, int limite);
int utn_getNombre(char nombre[], int len, char mensaje[], char mensajeError[], int reintentos);

int getCodigo(char codigo[], int len);
int esCodigo(char* cadena, int limite);
int utn_getCodigo(char codigo[], int len, char mensaje[], char mensajeError[], int reintentos);

int utn_getPath(char path[], int len, char mensaje[], char mensajeError[], int reintentos);
int getPath(char path[], int len);
int esPath(char* cadena, int limite);

#endif
