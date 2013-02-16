#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"


queue* create_queue(int size)
{
    queue* new_queue = (queue*) malloc(sizeof(queue));
    if( !new_queue )
        return NULL;

    new_queue->max_cells = size;   //maximum number of elements admitted
    new_queue->head_pos = 0;    // start everything from 0
    new_queue->tail_pos =0;     // in the beginning, tail=head

    new_queue->queue_base = (void **) calloc(sizeof(void *), MAX_QUEUE);
    if (new_queue->queue_base == NULL)
    {
        free(new_queue); // Unable to allocate stack entries, so free struct.
        return NULL;
    }

    new_queue->next = new_queue-> queue_base; // start at the base
    new_queue->queue_alert_en = 0;
    new_queue->queue_alert_de = 1;


    return new_queue;
}

int enqueue( queue* Q, void* ptr)
{
    if( (Q->tail_pos == Q->head_pos) && (Q->queue_alert_en==1) )  // normal overflow
    {
        Q->queue_alert_de=0;
        return -1;       // insuccess
    }

    if( Q->tail_pos == (Q->max_cells)-1 ) // if the tail is at its end
    {
        return enden(Q,ptr); // go to the special function
    }
    Q->queue_alert_en = 1;  // nothing will be introduced if something is already there

    *(Q->next) = ptr;    // introduce ptr
    (Q->next)++;         // increment tail
    (Q->tail_pos)++;
    return 0;
}

int enden(queue* Q, void* ptr)
{
    Q->tail_pos = 0;
    *(Q->next) =ptr;
    Q->next = Q->queue_base;

    return 0;
}

void* dequeue(queue* Q)
{
    if( (Q->head_pos == Q->tail_pos) && (Q->queue_alert_de==1) )
    {
        Q->queue_alert_en = 0;
        return NULL;  //stack overflow
    }

    Q->queue_alert_de = 1;

    if( Q->head_pos == (Q->max_cells)-1 )  // particular case head is at the end
        return endde(Q);   // special function to analyze and return


    void** ptr = Q->head;  // save the value to be returned
    (Q->head)++;           //increment
    (Q->head_pos)++;

    return (*ptr);
}

void* endde(queue* Q)
{
    void* ptr = *(Q->head);
    Q->head_pos = 0;
    Q->head = Q->queue_base;
    return ptr;
}
