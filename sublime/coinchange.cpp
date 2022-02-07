//possible ways

#include<bits/stdc++.h>
using namespace std;

int counbt(int arr[],int s,int n,vector<vector<int>> &dp){
   
    if(s == 0)
        return  dp[n][s] = 1;

    if(n == 0)
        return 0;

    if(dp[n][s] != -1)
        return dp[n][s];

    if(arr[n-1] <= s)
    {
        return dp[n][s] = counbt(arr,s-arr[n-1],n,dp)+counbt(arr , s,n-1 ,dp);
    }
    else
        return dp[n][s]= counbt(arr,s,n-1,dp);
}

int main(){
    
    int n = 3;
    int arr[] = {1,2,3};
    int s = 4;
    vector<vector<int>> dp(n+1 , vector<int>(s+1 , -1));
    
    cout<<counbt(arr,s,n,dp);
}