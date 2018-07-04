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
node* nthnodeEnd(node* head, int n){
	node *temp1 = head, *temp2 = head;
	while(n--)
		temp1 = temp1->next;
	while(temp1->next != NULL){
		temp2 = temp2->next;
		temp1 = temp1->next;
	}
	return temp2;
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
	cout<<nthnodeEnd(head,2)->data<<endl;
}