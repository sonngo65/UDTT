#include<bits/stdc++.h>
using namespace std;
void tinhTong(int m,int n,int b[][100]){
	for(int i = 1 ; i <= m ; i++ ){
		for(int j=0 ; j<=n ; j++){
			if(i>j){
				b[i][j]=b[i-1][j];
			}else{
				b[i][j] = b[i-1][j] + b[i][j-i];
			}
		}
	}
}
int main(){
	int m,n;
	cout<<"nhap so m: "<<endl;
		
	cin>>m;
	cout<<"nhap so can tinh tong : "<<endl;
	cin>>n;
	int b[m][100];

	for(int i=0;i<=m;i++){
		fill_n(b[i],n,0);
	}

	b[0][0]=1;
	tinhTong(m,n,b);
	cout<<b[m][n];
	
}
