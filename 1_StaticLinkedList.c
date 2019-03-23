#include <stdio.h>
#include <stdlib.h>
struct node{
  int data;
  struct node *next;
}*head,*head3=NULL;
struct node* insertNodeAtEnd(int data,struct node *temp);
void traverseList(struct node *head);
int is_element_of(int key , struct node* head);
int is_empty(struct node* head);
int size(struct node* head);
void enumerate(struct node *head);
void build(int a,int b,int c,int d,int e,int f,int g,int h);
int main() {
	head=insertNodeAtEnd(7,head);
	head=insertNodeAtEnd(5,head);
	head=insertNodeAtEnd(77,head);
	head=insertNodeAtEnd(67,head);
	head=insertNodeAtEnd(3,head);
	head=insertNodeAtEnd(90,head);
  traverseList(head);
  printf("Lets Search for 7 in the Linked List\n");
  if (is_element_of(7,head)) {
    printf("Element is found \n");
  } else {
    printf("Element is not found \n");
  }
  printf("Lets Check if list is empty or not\n");
  if (is_empty(head)) {
    printf("List is Empty\n" );
  } else {
    printf("List is not Empty\n");
  }
  printf("Lets Check the size of Linked List \n");
  printf("Number of Element present in Linked List = %d\n",size(head));
  printf("The Enumerate function is \n");
  enumerate(head);
  printf("The Build Function is \n");
  build(17,33,48,03,80,59,92,60);
  return 0;
}
void traverseList(struct node*head) {
  struct node *temp;
  temp = head;
  while (temp!=NULL) {
    printf("%d\t", temp->data);
    temp = temp->next;
  }
  printf("\n");
}
struct node* insertNodeAtEnd(int data,struct node *temp){
  struct node* new=(struct node*)malloc(sizeof(int));
  new->data=data;
  new->next=NULL;
  if(temp==NULL){
  	temp=new;
  }else{
  	struct node *ptr=temp;
  	while(ptr->next!=NULL){
  		ptr=ptr->next;
  	}
  	ptr->next=new;
  	ptr=ptr->next;
  }
  return temp;
}
int is_element_of(int key , struct node* head){
  struct node *temp;
  temp = head;
  while(temp->next != NULL){
    if (key == temp->data) {
      return 1;
    }
    temp=temp->next;
  }
  return 0;
}
int is_empty(struct node* head){
  if (head == NULL)    return 1;
  else    return 0;
}
int size(struct node* head){
  struct node *temp;
  temp = head;
  int count=1;
  while (temp-> next!= NULL) {
    count++;
    temp = temp->next;
  }
  return count;
}
void enumerate(struct node *head){
  for (struct node *temp = head; temp != NULL; temp=temp->next) {
    printf("%d\t",(temp->data+13) );
  }
  printf("\n");
}
void build(int a,int b,int c,int d,int e,int f,int g,int h)
{
	int i;
	int array[8];
	array[0]=a,array[1]=b,array[2]=c,array[3]=d,array[4]=e,array[5]=f,array[6]=g,array[7]=h;
	struct node *new=(struct node*)malloc(sizeof(int));
	new->data=array[0];
	new->next=NULL;
	head3=new;
	struct node* tmp=head3;
	for(i=1;i<8;i++)
	{
		struct node *new=(struct node*)malloc(sizeof(int));
		new->data=array[i];
		new->next=NULL;
		tmp->next=new;
		tmp=tmp->next;
	}
  traverseList(head3);
	return;
}
