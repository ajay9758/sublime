/*Given an array of positive integers representing the
 values of coins in your possession, write a function that
  returns the minimum amount of change 
  (the minimum amount of money) that you cannot create.
   The given coins can have any positive integer value
    and aren't unique (ie you can have multiple coins of same values).*/

#include<bits/stdc++.h>
using namespace std;

int fun(int arr[] , int n){

    sort(arr , arr+n);

    int ans = 0;

    for(int i=0;i<n;i++){

        int let = ans+1;

        if(arr[i]>let)
            return let;
        ans+=arr[i];
    }
    return ans;
}

int main(){
    int n;cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<fun(arr , n);
}

// 7
// 5 7 1 1 2 3 22