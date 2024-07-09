#include <iostream>
#include <int_stack.h>

using namespace std;

void menu() {
	Stack st, s; int val;
	int op;
	do {
		cout << "============================ MENU ============================\n";
		cout << "\t1) Them phan tu vao stack.\n";
		cout << "\t2) Xoa mot phan tu khoi stack.\n";
		cout << "\t3) Doi so thap phan sang nhi phan.\n";
		cout << "\t0) Ket thuc chuong trinh.\n";
		cout << "Nhap option: ";
		cin >> op;
		switch (op)
		{
		case 1:
			cout << "Nhap vao gia tri: ";
			cin >> val;
			st.push(val);
			break;
		case 2:
			val = st.pop();
			break;
		case 3:
			cout << "Nhap vao gia tri he thap phan: ";
			cin >> val;
			cout << "Gia tri he nhi phan cua " << val << " la: ";
			while (val!=0) {
				s.push(val % 2);
				val /= 2;
			}
			while (!s.isEmpty()) {
				cout << s.pop();
			}
			cout << endl;
			break;
		case 0:
			cout << "KET THUC CHUONG TRINH!\n";
			break;
		default:
			cout << "Khong co lua chon hop le!\n";
			break;
		}
	} while (op != 0);
}

int main() {	
	menu();
	system("pause");
	return 0;
}