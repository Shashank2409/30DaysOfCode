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

void solve(){
    string s,p;
    cin>>s>>p;
    string concat = p+"$"+s;
    int n = concat.length();
    int z[concat.length()]={};
    int l=0,r=0;
    fr1(i,n-1){
        if(i<=r)  z[i] = min(z[i-l], r-i+1);
        while(i+z[i]<n && concat[i+z[i]]==concat[z[i]]) z[i]++;
        if(i+z[i]-1>r){
            l=i;
            r=i+z[i]-1;
        }
    }
    for(int i=p.length()+1;i<n;i++)
        if(z[i]==p.length())
            cout<<"Pattern present at : "<<i-p.length()-1<<endl;
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

