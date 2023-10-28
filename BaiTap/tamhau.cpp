#include<bits/stdc++.h>
using namespace std;
int a[8][8];
int x[8];
// vi tri hau tai vi tri toa do vy = j(y)  vx=x[j](x)
void hienthi(int a[][8],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}

bool check(int vy,int vx){
	for(int i=0;i<vy;i++){
		if(x[i] == vx || vx>=8 || abs(x[i]-vx)==abs(i-vy) ){
			return false ;
		}
	}
	return true;
}
void tamhau(int j){
	for(int i=0;i<8;i++){
		if(check(j,i)){
			x[j]=i;
			a[j][i]=1;
			if(j==7){
							hienthi(a,8);
							cout<<"------------------"<<endl;
			}
			tamhau(j+1);
			
			x[j]=-1;
			a[j][i]=0;
		}
	
	}
}

int main(){
	for(int i=0;i<8;i++){
		x[i]=-1;
		for(int j=0;j<8;j++){
			a[i][j]=0;
		}
	}
	tamhau(0);
}
