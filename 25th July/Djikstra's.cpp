#include<bits/stdc++.h>
using namespace std;
#define LLPair pair<long long , long long>
const long long MAX_WEIGHT = 1e9 + 7;

int main(){
	long long nodes , edges , source;
	cin>>nodes>>edges>>source;
	
	vector<long long> graph[nodes + 1];
	map<LLPair , long long> wei;
	for(int i = 0; i < edges; i++){
		long long u , v , w;
		cin>>u>>v>>w;
		/* For removing self loops */
		if(u == v)
			continue;
		if(u > v) swap(u , v);
		/* For removing multiple edges */
		if(wei.find({u , v}) == wei.end()){
			graph[u].push_back(v);
			graph[v].push_back(u);
			wei[{u , v}] = w;
		}
		wei[{u , v}] = max(wei[{u , v}] , w);
	}
	
	priority_queue<LLPair , vector<LLPair> , greater<LLPair> >pq;
	long long distance[nodes + 1];
	memset(distance , MAX_WEIGHT , sizeof(distance));
	
	pq.push({0 , source});
	distance[source] = 0;
	
	while(pq.size()){
		long long dist = pq.top().first , from = pq.top().second;
		pq.pop();
		
		for(auto to : graph[from]){
			if(dist + wei[{min(from , to) , max(from , to)}] < distance[to]){
				distance[to] = dist + wei[{min(from , to) , max(from , to)}];
				pq.push({distance[to] , to});
			}
		}
	}
	
	for(int i = 1; i <= nodes; i++)
		cout<<distance[i]<<" ";
	cout<<"\n";
}
