#include <iostream>
using namespace std;

struct Node {
	int val;
	Node* next;
	/*Node(int x) {
	val = x;
	next = nullptr;
	}*/
};
typedef Node* node;

void Node_NULL(node &l)
{
	l = nullptr;
}

node create_node(int x) {
	node tmp = new Node;
	tmp->val = x;
	tmp->next = nullptr;
	return tmp;
}

void print(node l) {
	node p = l;
	if (l == nullptr) {
		cout << "Rong!\n";
	}
	else {
		while (p != nullptr) {
			cout << p->val << " ";
			p = p->next;
		}
		cout << endl;
	}
}

bool find(node l, int x) {
	if (l == nullptr) {
		return false;
	}
	else {
		while (l != nullptr) {
			if (l->val == x) {
				return true;
			}
		}
	}
}

node insert_first(node &l, int x) {
	node p = create_node(x);
	p->next = l;
	return p;
}

node erase_first(node &l) {
	if (l == nullptr) {
		cout << "Danh sach rong!\n";
	}
	l = l->next;
	l->next = nullptr;
	return l;
}

node insert_last(node &l, int x) {
	node tmp = create_node(x);
	if (l == nullptr) {
		l = tmp;
	}
	else {
		node p = l;
		while (p->next != nullptr) {
			p = p->next;
		}
		p->next = tmp;
	}
	return l;
}

node erase_last(node &l) {
	node trc = nullptr;
	node sau = l;
	if (l == nullptr) {
		cout << "Danh sach rong!\n";
	}
	else {
		while (sau->next != nullptr) {
			trc = sau;
			sau = sau->next;
		}
		if (sau == l) {
			l = nullptr;
		}
		else {
			trc->next = nullptr;
		}
		delete sau;

	}
	return l;
}

bool del_x(node &l, int x) {
	node q = nullptr;
	node p = l;
	if (l == nullptr) return false;
	while (p != nullptr && p->val != x) {
		q = p;
		p = p->next;
	}
	if (q->next == nullptr) {
		delete p;
		q->next = nullptr;
	}
	else {
		q->next = p->next;
		delete p;
	}
	return true;
}

//node insert(node l, int x) {
//	node tmp = create_node(x);
//	if (l == nullptr) {
//		l = tmp;
//	}
//
//}

void b2() {
	node head = new Node;
	int x;
	int op;
	do {
		cout << "----------------------------------------\n";
		cout << "\t1) Tao DS rong.\n";
		cout << "\t2) Hien thi danh sach.\n";
		cout << "\t3) Them phan tu vao dau danh sach.\n";
		cout << "\t4) Them phan tu vao cuoi danh sach.\n";
		cout << "\t5) Xoa phan tu dau danh sach.\n";
		cout << "\t6) Xoa phan tu cuoi danh sach.\n";
		cout << "\t7) Tim x trong danh sach va xoa x.\n";
		cout << "Nhap op : ";
		cin >> op;
		switch (op) {
		case 1:
			Node_NULL(head);
			break;
		case 2:
			cout << "DSLK: ";
			print(head);
			break;
		case 3:
			cout << "Nhap x: ";
			cin >> x;
			head = insert_first(head, x);
			cout << "Them dau thanh cong!\n";
			break;
		case 4:
			cout << "Nhap x: ";
			cin >> x;
			head = insert_last(head, x);
			cout << "Them cuoi thanh cong!";
			break;
		case 5:
			head = erase_first(head);
			break;
		case 6:
			head = erase_last(head);
			break;
		case 7:
			cout << "Nhap phan tu can tim: ";
			cin >> x;
			if (del_x(head, x)) {
				cout << "Xoa " << x << " thanh cong!";
			}
			else {
				cout << "Khong the xoa!";
			}
			break;
		case 0:
			cout << "KET THUC BAI 3!";
			break;
		default:
			cout << "Khong co op hop le!";
			break;
		}
	} while (op != 0);
}

int main() {
	b2();
	system("pause");
	return 0;
}