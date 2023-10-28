#include<bits/stdc++.h>
using namespace std;
void tong(int m,int n,int a[][100]){
	for(int i=1 ; i<=m;i++){
		for(int j=0;j<=n;j++){
			if(i>j){
				a[i][j]=a[i-1][j];
			}else{
				a[i][j]=a[i-1][j]+a[i][j-i];
			}
		}
	}
}
int main(){
	int n,m;
	cout<<"nhap m : ";
	cin>>m;
	cout<<"nhap n: ";
	cin>> n;
	int a[m+2][100];
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			a[i][j]=0;
		}
	}
	a[0][0]=1;
	tong(m,n,a);
	cout<<a[m][n];
	
}
