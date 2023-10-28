#include<bits/stdc++.h>
using namespace std;
int a[8][8];
void hienthi(int a[][8],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}
void madituan(int x,int y,int n,int j){
	int mx,my;
	for(int i=1;i<=8;i++){
		switch(i){
			case 1: 
				mx=x+1;
				my=y-2;
				break;
			case 2:
				mx=x+2;
				my=y-1;
				break;
				
			case 3: 
				mx = x+2;
				my = y+1;
				break;
			case 4:
				mx=x+1;
				my=y+2;
				break;
			case 5:
				mx=x-1;
				my=y+2;
				break;
			case 6:
				mx=x-2;
				my=y+1;
				break;
			case 7:
				mx=x-2;
				my=y-1;
				break;
			case 8:
				mx=x-1;
				my=y-2;
				break;
				
		}

		
		if(mx>=1 && mx<=n && my>=1 && my<=n && a[my-1][mx-1]==0){
		
			a[my-1][mx-1]=j;
			if(j==n*n){
					hienthi(a,n);	
			}
			madituan(mx,my,n,j+1);
			a[my-1][mx-1]=0;


		}
		
		
	}
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			a[i][j]=0;
		}
	}
	a[0][0]=1;
	madituan(1,1,n,2);
		
}
