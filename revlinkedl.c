#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
}*head,*temp;
struct node *head=NULL;
void traverse(){
	struct node *temp3;
	if(head==NULL) {
		printf("List is empty\n");
        return;
        }
    else{
        temp3=head;
        while(temp3!=NULL){
            printf("%d  ",temp3->data );
            temp3=temp3->next ;}
    }
}
void reverse(){
	struct node *pnode=NULL,*cnode,*nnode=NULL;
	cnode=head;
	while (cnode!=NULL){
		nnode=cnode->next;
		cnode->next=pnode;
		pnode=cnode;
		cnode=nnode;
	}
	head=pnode;
}
void main(){
	struct node *newnode;
	head=NULL;
	int choice=1;
	while (choice==1){
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("Enter the data");
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		if (head==NULL){
			head=newnode;
			temp=newnode;
		}
		else{
			temp->next=newnode;
			temp=newnode;
		}
		printf("Do you want to continue yes-1,no-0");
		scanf("%d",&choice);
	}
	printf("\nThe linked list :");
	traverse();
	reverse();
	printf("\nThe reverse of linked list :");
	traverse();
}
