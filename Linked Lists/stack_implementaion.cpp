// implementation of stack with the help of linked lists
#include <iostream>
#include <malloc.h>
using namespace std;
struct stacknode{
	int data;
	stacknode* next;
};
bool isempty(stacknode* stack){
	return !stack;
}
stacknode* newstacknode(int data){
	stacknode* temp = (stacknode *)malloc(sizeof(stacknode));
	temp->data = data;
	temp->next = NULL;
	return temp;
}
void push(stacknode** stack, int data){
	stacknode *temp = newstacknode(data);
	temp->next = *stack;
	*stack = temp;
}
int pop(stacknode** stack){
	if(isempty(*stack))
		return -1;
	stacknode* temp = *stack;
	*stack = (*stack)->next;
	int popped = temp->data;
	free(temp);
	return popped;
}
int main(){
	stacknode* root = NULL;
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{	int temp;
		cin>>temp;
		push(&root,temp);
	}
	while(!isempty(root))
		cout<<pop(&root)<<" ";
	cout<<endl;
}
