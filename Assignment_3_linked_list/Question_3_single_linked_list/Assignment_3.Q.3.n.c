#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head;
void insert(int data){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data= data;
    newnode->next = head;
    head = newnode;
}

void print_list(){
    struct node *temp = head;
    while(temp != NULL){
        printf("->%d",temp->data);
        temp = temp->next;
    }
}

void rotate_list(){             //function for one time rotation.
    struct node *cur=head,*next;
    next = cur->next;
    int first = cur->data;
    while(cur->next != NULL){
        cur->data = next->data;
        cur = next;
        next = next->next;
    }
    cur->data = first;
}

void rotate_k_times(){      //function for k time rotation.
    int i,k;
    printf("\nHow many times u want to rotate the list: ");
    scanf("%d",&k);
    printf("Your list after rotated %d times:\n\t",k);
    for(i=0;i<k;i++){
        rotate_list();
    }
}

int main(){
    head = NULL;       /*Unordered insertion*/
    insert(2);
    insert(7);
    insert(12);
    insert(56);        /*Ordered Increasing insertion */
    insert(200);
    insert(77);
    insert(6);
    printf("Your Original list is:\n\t");
    print_list();
    rotate_k_times();
    print_list();
    return 0;
}
