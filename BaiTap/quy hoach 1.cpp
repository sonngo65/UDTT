#include<bits/stdc++.h>
using namespace std;
struct goihang{
	int w;
	float v;
};
goihang a[]={
	{3,42},
	{5,72},
	{9,102},
	{7,62},
	{4,52},
	{4,22}

};
void xephang(int f[],int z[],int n,int m){
	int max=0;
	f[0]=0;
	z[0]=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<n;j++){
			if(f[i-a[j].w] + a[j].v > max && a[j].w	<= i){
				max= f[i-a[j].w ] + a[j].v ;
				z[i]=j;
			}
		}
		cout<<max<<endl;
		f[i]=max;
	}
}
int main(){

	int n = sizeof a/sizeof a[0];
	int m;
	cout<<"nhap khoi luong tui "<<endl;
	cin>>m;
	int f[m+1];
	int z[m+1];
	int k=m;

	for(int i=1;i<=m;i++){
		f[i]=-1;
	}
	xephang(f,z,n,m);

	while(f[m]!=0){
		cout<<"goi hang thu "<< z[m]+1<<endl;
		cout<<"khoi luong "<< a[z[m]].w<<endl;
		cout<<"gia tri "<<a[z[m]].v<<endl;
		m=m-a[z[m]].w;
	}
}
