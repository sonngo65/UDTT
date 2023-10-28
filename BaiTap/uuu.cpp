#include<bits/stdc++.h>
using namespace std;
struct goihang{
	int w;
	int v;
};
goihang a[]={
	{3,5},
	{6,12},
	{2,1},
	{7,8},
	{10,20}
	
};
int n = sizeof a/sizeof a[0];
void layHang(goihang a[],int m){
	int b[m];
	for(int i=0;i<=m;i++){
		b[i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<n;j++){
			if(a[j].w<=i){
				b[i]=(b[i-a[j].w] + a[j].v)>b[i] ? (b[i-a[j].w] + a[j].v):b[i]; 
			}else{
				if(b[i-1]>b[i]){
					b[i]=b[i-1];
				}
			}
		}			
		cout<<b[i]<<" "<< i<<endl;
	}
}
int main(){
	int m;
	cin>>m;
	layHang(a,m);
}
