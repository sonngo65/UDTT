#include<bits/stdc++.h>
using namespace std;
int a[] = {5,3,5,7,7,9,2,5,8,3,8};
int soNhoNhat(int a[],int k){
	if(k==0){
		return a[0];
	}
	return a[k] < soNhoNhat(a,k-1) ? a[k] : soNhoNhat(a,k-1);
}
int soNhoNhatCDT(int l, int r){
	int m = (l+r)/2;
	if(l==r){
		return a[l]; 
	}
	return soNhoNhatCDT(l,m) < soNhoNhatCDT(m+1,r) ? soNhoNhatCDT(l,m) : soNhoNhatCDT(m+1,r);
}
int main(){
	int k;
	int n = sizeof a/ sizeof a[0];
	cout<<soNhoNhatCDT(0,n-1);
}
