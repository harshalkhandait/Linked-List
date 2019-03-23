#include <stdio.h>
#include <stdlib.h>
struct node{
  int data;
  struct node * next;
}*head1,*head2,*unin,*intersecn;
struct node* createList(struct node *head);
void traverseList(struct node *head);
void push(struct node** head, int data);
int isPresent(struct node *head, int data);
struct node* getIntersection(struct node *head1 , struct node *head2);
struct node* getUnion(struct node *head1 , struct node *head2);
void getDifference(struct node* tmp1,struct node* tmp2);
void subSet(struct node* sub, struct node* super);
int main() {
  printf("Lets Create first linked list\n");
  head1=createList(head1);
  printf("Lets Create second linked list\n");
  head2=createList(head2);
  printf("The First Linked List is \n");
  traverseList(head1);
  printf("The Second Linked List is \n");
  traverseList(head2);
  intersecn = getIntersection (head1, head2);
  unin = getUnion (head1, head2);
  printf ("\n Intersection list is \n");
  traverseList (intersecn);
  printf ("\n Union list is \n");
  traverseList (unin);
  printf ("\n Diffrence of list is \n");
  getDifference(head2,head1);
  printf ("\n Let's check if second list is subset of  first list or not? \n");
  subSet(head1,head2);
  return 0;
}
struct node* createList(struct node *head){
  int choice =1;
  while (choice) {
    struct node *temp,*ptr;
    temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL){
      printf("\nOut of Memory Space:\n");
      exit(0);
    }
    printf("\nEnter the Data for the Linked List:\n");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(head==NULL){
      head=temp;
    }else{
      ptr=head;
      while(ptr->next!=NULL){
        ptr=ptr->next;
      }
      ptr->next=temp;
    }
    printf("Want to Enter more elements ?\n");
    scanf("%d",&choice );
  }
  return head;
}
void traverseList(struct node *head){
    struct node *temp;
    if(head == NULL)
    {
        printf("List is empty.\n");
        return ;
    }
    temp = head;
    while(temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int isPresent (struct node *head, int data)
{
    struct node *t = head;
    while (t != NULL)
    {
        if (t->data == data) return 1;
        t = t->next;
    }
    return 0;
}
void push (struct node** head, int key)
{
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = key;
    newNode->next = (*head);
    (*head) = newNode;
}
struct node *getUnion(struct node *head1, struct node *head2)
{
    struct node *result = NULL;
    struct node *t1 = head1, *t2 = head2;
    while (t1 != NULL){
        push(&result, t1->data);
        t1 = t1->next;
    }
    while (t2 != NULL){
        if (!isPresent(result, t2->data))
            push(&result, t2->data);
        t2 = t2->next;
    }
    return result;
}
struct node *getIntersection(struct node *head1,struct node *head2){
    struct node *result = NULL;
    struct node *t1 = head1;
    while (t1 != NULL){
        if (isPresent(head2, t1->data))
            push (&result, t1->data);
        t1 = t1->next;
    }
    return result;
}
void getDifference(struct node* tmp1,struct node* tmp2){
	struct node* tmp22=tmp2;
	printf("\nDiffrence of First and Second List is :- \n ");
	int flag;
	while(tmp1!=NULL){
		flag=0;
		tmp2=tmp22;
		while(tmp2!=NULL){
			if(tmp1->data==tmp2->data){
				flag=1;
			}
			tmp2=tmp2->next;
		}
		if(flag==0){
				printf("%d ",tmp1->data);
		}
		tmp1=tmp1->next;
	}
}
void subSet(struct node* sub, struct node* super){
	struct node* sup=super;
	int flag;
	while(sub!=NULL){
		flag=0;
		sup=super;
		while(sup!=NULL){
			if(sub->data==sup->data)
				flag=1;
			sup=sup->next;
		}
		if(flag==0){
			printf("\nNo ! Second list is  not subset of  first list \n");
			return;
		}
		sub=sub->next;
	}
	if(flag==1){
    printf("\nYes ! Second list is  not subset of  first list \n");
	}
}
