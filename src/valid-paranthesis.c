#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

struct stack {
  int   top;
  int   len;
  char* arr;
};

struct stack* init(int len) {
  struct stack* S = (struct stack*) malloc(sizeof(struct stack*));
  S->top = -1;
  S->len = len;
  S->arr = (char*) malloc(len * sizeof(char));
  return S;
}

void push(struct stack* S, char c) {
  S->top += 1;
  S->arr[S->top] = c;
}

char pop(struct stack* S) {
  if (S->top < 0) return 0;

  char c = S->arr[S->top];
  S->top -= 1;
  return c;
}

char peek(struct stack* S) {
  return S->arr[S->top];
}

bool isEmpty(struct stack* S) {
  return S->top == -1;
}

bool isValid(char* str) {
  int len = strlen(str);
  struct stack* S = init(len);
  
  for (int i = 0; i < len; i++) {
    switch (str[i]) {
      case '(': push(S, ')'); break;
      case '{': push(S, '}'); break;
      case '[': push(S, ']'); break;
      default:
      if (isEmpty(S) || pop(S) != str[i])
        return false;
    }
  }

  return isEmpty(S);
}

int main() {
  assert(!isValid("{}([]"));
  assert(!isValid("{}(["));
  assert(!isValid("{}(]"));
  assert(isValid("{}()[]"));
  return 0;
}