/*
The length of the segment matches Ron’s birth month, and,
The sum of the integers on the squares is equal to his birth day.

You must determine how many ways she can divide the chocolate.

 Consider the chocolate bar as an array of squares,s=[2,2,1,3,2] .
 She wants to find segments summing to Ron’s birth day,d=4  with a length 
 equalling his birth month,m=2 .
 In this case, there are two segments meeting her criteria:[2,2]  and [1,3] .
*/

#include<bits/stdc++.h>
using namespace std;

int main(){

    int c=0,n;
    cin>>n;
    int arr[n],s[n],d,m;

    for(int i=1;i<=n;i++)
        cin>>arr[i];

    cin>>d>>m;

    for(int i=1;i<=n;i++)
        s[i] = s[i-1]+arr[i]; // 2,4,5,8,10

    for(int i=m;i<=n;i++) // m=2 , 
        if(s[i]-s[i-m]==d) // = 4
            c++;

    cout<<c;

}