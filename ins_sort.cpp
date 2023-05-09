#include <bits/stdc++.h>
using namespace std;
void ins_sort(int *arr, int s)
{
    int j = 0;
    int key;
    for (int i = 1; i < s; i++)
    {
        j = i - 1;
        key = arr[i];
        while (j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    cout << "Sorted array:";
    for (int i = 0; i < s; i++)
    {
        cout << arr[i] << " ";
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
    ins_sort(arr, s);
}