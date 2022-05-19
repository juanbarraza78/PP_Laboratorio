/*
 ============================================================================
 Name        : PP_Laboratorio1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "entrada_validaciones_datos.h"
#include "Censista.h"
#include "Zona.h"
#include "Direccion.h"
#include "FechaDeNacimiento.h"
#include "Informes.h"

#define LEN_CENSISTAS 10
#define LEN_ZONAS 10

int main(void) {
	setbuf(stdout, NULL);
	int opciones;
	int bufferId;
	Censista censistas[LEN_CENSISTAS];
	Zona zonas[LEN_ZONAS];

	inicializarCensistas(censistas, LEN_CENSISTAS);
	inicializarZonas(zonas, LEN_ZONAS);

	do{
		printf("\n ---------Menu---------\n");
		printf("1) Cargar censista: \n");
		printf("2) Modificar censista: \n");
		printf("3) Dar de baja censista: \n");
		printf("4) Cargar zona: \n");
		printf("5) Asignar zona a censar: \n");
		printf("6) Carga de datos: \n");
		printf("7) Mostrar censistas: \n");
		printf("8) Mostrar zonas: \n");
		printf("9) Carga FORZADA.\n");
		printf("10) Informar: Cantidad de censistas en estado Activo con zona Pendiente\n");
		printf("11) Informar: Censistas de Avellaneda, Lanús, Lomas de Zamora o Banfield ordenados alfabéticamente por apellido y nombre\n");
		printf("12) Informar: Nombre de localidad con más casas ausentes\n");
		printf("13) Informar: El censista cuya zona fue la más censada\n");
		printf("14) Informar: el promedio de censos por censista/zona\n");
		printf("15) Salir.\n");
		if(!utn_getNumero(&opciones, "Ingrese una opcion\n", "Error, No existe esa opcion\n", 1, 15, 0))
		{
			switch(opciones)
			{
			case 1:
				if(!CargarCensista(censistas, LEN_CENSISTAS))
				{
					printf("Se cargo correctamente\n");
				}
				else
				{
					printf("No se cargo correctamente\n");
				}
				break;
			case 2:
				if(hayAlgoCargado(censistas, LEN_CENSISTAS) == 1)
				{
					listarCensistas(censistas, LEN_CENSISTAS);
					if(!utn_getNumero(&bufferId, "\nIngrese el id del censista que quiere modificar\n", "Error, id invalido\n", 1, 10000, 0) &&
							!modificarCensista(censistas, LEN_CENSISTAS, bufferId))
					{
						printf("Se pudo modificar correctamente\n");
					}
					else
					{
						printf("No se pudo modificar correctamente\n");
					}
				}
				else
				{
					printf("No hay nada cargado\n");
				}
				break;
			case 3:
				if(hayCensistaLiberado(censistas, LEN_CENSISTAS) == 1)
				{
					listarCensistasLiberados(censistas, LEN_CENSISTAS);
					if(!utn_getNumero(&bufferId, "\nIngrese el id del censista que quiere dar de baja\n", "Error, id invalido\n", 1, 10000, 0) &&
							!bajaCensistas(censistas, LEN_CENSISTAS, bufferId))
					{
						printf("Se pudo dar de baja correctamente\n");
					}
					else
					{
						printf("No se pudo dar de baja correctamente\n");
					}
				}
				else
				{
					printf("No hay nada ningun censista liberado\n");
				}
				break;
			case 4:
				if(!cargarZonas(zonas, LEN_ZONAS))
				{
					printf("Se cargo la zona correctamente\n");
				}
				else
				{
					printf("No se cargo la zona correctamente\n");
				}
				break;
			case 5:
				if(hayCensistaLiberado(censistas, LEN_CENSISTAS) == 1 && hayZonaPendienteYSinAsignar(zonas, LEN_ZONAS) == 1)
				{
					if(!asignarZonaACensista(zonas, LEN_ZONAS, censistas, LEN_CENSISTAS))
					{
						printf("Se asignaron correctamente la zona y el censista\n");
					}
					else
					{
						printf("No se asignaron correctamente la zona y el censista\n");
					}

				}
				else
				{
					printf("Faltan datos\n");
				}
				break;
			case 6:
				if(hayZonaPendienteYAsignadas(zonas, LEN_ZONAS) == 1)
				{
					if(!finalizarZonas(zonas, LEN_ZONAS, censistas, LEN_CENSISTAS))
					{
						printf("Se finalizo correctamente la zona\n");
					}
					else
					{
						printf("No se finalizo correctamente la zona\n");
					}
				}
				else
				{
					printf("Faltan datos\n");
				}
				break;
			case 7:
				if(hayAlgoCargado(censistas, LEN_CENSISTAS))
				{
					listarCensistas(censistas, LEN_CENSISTAS);
				}
				else
				{
					printf("No se cargo ningun censista\n");
				}

				break;
			case 8:
				if(hayZona(zonas, LEN_ZONAS) == 1)
				{
					listarTodosLosTiposDeZonas(zonas, LEN_ZONAS, censistas, LEN_CENSISTAS);
				}
				else
				{
					printf("No se cargo ninguna zona\n");
				}
				break;
			case 9:
				if(!cargarCensistaForzado(censistas, LEN_CENSISTAS, "Nombre1", "Apellido", "Calle", 11, "Localidad", 22, 12, 12, 1999) &&
						!cargarCensistaForzado(censistas, LEN_CENSISTAS, "Nombre2", "Bpellido", "Calle", 20, "Localidad", 19, 11, 12, 2000) &&
						!cargarCensistaForzado(censistas, LEN_CENSISTAS, "Nombre3", "Cpellido", "Calle", 30, "Localidad", 18, 11, 12, 1980) &&
						!cargarCensistaForzado(censistas, LEN_CENSISTAS, "Nombre4", "Dpellido", "Calle", 40, "Localidad", 30, 9, 12, 1990) &&
						!cargarCensistaForzado(censistas, LEN_CENSISTAS, "Nombre5", "Epellido", "Calle", 50, "Localidad", 22, 10, 12, 1970) &&
						!cargarCensistaForzado(censistas, LEN_CENSISTAS, "Nombre6", "Fpellido", "Calle", 60, "Localidad", 23, 10, 12, 1975) &&
						!cargarZonasForzada(zonas, LEN_ZONAS, "Calle1", "Calle2", "Calle3", "Calle4", 2) &&
						!cargarZonasForzada(zonas, LEN_ZONAS, "Dalle1", "Dalle2", "Calle3", "Calle4", 1) &&
						!cargarZonasForzada(zonas, LEN_ZONAS, "Ealle1", "Ealle2", "Calle3", "Calle4", 3) &&
						!cargarZonasForzada(zonas, LEN_ZONAS, "Falle1", "Falle2", "Calle3", "Calle4", 5) &&
						!cargarZonasForzada(zonas, LEN_ZONAS, "Galle1", "Galle2", "Calle3", "Calle4", 4))
				{
					printf("Carga forzada exitosa\n");
				}
				break;
			case 10:
				MostrarCantidadDeCensitasEnEstadoActivoYZonaPendiente(zonas, LEN_ZONAS, censistas, LEN_CENSISTAS);
				break;
			case 11:
				MostrarCensitasDeEtc(zonas, LEN_ZONAS, censistas, LEN_CENSISTAS);
				break;
			case 12:
				InformarLocalidadMayorCasasAusentes(zonas, LEN_ZONAS);
				break;
			case 13:
				InformarCensistaCuyaEsLaZonaMasCensada(zonas, LEN_ZONAS, censistas, LEN_CENSISTAS);
				break;
			case 14:
				break;
			}
		}
	}while(opciones != 15);
	return EXIT_SUCCESS;
}
