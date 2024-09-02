#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* createlist(int n) {
    struct node* newnode, *temp, *header;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = 9;
    newnode->next = NULL;
    header = newnode;
    temp = newnode;
    
    for (int i = 2; i <= n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = 9;
        newnode->next = NULL;
        temp->next = newnode;
        temp = temp->next;
    }
    
    return header;
}

int main() {
    int carry = 0;
    struct node *L1 = createlist(6);
    struct node *L2 = createlist(4);
    struct node* temp1 = L1;
    struct node* temp2 = L2;
    
    while (temp1 != NULL || temp2 != NULL || carry != 0) {
        int sum = carry;
        
        if (temp1 != NULL) {
            sum += temp1->data;
            temp1 = temp1->next;
        }
        
        if (temp2 != NULL) {
            sum += temp2->data;
            temp2 = temp2->next;
        }
        
        if (sum >= 10) {
            carry = 1;
            sum -= 10;
        } else {
            carry = 0;
        }
        
        printf("%d->", sum);
    }
    
    printf("NULL\n");
    return 0;
}
