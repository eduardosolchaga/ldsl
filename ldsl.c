//
// gcc ldsl.c -o ldsl
// ./ldsl

#include <stdio.h>
#include <stdlib.h>

#include "ldsl.h"

enum opcion {NONE = 0, INS_INI, INS_ANT, INS_DES, INS_FIN, ELI, BUS, IMP, SALIR = 8};

int menu (void)
{
	char opcion [10];

	printf("Lista Dinámica Simplemente Ligada.\n");
	printf("==================================\n");
	printf(" 1. Insertar al inicio.\n");
	printf(" 2. Insertar antes de ...\n");
	printf(" 3. Insertar despues de ...\n");
	printf(" 4. Insertar al final.\n");
	printf(" 5. Eliminar ...\n");
	printf(" 6. Buscar ...\n");
	printf(" 7. Imprimir lista.\n");
	printf(" 8. Salir.\n\n");
	printf("Opcion: ");

	scanf ("%s", opcion);

	return atoi (opcion);
}



int main (int argc, char *argv[])
{
	struct nodo *lista = NULL;
	struct nodo *nodo = NULL;
	int id = 0;
	int cual;
	enum opcion opcion;

	system ("reset");
	do
	{
		opcion = menu ();
		switch (opcion)
		{
			case INS_INI:
				nodo = crear_nodo (id++);
				if (nodo)
					insertar_nodo_inicio (&lista, nodo);
				imprimir_lista (lista);
				break;

			case INS_ANT:
				printf("Antes del nodo con id: ");
				scanf ("%d", &cual);
				if (buscar_nodo (lista, cual))
				{
					nodo = crear_nodo (id++);
					if (nodo)
						insertar_nodo_antes (&lista, nodo, cual);
					imprimir_lista (lista);
				}
				else
				{
					printf("Error. No existe el nodo con en identificador indicado !!!\n\n");
				}
				break;

			case INS_DES:
				printf("Antes del nodo con id: ");
				scanf ("%d", &cual);
				if (buscar_nodo (lista, cual))
				{
					nodo = crear_nodo (id++);
					if (nodo)
						insertar_nodo_despues (&lista, nodo, cual);
					imprimir_lista (lista);
				}
				else
				{
					printf("Error. No existe el nodo con en identificador indicado !!!\n\n");
				}
				break;

			case INS_FIN:
				nodo = crear_nodo (id++);
				if (nodo)
					insertar_nodo_final (&lista, nodo);
				imprimir_lista (lista);
				break;

			case ELI:
				printf("Id del nodo a eliminar: ");
				scanf ("%d", &cual);
				if (buscar_nodo (lista, cual))
				{
					nodo = extraer_nodo (&lista, cual);
					eliminar_nodo (&nodo);
					imprimir_lista (lista);
				}
				else
				{
					printf("\nError. No existe el nodo con en identificador indicado !!!\n\n");
				}
				break;

			case BUS:
				printf("Id del nodo a buscar: ");
				scanf ("%d", &cual);
				if (buscar_nodo (lista, cual))
				{
					printf("\nEl nodo con el identificador %d, si se encientra en la lista.\n\n", cual);
					imprimir_lista (lista);
				}
				else
				{
					printf("\nError. No existe el nodo con en identificador indicado !!!\n\n");
				}
				break;

			case IMP:
				imprimir_lista (lista);
				break;

			case SALIR:
				break;

			default:
				printf ("\nOpcion incorrecta ! \nPresiona una tecla para continuar...");
				break;
		}

	} while (opcion != SALIR);

	// Extraer cada elemento de la lista y eliminarlo.
	printf("\nEliminando todos los elementos contenidos en la lista !!!\n");
	while (lista)
	{
		nodo = extraer_nodo (&lista, lista -> id);
		eliminar_nodo (&nodo);
		printf(".");
	}
	printf("\nHecho. Lista vacia.\n");

	return 0;
}
