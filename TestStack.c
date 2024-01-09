#include "Stack.h"
#include <stdio.h>

int main() {
  Stack s1;
  Stack s2;
  init(&s1);
  init(&s2);
  push(&s1, 1);
  push(&s1, 2);
  push(&s1, 3);
  push(&s2, 5);
  push(&s2, 6);
  printf("%d %d\n", pop(&s1), pop(&s2));
  printf("%d\n", pop(&s1));
  /*while (!isEmpty(&s1)) {
    pop(&s1);
  }*/
  pop(&s1);
  destroy(&s1);
  destroy(&s2);
  return 0;
}
