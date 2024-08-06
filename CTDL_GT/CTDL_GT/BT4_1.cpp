#include <iostream>
#include "Thuvien.h"

using namespace std;

int main() {
	ThuVien thuvien;
	thuvien.addHead("1", "hello", "hello world", 5);
	thuvien.addHead("2", "hello", "hello world", 5);
	thuvien.addLast("3", "hello", "hello world", 5);
	thuvien.display();
	cout << "=================\n";
	thuvien.deleteid("3");
	thuvien.display();
	system("pause");
	return 0;
}
