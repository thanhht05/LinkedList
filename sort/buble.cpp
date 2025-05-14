#include <iostream>
using namespace std;
#include <iostream>
using namespace std;

void sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int tem = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tem;
            }
        }
    }
}

// {8,1,4,2,7} n=5
// + i=0
// + j chạy từ 0 đến 3
//    + So sánh lần lượt a[j] với a[j+1]
//          + 8>1 đúng. đổi chổ a[0] với a[1] =>  {1,8,4,2,7}
//          +  8>4 đúng. đổi chổ a[1] với a[2]. =>  {1,4,8,2,7}
//          + 8>2 đúng đổi chổ a[2] với a[3] => {1,4,2,8,7}
//          + 8>7 đúng. đổi chố a[3] với a[4] =>{1,4,2,7,8}

// + i=1
// + j chạy từ 0 đến 2
//     + So sánh lần lượt a[j] với a[j+1]
//          + 1>4 sai
//          + 4 > 2 đúng. đổi chổ a[1] với a[2]. => {1,2,4,7,8}
//          + 2<7 sai
//          + 7< 8 sai

// i=2
// j chạy từ 0 đến 1
// + So sánh lần lượt a[j] với a[j+1]
//         + 1>2 sai
//         + 2>4 sai

// i=3
// So sánh lần lượt a[j] với a[j+1]
// 1> 2 sai
// kết thúc chương trình

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