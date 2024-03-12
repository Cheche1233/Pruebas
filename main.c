#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura del nodo
typedef struct Nodo {
    void *dato;
    struct Nodo *anterior;
    struct Nodo *siguiente;
} Nodo;

// Definición de la estructura de la lista
typedef struct Lista {
    Nodo *cabeza;
    Nodo *cola;
} Lista;

// Función para crear un nodo
Nodo *crearNodo(void *dato) {
    Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
    if (nuevoNodo != NULL) {
        nuevoNodo->dato = dato;
        nuevoNodo->anterior = NULL;
        nuevoNodo->siguiente = NULL;
    }
    return nuevoNodo;
}

// Función para crear una lista vacía
Lista *crearLista() {
    Lista *nuevaLista = (Lista *)malloc(sizeof(Lista));
    if (nuevaLista != NULL) {
        nuevaLista->cabeza = NULL;
        nuevaLista->cola = NULL;
    }
    return nuevaLista;
}

// Función para añadir un nodo al principio de la lista
void addCabeza(Lista *lista, void *dato) {
    Nodo *nuevoNodo = crearNodo(dato);
    if (lista->cabeza == NULL) {
        lista->cabeza = lista->cola = nuevoNodo;
    } else {
        nuevoNodo->siguiente = lista->cabeza;
        lista->cabeza->anterior = nuevoNodo;
        lista->cabeza = nuevoNodo;
    }
}

// Función para añadir un nodo al final de la lista
void addCola(Lista *lista, void *dato) {
    Nodo *nuevoNodo = crearNodo(dato);
    if (lista->cola == NULL) {
        lista->cabeza = lista->cola = nuevoNodo;
    } else {
        nuevoNodo->anterior = lista->cola;
        lista->cola->siguiente = nuevoNodo;
        lista->cola = nuevoNodo;
    }
}

// Función para liberar la memoria ocupada por la lista y sus nodos
void liberarLista(Lista *lista) {
    Nodo *actual = lista->cabeza;
    Nodo *siguiente;
    while (actual != NULL) {
        siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
    free(lista);
}

// Función de ejemplo para imprimir los datos en la lista
void imprimirLista(Lista *lista) {
    Nodo *actual = lista->cabeza;
    while (actual != NULL) {
        // Suponiendo que los datos son de tipo int
        printf("%d ", *((int *)actual->dato));
        actual = actual->siguiente;
    }
    printf("\n");
}

int main() {
    // Ejemplo de uso
    Lista *lista = crearLista();

    int dato1 = 10;
    int dato2 = 20;
    int dato3 = 30;

    addCabeza(lista, &dato1);
    addCola(lista, &dato2);
    addCola(lista, &dato3);

    imprimirLista(lista);

    liberarLista(lista);

    return 0;
}


