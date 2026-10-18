#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;};
int main(){
    struct Node *head1 = NULL, *head2 = NULL;
    struct Node *newNode, *temp;
    int i, value;
    printf("Enter 5 integers:\n");
    for (i = 0; i < 5; i++){
        scanf("%d", &value);
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;
        if (head1 == NULL){
            head1 = newNode;}
        else{
            temp = head1;
            while (temp->next != NULL){
                temp = temp->next;}
            temp->next = newNode;}
    }
    temp = head1;
    while (temp != NULL){
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = temp->data;
        newNode->next = head2;
        head2 = newNode;
        temp = temp->next;}
    printf("Reversed Linked List:\n");
    temp = head2;
    while (temp != NULL){
        printf("%d", temp->data);
        if (temp->next != NULL){
            printf("->");}
        temp = temp->next;}
    printf("\n");
    return 0;}