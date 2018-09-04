#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
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

	void mostrarDatos() {
		Nodo * aux = cab;
		printf("\n=========== Datos Pila ===========\n");
		printf("\nElementos {");

		while (aux != NULL)
		{
			printf(" %d ", aux->info);
			aux = aux->sig;
		}

		printf("}");
		printf("\n=========== Fin Pila ===========\n");
	}
};

struct Cola {
	Nodo * cab = NULL;
	Nodo * cola = NULL;
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
				printf("\nDato: %d", aux->info);
				aux = aux->sig;
			}
	}

	void mostrarDatos() {
		Nodo * aux = cab;
		printf("\n=========== Datos Cola ===========\n");
		printf("\nElementos {");

		while (aux != NULL)
		{
			printf(" %d ", aux->info);
			aux = aux->sig;
		}

		printf("}");
		printf("\n=========== Fin Cola ===========\n");
	}
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
		else 
		{

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
				if (aux != NULL)
				{
					nuevo_nodo->sig = aux->sig;
					aux->sig = nuevo_nodo;
					if (nuevo_nodo->sig == NULL)
						fin = nuevo_nodo;
				}
				break;
			}
			aux = cab;
		}
	}

	void eliminar(int info) {
		Nodo * anterior = NULL;
		Nodo * aux = cab;

		if (cab == NULL)
			printf("\nNingun nodo existente en la Lista\n");
		else 
		{
			while ((aux != NULL) && (aux->info != info)) {
				anterior = aux;
				aux = aux->sig;
			}
			if (aux != NULL) {
				if (aux == cab) {
					cab = aux->sig;
					this->aux = cab;
				}
				else if (aux->sig == NULL) {
					fin = anterior;
					anterior->sig = NULL;
				}
				else
					anterior->sig = aux->sig;
				delete aux;
			}
		}
	}

	void mostrarSiguiente()
	{
		if (aux != NULL) 
		{
			printf("\nDato: %d", aux->info);
			aux = aux->sig;
		}
		else 
			printf("\nYa se recorrio la lista o no existen ningun nodo.\n");
	}

	void mostrar() 
	{
		if (cab == NULL)
			printf("\nNingun nodo existente en la Lista\n");
		else 
		{
			Nodo * aux = cab;
			while (aux != NULL)
			{
				printf("\nDato: %d", aux->info);
				aux = aux->sig;
			}
		}
	}

	void mostrarDatos() {
		Nodo * aux = cab;
		printf("\n=========== Datos Lista ===========\n");
		printf("\nElementos {");

		while (aux != NULL)
		{
			printf(" %d ", aux->info);
			aux = aux->sig;
		}

		printf("}");

		if (this->aux != NULL)
			printf("\nEl auxiliar se encuentra en: %d", this->aux->info);

		printf("\n=========== Fin Lista ===========\n");
	}

};

struct ListaCircular
{
	Nodo * cab = NULL;
	Nodo * fin = NULL;
	Nodo * aux = NULL;
	void insertar(int dato, Insercion tipoInsercion = InsercionFin) {
		Nodo *nuevo_nodo = (Nodo *)malloc(sizeof(Nodo));
		nuevo_nodo->info = dato;
		nuevo_nodo->sig = NULL;

		if (cab == NULL) {
			cab = fin = nuevo_nodo;
			fin->sig = cab;
			aux = nuevo_nodo;
		}
		else
		{

			switch (tipoInsercion)
			{
			case InsercionInicio:
				fin->sig = nuevo_nodo;
				nuevo_nodo->sig = cab;
				cab = nuevo_nodo;
				break;
			case InsercionFin:
				fin->sig = nuevo_nodo;
				fin = nuevo_nodo;
				nuevo_nodo->sig = cab;
				break;
			case InsercionAdelanteDe:
				if (aux != NULL)
				{
					nuevo_nodo->sig = aux->sig;
					aux->sig = nuevo_nodo;
					if (nuevo_nodo->sig == cab)
						fin = nuevo_nodo;
				}
				break;
			}
			aux = cab;
		}
	}

	void eliminar(int info) {
		Nodo * anterior = NULL;
		Nodo * aux = cab;

		if (cab == NULL)
			printf("\nNingun nodo existente en la Lista\n");
		else
		{
			while ((aux != NULL) && (aux->info != info)) {
				anterior = aux;
				aux = aux->sig;
			}
			if (aux != NULL) {
				if (aux == cab) {
					cab = aux->sig;
					this->aux = cab;
				}
				else if (aux->sig == NULL) {
					fin = anterior;
					anterior->sig = NULL;
				}
				else
					anterior->sig = aux->sig;
				delete aux;
			}
		}
	}

