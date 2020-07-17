#include<bits/stdc++.h>
using namespace std;

/* For Debugging */
void printArray(vector< vector<int> > &chess , vector<int> &row , vector<int> &diag , vector<int> &diagR1 , vector<int> &diagR2 , int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<chess[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n";
	for(int i =0 ;i<n;i++){
		cout<<diag[i]<<" ";
	}
	cout<<"\n\n";
	for(int i =0 ;i<n;i++){
		cout<<diagR1[i]<<" ";
	}
	cout<<"\n\n";
	for(int i =0 ;i<n;i++){
		cout<<diagR2[i]<<" ";
	}
	cout<<"\n\n";
}

bool solveNQueen(vector< vector<int> > &chess , vector<int> &row , vector<int> &diag , vector<int> &diagR1 , vector<int> &diagR2 , int col , int n){
	if(col == n)
		return true;
	for(int i = 0; i < n; i++){
		if(row[i] == 1 || diag[i + col] == 1)
			continue;
		if(i > col){
			if(diagR1[i - col] == 1)
				continue;
		}
		else{
			if(diagR2[col - i] == 1)
				continue;
		}
		
		chess[i][col] = 1;
		row[i] = 1 , diag[i + col] = 1;
		if(i > col) diagR1[i - col] = 1;
		else diagR2[col - i] = 1;
	
		if(solveNQueen(chess , row , diag , diagR1 , diagR2 , col + 1 , n))
			return true;
			
		chess[i][col] = 0;
		row[i] = 0 , diag[i + col] = 0;
		if(i > col) diagR1[i - col] = 0;
		else diagR2[col - i] = 0;
	}	
	return false;
}

int main(){
	long long n;
	cin>>n;
	vector<vector<int> >chess;
	for(int i = 0; i < n; i++){
		vector<int> temp(n);
		for(int j = 0; j < n; j++)
			temp[i] = 0;
		chess.push_back(temp);
	}
	
	vector<int> row(n) , diag(2*n) , diagR1(2*n) , diagR2(2*n);
	for(int i = 0; i < 2*n; i++){
		if(i < n) row[i] = 0;
		diag[i] = 0 , diagR1[i] = 0 , diagR2[i] = 0;
	}
	
	if(solveNQueen(chess , row , diag , diagR1 , diagR2 , 0 , n)){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout<<chess[i][j]<<" ";
			}
			cout<<"\n";
		}
	}
	else{
		cout<<"No Solution Exists!\n";
	}
}
