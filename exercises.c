#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "arraylist.h"
#include "stack.h"

//#include "exercises.h"

//Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
//NO MODIFICAR
void imprime_lista(List *L) {
   int *dato;
   dato = (int*)first(L);
   printf("[");
   while(dato != NULL) {
      printf("%d ", *dato);
      dato = (int*)next(L);
   }
   printf("]\n");

}

//Ojo que la pila se vacía al imprimir y se imprime en orden inverso
//NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) {
   void *dato;
   printf("[");
   while((dato = pop(P)) != NULL) {
      printf("%d ", *(int*)dato);
   }
   printf("]\n");
}

/* 
Ejercicio 1.
Crea una Lista y agrega punteros a elementos del 1 al 10.
Recuerda que la lista almacena punteros, por lo que
debes reservar memoria para cada elemento que agregues.
Al finalizar retorna la lista creada.
*/

List* crea_lista() {
   List* L = create_list();
   for (int k = 1; k <= 10; k++)
   {
      int* elemento = (int*)malloc(sizeof(int));
      *elemento = k;
      pushBack(L,elemento);
   }
   return L;
}

/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y 
retorne la suma de sus elementos.
*/
int sumaLista(List *L) {
   void* num = first(L);
   int suma = 0;
   while (num != NULL)
   {
      suma += *(int*)num;
      num = next(L);
   }
   return suma;
}

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos 
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List*L, int elem)
{
   void* indice = first(L);
   while (indice != NULL)
   {
      if ((*(int*)indice) == elem)
      {
         popCurrent(L);
      }
      indice = next(L);
   }
}

/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack* P1, Stack* P2) {
   Stack* aux = create_stack();
   while(top(P1) != NULL)
   {
      push(aux,top(P1));
      pop(P1);
   }
   while(top(aux) != NULL)
   {
      push(P1, top(aux));
      push(P2, top(aux));
      pop(aux);
   }
   free(aux);
}

/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus 
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int parentesisBalanceados(char *cadena) {
   Stack *pila = create_stack();
   
   void* parentesis;
   for (int i = 0; cadena[i] ; i++)
   {
      if (cadena[i] == '(' || cadena[i] == '{' || cadena[i] == '[')
      {
         if (cadena[i] == '(') parentesis = (void*) (int) ')';
         else if (cadena[i] == '{') parentesis = (void*) (int) '}';
         else if (cadena[i] == '[') parentesis = (void*) (int) ']';
         push(pila, parentesis);
      }
      else
      {
         if (top(pila) == NULL) return 0;
         if (top(pila) != (void*) (int) cadena[i] ) return 0;
         pop(pila);
      }
   }
   if (top(pila) == NULL) return 1;
   return 0;

}

