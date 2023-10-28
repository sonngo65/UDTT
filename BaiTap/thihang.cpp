#include<bits/stdc++.h>
using namespace std;
struct hang{
	int w;
	float v;
};
hang a[]={
	{4,6},
	{5,3},
	{7,4},
	{3,8},
	{9,2},
	{5,6},
	{7,8},
};
void sapxep(int n,int m,float f[][100],int z[][100]){
	for(int i=0;i<n;i++){
		f[i][0]=0;
	}
	for(int i=0;i<=m;i++){
		f[0][i]=0;
	}
	for(int i=0;i<n;i++){
		for(int j=1;j<=m;j++){
			f[i][j]=f[i-1][j];
			z[i][j]=i-1;
			if(j>=a[i].w && f[i-1][j-a[i].w] + a[i].v > f[i-1][j]){
				f[i][j]=f[i-1][j-a[i].w]+a[i].v;
				z[i][j]=i;
			}
		}
	}
}
int main(){
	int n= sizeof a/sizeof a[0];
	int m;
	cin>>m;
	float f[n+1][100];
	int z[n+1][100];
	sapxep(n,m,f,z);
	cout<<f[n-1][m]<<endl;
	int i=n-1;
	int j=m;
	while(i>=0){
			cout<<i<<" "<<z[i][j]<<endl;
		if(z[i][j]==i){
			cout<<"hang khoi luong: "<<a[i].w<<endl;
			cout<<"hang gia tri: "<<a[i].v<<endl;
			j=j-a[i].v;
			i=i-1;
		}else{
			i=z[i][j];
		}
	
	}
}
