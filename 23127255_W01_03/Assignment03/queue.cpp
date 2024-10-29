#include "queue.h"

void LinkedListQueue::init(int capacity) {
	if (num != 0) {
		clear();
	}
	cap = capacity;
}

void LinkedListQueue::enqueue(int x) {
	if (num == cap) {
		return;
	}
	Node *n = new Node;
	n->value = x;
	if (head == nullptr) {
		head = n;
	} else {
		if (tail == nullptr) {
			head->next = n;
			tail = n;
		} else {
			tail->next = n;
			tail = n;
		}
	}
	num++;
}

int LinkedListQueue::dequeue() {
	if (num == 0) {
		return 0;
	}
	int value = head->value;
	Node *tmp = head;
	head = head->next;
	if (head == tail) {
		tail = nullptr;
	}
	num--;
	delete tmp;
	return value;
}

Node *LinkedListQueue::peek() {
	return head;
}

bool LinkedListQueue::isEmpty() {
	return head == nullptr;
}

bool LinkedListQueue::isFull() {
	return num == cap;
}

void LinkedListQueue::clear() {
	Node *cur = head;
	while (cur != nullptr) {
		Node *tmp = cur;
		cur = cur->next;
		delete tmp;
	}
	head = nullptr;
	tail = nullptr;
	num = 0;
}
