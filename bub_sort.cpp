#include <bits/stdc++.h>
using namespace std;
void bub_sort(int *arr, int s)
{
    for (int i = 0; i < s - 1; i++)
    {
        for (int j = 0; j < s - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    cout << "Sorted array: " << endl;
    for (int j = 0; j < s; j++)
    {
        cout << arr[j] << " ";
    }
    cout << endl;
}
int main()
{
    cout << "Enter number of values: ";
    int s;
    cin >> s;
    int arr[s];
    cout << "Enter the values : " << endl;
    for (int i = 0; i < s; i++)
        cin >> arr[i];
    bub_sort(arr, s);
}