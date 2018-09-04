#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cstring>
#include <cstdio>
#include "Lista.h"
#include "ListaCircular.h"
#include "Pila.h"
#include "Cola.h"


using namespace std;

char menuPrincipal()
{
	char sel = 'S';
	printf("\nPILAS Y COLAS, LISTAS, LISTAS CIRCULARES\n	1.Insertar\n	2.Eliminar\n	3.Recorrer\n	S.Salir\n	Seleccion: ");
	scanf(" %c", &sel);
	return sel;
}

char menuColaPilaListaCircular()
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
	ListaCircular listaC;
	int dat;
	char opc = 'S';
	do {
		system("CLS");
		switch (opc = menuPrincipal())
		{
		case '1':
			int temp;
			pedirDato(temp);
			switch (menuColaPilaListaCircular())
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
				listaC.insertar(temp);
			}
			break;
			}
			break;
		case '2':
			switch (menuColaPilaListaCircular())
			{
			case '1':
				pila.eliminar(dat);
				break;
			case '2':
				cola.eliminar(dat);
				break;
			case '3':
				lista.eliminar(dat); //ELIMINAR EL AUX
				break;

			case '4':
				listaC.eliminar(dat); //ELMINAR EL AUX
				break;
			}
			printf("\nEliminado: ");
			printf("%d", dat);
			break;
		case '3':
			switch (menuColaPilaListaCircular())
			{
			case '1':
				pila.mostrar();
				break;
			case '2':
				cola.mostrar();
				break;
			
			case '3':
				lista.mostrar(); //MOSTRAR AUX
				break;
			
			case '4':
				listaC.mostrar(); //MOSTRAR AUX
				break;
			}	
			break;
		}
		system("PAUSE");
	} while (opc != 'S');
}
