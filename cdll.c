#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *prev;
	int data;
	struct node *next;
}*head,*temp;
struct node *head=NULL;
struct node *temp=NULL;

void traverse(){
	int c=0;
	struct node *temp3;
	if(head==NULL) {
		printf("List is empty\n");
        return;
        }
    else{
        temp3=head;
        printf("The List elements are:");
        while(temp3!=temp){
            printf("%d  ",temp3->data );
            temp3=temp3->next ;
            c++;
        }
        printf("%d  ",temp3->data );
        printf("\nNo of elements:%d\n",c+1);
    }
}
void deletion(){
	int z,p,i;
	struct node *temp1;
	if (head==NULL){
			printf("The list is empty\n");
		}
	printf("Delete element at 1.beginning 2.ending 3 specific position:");
	scanf("%d",&z);
	if (z==1){
		temp1=head;
		head=head->next;
		head->prev=temp1->prev;
		temp1->next=NULL;
		temp1->prev=NULL;
		return;
	}
	if(z==2){
		temp1=head;
		while (temp1->next!=temp){
			temp1=temp1->next;
		}
		temp1->next=head;
		temp->prev=NULL;
		temp->next=NULL;
		temp=temp1;
		return;
	}
	if (z==3){
		printf("Enter the position:");
		scanf("%d",&p);
		temp1=head;
		if (p==1){
		temp1=head;
		head=head->next;
		head->prev=temp1->prev;
		temp1->next=NULL;
		temp1->prev=NULL;
		return;
		}
		for (i=0;i<p-1;i++){
			temp1=temp1->next;
		}
		if (temp1==temp){
			temp1=head;
		while (temp1->next!=temp){
			temp1=temp1->next;
		}
		temp1->next=head;
		temp->prev=NULL;
		temp->next=NULL;
		temp=temp1;
		return;
		}
		else{
		
		if (temp1->next->next!=temp){
		temp1->next->next->prev=temp1;}
		temp1->next=temp1->next->next;
		//temp1->next->next=NULL;
		return;}
	}
}
void search(){
	int l=0,key;
	struct node *temp1;
	temp1=head;
	printf("Enter element to be searched:");
	scanf("%d",&key);
	if (head==NULL){
			printf("The list is empty\n");
		}
	while ((temp1->data!=key) &&(temp1->next!=head)){
		temp1=temp1->next;
		l++;
    }
    if ((temp1->next==head)&&(temp->data!=key)){
    	printf("Element is not found\n");
	}
	else{
		printf("Element is found at location %d\n",l);
	}
}
void insertion(){
	int z,p,i;
	struct node *temp1,*new1,*temp2;
	new1=(struct node *)malloc(sizeof(struct node));
	if(head==NULL){
		printf("Enter the data:");
		head=new1;
		temp=new1;
        }
    else{printf("Insert element at 1.beginning 2.ending 3 specific position:");
	scanf("%d",&z);    
	printf("Enter the data:");
	}
	scanf("%d",&new1->data);
	new1->next=NULL;
	new1->prev=NULL;
	if (z==1){
		new1->next=head;
		new1->prev=temp;
		head->prev=new1;
		head=new1;
		return;
	}
	if(z==2){
		temp->next=new1;
		new1->next=head;
		new1->prev=temp;
		temp=new1;
		return;
	}
	if (z==3){
		printf("Enter the position:");
		scanf("%d",&p);
		temp1=head;
		for (i=0;i<p-1;i++){
			temp1=temp1->next;
		}
			new1->next=temp1->next;
			temp1->next=new1;
			new1->prev=temp1;
			temp1->next->prev=new1;
		temp1=new1;
		return;
	}
}
void main(){
	int x=1,a;
	while(x==1){
		printf("MENU LIST\n");
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Search\n");
		printf("4.Traverse\n");
		printf("5.Exit\n");
		printf("Enter choice:");
		scanf("%d",&a);
		switch(a){
			case 1:insertion();
			break;
			case 2:deletion();
			break;
			case 3:search();
			break;
			case 4:traverse();
			break;
			case 5:exit(0);
		}
	printf("Do you want to continue the process(YES-1/NO-0):");
		scanf("%d",&x);	
	}
}
