#include<bits/stdc++.h>
using namespace std;
void hienthi(int n,int a[]){
	for(int i=n;i>=1;i--){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
void dequy(int k,int n,int a[],int b[]){
	if(k>0){
		for(int i=1 ;i<= n;i++){
			if(b[i]==0){
				a[k]=i;
				b[i]=1;
				dequy(k-1,n,a,b);
				b[i]=0;
			}
		}
	}else{
		hienthi(n,a);
	}
}
int main(){
	int n;
	cin>>n;
	int a[n+1];
	int b[n+1];
	for(int i=1;i<=n;i++){
		b[i]=0;
	}
	dequy(n,n,a,b);
}
