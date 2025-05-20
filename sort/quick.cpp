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

// mục đích của việc phân hoạch là đưa chốt về giữa. bên trái chốt là các phần tử >= chốt, bên phải là nhỏ hơn chốt. tiếp tục đệ quy ...

// step by step
// a = [4, 2, 7, 1, 3] n=5

// -Gọi quickSort(a, 0, 4)
// gọi phânHoach (a,0,4)
// -chot = a[4] = 3
// i = -1
// Vòng lặp từ j = 0 đến 3:
// j = 0: a[0] = 4 > chot → không đổi.
// j = 1: a[1] = 2 < chot → tăng i=0, hoán đổi a[0] vs a[1] → mảng: [2, 4, 7, 1, 3]
// j = 2: a[2] = 7 > chot → không đổi.
// j = 3: a[3] = 1 < chot → tăng i=1, hoán đổi a[1] ↔ a[3] → mảng: [2, 1, 7, 4, 3]
// Sau vòng lặp: tăng i=2, hoán đổi a[2] ↔ a[4] → mảng: [2, 1, 3, 4, 7]
// Trả về p = 2

// Tiếp tục gọi quickSort(a, 0, 1)
//  -Gọi phanHoach(a, 0, 1)
// chot = a[1] = 1
// i = -1
// j = 0: a[0] = 2 > chot → không đổi.
// Sau vòng lặp: tăng i=0, hoán đổi a[0] ↔ a[1] → mảng: [1, 2, 3, 4, 7]
//  Trả về p = 0

// Gọi tiếp:
// quickSort(a, 0, -1) → dừng.
// quickSort(a, 1, 1) → dừng.

// ✅ Tiếp tục quickSort(a, 3, 4)
// 3️⃣ Gọi phanHoach(a, 3, 4)
// chot = a[4] = 7

// i = 2

// j = 3: a[3] = 4 < chot → tăng i=3, hoán đổi a[3] ↔ a[3] → không đổi.

// Tăng i=4, hoán đổi a[4] ↔ a[4] → không đổi.

// Trả về p = 4

// Gọi tiếp:

// quickSort(a, 3, 3) → dừng.

// quickSort(a, 5, 4) → dừng.
