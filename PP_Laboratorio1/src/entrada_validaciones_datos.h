/*
 * H
 */

#ifndef ENTRADA_VALIDACIONES_DATOS_H_
#define ENTRADA_VALIDACIONES_DATOS_H_

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

int esNombre(char* cadena, int limite);
int getNombre(char nombre[], int len);
int utn_getNombre(char nombre[], int len, char mensaje[], char mensajeError[], int reintentos);

int getCodigo(char codigo[], int len);
int esCodigo(char* cadena, int limite);
int utn_getCodigo(char codigo[], int len, char mensaje[], char mensajeError[], int reintentos);

#endif
