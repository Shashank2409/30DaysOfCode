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
#define int_max 1e9

void solve(){
    int vertex, edges;
    cin>>vertex>>edges;
    vector<int> graph[N];
    int u,v,w;
    int shortest_paths[1004][1004];
    fr(i,vertex){
        fr(j,vertex){
            if(i==j) shortest_paths[i][j]=0;
            else shortest_paths[i][j] = int_max;
        }
    }
    fr(i,edges){
        cin>>u>>v>>w;
        graph[u].push_back(v);
        shortest_paths[u][v]=w;
    }
    fr(i,vertex){
        fr(j,vertex){
            if(j==i) continue;
            fr(k,vertex){
                if(k==i || j==k) continue;
                if(shortest_paths[j][k] > (shortest_paths[j][i]+shortest_paths[i][k])){
                    cout<<"here";
                    shortest_paths[j][k] = shortest_paths[j][i]+shortest_paths[i][k];
                }
            }
        }
    }
    cout<<endl<<"shortest paths are : "<<endl;
    fr(i,vertex){
        fr(j,vertex) cout<<shortest_paths[i][j]<<" ";
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

