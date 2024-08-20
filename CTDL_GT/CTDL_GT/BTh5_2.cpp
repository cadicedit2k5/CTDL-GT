#include <iostream>
using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;
	Node(int val = 0, Node* left = NULL, Node* right = NULL) {
		this->val = val;
		this->left = left;
		this->right = right;
	}
};
typedef Node* node;

struct BinaryTreeSearch {
	node root;

	BinaryTreeSearch() {
		root = NULL;
	}

	void insertNodeRegression(int x, node &tmp){
		if (tmp != NULL) {
			if (tmp->val == x) {
				return;
			}
			else if (x < tmp->val) {
				insertNodeRegression(x, tmp->left);
			}
			else {
				insertNodeRegression(x, tmp->right);
			}
		}
		tmp = new Node(x);
	}

	node searchNodeRegression(int x, node tmp) {
		if (tmp == NULL) {
			return NULL;
		}
		else {
			if (tmp->val == x) {
				return tmp;
			}
			else if (x < tmp->val) {
				searchNodeRegression(x, tmp->left);
			}
			else {
				searchNodeRegression(x, tmp->right);
			}
		}
	}

	void searchStandFor(node &p, node&q) {
		if (q->left == NULL) {
			p->val = q->val;
			p = q;
			q = q->right;
		}
		searchStandFor(p->left, q);
	}

	bool erase(int x, node tmp) {
		if (tmp == NULL) {
			return false;
		}
		else if (tmp->val == x) {
			node p = tmp;
			if (tmp->left == NULL) {
				tmp = tmp->right;
			}
			else if (tmp->right == NULL) {
				tmp = tmp->left;
			}
			else {
				searchStandFor(p, tmp->right);
			}
			delete p;
			return true;
		}
		if (tmp->val > x) {
			erase(x, tmp->left);
		}
		else {
			erase(x, tmp->right);
		}
	}
};