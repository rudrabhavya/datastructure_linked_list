#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
}*head,*temp;
struct node *head=NULL;
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
        while(temp3!=NULL){
            printf("%d  ",temp3->data );
            temp3=temp3->next ;
            c++;
        }
    }
	printf("\nNo of elements:%d\n",c);
}
void deletion(){
	int z,p,i;
	struct node *temp1,*fp;
	if (head==NULL){
			printf("The list is empty\n");
		}
	printf("Delete element at 1.beginning 2.ending 3.specific position 4.All:");
	scanf("%d",&z);
	if (z==1){
		temp=head;
		head=head->next;
		temp->next=NULL;
		free(temp);
		return;
	}
	if(z==2){
		temp1=head;
		temp=head;
		while(temp->next!=NULL){
          temp=temp->next ;
        }
		while (temp1->next!=temp){
			temp1=temp1->next;
		}
		fp=temp1->next;
		temp1->next=NULL;
		temp=temp1;
		free(fp);
		return;
	}
	if (z==3){
		printf("Enter the position:");
		scanf("%d",&p);
		temp1=head;
		if (p==0){
		    temp=head;
			head=head->next;
			temp->next=NULL;
			free(temp);
			return;	
		}
		for (i=0;i<p-1;i++){
			temp1=temp1->next;
		}
		fp=temp1->next;
		temp1->next=temp1->next->next;
		free(fp);
		return;
	}
	if (z==4){
		while(head!=NULL){
			temp=head;
			head=head->next;
			free(temp);
		}
	}
}
void search(){
	int l=0,key;
	temp=head;
	printf("Enter element to be searched:");
	scanf("%d",&key);
	if (head==NULL){
			printf("The list is empty\n");
		}
	while ((temp->data!=key) &&(temp->next!=NULL)){
		temp=temp->next;
		l++;
    }
    if ((temp->next==NULL)&&(temp->data!=key)){
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
        }
    else{printf("Insert element at 1.beginning 2.ending 3 specific position:");
	scanf("%d",&z);    
	printf("Enter the data:");
	}
	scanf("%d",&new1->data);
	new1->next=NULL;
	if (z==1){
		new1->next=head;
		head=new1;
		return;
	}
	if(z==2){
		temp2=head;
        while(temp2->next!=NULL)
        {
            temp2=temp2->next ;
        }
		temp2->next=new1;
		new1->next=NULL;
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
