#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 3
#define SIZE 100

typedef struct Stack {
    char items[MAX][SIZE];
    int top;
} Stack;

void initStack(Stack* s) {
    // Starting at -1 because top will be incremented making the first value 0
    s->top = -1;
}

int isEmpty(Stack* s) {
    // 1 if empty 0 if not empty
    return s->top == -1;
}

int isFull(Stack* s) {
    // 1 if full 0 if not full
    return s->top == MAX - 1;
}

void push(Stack* s, char* website) {
    if (isFull(s)) {
        printf("History is full\n");
    } else {
        // Increment top and place website in items array at position top i.e. items[top] = website
        // Example: items[0] = "www.google.com"
        s->top++;
        strcpy(s->items[s->top], website);
    }
}

char* pop(Stack* s) {
    if (isEmpty(s)) {
        printf("History is empty\n");
        return NULL;
    } else {
        // Return the item at the top of the stack then decrement
        // return s->items[s->top--]; Will perform return s->items[s->top] then do s->top--
        // Basically will return first then decrement
        return s->items[s->top--];
    }
}

void printStack(Stack* s, const char* name) {
    printf("%s Stack:\n", name);
    if (isEmpty(s)) {
        printf("  (empty)\n");
    } else {
        // Starting at top and decrementing so visually the item at the top is on top
        for (int i = s->top; i >= 0; i--) {
            printf("  %s\n", s->items[i]);
        }
    }
    printf("\n");
}

void goBack(Stack* backStack, Stack* forwardStack, char* currentPage) {
    if (isEmpty(backStack)) {
        printf("No previous page\n");
        return;
    }
    
    // Push the current page onto the forward stack
    push(forwardStack, currentPage);

    // Pop the next page from the back stack
    char* previousPage = pop(backStack);
    printf("Going back to: %s\n", previousPage);

    // Update the current page
    strcpy(currentPage, previousPage);
}

void goForward(Stack* forwardStack, Stack* backStack, char* currentPage) {
    if (isEmpty(forwardStack)) {
        printf("No forward page\n");
        return;
    }

    // Push the current page onto the back stack
    push(backStack, currentPage);

    // Pop the next page from the forward stack
    char* nextPage = pop(forwardStack);
    printf("Going forward to: %s\n", nextPage);

    // Update the current page
    strcpy(currentPage, nextPage);
}

void displayCurrentPage(const char* currentPage) {
    printf("Current page: %s\n", currentPage);
}

int main() {
    Stack backStack;
    Stack forwardStack;
    initStack(&backStack);
    initStack(&forwardStack);
    char currentPage[SIZE];

    strcpy(currentPage, "www.reddit.com");
    push(&backStack, "www.youtube.com");
    push(&backStack, "www.google.com");

    printf("Initial State:\n");
    displayCurrentPage(currentPage);
    printStack(&backStack, "Back");
    printStack(&forwardStack, "Forward");

    goBack(&backStack, &forwardStack, currentPage);  // Go back from "www.reddit.com" to "www.youtube.com"
    printf("After Going Back:\n");
    displayCurrentPage(currentPage);
    printStack(&backStack, "Back");
    printStack(&forwardStack, "Forward");

    goBack(&backStack, &forwardStack, currentPage);  // Go back from "www.youtube.com" to "www.google.com"
    printf("After Going Back Again:\n");
    displayCurrentPage(currentPage);
    printStack(&backStack, "Back");
    printStack(&forwardStack, "Forward");

    goForward(&forwardStack, &backStack, currentPage); // Go forward to "www.youtube.com"
    printf("After Going Forward:\n");
    displayCurrentPage(currentPage);
    printStack(&backStack, "Back");
    printStack(&forwardStack, "Forward");

    goForward(&forwardStack, &backStack, currentPage); // Go forward to "www.reddit.com" which is the original starting state
    printf("After Going Forward:\n");
    displayCurrentPage(currentPage);
    printStack(&backStack, "Back");
    printStack(&forwardStack, "Forward");

    return 0;
}
