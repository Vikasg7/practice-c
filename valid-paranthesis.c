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

struct stack init(int len) {
    struct stack S;
    S.top = -1;
    S.len = len;
    S.arr = (char*) malloc(len * sizeof(char));
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

bool isEmpty(struct stack* S) {
    return S->top == -1;
}

bool isValid(char* str) {
    int len = strlen(str);
    struct stack S = init(len);
    
    int i; char chr;
    for (i = 0; i < len; i++) {
        chr = str[i];
        if (chr == '(' || chr == '{' || chr == '[') {
            push(&S, chr);
            continue;
        }
        char top = pop(&S);
        if ((top == '(' && chr == ')') ||
            (top == '[' && chr == ']') ||
            (top == '{' && chr == '}'))
                continue;
        return false;
    }

    if (!isEmpty(&S)) return false;
    return true;
}

int main() {
    assert(isValid("{}([]") == 0);
    assert(isValid("{}()[]") == 1);
    assert(isValid("{}([") == 0);
    assert(isValid("{}(]") == 0);
    return 0;
}