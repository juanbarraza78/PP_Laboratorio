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
		printf("9) Salir.\n");
		if(!utn_getNumero(&opciones, "Ingrese una opcion\n", "Error, No existe esa opcion\n", 1, 9, 0))
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
				// los censistas tienen que estar liberados y las zonas no tienen que estar asignadas (dniCensistas != -1) y tienen que estar en pendiente
				break;
			case 6:
				printf("Opcion 6: \n");
				break;
			case 7:
				listarCensistas(censistas, LEN_CENSISTAS);
				break;
			case 8:
				printf("Opcion 8: \n");
				break;
			}
		}
	}while(opciones != 9);
	return EXIT_SUCCESS;
}
