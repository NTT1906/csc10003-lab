#ifndef LAB1_ASSIGN3_QUEUE_H
#define LAB1_ASSIGN3_QUEUE_H

struct Node{
	int value;
	Node *next = nullptr;
};

struct LinkedListQueue{
	Node *head = nullptr, *tail = nullptr;
	int cap = 0, num = 0;

	void init(int capacity);
	void enqueue(int x);
	int dequeue();
	Node *peek();
	bool isEmpty();
	bool isFull();
	void clear();
};

#endif //LAB1_ASSIGN3_QUEUE_H
