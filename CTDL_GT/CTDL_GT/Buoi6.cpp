#include <iostream>
using namespace std;

struct DSD {
	int *a;
	int n;
	int capacity;

	DSD(int cap = 100) {
		a = new int[cap];
		capacity = cap;
	}

	void nhap() {
		cout << "Nhap n = ";
		cin >> n;
		for (int i = 0; i < n; i++) {
			cout << "Nhap a[" << i << "] = ";
			cin >> a[i];
		}
	}

	void xuat() {
		for (int i = 0; i < n; i++) {
			cout << "a[" << i << "] = " << a[i] << endl;
		}
		cout << endl;
	}


	void xuat_k() {
		for (int i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
	}

	int search(int x) {
		int i = 0;
		while (i < n && a[i] != x) {
			i++;
		}
		if (i == n) {
			return -1;
		}
		return i;
	}

	//Mang phai la mang da duoc sap sep
	int binarySearch(int x) {
		int left = 0, right = n - 1, mid;
		while (left < right) {
			mid = (left + right) / 2;
			if (x == a[mid]) return mid;
			else if (x > a[mid]) left = mid + 1;
			else right = mid - 1;
		}
		return -1;
	}
};




int main() {
	DSD d;
	d.nhap();
	d.xuat();
	cout << d.search(10) << endl;
	cout << d.binarySearch(20) << endl;
	system("pause");
	return 0;
}