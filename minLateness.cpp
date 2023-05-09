#include <bits/stdc++.h>
using namespace std;
void merge(int *a, int f, int mid, int l, int *b, int *j)
{
    int res[l - f + 1];
    int res_b[l - f + 1];
    int res_j[l - f + 1];
    int p1 = f;
    int p2 = mid + 1;
    int k = 0;
    while (p1 <= mid && p2 <= l)
    {
        if (a[p1] <= a[p2])
        {
            res[k] = a[p1];
            res_b[k] = b[p1];
            res_j[k] = j[p1];
            k++;
            p1++;
        }
        else
        {
            res[k] = a[p2];
            res_b[k] = b[p2];
            res_j[k] = j[p2];
            k++;
            p2++;
        }
    }
    while (p1 <= mid)
    {
        res[k] = a[p1];
        res_b[k] = b[p1];
        res_j[k] = j[p1];
        k++;
        p1++;
    }
    while (p2 <= l)
    {
        res[k] = a[p2];
        res_b[k] = b[p2];
        res_j[k] = j[p2];
        k++;
        p2++;
    }

    for (int i = 0; i < l - f + 1; i++)
    {
        a[i + f] = res[i];
        b[i + f] = res_b[i];
        j[i + f] = res_j[i];
    }
}
void mergeSort(int *a, int f, int l, int *b, int *j)
{
    if (f < l)
    {
        int mid = (f + l) / 2;
        mergeSort(a, f, mid, b, j);
        mergeSort(a, mid + 1, l, b, j);
        merge(a, f, mid, l, b, j);
    }
}
int main()
{
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;
    int jobs[n];
    int d[n];
    int b[n];
    cout << "Enter burst and deadline time of jobs: ";
    for (int i = 0; i < n; i++)
    {
        cin >> b[i] >> d[i];
        jobs[i] = i + 1;
    }
    mergeSort(d, 0, n - 1, b, jobs);
    int s = 0;
    int st[n];
    int ft[n];
    for (int i = 0; i < n; i++)
    {
        st[i] = s;
        ft[i] = st[i] + b[i];
        s = ft[i];
    }
    cout << "J\tST\tFT\n";
    for (int i = 0; i < n; i++)
    {
        cout << jobs[i] << "\t" << st[i] << "\t" << ft[i] << endl;
    }
}