#include <stdio.h>
#include <stdlib.h>

/*
 * Singly Linked List, only traverse forward
 * Node - has 2 params: data and address of next node
 */
struct Node {
    int data; //4 bytes
    struct Node *next; //8 bytes
}; //16 bytes (12 bytes + 4 bytes of padding)
struct Node* createNode(int data) {
    struct Node* tmp;
    tmp = (struct Node*) malloc(sizeof(struct Node*));
    tmp->data = data;
    tmp->next = NULL;
    return tmp;
}
struct Node* insertionAtHead(struct Node* head, int data) {
    struct Node* tmp = createNode(data);
    if (head == NULL) {
        //first node
        head = tmp;
        return head;
    }
    tmp->next = head;
    head = tmp;
    return head;
}
struct Node* insertionAtTail(struct Node* head, int data) {
    struct Node* tmp = createNode(data);
    struct Node* ptr = head;
    if (head == NULL) {
        //first node
        head = tmp;
        return head;
    }
    //traverse through the entire list and STOP at the tail
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = tmp;
    return head;
}
struct Node* deleteAtPos(struct Node* head, int pos) { //1 based indexing; head is at pos '1'.
    struct Node* ptr = head, *tmp; int i;
    //What if the list is empty?
    if (head == NULL) {
        printf("LL is empty.\n");
        return NULL;
    }
    //check the node to be head
    if (pos == 1) {
        head = head->next;
        free(ptr);
        return head;
    }
    /*
     * pos = 4 -> index = 3;
     * We want to STOP at index 2.
     * 24, 36, 48, 60, 72
     *  0   1   2   3   4
     */
    for (i=1; i<pos-1; i++) {
        if (ptr) {
            ptr = ptr->next;
        } else {
            printf("\'Positin\' is outside the boundary of the LL.\n");
            return head;
        }
    }
    tmp = ptr->next; //Node, we want to delete
    ptr->next = tmp->next;
    free(tmp);
    return head;
}
void display(struct Node *head) {
    struct Node *ptr = head;
    while (ptr) {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
int main() {
    struct Node *head = NULL;

    //Insert at head '24'
    head = insertionAtHead(head, 24); //LL: HEAD->24->NULL
    //Insert at head '12'
    head = insertionAtHead(head, 12); //LL: HEAD->12->24->NULL
    //Insert at head '10'
    head = insertionAtHead(head, 10); //LL: HEAD->10->12->24->NULL
    //Insert at Tail '36'
    head = insertionAtTail(head, 36); //LL: HEAD->10->12->24->36->NULL
    //Insert at Tail '48'
    head = insertionAtTail(head, 48); //LL: HEAD->10->12->24->36->48->NULL
    //Insert at Tail '60'
    head = insertionAtTail(head, 60); //LL: HEAD->10->12->24->36->48->60->NULL
    display(head);

    head = deleteAtPos(head, 3);
    display(head);

    head = deleteAtPos(head, 5);
    display(head);
    return 0;
}