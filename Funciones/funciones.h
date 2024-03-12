#include "/workspaces/Pruebas/Estructuras/Listas.h"

//////LISTAS ENLAZADAS////////
void AddTail(Lista *lista, void *data);
void Inicializar(Lista *lista);
void leer(Lista *lista);
void ImprimirLista(Lista *lista);
void Liberar(Lista *lista);
int EstaVacia(Lista *lista);

/////PILAS//////
void InicializarPila(Pila *pila);
void push(Pila *pila, void *data);
void* pop(Pila *pila);
void ListaAPila(Lista *lista, Pila *pila);
