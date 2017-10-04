#include <stdio.h>
#include <stdlib.h>

#include "Utils.c"
#include "BubbleSort.c"

int main()
{
    int* nums = createNums(10);
    for (int i = 0; i < 10; ++i) {
        printf("%d\n", nums[i]);
    }

    Node* head = createLinkedList(nums, 10, 0);
    showList(head, 20);

    printf("compare result %s\n", validate(nums, 10, head, 10) ? "true":"false");
    printf("Hello World\n");
    return 0;
}
