#include <bits/stdc++.h>
using namespace std;
int Lomuto_p(int *a, int f, int l)
{
    int r = f + rand() % (l - f + 1);
    swap(a[r], a[l]);
    int pivot = a[l];
    int k = f - 1;
    int i = f;
    for (i = f; i <= l; i++)
    {
        if (a[i] <= pivot)
        {
            k++;
            swap(a[k], a[i]);
        }
    }
    return k;
}

int RandomizedSelect(int *a, int f, int l, int i)
{
    if (f == l)
        return a[f];
    int pivot = Lomuto_p(a, f, l);
    int k = pivot - f + 1;
    if (i == k)
        return a[i];
    else if (i < k)
    {
        return RandomizedSelect(a, f, pivot - 1, i);
    }
    else
        return RandomizedSelect(a, pivot + 1, l, i - k);
}
int main()
{
    int arr[] = {12, 4, 22, 57, 4, 2};
    int ans = RandomizedSelect(arr, 0, 5, 5);
    cout << ans << endl;
}