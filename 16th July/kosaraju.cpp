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


// implementation of kasuraju's algorithm

void dfs(int n, vector<int> graph[], bool visited[], stack<int> *st){
    if(visited[n]==true) return;
    visited[n]=true;
    fr(i,graph[n].size()) dfs(graph[n][i],graph,visited, st);
    (*st).push(n);
}

void rev_dfs(int top,vector<int> rev_graph[], bool visited[]){
    if(visited[top]==true) return;
    visited[top]=true;
    fr(i,rev_graph[top].size()) rev_dfs(rev_graph[top][i], rev_graph, visited);
    cout<<top<<" ";

}

void solve(){
    int vertices,edges;
    cout<<"enter vertices and edges: "<<endl;
    cin>>vertices>>edges;
    vector<int> graph[vertices+3];
    vector<int> rev_graph[vertices+3];
    stack<int> st;
    int u,v;
    fr(i,edges){
        cin>>u>>v;
        graph[u].push_back(v);
        rev_graph[v].push_back(u);
    }
    bool visited[vertices+3]={false};
    fr(i,vertices)  dfs(i,graph,visited, &st);
    bool rev_visited[vertices+3]={false};
    while(!st.empty()){
        int top = st.top();
        st.pop();
        if(rev_visited[top]==false){
            rev_dfs(top, rev_graph, rev_visited);
            cout<<endl;
        }
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

