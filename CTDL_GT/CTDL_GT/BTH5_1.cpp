#include <iostream>
using namespace std;

struct Graph {
	int ** g;
	int capacity;
	int n;
	
	//Bien dung de duyet Prim
	int *E1;
	int *E2;
	int *wE;
	int nE;

	int *T1;
	int *T2;
	int *wT;
	int nT;

	Graph(int cap = 100) {
		g = new int*[cap];
		for (int i = 0; i < cap; i++) {
			g[i] = new int[cap];
		}
		capacity = cap;
		n = 0;

		//Khoi tao bien cho Prim
		E1 = new int[cap];
		E2 = new int[cap];
		wE = new int[cap];
		nE = 0;

		T1 = new int[cap];
		T2 = new int[cap];
		wT = new int[cap];
		nT = 0;
	}

	void init() {
		cout << "Nhap vao so dinh cua ma tran ke: ";
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
			{
				cout << "Nhap vao canh ke cua dinh thu " << i << " va " << j << ": ";
				cin >> g[i][j];
			}
		} 
	}

	void display() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << g[i][j] << " ";
			}
			cout << endl;
		}
	}

	bool isExist(int d, int D[], int nD) {
		for (int i = 0; i < nD; i++) {
			if (D[i] == d) {
				return true;
			}
		}
		return false;
	}

	void xoa(int d) {
		for (int i = d; i < nE; i++) {
			E1[i] = E1[i + 1];
			E2[i] = E2[i + 1];
			wE[i] = wE[i + 1];
		}
		nE--;
	}

	void xoaCanhE(int d1, int d2) {
		for (int i = 0; i < nE; i++) {
			if (E1[i] == d1 && E2[i] == d2) {
				xoa(i);
				break;
			}
		}
	}

	void duyetPrim(int s) {
		int u = s;
		int min, d1, d2;
		while (nT < n - 1) {
			for (int v = 0; v < n; v++) {
				if (g[u][v] != 0) {
					if (!isExist(v, T2, nT)) {
						E1[nE] = u;
						E2[nE] = v;
						wE[nE] = g[u][v];
						nE++;
					}
				}
			}

			//Tao min, d1, d2 tam thoi
			for (int i = 0; i < nE; i++) {
				if (!isExist(E2[i], T2, nT)) {
					min = wE[i];
					d1 = E1[i];
					d2 = E2[i];
					break;
				}
			}
			//Tim min tai vi tri dang xet
			for (int i = 0; i < nE; i++) {
				if (!isExist(E2[i], T2, nT)) {
					if (min > wE[i]) {
						min = wE[i];
						d1 = E1[i];
						d2 = E2[i];
					}
				}
			}

			T1[nT] = d1;
			T2[nT] = d2;
			wT[nT] = min;
			nT++;
			g[d1][d2] = 0;
			g[d2][d1] = 0;
			xoaCanhE(d1, d2);
			u = d2;
		}
	}

	void initE() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (g[i][j] != 0) {
					E1[nE] = i;
					E2[nE] = j;
					wE[nE] = g[i][j];
					nE++;
					g[i][j] = 0;
					g[j][i] = 0;
				}
			}
		}
	}

	void sortE() {
		for (int i = 0; i < nE - 1; i++)
		{
			for (int j = i + 1; j < nE; j++) {
				if (wE[i] > wE[j]) {
					swap(E1[i], E1[j]);
					swap(E2[i], E2[j]);
					swap(wE[i], wE[j]);
				}
			}
		}
	}

	void duyetKruskal() {
		initE();
		sortE();
		for (int i = 0; i < nE; i++) {
			if (isExist(E1[i], T1, nT) && isExist(E2[i], T2, nT)) {
				continue;
			}
			if (isExist(E1[i], T2, nT) && isExist(E2[i], T1, nT)) {
				continue;
			}
			T1[nT] = E1[i];
			T2[nT] = E2[i];
			wT[nT] = wE[i];
			nT++;
			if (nT == n - 1) {
				break;
			}
		}
	}

	void displayT() {
		int tong = 0;
		for (int i = 0; i < nT; i++) {
			cout << "(" << T1[i] << ", " << T2[i] << ") = " << wT[i] << endl;
			tong += wT[i];
		}
		cout << tong << endl;
	}
};

int main() {
	Graph g;
	g.init();
	g.display();
	g.duyetKruskal();
	g.displayT();
	system("pause");
	return 0;
}