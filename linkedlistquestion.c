#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;


}Node;
void Insertatbeginning(Node **head,int data){
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data =data;
    new_node->next = (*head);
    (*head) = new_node;
}
void insertafter(Node *prev,int data){
    if(prev==NULL){
        printf("Please pass real address");
    }
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = prev->next;
    prev->next = new_node;
}
void insertatend(Node **head,int data){
    Node *new_node =(Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    if(*head ==NULL){
        *head = new_node;
        return;
    }
    Node *last = *head;
    while(last->next != NULL){
        last = last->next;
    }
    last->next = new_node;
}

void printlist(Node *head){
    while(head->next !=NULL){
        printf("%d ->",head->data);
        head = head->next;
    }
    printf("%d\n",head->data);
}
int backsum(Node *head){
    int sum =0;
    int count = 0;
    while(head->next != NULL){
        sum = sum + power10(head->data,count);
        count++;
        head = head->next;
    }
    sum = sum + power10(head->data,count);
    return sum;
}
int power10(int a,int b){
    int n =a;
    if(b==0){
        return n;
    }
    for(int i=0;i<b;i++){
        n  =n*10;
    }
    return n;
}
int main(){
    printf("How many numbers you want in linked list 1:-");
    int n;
    scanf("%d",&n);
    Node *head1=NULL;
    for(int i=0;i<n;i++){
        int data;
        printf("enter %d number:-",i+1);
        scanf("%d",&data);
        insertatend(&head1,data);
    }
    printlist(head1);
    int num1 = backsum(head1);
    printf("%d\n",num1);
     printf("How many numbers you want in linked list 2:-");
    int a;
    scanf("%d",&a);
    Node *head2=NULL;
    for(int i=0;i<a;i++){
        int data;
        printf("enter %d number:-",i+1);
        scanf("%d",&data);
        insertatend(&head2,data);
    }
    printlist(head2);
    int num2 = backsum(head2);
    printf("%d\n",num2);
    int num3 = num1 + num2;
    printf("%d\n",num3);
    Node *reshead = NULL;
    while(num3 !=0){
        int rem = num3%10;
        insertatend(&reshead,rem);
        num3 = num3/10;
    }
    printlist(reshead);
}