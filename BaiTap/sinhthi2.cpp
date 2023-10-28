#include<bits/stdc++.h>
using namespace std;
void hienthi(int a[],int k){
	for(int i=0;i<k;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
void sinh(int a[],int n,int k){
	for(int i=0;i<k;i++){
		a[i]=i+1;
		cout<<a[i]<<" ";
	}
	cout<<endl;
	int i=k-1;
	while(i>=0){

		if(a[i]<n-(k-(i+1))){
			a[i]=a[i]+1;
			for(int j=i+1;j<k;j++){
				a[j]=a[i]+1;
			}
			
			hienthi(a,k);
			i=k-1;
		}else{
			i--;
		}
	}
}
int main(){
	int n,k;
	cout<<"nhap n: "<<endl;
	cin>>n;
	cout<<"nhap k: "<<endl;
	cin>>k;
	int a[k+1];
	sinh(a,n,k);
}
