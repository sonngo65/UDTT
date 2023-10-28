#include<bits/stdc++.h>
using namespace std;
void hienthi(int n,int a[]){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
void sinhNhiPhan(int n,int a[]){
	for(int i=0;i<n;i++){
		a[i]=0;
		cout<<a[i]<<" ";
	}
	cout<<endl;
	int i=n-1;
	
	while(i>=0){
		if(a[i]==1){
			a[i]=0;
			i--;
		}else{
			a[i]=1;
			i=n-1;
			hienthi(n,a);
		}
		
		
	}
}
int main(){
	int n;
	cout<<"nhap so nguyen n: ";
	cin>>n;
	int a[n+1];
	sinhNhiPhan(n,a);
}
