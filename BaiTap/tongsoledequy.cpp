#include<bits/stdc++.h>
using namespace std;
int a[] = {2,4,6,3,7,24,6,7,1,47,3,2,6,9,1 };
int tongsole(int a[],int n){
	if(n<0){
		return 0;
	}
	return ((a[n] % 2) != 0 ? a[n] : 0 ) + tongsole(a,n-1) ; 
}
int main(){
	int n= sizeof a/sizeof a[0];
	cout<<tongsole(a,n);
}
