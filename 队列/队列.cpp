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
void push(struct Queue* myQueue, int data) {//入队
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
void pop(struct Queue* myQueue) {//出队
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
int front(struct Queue* myQueue){//获取队头元素
	if (myQueue->size == 0) {
		printf("队为空，无法获取队头元素");
		system("pause");
		return 0;
	}
	else {
		return myQueue->frontNode->data;
	}
}
int main(void){
	struct Queue* myQueue = CreatQueue();
	push(myQueue,1);
	push(myQueue, 2);
	push(myQueue, 3);
	push(myQueue, 4);
	push(myQueue, 5);
	push(myQueue, 6);
	push(myQueue, 7);
	push(myQueue, 8);
	push(myQueue, 9);
	while (empty(myQueue)) {
		printf("%d",front(myQueue));
		printf("\n");
		pop(myQueue);//出队
	}

}