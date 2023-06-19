//
//  pqueue.hpp
//  ALDA_Exercise7v12023
//
//  Created by Michael Strommer on 19.06.23.
//

#ifndef pqueue_hpp
#define pqueue_hpp

#include <stdio.h>
#include <stdlib.h>

struct _element {
    int data[2];
    int priority;
    struct _element *next;
};

typedef struct _element element;

struct _pqueue {
    struct _element *head; // Erstes Element in der Queue
    int count; // Anzahl der Elemente in der Queue
};

typedef struct _pqueue pqueue;

pqueue*  p_init(void);
void     p_enqueue(pqueue *queue, int data[2], int priority);
element* p_peek(pqueue *queue);
void     p_dequeue(pqueue *queue);
void     p_enqueueOrIncrementPriority(pqueue *queue, int data[2], int priority);
int      p_isEmpty(pqueue *queue);
void     p_print(pqueue *queue);

#endif /* pqueue_hpp */
