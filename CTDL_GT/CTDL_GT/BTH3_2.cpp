#include <iostream>

using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;
	Node(int val = 0, Node* l = 0, Node* r = 0) {
		this->val = val;
		left = l;
		right = r;
	}
};

typedef Node* node;
node root;

void emptyTree() {
	root = NULL;
}

void insertNodeRegresion(node &p,int x) {
	if (p == NULL) {
		p = new Node(x);
	}
	else {
		if (p->val == x) {
			return;
		}
		else if (p->val > x) {
			insertNodeRegresion(p->left, x);
		}
		else {
			insertNodeRegresion(p->right, x);
		}
	}
}

node searchRegresion(node p, int x) {
	if (p == NULL) {
		return NULL;
	}
	if (p->val == x) 
		return p;
	else if (p->val > x) {
		searchRegresion(p->left, x);
	}
	else searchRegresion(p->right, x);
}

void searchStandFor(node &p, node &q) {
	if (q->left == NULL) {
		p->val = q->val;
		p = q;
		q = q->right;
	}
	return searchStandFor(p->left, q);
}

bool erase(node &T, int x) {
	if (T == NULL) {
		return 0;
	}
	if (T->val == x) {
		node p = T;
		if (T->left == NULL) {
			T = T->right;
		}
		else if (T->right == NULL) {
			T = T->left;
		}
		else {
			searchStandFor(p, T->right);
		}
		delete p;
		return 1;
	}
	if (T->val > x) {
		erase(T->left, x);
	}
	if (T->val < x) {
		erase(T->right, x);
	}
}

void duyetNLR(node p) {
	if (p == NULL) {
		return;
	}
	cout << p->val;
	duyetNLR(p->left);
	duyetNLR(p->right);
}

void duyetLNR(node p) {
	if (p == NULL) {
		return;
	}
	duyetLNR(p->left);
	cout << p->val;
	duyetLNR(p->right);
}

void duyetLRN(node p) {
	if (p == NULL) {
		return;
	}
	duyetLRN(p->left);
	duyetLRN(p->right);
	cout << p->val;
}

int countValue(node p) {
	if (p == NULL) return 0;
	return 1 + countValue(p->left) + countValue(p->right);
}

double total(node p) {
	if (p == NULL) {
		return 0;
	}
	return p->val + total(p->left) + total(p->right);
}

double avarageValue(node p) {
	int cnt = countValue(p);
	double sum = total(p);
	return sum / cnt;
}

int valueMax(node p) {
	while (p->right != NULL) {
		p = p->right;
	}
	return p->val;
}

bool snt(int x) {
	if (x < 2) {
		return false;
	}
	for (int i = 2; i <= sqrt(x); i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

int countPrime(node p) {
	if (p == NULL) {
		return 0;
	}
	if (snt(p->val)) {
		return 1 + countPrime(p->left) + countPrime(p->right);
	}
	else {
		return 0 + countPrime(p->left) + countPrime(p->right);
	}
}

//BT3
void insertNodeNormal(int x)
{

	node p = root;
	while (p != NULL) {
		if (p->val > x) {
			p = p->right;
		}
		else {
			p = p->left;
		}
	}
	p = new Node(x);
}

int main() {
	int x;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		insertNodeRegresion(root, x);
	}
	cout << avarageValue(root);
	system("pause");
	return 0;
}