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
node* middle(node* head){	// returns the middle element
	node *temp1 = head, *temp2 = head;
	while(temp2->next){
		temp1 = temp1->next;
		temp2 = temp2->next;
		temp2 = temp2->next;
		if(!temp2)
			break;
	}
	return temp1;
}
int main(){
	node* head = newnode(1);
	node* second = newnode(2);
	node* third = newnode(3);
	node* fourth = newnode(4);
	head->next = second;
	second->next = third;
	third->next = fourth;
	node* temp = head;
	while(temp){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
	cout<<middle(head)->data<<endl;
}
