#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 5

void init(Stack *s) {
  s->data = (int *)malloc(INITIAL_CAPACITY * sizeof(int));
  if (s->data == NULL) {
    printf("Memory allocation failed");
    exit(1);
  }
  s->size = 0;
  s->capacity = INITIAL_CAPACITY;
}

void destroy(Stack *s) {
  free(s->data);
}

void push(Stack *s, int element) {
  if (isFull(s)) {
    s->capacity *= 2;
    s->data = (int *)realloc(s->data, s->capacity * sizeof(int));
    if (s->data == NULL) {
      perror("Memory reallocation failed");
      exit(1);
    }
  }
  s->data[s->size++] = element;
}

int pop(Stack *s) {
  if (isEmpty(s)) {
    printf("Error: Cannot pop from an empty stack\n");
    exit(1);
  }
  return s->data[--(s->size)];
}

bool isEmpty(const Stack *s) { return s->size == 0; }
bool isFull(const Stack *s) { return s->size == s->capacity; }
