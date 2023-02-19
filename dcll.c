
//circular double linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *prev;
	int data;
	struct node *next;
}*head,*tail,*new,*temp;
struct node *head=NULL;
void create(){
    struct node *new;
    int data,c=1;
    while(c){
        new=(struct node *)malloc(sizeof(struct node));
        printf("enter the data:");
        scanf("%d",&data);
        new->data=data;
        new->next=NULL;
        if(head==NULL){
            head=new;
            tail=new;
            tail->next=head;
            head->prev=tail;
        }
        else{
            tail->next=new;
            new->prev=tail;
            tail=new;
            tail->next=head;
            head->prev=tail;
        }
        printf("do you want to cotinue(1-yes/0-no)");
        scanf("%d",&c);
    }
}
void traverse(){
	int count=0;
	struct node *temp;
	if(head==NULL) {
		printf("List is empty\n");
        return;
        }
    else{
        temp=head;
        printf("The List elements are:");
        while(temp!=tail){
            printf("%d  ",temp->data );
            temp=temp->next ;
            count++;
        }
        printf("%d  ",temp->data );
    }
	printf("\nNo of elements:%d\n",count+1);
}
void deletion(){
	int z,p,i;
	struct node *temp;
	temp=head;
	if (head==NULL){
			printf("The list is empty\n");
			return;
		}
	printf("Delete element at 1.beginning 2.ending 3.specific position:");
	scanf("%d",&z);
	if (z==1){
		head=head->next;
		head->prev=tail;
		temp->next=NULL;
		temp->prev=NULL;
		return;
	}
	if(z==2){
		while (temp->next!=tail){
			temp=temp->next;
		}
		temp->next=head;
		tail->prev=NULL;
		tail->next=NULL;
		tail=temp;
		head->prev=tail;
		return;
	}
	if (z==3){
		printf("Enter the position:");
		scanf("%d",&p);
		temp=head;
		for (i=0;i<p-1;i++){
			temp=temp->next;
		}
		temp->next=temp->next->next;
		temp->next->next->prev=temp;
		return;
	}
}
void search(){
	int l=0,key;
	struct node *temp;
	temp=head;
	printf("Enter element to be searched:");
	scanf("%d",&key);
	if (head==NULL){
			printf("The list is empty\n");
		}
	while ((temp->data!=key) &&(temp->next!=head)){
		temp=temp->next;
		l++;
    }
    if ((temp->next==head)&&(temp->data!=key)){
    	printf("Element is not found\n");
	}
	else{
		printf("Element is found at location %d\n",l);
	}
}
void insertion(){
	int z,p,i;
	struct node *temp,*new1;
	new1=(struct node *)malloc(sizeof(struct node));
    printf("Insert element at 1.beginning 2.ending 3 specific position:");
	scanf("%d",&z);    
	printf("Enter the data:");
	scanf("%d",&new1->data);
	if (z==1){
		new1->next=head;
		new1->prev=tail;
		head->prev=new1;
		head=new1;
		tail->next=head;
		return;
	}
	if(z==2){
		new1->next=head;
		new1->prev=tail;
		tail->next=new1;
		tail=new1;
		head->prev=tail;
		return;
	}
	if (z==3){
		printf("Enter the position:");
		scanf("%d",&p);
		temp=head;
		for (i=0;i<p-1;i++){
			temp=temp->next;
		}
			new1->next=temp->next;
			temp->next=new1;
			new1->prev=temp;
			new1->next->prev=new1;
			temp=new1;
		return;
	}
}
void main(){
	int x=1,a;
	while(x==1){
		printf("MENU LIST\n");
		printf("1.create\n2.Insert\n3.delete\n4.search\n5.traverse\n6.exit\n");
		printf("enter your choice:");
		scanf("%d",&a);
		switch(a){
		    case 1:create();
		    break;
			case 2:insertion();
			break;
			case 3:deletion();
			break;
			case 4:search();
			break;
			case 5:traverse();
			break;
			case 6:exit(0);
		}
	printf("Do you want to continue the process(YES-1/NO-0):");
		scanf("%d",&x);	
	}
}
