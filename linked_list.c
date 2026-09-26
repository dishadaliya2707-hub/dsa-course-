#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

// display the list
void printList() {
    struct node *p = head;
    printf("\n[");

    // start from the beginning
    while (p != NULL) {
        printf(" %d ", p->data);
        p = p->next;
    }
    printf("]");
}

// insertion at the beginning
void insertatbegin(int data) {
    // create a link
    struct node *lk = (struct node*) malloc(sizeof(struct node));
    lk->data = data;

    // point it to old first node
    lk->next = head;

    // point first to new first node
    head = lk;
}

void insertatend(int data) {
    // create a link
    struct node *lk = (struct node*) malloc(sizeof(struct node));
    lk->data = data;
    lk->next = NULL;

    struct node *linkedlist = head;

    if (head == NULL) {
        head = lk;
        return;
    }

    while (linkedlist->next != NULL) {
        linkedlist = linkedlist->next;
    }

    linkedlist->next = lk;
}

void deleteatend() {
    if (head == NULL) {
        return;
    }
    
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct node *linkedlist = head;
    while (linkedlist->next->next != NULL) {
        linkedlist = linkedlist->next;
    }
    
    free(linkedlist->next);
    linkedlist->next = NULL;
}

void main() {
    // 50-> 22-> 12-> 30-> 44
    insertatbegin(12);
    insertatbegin(22);
    insertatend(30);
    insertatend(44);
    insertatbegin(50);

    printf("Linked List: ");
    // print list
    printList();
}