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
    int mu, lambda, mu2, lambda2, i, j;
    printf("|Len\t|LoopAt\t|Loop?\t|MU\t|lambda\t|findLen test\t|sort test\t|\n");
    for (i = 0; i < 4; i ++) {
        for (j = 0; j <= i; j ++) {
            nums = createNums(i);
            head = createLinkedList(nums, i, j);
            printf("|%d\t|%d\t|%s\t", i, j, findLen(head, &mu, &lambda) ? "true":"false");
            printf("|%d\t|%d\t", mu, lambda);

            // Sort
            qsort(nums, i, sizeof(int), cmp);
            sort(&head);

            findLen(head, &mu2, &lambda2);
            printf("|%s\t\t", (mu == mu2 && lambda == lambda2) ? "\x1B[32mpassed\x1B[37m":"\x1B[31mfailed\x1B[37m");
            printf("|%s\t\t|\n", validate(nums, i, head, mu + lambda) ? "\x1B[32mpassed\x1B[37m":"\x1B[31mfailed\x1B[37m");

            freeList(head, mu + lambda);
            free(nums);
        }
    }

    return 0;
}
