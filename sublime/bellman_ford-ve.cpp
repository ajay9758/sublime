//bellman with -ve cycle detection
#include<bits/stdc++.h>
using namespace std;

int find(int n ,vector<int> &parent){
	if(parent[n] == -1)
		return n;
	else
		return find(parent[n] , parent);
}

int main(){
	int n,m,s,d,w;
	cin>>n>>m;

	vector<vector<int>> adj;
	vector<int> dist(n+1 , 1e4);
	vector<int> parent(n+1 , -1);

	for(int i=0;i<m;i++){
		cin>>s>>d>>w;
		adj.push_back({s,d,w});
		//adj.push_back({d,s,w});
	}

	int src;cin>>src;
	dist[src] = 0;

	bool flag = false;
	for(int i=1;i<n;i++){
		
		flag = false;
		for(auto it : adj){
			int u,v,w;
			u = it[0];
			v = it[1];
			w = it[2];

			if(dist[v] > dist[u] + w){
				
				dist[v] = dist[u]+w;
				parent[v] = u;
				flag = true;
			}
		}
	}

	if(flag)
		cout<<" -ve cycle h re";
	else
	{
		for(int i=0;i<n;i++){
			find(i , parent);
			cout<<dist[i]<<endl;
	 	}
	 }

}

/*
5 8
1 2 3
3 2 5
1 3 2
3 1 1
1 4 2
0 2 4
4 3 -3
0 1 -1
0

*/