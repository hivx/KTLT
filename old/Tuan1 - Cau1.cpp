#include <stdio.h>
#include <stdlib.h>

#define INCREMENT(x) ++x

int main() {
    char* ptr = "DHBK-HN";  // A string literal is assigned to ptr
    int x = 10;

    // 1st printf statement
    printf("%s  ", 1 + INCREMENT(ptr + 1));

    // 2nd printf statement
    printf("%d", 1 + INCREMENT(x + 1));

    return 0;
}
