#ifndef BUBBLESORT_C
#define BUBBLESORT_C

#include <stdio.h>
#include <stdlib.h>
#include "Utils.c"

void sort(Node** head);

Node* floatUp(Node* head, int len);

void sort(Node** head) {
    int mu, lambda, total_len;
    bool has_cycle = findLen(*head, &mu, &lambda);
    
    total_len = mu + lambda;

    int now_len = total_len;
    while(now_len) {
        *head = floatUp(*head, now_len);
        -- now_len;
    }

    if (has_cycle)
        link(*head, total_len - 1, mu - 1);
}

Node* floatUp(Node* head, int len) {
    if (len == 1)
        return head;
    else {
        Node* a;
        Node* b;
        Node* t;
        a = head;
        b = head->next;

        if (a->val > b->val) {
            t = b->next;
            a->next = t;
            b->next = floatUp(a, len - 1);
            return b;
        } else {
            a->next = floatUp(b, len - 1);
            return a;
        }
    }
}

#endif
