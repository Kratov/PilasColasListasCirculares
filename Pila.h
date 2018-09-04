#pragma once
#include <stdio.h>
#include <cstdlib>
#include "Nodo.h"

struct Pila {

	Nodo * cab = NULL;

	void insertar(const int info) {
		Nodo * nuevo = (Nodo *)malloc(sizeof(Nodo));
		nuevo->info = info;
		nuevo->sig = NULL;
		if (cab == NULL)
			cab = nuevo;
		else
		{
			nuevo->sig = cab;
			cab = nuevo;
		}
	}

	void eliminar(int & eliminado) {
		if (cab != NULL)
		{
			Nodo * aux = cab;
			eliminado = cab->info;
			cab = cab->sig;
			delete aux;
		}
		else
			printf("\nNingun nodo existente en Pila\n");

	}

	void mostrar()
	{
		Nodo * aux = cab;
		if (cab == NULL)
			printf("\nNingun nodo existente en Pila\n");
		else
			while (aux != NULL)
			{
				printf("\nDato: %d", aux->info);
				aux = aux->sig;
			}
	}
};