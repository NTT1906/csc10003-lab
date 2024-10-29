#include <iostream>

#include "queue.h"

using namespace std;

void printQueue(LinkedListQueue &q) {
	Node *cur = q.head;
	cout << "Queue: {";
	while (cur != nullptr) {
		cout << cur->value;
		if (cur->next != nullptr) cout << ", ";
		cur = cur->next;
	}
	cout << "}.\n";
}

int main() {
	LinkedListQueue q;
	q.init(10);
	q.enqueue(12);
	q.enqueue(11);
	printQueue(q);
	q.enqueue(14);
	q.enqueue(16);
	q.enqueue(155);
	printQueue(q);
	q.clear();

	q.dequeue();
	printQueue(q);
	cout << "Queue is " << (q.isEmpty() ? "empty" : (q.isFull() ? "full" : "opened")) << ".\n";
	q.enqueue(153);
	q.enqueue(-13);
	q.enqueue(133);
	printQueue(q);
	q.dequeue();
	printQueue(q);
	cout << "Queue is " << (q.isEmpty() ? "empty" : (q.isFull() ? "full" : "opened")) << ".\n";
	return 0;
}
