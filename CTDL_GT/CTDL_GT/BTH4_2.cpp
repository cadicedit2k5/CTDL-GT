#include <iostream>
using namespace std;

struct Node {
	int val;
	Node* next;

	Node(int x = 0, Node* ptr = NULL) {
		val = x;
		next = ptr;
	}
};

struct SLL {
	Node* head;
	SLL() {
		head = NULL;
	}

	void addHead(int k) {
		head = new Node(k, head);
	}

	int erase(int x) {
		Node* tmp = head;
		Node* pre = NULL;
		while (tmp != NULL && tmp->val != x) {
			pre = tmp;
			tmp = tmp->next;
		}
		if (tmp == NULL) {
			return 0;
		}
		else {
			if (tmp == head) {
				head = head->next;
				return 1;
			}
			pre->next = tmp->next;
			tmp->next = NULL;
			delete tmp;
			return 1;
		}
	}

	Node* search(int k) {
		Node* tmp = head;
		while (tmp != NULL && tmp->val != k) {
			tmp = tmp->next;
		}
		return tmp;
	}

	void display() {
		if (head == NULL) {
			return;
		}
		Node * tmp = head;
		while (tmp != NULL) {
			cout << tmp->val << " ";
			tmp = tmp->next;
		}
	}
};

struct HashTable {
	SLL* table;
	int capacity;
	int n;

	HashTable(int m = 101) {
		capacity = m;
		n = 0;
		table = new SLL[capacity];
	}

	int hash(int k) {
		return k % capacity;
	}

	void insert(int k) {
		int bin = hash(k);
		table[bin].addHead(k);
		n++;
	}

	int erase(int k) {
		int bin = hash(k);
		if (table[bin].erase(k)) {
			return 1;
			n--;
		}
		else {
			return 0;
		}
	}

	Node* search(int k) {
		int bin = hash(k);
		return table[bin].search(k);
	}

	void display() {
		for (int i = 0; i < capacity; i++) {
			table[i].display();
		}
	}
};

int main() {
	HashTable h;
	int n;
	cin >> n;
	while (n--) {
		int x; cin >> x;
		h.insert(x);
	}
	h.display();
	if (h.erase(10)) {
		cout << "xoa 10 thanh cong\n";
	}
	else {
		cout << "Xoa khong thanh cong\n";
	}
	if (h.search(40)) {
		cout << "Tim thay\n";
	}
	else cout << "Khong thay\n";
	h.display();
	system("pause");
	return 0;
}