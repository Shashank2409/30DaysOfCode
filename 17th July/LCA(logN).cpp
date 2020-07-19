#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<iomanip>
#include<cstring>
#include<queue>
#include<stack>
#include<cmath>
using namespace std;

#define mod 1000000007
#define fr(i,n) for(int i=0;i<n;i++)
#define frn(i,n) for(int i=n-1;i>=0;i--)
#define fr1(i,n) for(int i=1;i<=n;i++)
#define frn1(i,n) for(int i=n;i>0;i--)
#define N 100002
#define ll long long
#define mid(a,b) a+(b-a)/2

int max_val[2]={N,0};

void dfs(vector<int> tree[], int curr, int count, int first[], vector<int> *height, vector<int> *dfs_trav){
    (*dfs_trav).push_back(curr);
    (*height).push_back(count);
    if(first[curr]==-1)
        first[curr]=(*dfs_trav).size()-1;
    
    fr(i,tree[curr].size()){
        dfs(tree, tree[curr][i], count+1, first, height, dfs_trav);
        (*dfs_trav).push_back(curr);
        (*height).push_back(count);
    }

}

void create_segment_tree(vector<int> height, int s_tree_array[][2], int idx, int l, int r){
    if(l==r){
        s_tree_array[idx][0]=height[l];
        s_tree_array[idx][1]=l;
        return;
    }
    int mid = mid(l,r);

    create_segment_tree(height, s_tree_array, (2*idx)+1, l, mid);
    create_segment_tree(height, s_tree_array, (2*idx)+2, mid+1, r);    

    if(s_tree_array[2*(idx)+1][0] < s_tree_array[2*(idx)+2][0]){
        s_tree_array[idx][0] = s_tree_array[2*(idx)+1][0];
        s_tree_array[idx][1] = s_tree_array[2*(idx)+1][1];
    }else{
        s_tree_array[idx][0] = s_tree_array[2*(idx)+2][0];
        s_tree_array[idx][1] = s_tree_array[2*(idx)+2][1];
    }
}

int* get_min_number(int s_tree_aray[][2], int idx, int l, int r, int ql, int qr){
    if(l>qr || r<ql) return max_val;   //defined at the top
    if(l>=ql && r<=qr) return s_tree_aray[idx];
    int mid_ele = mid(l,r);
    int *left_min = get_min_number(s_tree_aray,2*idx+1, l, mid_ele, ql, qr);
    int *right_min = get_min_number(s_tree_aray,2*idx+2, mid_ele+1, r, ql, qr);
    return (left_min[0]<right_min[0])?left_min:right_min;
}


void solve(){
    int vertices, edges;
    cin>>vertices>>edges;
    vector<int> tree[vertices + 5];
    int u,v;
    fr(i,edges){
        cin>>u>>v;
        tree[u].push_back(v);
    }
    int first[vertices+5];
    int count=1;
    vector<int> dfs_trav, height;
    fr(i,vertices) first[i]=-1;
    dfs(tree, 0, count, first, &height, &dfs_trav);

    int size_segment_tree = 2*(2<<(int(ceil(log2(height.size())))))-1;
    int s_tree_array[size_segment_tree + 1][2];

    create_segment_tree(height, s_tree_array, 0, 0, height.size()-1);

    // Queries
    int q;
    cin>>q;
    while(q--){
        int ql, qr;
        cin>>ql>>qr;
        if(first[ql]>first[qr]){
            ql = ql+qr;
            qr = ql-qr;
            ql = ql-qr;
        }
        int *ans = get_min_number(s_tree_array, 0, 0, height.size()-1, first[ql], first[qr]);
        cout<<"LCA is : "<<dfs_trav[ans[1]]<<endl;
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

