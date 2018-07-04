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
node *detectCycle(node *head) {
    if (head == NULL || head->next == NULL) return NULL;
	node* firstp = head;
    node* secondp = head;
    bool isCycle = false;
	while(firstp != NULL && secondp != NULL) {
        firstp = firstp->next;
        if (secondp->next == NULL) return NULL;
        secondp = secondp->next->next;
        if (firstp == secondp) { isCycle = true; break; }
    }
	if(!isCycle) return NULL;
	firstp = head;
	while( firstp != secondp) {
	    firstp = firstp->next;
	    secondp = secondp->next;
	}
	return firstp;    
}
int main(){
	node* head = newnode(1);
	node* second = newnode(2);
	node* third = newnode(3);
	head->next = second;
	second->next = third;
	third->next = second;
	if(!detectCycle(head))
		cout<<-1<<endl;
	else
		cout<<detectCycle(head)->data<<endl;
}