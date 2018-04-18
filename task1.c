//Michael Küchler, 16-924-318

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
int pop(struct Node** stackTop){
	if(isEmpty(*stackTop)){
		return -1;
	}
	int key = (*stackTop)->key;
	struct Node *temp = (*stackTop)->next;
	free(*stackTop);
	*stackTop=temp;
	return key;
}
void printStack(struct Node* stackTop){
	printf("stack:\n");
	if(isEmpty(stackTop)==0){
		while(stackTop->next != NULL){
			printf("%d\n",stackTop->key);
			stackTop = stackTop->next;
		}
	}
	
}


int main(){
	return 0;
}
