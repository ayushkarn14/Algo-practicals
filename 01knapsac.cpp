#include <bits/stdc++.h>
using namespace std;
int knapsack(int W, int n, int wt[], int val[])
{
    int M[n + 1][W + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
                M[i][j] = 0;
            else if (wt[i - 1] > j)
            {
                M[i][j] = M[i - 1][j];
            }
            else
                M[i][j] = max(M[i - 1][j], val[i - 1] + M[i - 1][j - wt[i - 1]]);
        }
    }
    return M[n][W];
}
int main()
{
    cout << "Enter weight capacity : ";
    int w;
    cin >> w;
    cout << "Enter number of items : ";
    int n;
    cin >> n;
    int wt[n];
    int val[n];
    cout << "Enter " << n << " value and weights \n";
    for (int i = 0; i < n; i++)
    {
        cin >> val[i] >> wt[i];
    }
    int ans = knapsack(w, n, wt, val);
    cout << "Max value = " << ans;
}