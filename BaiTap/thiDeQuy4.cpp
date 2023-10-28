#include<bits/stdc++.h>
using namespace std;
int deQuyCoNho(int n,int a[]){
	if(n<3){
		return 1;
	}
	if(a[n]>0){
		return a[n];
	}
	else{
		return a[n]= deQuyCoNho(n-1,a) + deQuyCoNho(n-2,a);
	}
}
int main(){
	int n;
	cout<<"Nhap so thu N : ";
	cin>>n;
	int a[n];
	for(int i=0;i<=n;i++){
		a[i]=0;
	}
	deQuyCoNho(n,a);
	cout<<a[n];
}
