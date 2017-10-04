#ifndef UTILS_C
#define UTILS_C

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX(a,b) (((a)>(b))?(a):(b))

// Basic Linked List Node Definition
typedef struct __node
{
    int val;
    struct __node* next;
} Node;


// Utils for calculation
bool findLen(Node* head, int** mu, int** lambda);

void link(Node* head, int from, int to);

// Utils for generating testing data
Node* newNode(int val, Node* next);

Node* createLinkedList(int* nums, int nums_len, int loop_at);

int* createNums(int nums_len);

bool validate(int* nums, int nums_len, Node* head, int ll_len);

// Utils for displaying
void showList(Node* head, int len);



// Implement here
// Cal
void link(Node* head, int from, int to) {
    Node* f_node = NULL;
    Node* t_node = NULL;
    Node* cur = head;

    int i = 0, term = MAX(from, to) + 1;
    for(; i < term && cur != NULL; ++ i) {
        if (i == from) f_node = cur;
        if (i == to) t_node = cur;

        cur = cur->next;
    }

    if (i == term)
        f_node->next = t_node;
}

// Gen
Node* newNode(int val, Node* next) {
    Node* fac = (Node*) malloc(sizeof(Node));
    fac->val = val;
    fac->next = next;

    return fac;
}

Node* createLinkedList(int* nums, int nums_len, int loop_at) {
    Node* cur_head = NULL;

    int num_ptr = nums_len;
    while (num_ptr --) {
        cur_head = newNode(nums[num_ptr], cur_head);
    }

    if (loop_at >= 0 && loop_at < nums_len)
        link(cur_head, nums_len - 1, loop_at);

    return cur_head;
}

int* createNums(int nums_len) {
    srand(time(NULL));

    int* nums = (int*) malloc(sizeof(int) * nums_len);
    for (int i = 0; i < nums_len; ++ i) {
        nums[i] = rand() & 0x0000007f;
    }

    return nums;
}

// Display
void showList(Node* head, int len) {
    Node* nptr = head;

    printf("----Linked List Values----\n");

    while (len && nptr != NULL) {
        printf("%d\n", nptr->val);
        nptr = nptr->next;
        len--;
    }

    if (len != 0)
        printf("[Error]List Len Count Fail!! %d\n", len);

    printf("--------------------------\n");
}
#endif
