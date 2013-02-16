#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

typedef struct {
  int x;
  double y;
} test; // Just some arbitrary struct


int main()
{

    test* ex=(test*) malloc((MAX_QUEUE+2)*sizeof(test));
    ex->x=0; (ex+1)->x=1; (ex+2)->x=2; (ex+3)->x=3; (ex+4)->x=4;
    ex->y=0.1; (ex+1)->y=0.2; (ex+2)->y=0.3; (ex+3)->y=0.4; (ex+4)->y=0.5;

    queue* new_queue = create_queue(MAX_QUEUE);

    test* ret_ex = (test*) malloc (sizeof(test));

    if(!(ret_ex = (test *) dequeue(new_queue)))
        printf("queue empty\n");
    else
        printf("Enqueued:  x = %5d, y = %10.3f\n", ret_ex->x, ret_ex->y);

    int i;
    for(i=0; i<5; i++)
        if( enqueue(new_queue, (void *)(ex+i)) < 0)
            printf("queue is full\n");
        else
            printf("enqueuing: x = %5d, y = %10.3f\n", (ex+i)->x, (ex+i)->y);

    if(!(ret_ex = (test *) dequeue(new_queue)))
        printf("queue empty\n");
    else
        printf("Dequeued:  x = %5d, y = %10.3f\n", ret_ex->x, ret_ex->y);

    if( enqueue(new_queue, (void *)(ex+4)) < 0)
        printf("queue is full\n");
    else
        printf("enqueuing: x = %5d, y = %10.3f\n", (ex+4)->x, (ex+4)->y);



    for(i=0; i<5; i++)
        if(!(ret_ex = (test *) dequeue(new_queue)))
            printf("queue empty\n");
        else
            printf("Dequeued:  x = %5d, y = %10.3f\n", ret_ex->x, ret_ex->y);

    return 0;
}
