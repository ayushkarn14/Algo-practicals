#include <bits/stdc++.h>
using namespace std;
struct Jobs
{
    int start, finish, profit;
};
bool comp(Jobs a, Jobs b)
{
    return a.finish < b.finish;
}
int latestNonConflicting(Jobs *arr, int i)
{
    for (int j = i - 1; j >= 0; j--)
    {
        if (arr[j].finish <= arr[i].start)
            return j;
    }
    return -1;
}
int findMaxProfit(Jobs *arr, int n)
{
    sort(arr, arr + n, comp);

    int *table = new int[n];
    table[0] = arr[0].profit;

    for (int i = 1; i < n; i++)
    {
        int inc = arr[i].profit;
        int l = latestNonConflicting(arr, i);
        if (l != -1)
            inc += table[l];
        table[i] = max(inc, table[i - 1]);
    }
    int ans = table[n - 1];
    delete[] table;
    return ans;
}
int main()
{
    Jobs arr[] = {{3, 10, 20},
                  {1, 2, 50},
                  {6, 19, 100},
                  {2, 100, 200}};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The optimal profit is "
         << findMaxProfit(arr, n);
    return 0;
}