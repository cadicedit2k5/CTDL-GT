#include <iostream>
using namespace std;

int getMax(int a[], int n)
{
    int maxVal = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > maxVal)
        {
            maxVal = a[i];
        }
    }
    return maxVal;
}

// Thuc hien count Sort tren moi con so
void countingSort(int a[], int n, int exp)
{
    int output[100], countArr[10] = {0};

    // Luu chu so hang don vi hien tai vao trong mang
    for (int i = 0; i < n; i++)
    {
        countArr[(a[i] / exp) % 10]++;
    }

    // Cho gia tri truoc bang gia tri sau
    // Xac dinh vi tri cua phan tu trong mang dau ra
    for (int i = 1; i < 10; i++)
    {
        countArr[i] += countArr[i - 1];
    }

    // Tao mang output
    for (int i = n - 1; i >= 0; i--)
    {
        output[countArr[(a[i] / exp) % 10] - 1] = a[i];
        countArr[(a[i] / exp) % 10]--;
    }

    // Luu gia tri output hien tai vao trong mang ban dau
    for (int i = 0; i < n; i++)
    {
        a[i] = output[i];
    }
}

void radixSort(int a[], int n)
{
    // Lấy ra giá trị lớn nhất của mảng để tính số các chữ số
    int max = getMax(a, n);

    // Duyệt qua mỗi đơn vị và thực thi countSort trên đó
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countingSort(a, n, exp);
    }
}
int main()
{
    int a[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    radixSort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
