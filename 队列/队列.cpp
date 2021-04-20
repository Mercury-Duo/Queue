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
struct Node* CreatNode(int data) {//初始化节点
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
struct Queue* CreatQueue() {//新建队列
	struct Queue* myQueue = (struct Queue*)malloc(sizeof(struct Queue));
	myQueue->frontNode = myQueue->tailNode = NULL;
	myQueue->size = 0;
	return myQueue;
}
int empty(struct Queue* myQueue) {//判断是否为空
	if (myQueue->size == 0)return 0;
	return 1;
}
void push(struct Queue* myQueue, int data) {
	struct Node* node1 = CreatNode(data);
	if (myQueue->size == 0) {
		myQueue->frontNode = myQueue->tailNode = node1;
	}
	else {
		myQueue->tailNode->next = node1;
		myQueue->tailNode = node1;
	}
	myQueue->size++;
}
void pop(struct Queue* myQueue) {
	if (myQueue->size == 0) {
		printf("队为空");
		return;
	}
	else {
		struct Node* nextNode = myQueue->frontNode->next;
		free(myQueue->frontNode);
		myQueue->frontNode = nextNode;
		myQueue->size--;
	}
}

int main(void){}