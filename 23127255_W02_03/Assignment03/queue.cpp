#include "queue.h"

Node::Node(int value, Node *next = nullptr) : value(value), next(next) {}

int Node::getValue() {
	return this->value;
}

Node *Node::setNext(Node *next) {
	this->next = next;
	return this;
}

Node *Node::setNext(int value) {
	return this->setNext(new Node(value));
}

Node *Node::getNext() { return this->next; }

LinkedListQueue::LinkedListQueue(int cap) {
	this->init(cap);
}

LinkedListQueue::~LinkedListQueue() {
	this->clear();
}

int LinkedListQueue::getCapacity() {
	return this->cap;
}

LinkedListQueue *LinkedListQueue::setCapacity(int cap) {
	this->cap = cap;
	return this;
}

Node *LinkedListQueue::getHead() { return this->head; }
Node *LinkedListQueue::getTail() { return this->tail; }
int LinkedListQueue::getNum() { return this->num; }

void LinkedListQueue::init(int capacity) {
	if (this->num != 0) {
		clear();
	}
	this->cap = capacity;
}

void LinkedListQueue::enqueue(int x) {
	if (this->num == this->cap) {
		return;
	}
	Node *n = new Node(x);
	if (this->head == nullptr) {
		this->head = n;
	} else {
		if (this->tail == nullptr) {
			this->head->setNext(n);
			this->tail = n;
		} else {
			this->tail->setNext(n);;
			this->tail = n;
		}
	}
	this->num++;
}

int LinkedListQueue::dequeue() {
	if (this->num == 0) {
		return 0;
	}
	int value = this->head->getValue();
	Node *tmp = this->head;
	this->head = this->head->getNext();
	if (this->tail == nullptr) {
		delete this->head;
		this->num = 0;
		return value;
	}
	if (this->head == this->tail) {
		this->tail = nullptr;
	}
	this->num--;
	delete tmp;
	return value;
}

Node *LinkedListQueue::peek() {
	return this->head;
}

bool LinkedListQueue::isEmpty() {
	return this->num == 0; // or this->head == nullptr;
}

bool LinkedListQueue::isFull() {
	return this->num == this->cap;
}

void LinkedListQueue::clear() {
	Node *cur = this->head;
	while (cur != nullptr) {
		Node *tmp = cur;
		cur = cur->getNext();
		delete tmp;
	}
	this->head = nullptr;
	this->tail = nullptr;
	this->num = 0;
}
