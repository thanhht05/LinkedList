#include <iostream>
#include <time.h>
using namespace std;
int phanHoach(int a[], int l, int r)
{
    int chot = a[r];
    int i = l - 1;

    for (int j = l; j < r; j++)
    {
        if (a[j] < chot)
        {
            ++i;
            int tem = a[i];
            a[i] = a[j];
            a[j] = tem;
        }
    }
    ++i;
    int tem = a[i];
    a[i] = a[r];
    a[r] = tem;
    return i;
}

void quickSort(int a[], int l, int r)
{
    if (l >= r)
        return;
    int p = phanHoach(a, l, r);
    quickSort(a, l, p - 1);
    quickSort(a, p + 1, r);
}
int main()
{
    int a[1000];
    int n;
    cin >> n;
    // srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    quickSort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}