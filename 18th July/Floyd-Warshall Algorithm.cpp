#include<bits/stdc++.h>
using namespace std;
const long long MAX_NO = 1e9 + 7;

int main(){
	int nodes , edges;
	cin>>nodes>>edges;
	
	long long graph[nodes + 1][nodes + 1] , distance[nodes + 1][nodes + 1];
	for(int i = 0; i <= nodes; i++)
		for(int j = 0; j <= nodes; j++)
			graph[i][j] = (i == j) ? 0 : MAX_NO;
			
	for(int i = 0; i < edges; i++){
		int u , v , w;
		cin>>u>>v>>w;
		graph[u][v] = w;
		/* Uncomment this line for un-directed graph */
		/* graph[v][u] = w; */
	}	
	
	for(int i = 0; i <= nodes; i++)
		for(int j = 0; j <= nodes; j++)
			distance[i][j] = graph[i][j];
			
	for(int inter = 1; inter <= nodes; inter++){
		for(int source = 1; source <= nodes; source++){
			for(int dest = 1; dest <= nodes; dest++){
				distance[source][dest] = min(distance[source][dest] , distance[source][inter] + distance[inter][dest]);
			}
		}
	}
	
	for(int i = 1; i <= nodes; i++){
		for(int j = 1; j <= nodes; j++){
			if(distance[i][j] == MAX_NO)
				cout<<"INF ";
			else
				cout<<distance[i][j]<<" ";
		}
		cout<<"\n";
	}
	
}
