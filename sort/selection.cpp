#include <iostream>
using namespace std;
void sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minId = i;

        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[minId])
            {
                minId = j;
            }
        }
        int tem = a[i];
        a[i] = a[minId];
        a[minId] = tem;
    }
}

// a[] = {29, 10, 14, 37, 13}
//  Vòng lặp i=0
//       +  minId=0- -> giả sử số nhỏ nhất là 29
//       + Vòng lặp for thứ 2. Lần lượt so sánh a[j] <a[minId]
//             + 10<29 đúng. Cập nhật minId=1
//             + 14<10 sai
//             + 37<10 sai
//              13<10 sai
//       + Sau khi kết thúc vòng lặp 2 đổi chổ a[0] với a[1];
//       => {10, 29, 14, 37, 13}

// Vòng lặp i=1
//      + minId=1; -> giả sử số nhỏ nhất là 29
//      + Vòng lặp for thứ 2 so sánh a[j] < a[minId]
//             + 14 <29 đúng. cập nhật minId=2;
//             + 37<14 sai
//             + 13 < 14 đúng. cập nhật minId=4
//      + Sau khi kết thúc vòng lặp 2 đổi chổ a[1] với a[4];
//      => {10, 13, 14, 37, 29}

// Vòng lặp i=2
//      + minId=2; -> giả sử số nhỏ nhất là 14
//      + Vòng lặp for thứ 2 so sánh a[j] < a[minId]
//              + 37 < 14 sai
//              + 29 <14 sai
//      + Sau khi kết thúc vòng lặp mảng không thay đổi

// Vòng lặp i=3
//      + minId=3; -> giả sử số nhỏ nhất là 37
//      + Vòng lặp for thứ 2 so sánh a[j] < a[minId]
//              + 29<37 đúng. cập nhất minId=4
//      + Sau khi kết thúc vòng lặp 2 đổi chổ a[3] với a[4];
//      => {10, 13, 14, 29, 37}

// vòng lặp i=4 kết thúc chương trình

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}