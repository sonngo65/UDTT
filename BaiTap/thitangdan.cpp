#include<bits/stdc++.h>
using namespace std;
int a[]={5,3,4,7,5,6,7,2,9,12,5,34,86,12,43};
void quyhoach(int n,int f[],int z[]){

	for(int i=0;i<n;i++){
		f[i]=0;
		z[i]=0;
	}
		f[n-1]=1;
	for(int i=n-2;i>=0;i--){
		int max=0;
		for(int j=n-1;j>i;j--){
			if(a[j]>a[i] && f[j]>f[max]){
				max = j;
			}
		}
		f[i]=f[max]+1;

		z[i]=max;
	}
}
int main(){
	int n=sizeof a/ sizeof a[0];
	int f[n+2],z[n+2];
	quyhoach(n,f,z);
	int max=0;
	for(int i=0;i<n;i++){
		if(max<f[i]){
			max=i;
		}
	}
	cout<<max<<endl;
	while(z[max]!=0){
		cout<<a[max]<<" ";
		max = z[max];
	}
}
