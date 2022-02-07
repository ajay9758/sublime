#include <bits/stdc++.h>
using namespace std;
int ans = 100000000;

void solve(int a[], int n, int k, int index, int sum,int maxsum)
{
    
    if (k == 1) {
        maxsum = max(maxsum, sum);
        sum = 0;
        for (int i = index; i < n; i++) {
            sum += a[i];
        }
        
        maxsum = max(maxsum, sum);
        
        ans = min(ans, maxsum);
        return;
    }
    sum = 0;
    
    for (int i = index; i < n; i++) {
        sum += a[i];
    
        maxsum = max(maxsum, sum);
    
        solve(a, n, k - 1, i + 1, sum, maxsum);
    }
}

int main()
{
    int arr[] = { 1, 2, 3, 4 };
    int k = 3; // K divisions
    int n = 4; // Size of Array
    solve(arr, n, k, 0, 0, 0);
    cout << ans << "\n";
}
