#ifndef UTILS_C
#define UTILS_C

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
Node* createLinkedList(int* nums, int nums_len, int loop_at);

int* createNums(int nums_len);

bool validate(int* nums, int nums_len, Node* head, int ll_len);

// Utils for displaying
void showList(Node* head);

// Implement here

#endif
