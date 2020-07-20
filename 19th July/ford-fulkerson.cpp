#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<iomanip>
#include<cstring>
#include<queue>
#include<stack>
using namespace std;

#define mod 1000000007
#define fr(i,n) for(int i=0;i<n;i++)
#define frn(i,n) for(int i=n-1;i>=0;i--)
#define fr1(i,n) for(int i=1;i<=n;i++)
#define frn1(i,n) for(int i=n;i>0;i--)
#define N 100002
#define ll long long
#define mid(a,b) a+(b-a)/2

int bfs(int s,int t, vector<int> graph[], int capacity[][1003], int parent[]){
    queue<pair<int,int>> q;
    q.push({s,INT32_MAX});
    while(!q.empty()){
        int curr = q.front().first;
        int flow_curr = q.front().second;
        q.pop();
        fr(i,graph[curr].size()){
            if(parent[graph[curr][i]]==-1 &&  capacity[curr][graph[curr][i]]>0){
                parent[graph[curr][i]]=curr;
                int flow_new = min(flow_curr, capacity[curr][graph[curr][i]]);
                if(graph[curr][i]==t) return flow_new;
                q.push({graph[curr][i],flow_new});
            }
        }
    }
    return 0;
}

void solve(){
    int vertices, edges;
    cin>>vertices>>edges;
    vector<int> graph[1003];
    int capacity[1003][1003];
    int flow[1003][1003];
    fr(i,1003) fr(j,1003) capacity[i][j]=flow[i][j]=0;
    int u,v,w;
    fr(i,edges){
        cin>>u>>v>>w;
        graph[u].push_back(v);
        capacity[u][v]=w;
    }
    
    int s,t;
    cin>>s>>t;
    int total_flow=0;

    while(1){
        int parent[vertices];
        fr(i,vertices) parent[i]=-1;
        parent[s]=-2;
        int extra_flow=bfs(s,t,graph,capacity,parent);
        if(extra_flow==0) break;
        total_flow+=extra_flow;
        int curr = t;
        while(curr!=s){
            int next=parent[curr];
            capacity[next][curr]-=extra_flow;
            flow[next][curr]+=extra_flow;
            curr=next;
        }
    }
    cout<<"Total flow is : "<<total_flow<<endl;
    cout<<"The flow matrix is : "<<endl;
    fr(i,vertices){
        fr(j,vertices) cout<<flow[i][j]<<" ";
        cout<<endl;
    }
}


int main(){
    ios_base::sync_with_stdio(false);   
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    // t=1;
    while(t--){
        solve();
    }
}



/*
1
6 9     vertex and edges
0 1 7
1 2 5
2 5 8
0 4 4
4 3 2
3 5 5
4 1 3
3 2 3   
1 3 3
0 5     s and t
*/