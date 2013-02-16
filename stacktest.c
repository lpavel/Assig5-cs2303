#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

typedef struct {
  int x;
  double y;
} Foo; // Just some arbitrary struct


int main() {
  const int max_entries = 5; // size of stack
  Foo* new_foo1;
  Foo* new_foo2;
  Foo* returned_foo;

  // First, create a stack
  Stack *new_stack = create_stack(max_entries);

  // Allocate a Foo and push it onto the stack.
  new_foo1 = (Foo *) malloc(sizeof(Foo));
  new_foo1->x = 6;
  new_foo1->y = 14.79;
  printf("Pushing: x = %5d, y = %10.3f\n", new_foo1->x, new_foo1->y);
  push(new_stack, (void *) new_foo1);

  // Allocate another Foo and push it onto the stack.
  new_foo2 = (Foo *) malloc(sizeof(Foo));
  new_foo2->x = 217;
  new_foo2->y = 3.14159;
  printf("Pushing: x = %5d, y = %10.3f\n", new_foo2->x, new_foo2->y);
  push(new_stack, (void *) new_foo2);

  // Peek at the top of the stack
  returned_foo = (Foo *) peek(new_stack);
  printf("Peeked:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);

  // Retrieve the Foos and print them.
  returned_foo = (Foo *) pop(new_stack);
  printf("Popped:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);
  returned_foo = (Foo *) pop(new_stack);
  printf("Popped:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);

  // Clean up
  delete_stack(new_stack);
  free(new_foo1);
  free(new_foo2);

  // MY TESTS
  printf("\n\nFROM NOW ON ME\n\n");

  // first check how it reacts when is empty


    if(!(returned_foo= (Foo *) pop(new_stack)))
      printf("stack empty\n");
    else
      printf("Popped:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);

    if(!( returned_foo = (Foo *) peek(new_stack)))
      printf("stack empty\n");
    else
      printf("Peeked:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);


  Foo* elements = (Foo*) malloc((max_entries+1)*sizeof(Foo));

  int i;
  double j=10.3;

  for(i=0; i<max_entries; i++)
  {
    (elements+i)->x=i;
    (elements+i)->y=j+i;
    printf("Pushing: x = %5d, y = %10.3f\n", (elements+i)->x, (elements+i)->y);
    if( push(new_stack, (void *) (elements+i)) < 0)
      printf("stack is full\n");
  }

  (elements+i)->x=i;
  (elements+i)->y=j+i;
  if( push(new_stack, (void *) (elements+i)) < 0)
    printf("stack is full\n");

  for(i=0; i<max_entries+1; i++)
  {
    if( !( returned_foo = (Foo *) peek(new_stack)))
      printf("stack empty\n");
    else
      printf("Peeked:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);
    if(!(returned_foo= (Foo *) pop(new_stack)))
      printf("stack empty\n");
    else
      printf("Popped:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);

  }
  return 0;
}

