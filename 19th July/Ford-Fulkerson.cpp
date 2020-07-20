#include<bits/stdc++.h>
using namespace std;
const int maxNodes = 1e3 + 5;
int graph[maxNodes][maxNodes] , residual[maxNodes][maxNodes] , parent[maxNodes]; 

bool checkAugmentedPath(int &source , int &sink , int &nodes){
	bool visited[nodes + 1];
	memset(visited , 0 , sizeof(visited));
	queue<int>q;
	q.push(source);
	while(q.size()){
		int present = q.front();
		q.pop();
		for(int i = 1; i <= nodes; i++){
			if(residual[present][i] && !visited[i]){
				q.push(i);
				visited[i] = true;
				parent[i] = present;
			}
		}
	}
	return visited[sink];
}

int main(){
	int nodes , edges , source , sink , max_flow = 0;
	/*  2<= nodes <= 1000 */
	cin>>nodes>>edges>>source>>sink;
	
	for(int i = 1; i <= edges; i++){
		int u , v ,f;
		cin>>u>>v>>f;
		graph[u][v] = f;
		residual[u][v] = f;
	}
	
	while(checkAugmentedPath(source , sink , nodes)){
		int present_flow = 1e9 + 5;
		for(int node = sink; node != source; node = parent[node]){
			present_flow = min(present_flow , residual[parent[node]][node]);
		}
		
		for(int node = sink; node != source; node = parent[node]){
			residual[node][parent[node]] += present_flow;
			residual[parent[node]][node] -= present_flow;
		}
		max_flow += present_flow;
	}
	cout<<max_flow<<"\n";
	
}
