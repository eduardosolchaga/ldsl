#ifndef _LDSL_H_
#define _LDSL_H_

#include <stdio.h>
#include <stdlib.h>


struct nodo
{
	int id;
	struct nodo *next;
};


struct nodo *crear_nodo (int id);
void insertar_nodo_inicio (struct nodo **lista, struct nodo *nodo);
void insertar_nodo_final (struct nodo **lista, struct nodo *nodo);
void insertar_nodo_antes (struct nodo **lista, struct nodo *nodo, int id);
void insertar_nodo_despues (struct nodo **lista, struct nodo *nodo, int id);
struct nodo *buscar_nodo (struct nodo *lista, int id);
struct nodo *extraer_nodo (struct nodo **lista, int id);
void eliminar_nodo (struct nodo **nodo);
void imprimir_lista (struct nodo *lista);


struct nodo *crear_nodo (int id)
{
	struct nodo *nodo = NULL;

	nodo = (struct nodo *) malloc (sizeof (struct nodo));
	if (nodo)
	{
		nodo -> id = id;
		nodo -> next = NULL;
	}

	return nodo;
}


void insertar_nodo_inicio (struct nodo **lista, struct nodo *nodo)
{
	nodo -> next = *lista;
	(*lista) = nodo;
}


void insertar_nodo_final (struct nodo **lista, struct nodo *nodo)
{
	struct nodo *act = *lista;

	if (!act)
	{
		*lista = nodo;
	}
	else
	{
		while (act -> next)
		{
			act = act -> next;
		}
		act -> next = nodo;
	}
}


void insertar_nodo_antes (struct nodo **lista, struct nodo *nodo, int id)
{
	struct nodo *ant = NULL, *act = *lista;

	while (act -> id != id)
	{
		ant = act;
		act = act -> next;
	}
	if (ant)
	{
		nodo -> next = act;
		ant -> next = nodo;
	}
	else
	{
		nodo -> next = act;
		(*lista) = nodo;

	}
}


void insertar_nodo_despues (struct nodo **lista, struct nodo *nodo, int id)
{
	struct nodo *act = *lista;

	while (act -> id != id)
	{
		act = act -> next;
	}
	nodo -> next = act -> next;
	act -> next = nodo;
}


struct nodo *buscar_nodo (struct nodo *lista, int id)
{
	struct nodo *act = lista;

	while (act && act -> id != id)
	{
		act = act -> next;
	}

	return act;
}


struct nodo *extraer_nodo (struct nodo **lista, int id)
{
	struct nodo *ant = NULL, *act = NULL;

	if ((*lista) -> id == id)
	{
		act = *lista;
		*lista = (*lista) -> next;
		act -> next = NULL;
	}
	else
	{
		ant = *lista;
		act = (*lista) -> next;
		while (act && act -> id != id)
		{
			ant = act;
			act = act -> next;
		}
		if (act)
		{
			ant -> next = act -> next;
			act -> next = NULL;
		}
	}

	return act;
}


void eliminar_nodo (struct nodo **nodo)
{
	free (*nodo);
	nodo = NULL;
}


void imprimir_lista (struct nodo *lista)
{
	printf("\nlista * -> ");
	while (lista)
	{
		printf("%d -> ", lista -> id);
		lista = lista -> next;
	}
	printf("NULL\n");
	printf("\n\n");
}

#endif