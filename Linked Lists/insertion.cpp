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
node* insert(node* head, int data, int pos){
	node* temp = newnode(data);
	if(pos == 0){
		temp->next = head;
		return temp;
	}
	node* temp2 = head;
	while(--pos){
		temp2 = temp2->next;
	}
	temp->next = temp2->next;
	temp2->next = temp;
	return head;
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
	head =insert(head, 0, 3);
	temp = head;
	while(temp){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}
