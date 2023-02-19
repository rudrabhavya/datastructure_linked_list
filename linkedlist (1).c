#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
void printarray(struct node *head,struct node *temp){
	temp=head;
	printf("the data is:");
	while(temp!=NULL)
	{
	    printf("%d",temp->data);
		temp=temp->next;
	    
	}
}
void insertion(struct node *head,struct node *temp){
	int z,p,i;
	printf("Insert element at 1.beginning 2.ending 3 specific position:");
	scanf("%d",&z);
	struct node *temp1,*new1;
	new1=(struct node *)malloc(sizeof(struct node));
	printf("Enter the data");
	scanf("%d",&new1->data);
	new1->next=NULL;
	if (z==1){
		new1->next=head;
		head=new1;
	}
	else if(z==2){
		temp->next=new1;
		new1->next=NULL;
		new1=temp;
	}
	else{
		printf("Enter the position:");
		scanf("%d",&p);
		temp1=head;
		for (i=0;i<p-2;i++){
			temp1=temp1->next;
		}
			new1->next=temp1->next;
			temp1->next=new1;
		temp1=new1;
	}
}

void main(){
	struct node *head,*newnode,*temp;
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
	insertion(head,temp);
	printarray(head,temp);

}
