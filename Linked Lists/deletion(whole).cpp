#include<iostream>
#include<malloc.h>
using namespace std;
struct node{
	int data;
	node* next;
};
node* newnode(int data){
	node* temp = (node *)malloc(sizeof(node));
	temp->data = data;
	return temp;
}
void deletion(node** head){
	node* curr = *head;
	node* next;
	while(curr != NULL){
		next = curr->next;
		free(curr);
		curr = next;
	}
	*head = NULL;
}
int main(){
	node* head = newnode(1);
	node* second = newnode(2);
	node* third = newnode(3);
	head->next = second;
	second->next = third;
	node* temp = head;
	while(temp){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
	deletion(&head);
	temp = head;
	while(temp){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}