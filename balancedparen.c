#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
struct Node {
    char data;
    struct Node* next;
};
struct Node* push(struct Node* top, char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = top;
    top = newNode;
    return top;
}
struct Node* pop(struct Node* top) {
    if (top == NULL) {
        printf("Error: stack is empty!\n");
        return NULL;
    }
    struct Node* temp = top;
    top = top->next;
    free(temp);
    return top;
}

bool arePair(char opening, char closing) {
    if (opening == '(' && closing == ')') return true;
    else if (opening == '{' && closing == '}') return true;
    else if (opening == '[' && closing == ']') return true;
    else return false;
}

bool areParenthesesBalanced(char exp[]) {
    struct Node* top = NULL;
    for (int i = 0; i < strlen(exp); i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            top = push(top, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            char opening = top ? top->data : '\0';
            top = pop(top);
            if (opening == '\0' || !arePair(opening, exp[i])) {
                return false;
            }
        }
    }

    return top == NULL;
}

int main() {
    char expression[100];
    printf("Enter an expression: ");
    fgets(expression, 100, stdin);
    if (areParenthesesBalanced(expression)) {
        printf("Balanced\n");
    } else {
        printf("Not Balanced\n");
    }

    return 0;
}
