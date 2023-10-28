#include<bits/stdc++.h>
using namespace std;
void hienthi(int n,int a[]){
	for(int i=n;i>=1;i--){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
void deQuy(int k,int n,int a[]){
	
		
		if(k>0){
			for(int i=0;i<=1;i++){
			a[k]=i;
			deQuy(k-1,n,a);}
		}else{
			hienthi(n,a);
		}

	
	
}
int main(){
	int n;
	cin>>n;
	int a[n+1];
	deQuy(n,n,a);
}
