#include<bits/stdc++.h>
using namespace std;
float a[]={3.4 ,4.5 ,1.2 , 4.7 ,4.4 ,6.3 ,10, 4 ,3.2 ,12 ,2.4 ,14 , 12.2 ,14 , 15.3 ,6.2};
void tangdainhat(int f[],int z[],float a[],int n){
	for(int i=n-1;i>=0;i--){
		int max=0;
		for(int j=n-1;j>i;j--){
			if(f[j]>max && a[i] <a[j]){
				max = f[j];
				z[i]=j;
			}
			f[i]=max + 1;
		}
	}
}
int main(){
	int n=sizeof a/sizeof a[0];
	int f[n+1],z[n+1];
	for(int i=0;i<n;i++){
		f[i]=0;
		z[i]=0;
	}
	tangdainhat(f,z,a,n);
	int max=0;
	int k=0;
	for(int i=0;i<n;i++){
		if(f[i]>max){
			max=f[i];
			k=i;
		}
	}

	while(z[k]!=0){
		cout<<a[k]<<" ";
		k=z[k];
	}
}
