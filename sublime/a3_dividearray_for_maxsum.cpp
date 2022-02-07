//Given an array a of size N and an integer K, the task is to divide the array into K segments 
//such that sum of the minimum of K segments is maximized. 

#include <bits/stdc++.h>
using namespace std;
const int MAX = 10;

int maximizeSum(int a[], int n, int ind,int k, int dp[MAX][MAX])
{
    if (k == 0) {
        // If we are at the end
        if (ind == n)
            return 0;
        // If we donot reach the end then return a negative number
        else
            return -1e9;
    }
    else if (ind == n)
        return -1e9;

    else if (dp[ind][k] != -1)
        return dp[ind][k];

    else {
        int ans = 0;

        int mini = a[ind];

        for (int i = ind; i < n; i++) {

            mini = min(mini, a[i]);

            ans = max(ans, maximizeSum(a, n, i + 1, k - 1, dp) + mini);
        }
        return dp[ind][k] = ans;
    }
}

int main()
{
    int a[] = { 5, 7, 4, 2, 8, 1, 6 };
    int k = 3;
    int n = 7;

    int dp[MAX][MAX];
    memset(dp, -1, sizeof dp);

    cout << maximizeSum(a, n, 0, k, dp);

    return 0;
}

