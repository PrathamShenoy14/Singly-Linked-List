#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

void traverse_nodes(struct node *head,int trav_choice){
    int count=0;
    struct node *ptr = head;
    if(trav_choice==1){
        while(ptr!=NULL){
            count++;
            ptr = ptr->link;
        }
        printf("The no. of nodes in the Linked List are %d\n",count);
    }
    else{
        while(ptr!=NULL){
            printf("%d\n",ptr->data);
            ptr = ptr->link;
        }
    }    
}

struct node* add_first(struct node *head,int info){
    struct node *temp = NULL;
    temp = (struct node*)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("Memory Allocation failed");
    }
    temp->data = info;
    temp->link = head;
    return temp;
}

void add_end(struct node *head,int info){
    struct node *temp = NULL;
    struct node *ptr = head;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = info;
    temp->link = NULL;
    while(ptr->link!=NULL){
        ptr= ptr->link;
    }
    ptr->link = temp;
}

struct node* add_bw(struct node *head,int pos,int info){
    if(pos==1){
        head = add_first(head,info);
    }
    else{
        struct node *temp =NULL;
        struct node *ptr =head;
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = info;
        while(pos!=2){
            ptr = ptr->link;
            pos--;
        }
        if(ptr->link==NULL){
            ptr->link = temp;
            temp-link = NULL;
        }    
        temp->link = ptr->link;
        ptr->link = temp;
    }
    return head;
}

struct node* del_single1(struct node *head){
    struct node *temp = head;
    return head->link;
    free(temp);
}

void del_single2(struct node *head,int pos){
        struct node *temp=head;
        struct node *ptr=head;;
        while(pos!=2){
            ptr = ptr->link;
            pos--;
        }
        temp = ptr->link;
        ptr->link = temp->link;
        free(temp);
}

struct node* del_all(struct node *head){
    struct node *temp = head;
    while(temp->link!=NULL){
        head = head->link;
        free(temp);
        temp = head;
    }
        free(temp);
        return NULL;
}

struct node* rev_list(struct node *head){
    struct node *next = head;
    struct node *prev = NULL;
    while(next!=NULL){
        next = next->link;
        head->link = prev;
        prev = head;
        head = next;
    }
    return prev;
}



int main(){
    int pos;
    struct node *head;
    head = (struct node*)malloc(sizeof(struct node));
    if(head == NULL){
        printf("Memory allocation failed");
    }
    int info;
    printf("Enter data in head node:");
    scanf("%d",&info);
    head->data = info;
    head->link = NULL;

    int choice=0;
    do{
        printf("Enter 1 to add node\n");
        printf("Enter 2 to delete node\n");
        printf("Enter 3 to traverse all nodes\n");
        printf("Enter 4 to reverse all nodes\n");
        printf("Enter 5 to exit program\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            int add_choice,info;
            printf("Enter 1 to add node at start\n");
            printf("Enter 2 to add node at end\n");
            printf("Enter 3 to enter node in between\n");
            scanf("%d",&add_choice);
            printf("Enter integer data for node:");
            scanf("%d",&info);
            if(add_choice==1){
                head = add_first(head,info);
            }
            else if(add_choice==2){
                add_end(head,info);
            }
            else{
                printf("Enter position at which u want to add a node:");
                scanf("%d",&pos);
                head = add_bw(head,pos,info);
            }
            break;
        case 2:
            int del_choice,pos;
            printf("Enter 1 to delete a single node\n");
            printf("Enter 2 to delete all nodes\n");
            scanf("%d",&del_choice);
            if(del_choice==1){
                printf("Enter position of node which you want to delete:");
                scanf("%d",&pos);
                if(pos==1){
                    head = del_single1(head);
                }
                else{
                    del_single2(head,pos);
                }
            }
            else{
                head = del_all(head);
            }
            break;
        case 3:
            int trav_choice;
            printf("Enter 1 to count no. of nodes\n");
            printf("Enter 2 to print data in every node\n");
            scanf("%d",&trav_choice);
            traverse_nodes(head,trav_choice);
            break;
        case 4:
            head = rev_list(head);
            break;
        case 5:
            printf("Thank You!");
            break;
        default:
            printf("Invalid option! Try Again");
            break;
        }
    }while(choice!=5);
}
