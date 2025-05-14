#include <iostream>
using namespace std;
void solve(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int c = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] <= a[i])
            {
                c++;
            }
        }
        cout << c << " ";
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    solve(a, n);
}