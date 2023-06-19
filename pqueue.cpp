//
//  pqueue.cpp
//  ALDA_Exercise7v12023
//
//  Created by Michael Strommer on 19.06.23.
//

#include "pqueue.hpp"


/*
 Erstellt Speicher für Queue und liefert Adresse zurück.
 */
pqueue *p_init(){
    pqueue *tmp = (pqueue *)malloc(sizeof(pqueue));
    tmp->head = NULL;
    tmp->count = 0;
    return tmp;
}

/*
 Fügt ein Element in die Priority Queue an der richtigen Stelle ein. Die bereits in der Queue existierenden Elemente sind nach ihrer Priorität gereiht. Niedrigere Werte haben in dieser Implementierung eine höhere Priorität und befinden sich weiter vorne in der Queue.
 */
void p_enqueue(pqueue *queue, int data[2], int priority){
    // Neues Element anlegen
    element *newElement = (element*) malloc(sizeof(element));
    newElement->data[0] = data[0];
    newElement->data[1] = data[1];
    newElement->priority = priority;
    element **tmp = &queue->head; // Two Star Programming
    
    // Stelle zum Einfügen suchen
    while(*tmp && (*tmp)->priority < priority){
        tmp = &(*tmp)->next;
    }
    // Einfügen in die Listen
    newElement->next = *tmp;
    *tmp = newElement;
    queue->count++;
}

/*
  liefert einen Pointer auf das vorderste Element (höchste Priorität) in der Queue zurück. Das Element wird jedoch nicht entfernt.
 */
element *p_peek(pqueue *queue){
    return queue->head;
}

/*
 entfernt das vorderste Element aus der Queue. Beachten Sie hier Speicher entsprechend freizugeben.
 */
void p_dequeue(pqueue *queue){
    element * toDelete = queue->head;
    if(toDelete){
        queue->head = toDelete->next;
        queue->count--;
        free(toDelete);
    }
}

/*
 Sucht ein Element in der Queue, welches mit data übereinstimmt. Wurde solch ein Element gefunden, wird überprüft ob die neue Priorität höher ist als die ursprüngliche. Ist dies der Fall wird die Priorität überschrieben und es erfolgt eine Neueinordnung in der Warteschlange. Ansonsten wird das Element NEU in die Queue eingefügt.
 */
void p_enqueueOrIncrementPriority(pqueue *queue, int data[2], int priority){
    // Element zuerst löschen wenn die Priorität erhöht wurde
    element **current = &queue->head;
    int enqueueRequired = 1;
    // Delete Funktion
    while(*current){
        if((*current)->data[0] == data[0] && (*current)->data[1] == data[1]){
            if((*current)->priority > priority){
                // Update notwendig also löschen:
                element * tmp = *current;
                *current = (*current)->next;
                free(tmp);
            } else {
                enqueueRequired = 0;
            }
            break;
        }
        current = &(*current)->next;
    }
    // Nur wenn Enqueue notwendig ist
    if(enqueueRequired){
        p_enqueue(queue, data, priority);
    }
}

/*
 liefert 1 zurück falls die Queue leer ist, andernfalls 0.
 */
int p_isEmpty(pqueue *queue){
    return queue->head == NULL;
}

/*
 gibt die komplette Warteschlange auf der Konsole aus.
 */
void p_print(pqueue *queue){
    element *tmp = queue->head;
    printf("Q = < ");
    while(tmp){
        printf("([%i,%i] : P%i)", tmp->data[0], tmp->data[1], tmp->priority);
        tmp = tmp->next;
        if(tmp){
            printf(" , ");
        }
    }
    printf(" >");
    printf("\n");
}
