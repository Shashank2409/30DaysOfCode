#include<bits/stdc++.h>
using namespace std;
const long long maxS = 1e3 + 5 , maxWeight = 1e9 + 7;
long long graphWeights[maxS][maxS];
bool visited[maxS];

 

int main(){
	/* This will help in removing parallel edges and self loops */
	for(int i = 0; i < maxS; i++)
		for(int j = 0; j < maxS; j++)
			graphWeights[i][j] = (i == j)? 0 : maxWeight;
	
	long long nodes , edges;
	cin>>nodes>>edges;
	
	vector<long long> graph[nodes + 1] , parent(nodes + 1 , -1) , key(nodes + 1 , maxWeight);
	for(int i = 0; i < edges; i++){
		long long u , v , w;
		cin>>u>>v>>w;
		/* Self loop */
		if(u == v)
			continue;
		/* Parallel edge */
		if(graphWeights[u][v] == maxWeight){
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		graphWeights[u][v] = min(graphWeights[u][v] , w);
		graphWeights[v][u] = min(graphWeights[v][u] , w);
	}
	
	
	priority_queue <pair<int , int> , vector<pair<int , int> >, greater<pair<int , int> > >nextEdge;
	nextEdge.push({0 , 1});
	int presNode = 0;
	key[presNode] = 0 , parent[1] = -1;
	
	while(nextEdge.size()){
		pair<int , int> pres = nextEdge.top();
		nextEdge.pop();
		presNode = pres.second;
		visited[presNode] = 1;
		
		for(int i = 0; i < graph[presNode].size(); i++){
			int node = graph[presNode][i] , wei = graphWeights[presNode][node];
			if(visited[node] == false && key[node] > wei){
				key[node] = wei;
				nextEdge.push({key[node] , node});
				parent[node] = presNode;
			}
		}
	}
	
	for(int i = 1;i <= nodes; i++)
		cout<<i<<" "<<parent[i]<<"\n";
}
