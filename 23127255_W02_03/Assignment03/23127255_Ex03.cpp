#include <iostream>

#include "queue.h"

using namespace std;

void printQueue(LinkedListQueue &q) {
	Node *cur = q.getHead();
	cout << "Queue: {";
	while (cur != nullptr) {
		cout << cur->getValue();
		if (cur->getNext() != nullptr) cout << ", ";
		cur = cur->getNext();
	}
	cout << "}.\n";
}

int main() {
	LinkedListQueue q(10);
	cout << "The capacity of queue is 10\n";
	cout << "Add 12, 11\n";
	q.enqueue(12);
	q.enqueue(11);
	printQueue(q);
	cout << "Add 14, 16, 155\n";
	q.enqueue(14);
	q.enqueue(16);
	q.enqueue(155);
	printQueue(q);
	cout << "Cleared queue\n";
	q.clear();

	q.dequeue();
	printQueue(q);
	cout << "Queue is " << (q.isEmpty() ? "empty" : (q.isFull() ? "full" : "opened")) << ".\n";
	cout << "Add 153, -13, 133\n";
    q.enqueue(153);
	q.enqueue(-13);
	q.enqueue(133);
	printQueue(q);
	cout << "Dequeue 153\n";
	q.dequeue();
	printQueue(q);
	cout << "Queue is " << (q.isEmpty() ? "empty" : (q.isFull() ? "full" : "opened")) << ".\n";
	return 0;
}
