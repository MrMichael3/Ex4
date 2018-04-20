//Michael Küchler, 16-924-318

#include <stdio.h>
#include <stdlib.h>

struct Node{
	int key;
	struct Node* next;
};

struct Queue{
	struct Node* stack1;
	struct Node* stack2;
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
	if(isEmpty(stackTop)==0){
		while(stackTop->next != NULL){
			printf("%d\n",stackTop->key);
			stackTop = stackTop->next;
		}
		//print first element
		printf("%d\n",stackTop->key);
	}	
}



void enQueue(struct Queue* q, int key){
	push(&q->stack1,key);
}

int deQueue(struct Queue* q){
	//empty stack
	if(isEmpty(q->stack1)){
		return -1;
	}
	//from stack 1 to stack 2
	int value;
	while(isEmpty(q->stack1)==0){
		value = pop(&q->stack1);
		push(&q->stack2,value);
	}
	//key to return
	int key = pop(&q->stack2);
	//from stack 2 back to 1
	while(isEmpty(q->stack2)==0){
		value = pop(&q->stack2);
		push(&q->stack1,value);
	}
	return key;
}
void printQueue(struct Queue* q){
	printf("Queue:\n");
	int value;
	//change order
	while(isEmpty(q->stack1)==0){
		value = pop(&q->stack1);
		push(&q->stack2,value);
	}
	printStack(q->stack2);
	
	
	
	
}
int main(){
	struct Queue* q = malloc(sizeof(struct Queue));
	q->stack1 = NULL;
	q->stack2 = NULL;
	enQueue(q,2);
	enQueue(q,8);
	enQueue(q,11);
	enQueue(q,15);
	deQueue(q);
	deQueue(q);
	enQueue(q,1);
	enQueue(q,5);
	printQueue(q);
	
}


