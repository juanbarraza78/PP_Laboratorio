/*
 * Informes.h
 *
 *  Created on: 19 may. 2022
 *      Author: juanb
 */

#ifndef INFORMES_H_
#define INFORMES_H_

int MostrarCantidadDeCensitasEnEstadoActivoYZonaPendiente(Zona pArrayZona[], int lenZona,Censista pArrayCensista[], int lenCensista);
int MostrarCensitasDeEtc(Zona pArrayZona[], int lenZona,Censista pArrayCensista[], int lenCensista);
int ordenarCensistas(Censista* list, int len, int order);
int InformarLocalidadMayorCasasAusentes(Zona pArrayZona[], int lenZona);
int InformarCensistaCuyaEsLaZonaMasCensada(Zona pArrayZona[], int lenZona,Censista pArrayCensista[], int lenCensista);

#endif /* INFORMES_H_ */
