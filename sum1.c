#include <stdio.h>
#include <string.h>

int sub(int x, int y) {
    return x - y;
}

int mul(int x, int y) {
    return x * y;
}

int add(int x, int y) {
    return x + y;
}

float div(int x, int y) {
    if (y == 0) {
        printf("Error: Division by zero\n");
        return 0;
    }
    return x / y;
}

typedef int (*fptr)(int, int);

typedef struct map {
    char name[10];
    fptr func;
} Map;

float perform_operation(char *oper, int x, int y) {
    Map ops[] = {{"add", add}, {"sub", sub}, {"mul", mul}, {"div", (fptr)div}};
    int n = sizeof(ops) / sizeof(ops[0]);
    for (int i = 0; i < n; i++) {
        if (strcmp(oper, ops[i].name) == 0) {
            if (strcmp(oper, "div") == 0) {
                return ops[i].func(x, y); // For division, return float
            } else {
                return (float)ops[i].func(x, y); // For other operations, cast result to float
            }
        }
    }
    printf("Invalid operation requested\n");
    return 0;
}

int main() {
    int x, y;
    char oper[10];
    scanf("%s %d %d", oper, &x, &y);
    float result = perform_operation(oper, x, y);
    if (strcmp(oper, "div") == 0) {
        printf("Output is %.2f\n", result); // Print division result as float
    } else {
        printf("Output is %.0f\n", result); // Print other results as integer
    }
    return 0;
}

