#include<bits/stdc++.h>
using namespace std;
void hienthi(int k,int a[]){
	for(int i=k;i>=1;i--){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
void deQuy(int k,int l,int n,int a[],int b[]){

			if(k>0){
				for(int i=1 ; i<= n ; i++ ){
					if(b[i]==0){
						a[k]=i;
						b[i]=1;
						deQuy(k-1,l,n,a,b);
						b[i]=0;
					}	
				}
			}else{
				hienthi(l,a);
			}
	
}
int main(){
	int n;
	cin>>n;
	int k;
	cin>> k;
	int a[k+1];
	int b[n+1];
	for(int i=1;i<=n;i++){
		b[i]=0;
	}
	deQuy(k,k,n,a,b);
}

