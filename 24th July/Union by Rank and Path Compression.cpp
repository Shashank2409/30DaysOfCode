#include<bits/stdc++.h>
using namespace std;
 
void unionSet(int x , int y , int rank[] , int parent[]){
	if(rank[x] > rank[y]){
		parent[y] = x;
	}
	else{
		parent[x] = y;
		if(rank[x] == rank[y]) rank[y]++;
	}
}

int findSet(int parent[] , int u){
	int x = parent[u];
	if(x == u)
		return u;
	/* Path compression */
	parent[u] = findSet(parent , x);	
	return parent[u];
}

void makeSet(int parent[] , int rank[] , int n){
	for(int i = 0; i <= n; i++)
		parent[i] = i , rank[i] = 0;
}

int main(){
	/* nodes and operations */
	long long n , ope;
	cin>>n>>ope;
	
	int parent[n + 1] , rank[n + 1];
	bool cycle = false;
	
	/* Set parent of i as i and rank of i as 0 */
	makeSet(parent , rank , n);
	
	for(int i = 0; i < ope; i++){
		long long u , v;
		cin>>u>>v;
		/* A cycle has already been detected */
		if(cycle) continue;
		int x = findSet(parent , u) , y = findSet(parent , v);
		if(x == y){
			cycle = true;
			continue;
		}
		
		unionSet(x , y , rank , parent);
	}
	if(cycle)
		cout<<"Graph contains cycle\n";
	else
		cout<<"Graph does not contain any cycles\n";
}
