#pragma once
#include <stdio.h>
#include <cstdlib>
#include "Nodo.h"
#include "enums.h"

struct Lista {
	Nodo * cab = NULL;
	Nodo * fin = NULL;
	Nodo * aux = NULL;
	void insertar(int dato, Insercion tipoInsercion = InsercionFin) {
		Nodo *nuevo_nodo = (Nodo *)malloc(sizeof(Nodo));
		nuevo_nodo->info = dato;
		nuevo_nodo->sig = NULL;

		if (cab == NULL) {
			cab = nuevo_nodo;
			fin = nuevo_nodo;
			aux = nuevo_nodo;
		}
		else {

			switch (tipoInsercion)
			{
			case InsercionInicio:
				nuevo_nodo->sig = cab;
				cab = nuevo_nodo;
				break;
			case InsercionFin:
				fin->sig = nuevo_nodo;
				fin = nuevo_nodo;
				break;
			case InsercionAdelanteDe:
				nuevo_nodo->sig = aux->sig;
				aux->sig = nuevo_nodo;
				fin = nuevo_nodo;
				break;
			}
			aux = cab;
		}
	}

	void eliminar(int info) {
		Nodo * anterior = NULL;
		while ((aux != NULL) && (aux->info != info)) {
			anterior = aux;
			aux = aux->sig;
		}

		if (aux != NULL) {
			if (aux == cab)
				cab = aux->sig;
			else if (aux->sig == NULL) {
				fin = anterior;
				anterior->sig = NULL;
			}
			else
				anterior->sig = aux->sig;
			delete aux;
		}
	}

	void mostrarSiguiente()
	{
		if (aux != NULL) {
			printf("\nDato: %d", aux->info);
			aux = aux->sig;
		}
	}

	void mostrar() {
		Nodo * aux = cab;
		while (aux != NULL) {
			printf("\nDato: %d", aux->info);
			aux = aux->sig;
		}
	}

};