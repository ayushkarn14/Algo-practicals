#include <bits/stdc++.h>
using namespace std;
int max_digits(int *arr, int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }
    int c = 0;
    while (max > 0)
    {
        c++;
        max /= 10;
    }
    return c;
}
int *countSort(int *arr, int n, int j)
{
    int f[10];
    for (int i = 0; i < 9; i++)
        f[i] = 0;
    for (int i = 0; i < n; i++)
    {
        int p = pow(10, j);
        int q = pow(10, j - 1);
        f[(arr[i] % p) / (q)]++;
    }
    int d[n];
    for (int i = 0; i < n; i++)
    {
        int p = pow(10, j);
        int q = pow(10, j - 1);
        d[i] = (arr[i] % p) / (q);
    }
    for (int i = 1; i < 10; i++)
    {
        f[i] += f[i - 1];
    }
    int *ans = new int[n];
    for (int i = n - 1; i >= 0; i--)
    {
        int k = d[i];
        int l = arr[i];
        f[k]--;
        ans[f[k]] = l;
    }
    return ans;
}
int main()
{
    cout << "Enter value of n: ";
    int n;
    cin >> n;
    int *arr = new int[n];
    cout << "Enter values: \n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int *out = new int[n];
    int d = max_digits(arr, n);
    for (int i = 1; i <= d; i++)
    {
        out = countSort(arr, n, i);
    }
    // delete[] arr;
    arr = out;
    // delete[] out;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}