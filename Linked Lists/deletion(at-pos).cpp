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
void deletion(node** head, int pos){
	if(*head == NULL)
		return;
	node* temp = *head;
	if(pos == 0){
		*head = temp->next;
		free(temp);
		return;
	}
	while(--pos){
		temp = temp->next;	
		if(temp == NULL)
			return;	
	}
	if(temp->next == NULL)
		return;
	free(temp->next);
	temp->next = temp->next->next;
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
	deletion(&head, 3);
	temp = head;
	while(temp){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}