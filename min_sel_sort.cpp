#include <bits/stdc++.h>
using namespace std;
void sel_sort(int *arr, int s)
{   
    for(int i=0;i<s-1;i++){
        int min=i;
        for (int j = i+1; j < s; j++)
        {
            if(arr[j]<arr[min])
                min=j;
        }
        swap(arr[i],arr[min]);
    }
    cout<<"Sorted array: "<<endl;
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
    cout<<"Enter the values : "<<endl;
    for (int i = 0; i < s; i++)
        cin>>arr[i];
    sel_sort(arr,s);
}