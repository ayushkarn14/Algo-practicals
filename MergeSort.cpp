#include <bits/stdc++.h>
using namespace std;
void merge(int *a, int f, int mid, int l)
{
    int res[l - f + 1];
    int p1 = f;
    int p2 = mid + 1;
    int k = 0;
    while (p1 <= mid && p2 <= l)
    {
        if (a[p1] <= a[p2])
        {
            res[k++] = a[p1];
            p1++;
        }
        else
        {
            res[k++] = a[p2];
            p2++;
        }
    }
    while (p1 <= mid)
    {
        res[k++] = a[p1];
        p1++;
    }
    while (p2 <= l)
    {
        res[k++] = a[p2];
        p2++;
    }

    for (int i = 0; i < l - f + 1; i++)
    {
        a[i + f] = res[i];
    }
}
void mergeSort(int *a, int f, int l)
{
    if (f < l)
    {
        int mid = (f + l) / 2;
        mergeSort(a, f, mid);
        mergeSort(a, mid + 1, l);
        merge(a, f, mid, l);
    }
}
int main()
{
    cout << "Enter number of elements : ";
    int n;
    cin >> n;
    int a[n];
    cout << "Enter the values :\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    mergeSort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}