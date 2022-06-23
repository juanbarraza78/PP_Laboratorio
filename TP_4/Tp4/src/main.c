#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "utn.h"
#include "informes.h"

int main()
{
	setbuf(stdout, NULL);
	LinkedList* listaPasajeros = ll_newLinkedList();
	int opciones;
	int cantidadGuardada;
	int flagSave = 0;
	int flagCerrar = 0;

	int acomulardor = 0;
	LinkedList* listaPasajerosAuxiliar;

	do
	{
		flagCerrar = 0;
		printf("\n ---Menu---\n");
		printf("1) CARGAR DATOS(MODO TEXTO)\n");
		printf("2) CARGAR DATOS(MODO BINARIO)\n");
		printf("3) ALTA\n");
		printf("4) MODIFICAR\n");
		printf("5) BAJA\n");
		printf("6) LISTAR\n");
		printf("7) ORDENAR\n");
		printf("8) GUARDAR DATOS(MODO TEXTO)\n");
		printf("9) GUARDAR DATOS(MODO BINARIO)\n");
		printf("10) PASAJEROS POR CLASE\n");
		printf("11) GENERAR Y MOSTRAR ARCHIVO DE VUELOS\n");
		printf("12) CALCULAR MILLAS ACUMULADAS\n");
		printf("13) SALIR\n\n");
		if(!utn_getNumero(&opciones, "Ingrese una opcion\n", "Error, Opcion invalida\n", 1, 13, 0))
		{
			switch(opciones)
			{
			case 1:
				controller_loadFromText("data.csv", listaPasajeros);
				break;
			case 2:
				controller_loadFromBinary("dataBinario.csv", listaPasajeros);
				break;
			case 3:
				if(!controller_addPassenger(listaPasajeros))
				{
					printf("add ok\n");
				}
				break;
			case 4:
				if(ll_isEmpty(listaPasajeros) == 0)
				{
					if(!controller_editPassenger(listaPasajeros))
					{
						printf("modificar ok\n");
					}
				}
				else
				{
					printf("No hay nada guardado\n");
				}

				break;
			case 5:
				if(ll_isEmpty(listaPasajeros) == 0)
				{
					if(!controller_removePassenger(listaPasajeros))
					{
						printf("remove ok\n");
					}
				}
				else
				{
					printf("No hay nada guardado\n");
				}

				break;
			case 6:
				if(ll_isEmpty(listaPasajeros) == 0)
				{
					controller_ListPassenger(listaPasajeros);
				}
				else
				{
					printf("No hay nada guardado\n");
				}
				break;
			case 7:
				if(ll_isEmpty(listaPasajeros) == 0)
				{
					controller_sortPassenger(listaPasajeros);
				}
				else
				{
					printf("No hay nada guardado\n");
				}
				break;
			case 8:
				if(ll_isEmpty(listaPasajeros) == 0)
				{
					cantidadGuardada = controller_saveAsText("data.csv", listaPasajeros);
					if(cantidadGuardada >= 0)
					{
						printf("se pudo guardar correctamente %d elementos\n", cantidadGuardada);
						flagSave = 1;
					}
				}
				else
				{
					printf("No hay nada guardado\n");
				}
				break;
			case 9:
				if(ll_isEmpty(listaPasajeros) == 0)
				{
					cantidadGuardada = controller_saveAsBinary("dataBinario.csv", listaPasajeros);
					if(cantidadGuardada >= 0)
					{
						printf("se pudo guardar correctamente %d elementos\n", cantidadGuardada);
						flagSave = 1;
					}
				}
				else
				{
					printf("No hay nada guardado\n");
				}
				break;
			case 10:
				if(!ll_isEmpty(listaPasajeros))
				{
					acomulardor = ll_count(listaPasajeros, Passenger_acomularEconomico);
					if(acomulardor > 0)
					{
						printf("La cantidad de pasajeros de clase economica son: %d\n",acomulardor);
					}
					acomulardor = ll_count(listaPasajeros, Passenger_acomularEjecutivo);
					if(acomulardor > 0)
					{
						printf("La cantidad de pasajeros de clase ejecutiva son: %d\n",acomulardor);
					}
					acomulardor = ll_count(listaPasajeros, Passenger_acomularPrimera);
					if(acomulardor > 0)
					{
						printf("La cantidad de pasajeros de primera clase son: %d\n",acomulardor);
					}
				}
				else
				{
					printf("No hay nada guardado\n");
				}
				break;
			case 11:
				if(!ll_isEmpty(listaPasajeros))
				{
					listaPasajerosAuxiliar = ll_filter(listaPasajeros, Passenger_filtrarTipoPasageroFirstClass);
					if(listaPasajerosAuxiliar != NULL)
					{
						controller_ListPassenger(listaPasajerosAuxiliar);
						controller_saveAsText("auxiliar.csv", listaPasajerosAuxiliar);
					}
				}
				else
				{
					printf("No hay nada guardado\n");
				}
				break;
			case 12:
				if(!ll_isEmpty(listaPasajeros))
				{
					ll_map(listaPasajeros, Passenger_imprimirConMIllas);
				}
				else
				{
					printf("No hay nada guardado\n");
				}
				break;
			case 13:
				flagCerrar = 1;
				break;
			}
		}
	}while(!(flagCerrar == 1 && flagSave == 1));
	return EXIT_SUCCESS;
}


