#include <stdio.h>
#include <stdlib.h>

#include "Utils.c"
#include "BubbleSort.c"

int cmp(const void *a, const void *b) {
    return *(int*)a > *(int*)b;
}

int main()
{
    int* nums;
    Node* head;
    int mu, lambda, i, j;
    printf("|Len\t|LoopAt\t|Loop?\t|MU\t|lambda\t|test\t|\n");
    for (i = 0; i < 1000; i ++) {
        for (j = 0; j <= i; j ++) {
            nums = createNums(i);
            head = createLinkedList(nums, i, j);
            printf("|%d\t|%d\t|%s\t", i, j, findLen(head, &mu, &lambda) ? "true":"false");
            printf("|%d\t|%d\t", mu, lambda);

            // Sort
            qsort(nums, i, sizeof(int), cmp);
            sort(&head);
            printf("|%s\t|\n", validate(nums, i, head, mu + lambda) ? "passed":"failed");

            freeList(head, mu + lambda);
            free(nums);
        }
    }

    return 0;
}
