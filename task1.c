//Michael K�chler, 16-924-318

#include <stdio.h>
#include <stdlib.h>

struct Node{
	int key;
	struct Node* next;
};

int isEmpty(struct Node* stackTop){
	if(stackTop == NULL){
		return 1;
	}
	return 0;
}
void push(struct Node** stackTop,int key){
	struct Node* newNode = malloc(sizeof(struct Node));
	newNode->key=key;
	newNode->next=*stackTop;
	*stackTop=newNode;
	
}
int pop(struct Node** stackTop,int key){
	
	return 0;
}
void printStack(struct Node* stackTop){
	
}


int main(){
	return 0;
}
