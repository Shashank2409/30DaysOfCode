#include<bits/stdc++.h>
using namespace std;

int placeOfPivot(long long nos[] , int low , int high){
	long long pivot = nos[high]  , place = low - 1;
	for(int i = low; i < high; i++){
		if(nos[i] < pivot){
			place++;
			swap(nos[place] , nos[i]);
		}
	}
	swap(nos[++place] , nos[high]);
	return place;
}

void quickSort(long long nos[] , int low , int high){
	if(low >= high)
		return ;
	
	int index = placeOfPivot(nos , low , high);
	quickSort(nos , low , index - 1);
	quickSort(nos , index + 1 , high);
}

int main(){
	int n;
	cin>>n;
	long long nos[n];
	for(int i = 0; i < n; i++)
		cin>>nos[i];
		
	quickSort(nos , 0 , n - 1);
	
	for(int i = 0; i < n; i++)
		cout<<nos[i]<<" ";
	cout<<"\n";
}
