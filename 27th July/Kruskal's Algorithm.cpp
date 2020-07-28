#include<bits/stdc++.h>
using namespace std;
#define LLPair pair<long long , long long>

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
	long long nodes , edges;
	set<LLPair > mst;
	cin>>nodes>>edges;
	
	vector<long long> graph[nodes + 1];
	map<LLPair , long long> wei;
	priority_queue<LLPair , vector<LLPair> , greater<LLPair> >pq;
	LLPair hash[nodes + 1];
	
	for(int i = 0; i < edges; i++){
		long long u , v , w;
		cin>>u>>v>>w;
		if(u > v) swap(u , v);
		/* Indexing the edges */
		hash[i] = {u , v};
		/* For removing self loops */
		if(u == v)
			continue;
		/* For removing multiple edges */
		if(wei.find({u , v}) == wei.end()){
			graph[u].push_back(v);
			graph[v].push_back(u);
			wei[{u , v}] = w;
		}
		wei[{u , v}] = max(wei[{u , v}] , w);
		pq.push({wei[{u , v}] , i});
	}
	
	bool visited[nodes + 1];
	int count = 0;
	int parent[nodes + 1] , rank[nodes + 1];
	bool cycle = false;
	
	memset(visited , false , sizeof(visited));
	/* Set parent of i as i and rank of i as 0 */
	makeSet(parent , rank , nodes);
	
	while(count < nodes - 1){
		LLPair fro = pq.top();
		pq.pop();
		int u = findSet(parent , hash[fro.second].first) , v = findSet(parent , hash[fro.second].second);
		if(u == v)
			continue;
		mst.insert({hash[fro.second].first , hash[fro.second].second});
		unionSet(u , v , rank , parent);
		count ++;
	}
	auto it = mst.begin();
	while(it != mst.end()){
	    LLPair edge = *it;
	    cout<<edge.first<<" "<<edge.second<<endl;
	    it++;
	}
}
