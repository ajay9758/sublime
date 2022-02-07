//Creatnx now wants to decorate his house by flower pots. 
//He plans to buy exactly  ones. He can only buy them from 
//Triracle's shop. There are only two kind of flower
// pots available in that shop. The shop is very strange. If you buy  
// flower pots of kind 1 then you must pay a*  and  if you buy  flower pots of 
//kind 2. Please help Creatnx buys exactly  flower pots that minimizes money he pays.


#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
		ll n,a,b;

		cin>>n>>a>>b;
				
		ll x=(n*b)/(a+b); //int x = (n*b)/(a+b);

		ll cost1=a*x*x+b*(n-x)*(n-x);

		ll cost2=a*(x+1)*(x+1)+b*(n-x-1)*(n-x-1);

		cout<<min(cost1,cost2)<<endl;

}