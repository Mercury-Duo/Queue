#include<stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	struct Node* next;
};
struct Queue {
	int size;
	struct Node* frontNode;
	struct Node* tailNode;
};
struct Node* CreatNode(int data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
struct Queue* CreatQueue(int data) {
	struct Queue* myQueue = (struct Queue*)malloc(sizeof(struct Queue));
	//struct Node* node1 = CreatNode(data);
	myQueue->frontNode = myQueue->tailNode = NULL;
	myQueue->size = 0;
	return myQueue;
}
int empty(struct Queue* myQueue) {
	if (myQueue->size == 0)return 0;
	return 1;
}



int main(void){}