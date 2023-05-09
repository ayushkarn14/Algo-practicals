#include <bits/stdc++.h>
using namespace std;
void countSort(int *a, int n)
{
    int maxi = a[0];
    for (int i = 1; i < n; i++)
    {
        if (maxi < a[i])
            maxi = a[i];
    }
    int freq[maxi + 1] = {0};
    for (int i = 0; i < n; i++)
        freq[a[i]]++;
    for (int i = 1; i <= maxi; i++)
        freq[i] += freq[i - 1];
    int res[n];
    for (int i = n - 1; i >= 0; i--)
        res[--freq[a[i]]] = a[i];

    for (int i = 0; i < n; i++)
        cout << res[i] << " ";
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
    countSort(a, n);
}