	void mostrarSiguiente()
	{
		if (aux != NULL)
		{
			printf("\nDato: %d", aux->info);
			aux = aux->sig;
		}
		else
			printf("\nYa se recorrio la lista o no existen ningun nodo.\n");
	}

	void mostrar()
	{
		if (cab == NULL)
			printf("\nNingun nodo existente en la Lista\n");
		else
		{
			Nodo * aux = cab;
			bool continuar = true;
			while (continuar)
			{
				printf("\nDato: %d ", aux->info);
				if (aux == fin)
					continuar = false;
				aux = aux->sig;
			}
		}
	}

	void mostrarDatos() {
		Nodo * aux = cab;
		bool continuar = true;

		printf("\n=========== Datos Circular ===========\n");
		printf("\nElementos {");

		while (continuar)
		{
			printf(" %d ", aux->info);
			if (aux == fin)
				continuar = false;
			aux = aux->sig;
		}

		printf("}");

		if (this->aux != NULL)
			printf("\nEl auxiliar se encuentra en: %d", this->aux->info);

		printf("\n=========== Fin Lista Circular ===========\n");
	}
};

char menuPrincipal()
{
	char sel = 'S';
	printf("\nPARCIAL PRIMER CORTE\n	1.Pilas\n	2.Colas\n	3.Listas\n	4.Listas Circulares\n	S.Salir\n	Seleccion: ");
	scanf(" %c", &sel);
	return sel;
}

char menuColaPilaListaCircular()
{
	char sel = 'S';
	printf("\nAcciones:\n	1.Insertar\n	2.Eliminar\n	3.Recorrer\n	Seleccion: ");
	scanf(" %c", &sel);
	return sel;
}

Insercion menuTipoInsercion() 
{
	int op = 0;
	printf("\n	1.Inicio\n	2.Fin\n	3.Despues de aux\n Seleccion: ");
	scanf("%d", &op);
	switch (op)
	{
	case 1:
		return InsercionInicio;
	case 2:
		return InsercionFin;
	case 3:
		return InsercionAdelanteDe;
	}
}

char menuTipoMostrar()
{
	char op = 'S';
	printf("\n	1.Siguiente nodo(Aux)\n	2.Todo\n	Seleccion: ");
	scanf(" %c", &op);
	return op;
}

int pedirDato() 
{
	int dato;
	printf("\nIngresar dato: ");
	scanf("%d", &dato);
	return dato;
}


int main() 
{
	Pila pila;
	Cola cola;
	Lista lista;
	ListaCircular listaC;
	int dat;
	char opc = 'S';
	do {
		system("CLS");
		if (pila.cab != NULL)
			pila.mostrarDatos();
		if (cola.cab != NULL)
			cola.mostrarDatos();
		if (lista.cab != NULL)
			lista.mostrarDatos();
		if (listaC.cab != NULL)
			listaC.mostrarDatos();
		switch (opc = menuPrincipal())
		{
		case '1':
			switch (menuColaPilaListaCircular())
			{
			case '1':
				pila.insertar(pedirDato());
				break;
			case '2':
				pila.eliminar(dat);
				if (pila.cab != NULL)
					printf("\nDato eliminado: %d", dat);
				break;
			case '3':
				pila.mostrar();
				break;
			}
			break;
		case '2':
			switch (menuColaPilaListaCircular())
			{
			case '1':
				cola.insertar(pedirDato());
				break;
			case '2':
				cola.eliminar(dat);
				if (cola.cab != NULL)
					printf("\nDato eliminado: %d", dat);
				break;
			case '3':
				cola.mostrar();
				break;
			}
			break;
		case '3':
			switch (menuColaPilaListaCircular())
			{
			case '1':
				lista.insertar(pedirDato(), menuTipoInsercion());
				break;
			case '2':
				lista.eliminar(pedirDato());
				break;
			case '3':
				switch (menuTipoMostrar())
				{
				case '1':
					lista.mostrarSiguiente();
					break;
				case '2':
					lista.mostrar();
					break;
				}
				break;
			}
			break;
		
		case '4':
			switch (menuColaPilaListaCircular())
			{
			case '1':
				listaC.insertar(pedirDato(), menuTipoInsercion());
				break;
			case '2':
				listaC.eliminar(pedirDato());
				break;
			case '3':
				switch (menuTipoMostrar())
				{
				case '1':
					listaC.mostrarSiguiente();
					break;
				case '2':
					listaC.mostrar();
					break;
				}
				break;
			}
			break;
		}
		printf("\n");
		system("PAUSE");
	} while (opc != 'S');
}
