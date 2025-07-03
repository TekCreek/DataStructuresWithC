#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// ==========================
// Stack for Operators
// ==========================
typedef struct {
    char *stk;
    int top;
    int size;
} OperatorStack;

void initOpStack(OperatorStack *s, int size) {
    s->stk = (char *)malloc(size * sizeof(char));
    s->top = -1;
    s->size = size;
}

int isOpFull(OperatorStack *s) {
    return s->top == s->size - 1;
}

int isOpEmpty(OperatorStack *s) {
    return s->top == -1;
}

void pushOp(OperatorStack *s, char ch) {
    if (isOpFull(s)) {
        printf("Stack overflow\n");
        exit(1);
    }
    s->stk[++s->top] = ch;
}

char popOp(OperatorStack *s) {
    if (isOpEmpty(s)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->stk[s->top--];
}

char atTopOp(OperatorStack *s) {
    if (isOpEmpty(s)) {
        printf("Stack empty\n");
        exit(1);
    }
    return s->stk[s->top];
}

// ==========================
// Postfix Conversion
// ==========================
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '(' || ch == ')');
}

int priority(char ch) {
    switch (ch) {
        case '(':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
    }
    return -1;
}

void convertToPostfix(const char *infix, char *postfix) {
    OperatorStack s;
    int len = strlen(infix);
    initOpStack(&s, len);
    int j = 0;

    for (int i = 0; i < len; i++) {
        char ch = infix[i];
        if (!isOperator(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            pushOp(&s, ch);
        } else if (ch == ')') {
            while (!isOpEmpty(&s)) {
                char x = popOp(&s);
                if (x == '(') break;
                postfix[j++] = x;
            }
        } else {
            while (!isOpEmpty(&s) && priority(atTopOp(&s)) >= priority(ch)) {
                postfix[j++] = popOp(&s);
            }
            pushOp(&s, ch);
        }
    }

    while (!isOpEmpty(&s)) {
        postfix[j++] = popOp(&s);
    }
    postfix[j] = '\0';
    free(s.stk);
}

// ==========================
// Stack for Operands
// ==========================
typedef struct {
    double *stk;
    int top;
    int size;
} OperandStack;

void initOperandStack(OperandStack *s, int size) {
    s->stk = (double *)malloc(size * sizeof(double));
    s->top = -1;
    s->size = size;
}

int isOperandEmpty(OperandStack *s) {
    return s->top == -1;
}

void pushOperand(OperandStack *s, double val) {
    if (s->top == s->size - 1) {
        printf("Operand stack overflow\n");
        exit(1);
    }
    s->stk[++s->top] = val;
}

double popOperand(OperandStack *s) {
    if (isOperandEmpty(s)) {
        printf("Operand stack underflow\n");
        exit(1);
    }
    return s->stk[s->top--];
}

// ==========================
// Expression Evaluation
// ==========================
double apply(double v1, double v2, char op) {
    switch (op) {
        case '+': return v1 + v2;
        case '-': return v1 - v2;
        case '*': return v1 * v2;
        case '/': return v1 / v2;
        case '%': return (int)v1 % (int)v2;
    }
    return 0;
}

double evaluateExpr(const char *expr) {
    char postfix[100];
    convertToPostfix(expr, postfix);

    OperandStack s;
    initOperandStack(&s, strlen(postfix));

    for (int i = 0; postfix[i]; i++) {
        char ch = postfix[i];
        if (isOperator(ch)) {
            double op2 = popOperand(&s);
            double op1 = popOperand(&s);
            pushOperand(&s, apply(op1, op2, ch));
        } else if (isdigit(ch)) {
            pushOperand(&s, ch - '0');
        } else {
            printf("Invalid character in expression: %c\n", ch);
            exit(1);
        }
    }

    double result = popOperand(&s);
    free(s.stk);
    return result;
}

// ==========================
// Main
// ==========================
int main() {
    char expr[100];

    printf("Enter an infix expression (e.g. 2+3*4): ");
    scanf("%s", expr);

    printf("Postfix expression: ");
    char postfix[100];
    convertToPostfix(expr, postfix);
    printf("%s\n", postfix);

    double result = evaluateExpr(expr);
    printf("Result: %.2lf\n", result);

    return 0;
}
