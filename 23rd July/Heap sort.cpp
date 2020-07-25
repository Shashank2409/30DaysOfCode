#include<bits/stdc++.h>
using namespace std;

void heapify(long long *nos , int n , int i){
	int lar = i , l = 2 * i, r = 2 * i + 1;
	if(l <= n)
		if(nos[l] > nos[lar])
			lar = l;
			
	if(r <= n)
		if(nos[r] > nos[lar])
			lar = r;
			
	if(lar != i){
		swap(nos[lar] , nos[i]);
		heapify(nos , n , lar);
	}
}

int main(){
	long long n;
	cin>>n;
	long long nos[n + 1];
	for(int i = 1; i <= n; i++)
		cin>>nos[i];
	
	for(int i = n / 2; i > 0; i--)
		heapify(nos , n , i);
	
	for(int i = n; i > 0; i--){
		swap(nos[i] , nos[1]);
		heapify(nos , i - 1 , 1);
	}
	for(int i = 1; i <= n; i++)
	    cout<<nos[i]<<" ";
	cout<<"\n";
}
