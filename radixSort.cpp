#include <bits/stdc++.h>
using namespace std;
void countSort(int *a, int n, int place)
{
    int freq[10] = {0};

    for (int i = 0; i < n; i++)
        freq[(int)((a[i] / int(pow(10, place))) % 10)]++;

    for (int i = 1; i <= 9; i++)
        freq[i] += freq[i - 1];

    int res[n];

    for (int i = n - 1; i >= 0; i--)
        res[--freq[int((a[i] / int(pow(10, place))) % 10)]] = a[i];

    for (int i = 0; i < n; i++)
        a[i] = res[i];
}
void radixSort(int *a, int n)
{
    int maxi = a[0];
    for (int i = 0; i < n; i++)
        maxi = max(maxi, a[i]);

    int d = 0;
    while (maxi > 0)
    {
        d++;
        maxi /= 10;
    }

    for (int i = 1; i <= d; i++)
    {
        countSort(a, n, i);
    }

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}
int main()
{
    cout << "Enter number of elements :";
    int n;
    cin >> n;
    int a[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    radixSort(a, n);
}