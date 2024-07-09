#pragma once
#include <iostream>
#include <string>
using namespace std;

struct SinhVien {
	string hoten;
	string mssv;
	double diemtb;
	SinhVien* next;
	SinhVien(string ht = "", string ms = "", double dtb = 0, SinhVien* nxt = 0) {
		hoten = ht;
		mssv = ms;
		diemtb = dtb;
		next = nxt;
	}
};

typedef SinhVien* sinhvien;

struct DSSV {
	sinhvien head;


	DSSV() {
		head = NULL;
	}

	bool isEmpty() {
		return (head == NULL);
	}

	void insert_first(string ht, string ms, double dtb) {
		head = new SinhVien(ht, ms, dtb, head);
	}

	void insert_last(string ht, string ms, double dtb) {
		if (isEmpty()) {
			insert_first(ht, ms, dtb);
		}
		else {
			sinhvien tmp = head;
			while (tmp->next != NULL) {
				tmp = tmp->next;
			}
			tmp->next = new SinhVien(ht, ms, dtb, NULL);
		}
	}

	string erase_first() {
		if (!isEmpty()) {
			sinhvien tmp = head;
			head = head->next;
			string ms = tmp->mssv;
			delete tmp;
			return ms;
		}
		return "";
	}

	string erase_last() {
		if (!isEmpty()) {
			sinhvien tmp = head;
			sinhvien pre = new SinhVien;
			while (tmp->next != NULL) {
				pre = tmp;
				tmp = tmp->next;
			}
			if (head == tmp) {
				head = NULL;
			}
			else {
				pre->next = NULL;
			}
			string ms = tmp->mssv;
			delete tmp;
			return ms;
		}
		return "";
	}

	void display() {
		if (isEmpty()) {
			cout << "DANH SACH RONG!";
		}
		else {
			sinhvien tmp = head;
			cout << "-------- DANH SACH SINH VIEN ---------\n";
			while (tmp != NULL) {
				cout << "Ho va ten: " << tmp->hoten << endl;
				cout << "MSSV: " << tmp->mssv << endl;
				cout << "Diem trung binh: " << tmp->diemtb << endl;
				cout << "--------------------------------------\n";
				tmp = tmp->next;
			}
		}
	}

	void insert(string ht, string ms, double dtb, string i_ms) {
		sinhvien tmp = head;
		while (tmp->mssv != i_ms && tmp != NULL) {
			tmp = tmp->next;
		}
		if (tmp == NULL) {
			cout << "Sinh vien co ma so " << i_ms << " khong ton tai trong danh sach!\n";
		}
		else {
			sinhvien new_sv = new SinhVien(ht, ms, dtb, tmp->next);
			tmp->next = new_sv;
		}
	}
};