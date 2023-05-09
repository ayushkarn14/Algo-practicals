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
void quickSort(int *arr, int f, int l)
{
    if (f < l)
    {
        int pi = Lomuto_p(arr, f, l);
        quickSort(arr, f, pi - 1);
        quickSort(arr, pi + 1, l);
    }
}

int main()
{
    int arr[] = {12, 4, 22, 57, 4, 2};
    quickSort(arr, 0, 5);
    for (int i = 0; i < 6; i++)
        cout << arr[i] << " ";
    cout << "\n";
}