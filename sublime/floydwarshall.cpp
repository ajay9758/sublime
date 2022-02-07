#include<bits/stdc++.h>
using namespace std;
const int x = 1e5;
int main(){
	int n,m,s,d,w;
	cin>>n;

	vector<vector<int>> graph;

	for(int i=0;i<n;i++){
		vector<int> v;int temp;
		for(int j=0;j<n;j++){
			cin>>temp;
			v.push_back(temp);
		}
		graph.push_back(v);
	}

	vector<vector<int>> dist = graph;

	for(int k=0;k<n;k++){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(dist[i][j] > dist[i][k]+dist[k][j])
				dist[i][j] = dist[i][k]+dist[k][j];
		}
	}
}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
		{
			if(dist[i][j]==100) cout<<"i"<<" ";
			else
			cout<<dist[i][j]<<" ";
		}
		cout<<endl;
	}
}