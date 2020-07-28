#include<bits/stdc++.h>
using namespace std;
#define LLPair pair<long long , long long>

int main(){
	long long nodes , edges;
	cin>>nodes>>edges;
	
	vector<long long> graph[nodes + 1];
	map<LLPair , long long> wei;
	for(int i = 0; i < edges; i++){
		long long u , v , w;
		cin>>u>>v>>w;
		if(u > v) swap(u , v);
		/* For removing self loops */
		if(u == v)
			continue;
		/* For removing multiple edges */
		pq.push({w , i});
		if(wei.find({u , v}) == wei.end()){
			graph[u].push_back(v);
			graph[v].push_back(u);
			wei[{u , v}] = w;
		}
		wei[{u , v}] = max(wei[{u , v}] , w);
	}
	
	bool visited[nodes + 1];
	int count = 0;
	memset(visited , false , sizeof(visited));
	
	priority_queue<LLPair , vector<LLPair> , greater<LLPair> >pq;
	while(count < n){
		LLPair fro = pq.top();
		pq.pop();
	
		if(visited[edge1] && visited[edge2])
			continue;
		
		visited[edge1] = true , visited[edge2] = true;
		count ++;
	}
}
