
#include <stdio.h>

void change(int m) {
    m += 5;
}

int main() {
    int n = 10;
    change(n); 
    printf(" n value is %d", n); /* 10 */
    return 0;
}