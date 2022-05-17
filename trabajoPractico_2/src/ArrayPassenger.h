/*
 * H
 */
#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

typedef struct {
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[20];
	int typePassenger;
	int statusFlight;
	int isEmpty;
} Passenger;

int initPassengers(Passenger* list, int len);
int addPassengerForzado(Passenger pArray[], int len,int* id,char name[],char lastname[], float price,char flyCode[],int typePassenger, int statusFlight);
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[], int statusFlight);
int utn_getDatosPassager(int* id, char name[],int lenName, char lastName[],int lenLastName, float* price, int* typePassanger, char flyCode[], int lenFlyCode, int* statusFlight);
void mostrarPassenger(Passenger pasajero);
int printPassengers(Passenger pArray[], int len);
int modificarPasajero(Passenger pArray[], int len, int idPassenger);
int findPassengerById(Passenger* list, int len,int id);
int removePassenger(Passenger* list, int len, int id);
int hayAlgoCargado(Passenger pArray[], int len);
int sortPassengers(Passenger* list, int len, int order);
int sortPassengersByCode(Passenger* list, int len, int order);
int MostrarPromedioYTotalDePrecioPasajeros(Passenger* list, int len);
int filtrarYMostrarPorStatusVuelo(Passenger* list, int len);

#endif
