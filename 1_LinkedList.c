#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
}*head;
//Declaration
void createList();
void traverseList();
int is_element_of(int key , struct node* head);
void add(int data);
void Remove(struct node *head ,int data);
int capacity(struct node* head);
int main(){
  // Creation of linked list
  createList();
  //Traversal of linked list
  traverseList();
  // Add(S,x)
  printf("Enter the element you want to add in the Linked List:");
  int key;
  scanf("%d",&key);
  add(key);
  //remove(S,x)
  printf("Enter the element you want to remove in the Linked List:");
  scanf("%d",&key);
  Remove(head,key);
  //Capacity of linked List
  printf("The size of linked list is : %d \n",capacity(head));
  return 0;
}
void createList(){
  int choice =1;
  while (choice) {
    struct node *temp,*ptr;
    temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL){
      printf("\nOut of Memory Space:\n");
      exit(0);
    }
    printf("\nEnter the Data for the Set / Linked List:\n");
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
}
void traverseList(){
    struct node *temp;
    if(head == NULL)
    {
        printf("List is empty.");
        return;
    }
    printf("The Linked List is :\n" );
    temp = head;
    while(temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int is_element_of(int key , struct node* head){
  struct node *temp;
  temp = head;
  while(temp->next != NULL){
    if (key == temp->data) {
      return 1;
    }
    temp = temp->next;
  }
  return 0;
}
void add (int data){
  if (is_element_of(data,head)) {
    printf("Element is Present\n");
  } else {
    struct node *newNode, *temp;
    newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL){
      printf("Unable to allocate memory.");
    }else{
      newNode->data = data;
      newNode->next = NULL;
      temp = head;
      while(temp->next != NULL)
        temp = temp->next;
      temp->next = newNode;
      printf("DATA INSERTED SUCCESSFULLY\n");
      traverseList();
    }
  }
}
void Remove(struct node *head ,int data){
  if (is_element_of(data,head)) {
    struct node *temp,*prev;
    temp = head;
    if (temp != NULL && temp->data == data) {
      head = temp->next;
      free(temp);
      return;
    }
    while(temp != NULL && temp ->data != data){
      prev = temp;
      temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
  } else {
    printf("Data is not present in the Linked List\n");
  }
  traverseList();
}
int capacity(struct node* head){
  struct node *temp;
  temp = head;
  int count=1;
  while (temp-> next!= NULL) {
    count++;
    temp = temp->next;
  }
  return count;
}
