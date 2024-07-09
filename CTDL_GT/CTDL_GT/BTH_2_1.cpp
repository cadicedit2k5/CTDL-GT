#include <iostream>
#include <bt1.h>
using namespace std;

void menu() {
	DSSV dssv;
	string ht = "", ms = "", i_ms ="";
	double dtb = 0.0;
	int op;
	do {
		cout << "============================ MENU ============================\n";
		cout << "\t1) Them sinh vien vao dau danh sach.\n";
		cout << "\t2) Them sinh vien vao cuoi danh sach.\n";
		cout << "\t3) Xoa sinh vien o dau danh sach.\n";
		cout << "\t4) Xoa sinh vien o cuoi danh sach.\n";
		cout << "\t5) Them sinh vien moi vao sau mot sinh vien co san.\n";
		cout << "\t6) Hien thi danh sach sinh vien.\n";
		cout << "\t0) Ket thuc chuong chuong trinh.\n";
		cout << "Nhap vao lua chon: ";
		cin >> op;
		switch (op) {
		case 1:
			cout << "Nhap ho va ten: ";
			cin.ignore();
			getline(cin, ht);
			cout << "Nhap MSSV: ";
			cin.ignore(0);
			getline(cin, ms);
			cout << "Nhap diem trung binh: ";
			cin >> dtb;
			dssv.insert_first(ht, ms, dtb);
			ht = ""; ms = ""; dtb = 0.0;
			break;
		case 2:
			cout << "Nhap ho va ten: ";
			cin.ignore();
			getline(cin, ht);
			cout << "Nhap MSSV: ";
			cin.ignore(0);
			getline(cin, ms);
			cout << "Nhap diem trung binh: ";
			cin >> dtb;
			dssv.insert_last(ht, ms, dtb);
			ht = ""; ms = ""; dtb = 0.0;
			break;
		case 3:
			ms = dssv.erase_first();
			if (ms == "") {
				cout << "Khong co sinh vien nao trong danh sach!\n";
			}
			else {
				cout << "Sinh vien co ma so " << ms << " da xoa thanh cong!";
			}
			ms = "";
			break;
		case 4:
			ms = dssv.erase_last();
			if (ms == "") {
				cout << "Khong co sinh vien nao trong danh sach!\n";
			}
			else {
				cout << "Sinh vien co ma so " << ms << " da xoa thanh cong!";
			}
			ms = "";
			break;
		case 5:
			cout << "Nhap MSSV co san: ";
			cin.ignore();
			getline(cin, i_ms);
			cout << "Nhap ho va ten: ";
			cin.ignore(0);
			getline(cin, ht);
			cout << "Nhap MSSV: ";
			cin.ignore(0);
			getline(cin, ms);
			cout << "Nhap diem trung binh: ";
			cin >> dtb;
			dssv.insert(ht, ms, dtb, i_ms);
			ht = ""; ms = ""; dtb = 0.0; i_ms = "";
			break;
		case 6:
			dssv.display();
			break;
		default:
			cout << "Khong co lua chon hop le! Nhap lai!\n";
			break;
		}
	} while (op != 0);
}

int main() {
	menu();
	system("pause");
	return 0;
}