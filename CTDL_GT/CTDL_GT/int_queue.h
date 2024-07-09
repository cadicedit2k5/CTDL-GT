#pragma once
#include <iostream>

using namespace std;

struct ArrQueue {
	int* Q;
	int front, rear;
	int capacity;
	int n;
	ArrQueue(int cap = 100) {
		Q = new int[cap];
		capacity = cap;
		front = -1; rear = -1;
		n = 0;
	}

	bool isEmpty() {
		return (front = -1);
	}

	bool isFull() {
		return ((rear-front == capacity-1) ||(front-rear == -1));
	}

	void enqueue(int x) {
		if (isFull()) {
			cout << "Hang doi da day!\n";
		}
		else {
			if (isEmpty()) {
				front = 0;
			}
			else if (rear == capacity) {
				rear = -1;
			}
			Q[++rear] = x;
			n++;
		}
	}

	int dequeue() {
		if (isEmpty()) {
			cout << "Hang doi rong!\n";
		}
		else {
			int x = Q[front];
			if (front == rear) {
				front = rear = -1;
			}
			else if (front == capacity) {
				front = 0;
			}
			else {
				front++;
			}
			return x;
		}
	}
};

struct Node {
	int val;
	Node * next;
	Node(int x, Node* p = NULL) {
		val = x;
		next = p;
	}


};

struct SLL {
	Node* head;
	SLL() {
		head = NULL;
	}

	bool isEmpty() {
		return (head == NULL);
	}

	void them_cuoi(int x) {
		Node* tmp = head;
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = new Node(x);
	}
	int xoa_dau() {
		Node* tmp = head;
		head = head->next;
		int x = tmp->val;
		delete tmp;
		return x;
	}
};

struct LinkedQueue {
	SLL Q;
	int n;
	LinkedQueue() {
		n = 0;
	}

	bool isEmpty() {
		return (Q.isEmpty());
	}

	void enqueue(int x) {
		Q.them_cuoi(x);
	}

	int dequeue() {
		if (isEmpty()) {
			cout << "hang doi rong!\n";
		}
		else {
			int x = Q.xoa_dau();
			return x;
		}
	}
};