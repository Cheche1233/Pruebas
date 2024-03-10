#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para representar un nodo de la lista
typedef struct Nodo {
    char dato;
    struct Nodo* siguiente;
} Nodo;

// Estructura para representar una lista de caracteres
typedef struct Lista {
    Nodo* cabeza;
    Nodo* cola;
} Lista;

// Función para crear una nueva lista
Lista* crearLista() {
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    if (lista != NULL) {
        lista->cabeza = NULL;
        lista->cola = NULL;
    }
    return lista;
}

// Función para crear un nuevo nodo con un dato dado
Nodo* crearNodo(char dato) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevoNodo != NULL) {
        nuevoNodo->dato = dato;
        nuevoNodo->siguiente = NULL;
    }
    return nuevoNodo;
}

// Función para insertar un nuevo nodo al final de la lista
void insertar(Lista* lista, char dato) {
    Nodo* nuevoNodo = crearNodo(dato);
    if (nuevoNodo != NULL) {
        if (lista->cabeza == NULL) {
            lista->cabeza = nuevoNodo;
            lista->cola = nuevoNodo;
        } else {
            lista->cola->siguiente = nuevoNodo;
            lista->cola = nuevoNodo;
        }
    }
}

// Función para imprimir una lista de caracteres
void imprimirLista(Lista* lista) {
    Nodo* temp = lista->cabeza;
    while (temp != NULL) {
        printf("%c ", temp->dato);
        temp = temp->siguiente;
    }
    printf("\n");
}

// Función para liberar la memoria utilizada por una lista
void liberarLista(Lista* lista) {
    Nodo* temp = lista->cabeza;
    while (temp != NULL) {
        Nodo* siguiente = temp->siguiente;
        free(temp);
        temp = siguiente;
    }
    free(lista);
}

int main() {
    // Definir números de teléfono
    char* telefonos[] = {
        "664 511 3370",
        "555-123-4567",
        "(123) 456-7890",
        "123-456-789",
        "911"
    };

    // Crear y llenar listas para cada número de teléfono
    Lista* listas[5];
    for (int i = 0; i < 5; i++) {
        listas[i] = crearLista();
        for (int j = 0; j < strlen(telefonos[i]); j++) {
            insertar(listas[i], telefonos[i][j]);
        }
    }

    // Imprimir las listas de caracteres para cada número de teléfono
    for (int i = 0; i < 5; i++) {
        printf("Número de teléfono %d: ", i + 1);
        imprimirLista(listas[i]);
        liberarLista(listas[i]);
    }

    return 0;
}

