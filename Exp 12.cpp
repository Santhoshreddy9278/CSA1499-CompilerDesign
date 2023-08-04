#include <stdio.h>
#include <ctype.h>
void E();
void Eprime();
void T();
void Tprime();
void F();

char input[100];
int position = 0;

int main() {
    printf("Enter the string to be checked: ");
    scanf("%s", input);
    
    E();
    
    if (input[position] == '\0') {
        printf("string is accepted!\n");
    } else {
        printf("string is not accepted\n");
    }
    
    return 0;
}

void E() {
    T();
    Eprime();
}

void Eprime() {
    if (input[position] == '+') {
        position++;
        T();
        Eprime();
    }
}

void T() {
    F();
    Tprime();
}

void Tprime() {
    if (input[position] == '*') {
        position++;
        F();
        Tprime();
    }
}

void F() {
    if (input[position] == '(') {
        position++;
        E();
        if (input[position] == ')') {
            position++;
        } else {
            printf("string is not accepted\n");
        }
    } else if (isalpha(input[position])) {
        position++;
    } else {
        printf("string is not accepted\n");
    }
}
