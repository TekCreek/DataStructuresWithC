
#include <stdio.h>

int max(int a, int b) {
    if (a > b)
        return a;
    else    
        return b;

    /* return a > b ? a : b; */
}

int main() {
    int x = max(10, 20);
    int y = max(10, max(20, 30));
    int z = max(10, max(28, max(18, 5)));
    
    printf("\n x value %d y value %d z value %d", x, y, z);
}