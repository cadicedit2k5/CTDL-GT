#pragma once
#include <iostream>
using namespace std;


struct Stack {
	int* st;
	int capacity;
	int t;

	Stack(int cap = 100) {
		st = new int[cap];
		t = -1;
		capacity = cap;
	}

	bool Stack::isEmpty() {
		return (t < 0);
	}

	int size() {
		return (t + 1);
	}

	void push(int x) {
		if (size() == capacity) {
			cout << "Stack da day!\n";
		}
		else {
			st[++t] = x;
		}
	}

	int pop() {
		if (isEmpty()) {
			cout << "Stack rong!\n";
		}
		else {
			return st[t--];
		}
	}


};