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

#define INF 1000000003

int get_min(bool visited[], int weighs[], int vertices){
    int minidx = vertices;
    fr(i,vertices) if(visited[i]==false) if(weighs[i]<=weighs[minidx]) minidx = i;
    return minidx;
}


//  implementation in O(V^2) time and O(V) space 
void solve(){
    int vertices, edges;
    cin>>vertices>>edges;
    vector<pair<int,int>> graph[1003];
    int weighs[1003];
    bool visited[1003]={false};
    memset(weighs,INF,sizeof(weighs));
    int u,v,w;
    fr(i,edges){
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
        
    }
    weighs[0]=0;
    int visited_count=0;
    while(visited_count<vertices){
        int x = get_min(visited,weighs,vertices);
        visited_count+=1;
        visited[x]=true;
        fr(i,graph[x].size()){
            if(weighs[graph[x][i].first] > weighs[x]+graph[x][i].second){
                weighs[graph[x][i].first] = weighs[x]+graph[x][i].second;
            }
        }
    }
    cout<<"Weighs in MST are :"<<endl;
    fr(i,vertices) cout<<weighs[i]<<" ";

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

