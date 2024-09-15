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

int *countingSort(int a[], int n)
{
    // Tim kiem gia tri lon nhat trong mang dau vao
    int MAX = getMax(a, n);
    int *countArr = new int[MAX + 1];

    // Khoi tao mang dem gia tri voi tat ca gia tri bang 0
    for (int i = 0; i <= MAX; i++)
    {
        countArr[i] = 0;
    }

    // Tang gia tri mang dem neu phan tu do co ton tai
    for (int i = 0; i < n; i++)
    {
        countArr[a[i]]++;
    }

    // Xac dinh vi tri cuoi cung cua phan tu trong mang dau ra
    for (int i = 1; i <= MAX; i++)
    {
        countArr[i] += countArr[i - 1];
    }

    int *outputArr = new int[n];
    for (int i = n - 1; i >= 0; i--)
    {
        outputArr[countArr[a[i]] - 1] = a[i];
        countArr[a[i]]--;
    }

    delete[] countArr;
    return outputArr;
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

    int *b = countingSort(a, n);

    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;
    delete[] b;
    return 0;
}
