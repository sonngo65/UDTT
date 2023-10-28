#include<bits/stdc++.h>
using namespace std;
float a[] = {1.5,6.2,12.4,3.2,2.1,7.8,13.6,9,10.5,13.2,11.3,20,8,10,9};
int n = sizeof a/ sizeof a[0];


void dayConDonDieuTangDaiNhat(float a[],int b[],int k[],int n,int &result){
	
	b[n-1]=1;
	for(int i=n-2;i>=0;i--){
		float max=0;
		for(int j=n-1;j>i;j--){
			if(max<b[j] && a[i]<a[j]){
				max=b[j];
				k[i]=j;
			}
		
		}
	
		b[i]=max+1;
			if(result<b[i]){
			result=b[i];
		}
	}
}
int main(){
	int result=0;
	int b[n];
	int k[n];
	fill_n(b,n,0);
	fill_n(k,n,0);
	dayConDonDieuTangDaiNhat(a,b,k,n,result);
	for(int i=n-1;i>=0;i--){
		if(b[i]==result){
			int j=i;
			while(k[j]!=0){
				cout<<a[j]<<" ";
				j=k[j];
			}
			cout<<a[j];
		}
	}

}
