#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Sach {
	string id;
	string title;
	string content;
	int score;
	Sach* next;

	Sach(string maso = "", string tieude = "", string noidung = "", int diem = 0, Sach* link= NULL) {
		id = maso;
		title = tieude;
		content = noidung;
		score = diem;
		next = link;
	}
};

struct ThuVien {
	Sach *head;

	ThuVien() {
		head = NULL;
	}

	void addHead(string ms, string tieude, string nd, int diem) {
		head = new Sach(ms, tieude, nd, diem, head);
	}
	
	void addLast(string ms, string tieude, string nd, int diem) {
		Sach* tmp = new Sach(ms, tieude, nd, diem);
		Sach* p = head;
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = tmp;
	}

	string deleteHead() {
		string ms = head->id;
		Sach* tmp = head;
		head = head->next;
		tmp->next = NULL;
		delete tmp;
		return ms;
	}

	string deleteLast() {
		Sach* pre = NULL;
		Sach* nxt = head;
		string ms;
		while (nxt->next != NULL) {
			pre = nxt;
			nxt = nxt->next;
		}
		if (pre == head) {
			ms = head->id;
			head == NULL;
			delete pre;
			return ms;
		}
		ms = nxt->id;
		pre->next = NULL;
		delete nxt;
		return ms;
	}

	void display() {
		if (head == NULL) {
			cout << "Danh Sach rong!\n";
		}
		Sach* tmp = head;
		while (tmp != NULL) {
			cout << "----------------------------\n";
			cout << tmp->id << endl;
			cout << tmp->title << endl;
			cout << tmp->content << endl;
			cout << tmp->score << endl;
			tmp = tmp->next;
		}
	}

	bool deleteid(string ms) {
		if (head->id == ms) {
			head = head->next;
			return true;
		}
		Sach* tmp = head;
		Sach* pre = NULL;
		while (tmp != NULL && tmp->id != ms) {
			pre = tmp;
			tmp = tmp->next;
		}
		if (tmp == NULL) {
			return false;
		}
		pre->next = tmp->next;
		tmp->next = NULL;
		delete tmp;
		return true;
	}
};