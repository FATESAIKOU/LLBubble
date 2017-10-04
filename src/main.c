#include <stdio.h>
#include <stdlib.h>

#include "Utils.c"
#include "BobbleSort.c"

int main()
{
    Node* test = (Node*)malloc(sizeof(Node));
    test->val = 1;
    printf("Hello World: Node val %d\n", test->val);
    return 0;
}
