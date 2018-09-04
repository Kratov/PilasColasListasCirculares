#pragma once
#include <stdio.h>
#include <cstdlib>
#include "Nodo.h"

struct Cola {
	Nodo * cab = NULL;
	Nodo * cola = NULL;
	int nItems = 0;
	void insertar(const int info)
	{
		Nodo * nuevo = (Nodo *)malloc(sizeof(Nodo));
		nuevo->info = info;
		nuevo->sig = NULL;
		if (cab == NULL)
		{
			cola = nuevo;
			cab = nuevo;
		}
		else
		{
			cola->sig = nuevo;
			cola = nuevo;
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
			printf("\nNingun nodo existente en Cola\n");
	}

	void mostrar()
	{
		Nodo * aux = cab;

		if (cab == NULL)
			printf("\nNingun nodo existente en Cola\n");
		else
			while (aux != NULL)
			{
				printf("%d", aux->info);
				aux = aux->sig;
			}
	}
};
