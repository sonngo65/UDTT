#include<bits/stdc++.h>
using namespace std;
void quyhoach(int m,int n,int a[][100]){
	for(int i=1;i<=m;i++){
		for(int j=0;j<=n;j++){
			if(i>j){
				a[i][j]=a[i-1][j];
			}else{
				a[i][j]=a[i-1][j] + a[i][j-i];
			}
		}
	}
}
int main(){
	int n,m;
	cin>>n;
	cin>>m;
	int a[m+2][100];
	for(int i=0;i<=n;i++){
		a[0][i]=0;
	}
	for(int j=0;j<=m;j++){
		a[j][0]=0;
	}
	a[0][0]=1;
	quyhoach(m,n,a);
	cout<<"nhieu nhat"<<a[m][n];
}
