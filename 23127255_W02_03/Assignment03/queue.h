#ifndef LAB1_ASSIGN3_QUEUE_H
#define LAB1_ASSIGN3_QUEUE_H

class Node{
	int value;
	Node *next = nullptr;
public:
	Node(int value, Node *next);
	int getValue();
	Node *setNext(Node *next);
	Node *setNext(int value);
	Node *getNext();
};

class LinkedListQueue{
	Node *head = nullptr, *tail = nullptr;
	int cap = 0, num = 0;
public:
	LinkedListQueue(int cap);
	~LinkedListQueue();
	int getCapacity();
	LinkedListQueue *setCapacity(int cap);

	Node *getHead();
	Node *getTail();
	int getNum();
	
	void init(int capacity);
	void enqueue(int x);
	int dequeue();
	Node *peek();
	bool isEmpty();
	bool isFull();
	void clear();
};

#endif //LAB1_ASSIGN3_QUEUE_H
