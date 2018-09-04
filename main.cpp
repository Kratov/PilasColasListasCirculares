#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <cstring>
#include <cstdio>

using namespace std;

enum Insercion
{
	InsercionInicio,
	InsercionFin,
	InsercionAdelanteDe
};

struct Nodo
{
	int info;
	Nodo * sig;
};

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

	void borrar(int info) {
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

char menuPrincipal()
{
	char sel = 'S';
	printf("\nPILAS Y COLAS, LISTAS, LISTAS CIRCULARES\n	1.Insertar\n	2.Eliminar\n	3.Recorrer\n	S.Salir\n	Seleccion: ");
	scanf(" %c", &sel);
	return sel;
}

char menuColaPila()
{
	char sel = 'S';
	printf("\nAplicar a:\n	1.Pila\n	2.Cola\n	3.Lista\n	4.Lista Circulares\n	Seleccion: ");
	scanf(" %c", &sel);
	return sel;
}

int menuTipoInsercion() {
	int op = 0;
	printf("\n	1.Inicio\n	2.Fin\n	3.Despues de aux\n Seleccion: ");
	scanf("%d", op);
	return op;
}

void pedirDato(int & info) {
	printf("Pedir datos: ");
	scanf("%d", &info);
}


int main() {
	Pila pila;
	Cola cola;
	Lista lista;
	int dat;
	char opc = 'S';
	do {
		system("CLS");
		switch (opc = menuPrincipal())
		{
		case '1':
			int temp;
			pedirDato(temp);
			switch (menuColaPila())
			{
			case '1':
			{
				pila.insertar(temp);
			}
			break;
			case '2':
			{
				cola.insertar(temp);
			}
			break;
			case '3':
			{
				lista.insertar(temp);
			}
			break;
			case '4':
			{
				cola.insertar(temp);
			}
			break;
			}
			break;
		case '2':
			switch (menuColaPila())
			{
			case '1':
				pila.eliminar(dat);
				break;
			case '2':
				cola.eliminar(dat);
				break;
			}
			printf("\nEliminado: ");
			printf("%d", dat);
			break;
		case '3':
			switch (menuColaPila())
			{
			case '1':
				pila.mostrar();
				break;
			case '2':
				cola.mostrar();
				break;
			}
			break;
		}
		system("PAUSE");
	} while (opc != 'S');
}
