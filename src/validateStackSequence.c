#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

struct stack {
  int   top;
  int   len;
  int*  arr;
};

struct stack* init(int len) {
  struct stack* S = (struct stack*) malloc(sizeof(struct stack));
  S->top = -1;
  S->len = len;
  S->arr = (int*) malloc(len * sizeof(int));
  return S;
}

bool isEmpty(struct stack* S) {
  return S->top == -1;
}

void push(struct stack* S, int c) {
  S->top += 1;
  S->arr[S->top] = c;
}

int pop(struct stack* S) {
  if (isEmpty(S)) return 0;

  int c = S->arr[S->top];
  S->top -= 1;
  return c;
}

int peek(struct stack* S) {
  return S->arr[S->top];
}

bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize) {
  struct stack* s = init(pushedSize);
  int j = 0;
  for(int i=0; i<pushedSize; i++)	{
    push(s, pushed[i]);

    while(!isEmpty(s) && peek(s)==popped[j]) {
      pop(s);
      j++;
    }
  }
  return isEmpty(s);
}

int main() {
  int pushed[] = {1,2,3,4,5};
  int popped[] = {4,5,3,2,1};
  assert(validateStackSequences(pushed, 5, popped, 5));
  return 0;
}