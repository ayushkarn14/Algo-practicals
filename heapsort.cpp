#include <bits/stdc++.h>
using namespace std;
void heapify(int *a, int n, int i)
{
    int l = i * 2;
    int r = i * 2 + 1;
    int largest = i;
    if (l <= n && a[largest] < a[l])
        largest = l;
    if (r <= n && a[largest] < a[r])
        largest = r;
    if (i != largest)
    {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void heapSort(int *a, int n)
{
    for (int i = n / 2; i >= 1; i--)
    {
        heapify(a, n, i);
    }
    for (int i = n; i >= 1; i--)
    {
        swap(a[1], a[i]);
        heapify(a, i - 1, 1);
    }
}
void inorder(int *a, int n, int i)
{
    if (i * 2 <= n)
        inorder(a, n, i * 2);
    cout << a[i];
    if (i * 2 + 1 <= n)
        inorder(a, n, i * 2 + 1);
}
void preorder(int *a, int n, int i)
{
    cout << a[i];
    if (i * 2 <= n)
        preorder(a, n, i * 2);
    if (i * 2 + 1 <= n)
        preorder(a, n, i * 2 + 1);
}
void postorder(int *a, int n, int i)
{
    if (i * 2 <= n)
        postorder(a, n, i * 2);
    if (i * 2 + 1 <= n)
        postorder(a, n, i * 2 + 1);
    cout << a[i];
}
int main()
{
    cout << "Enter number of elements : ";
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    heapSort(a, n);
    cout << "Ans: \n";
    for (int i = 1; i < n + 1; i++)
        cout << a[i] << " ";
    cout << "\n";
    cout << "\nPreorder\n";
    preorder(a, n, 1);
    cout << "\nInorder\n";
    inorder(a, n, 1);
    cout << "\nPostorder\n";
    postorder(a, n, 1);
}