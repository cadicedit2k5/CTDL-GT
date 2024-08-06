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

	void addLast(int k) {
		Node* tmp = head;
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = new Node(k);
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

struct DoThi {
	SLL* dothi;
	int capacity;
	int n;

	DoThi(int cap = 100, int len = 0) {
		capacity = cap;
		n = len;
		dothi = new SLL[cap];
	}

	void nhap() {
		cout << "Nhap so dinh: ";
		cin >> n;
		int d, m, x;
		for (int i = 0; i < n; i++) {
			cout << "Nhap vao dinh thu " << i + 1 << ": ";
			cin >> d;
			dothi[i].addHead(d);
			cout << "Nhap so dinh ke cua " << d << ": ";
			cin >> m;
			for (int j = 0; j < m; j++) {
				cout << "Nhap vao canh thu " << j + 1 << ": ";
				cin >> x;
				dothi[i].addLast(x);
			}
		}
	}

	void xuat() {
		for (int i = 0; i < n; i++) {
			cout << "Danh sach canh ke cua dinh thu " << i + 1 << ":";
			dothi[i].display();
			cout << endl;
		}
	}
};

int main() {
	DoThi d;
	d.nhap();
	d.xuat();
	system("pause");
	return 0;
}