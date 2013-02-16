#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE (3)

/** definition of struct queue
*/

struct Queue
{
  void** queue_base;
  void** next;
  void** head;
  int max_cells;
  int head_pos;
  int tail_pos;
  int queue_alert_en;  // true is cannot be add, false if can be added
  int queue_alert_de;  // true if cannot be poped, false if it can be popped
};

typedef struct Queue queue; // for easiness

/** Creates a queue
* @param size - the size of the queue
* @return new_queue - the address of th enew queue
*/

queue* create_queue(int size);

/** enqueues an element
* @param Q - the queue working with
* @param ptr - the pointer to be introduced
* return 0, -1 -  0- success, -1 overflow
*/

int enqueue( queue* Q, void* ptr);

/** dequeue an element
* @param Q - the queue working with
* @return head of the queue, NULL if unsuccessfull
*/
void* dequeue( queue* Q );

/** solves enqueue if the queue is at its end
* @param Q the queue working with
* @param ptr - the pointer to be introduced
*/
int enden (queue* Q, void* ptr);

/** solves dequeue if queue is at its end
* @param Q - the queue working with
* @return head of the queue, NULL if unsuccessfull
*/

void* endde ( queue* Q);

#endif
