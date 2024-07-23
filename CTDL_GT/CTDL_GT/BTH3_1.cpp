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

	void selectionSort() {
		for (int i = 0; i < n - 1; i++) {
			int min = a[i];
			int i_min = i;
			for (int j = i + 1; j < n; j++) {
				if (a[j] < a[i]) {
					i_min = j;
				}
			}
			swap(a[i], a[i_min]);
		}
	}

	void interchangeSort() {
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (a[j] < a[i]) {
					swap(a[i], a[j]);
				}
			}
		}
	}

	void insertionSort() {
		for (int i = 1; i < n; i++) {
			int x = a[i];
			int j = i - 1;
			while (j >= 0 && a[j] > x) {
				a[j + 1] = a[j];
				j--;
			}
			a[j + 1] = x;
		}
	}

	void bubbleSort() {
		for (int i = 0; i < n - 1; i++) {
			for (int j = n - 1; j > i; j--) {
				if (a[j] < a[i]) {
					swap(a[i], a[j]);
				}
			}
		}
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
	d.bubbleSort();
	d.xuat_k();
	cout << d.search(10) << endl;
	cout << d.binarySearch(20) << endl;
	system("pause");
	return 0;
}