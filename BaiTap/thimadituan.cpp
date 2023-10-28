#include<bits/stdc++.h>
using namespace std;
void madituan(int n,int m,int a[][8],int dem){
	
	int y=n;
	int x=m;

	a[y][x]=dem;
		if(dem>=25){
		
		cout<<"----------------------"<<endl;
		for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"-------------------"<<endl;
		
	}else{
	
	for(int i=1;i<=8;i++){
		switch(i){
			case 1:
				x=m+1;
				y= n-2;
				break;
			case 2:
				x = m+2;
				y=n-1;
				break;
			case 3:
				x = m+2;
				y=n+1;
				break;
			case 4: 
				x= m+1;
				y=n+2;
				break;
			case 5:
				x = m-1;
				y=n+2;
				break;
			case 6:
				x = m-2;
				y=n+1;
				break;
			case 7: 
				x=m-2;
				y=n-1;
				break;
			case 8:
				x=m-1;
				y=n-2;
				break;
				 
		}
		if(x>=0 && y>= 0 && x < 5  && y < 5 && a[y][x]==0){
			dem++;
			madituan(y,x,a,dem);
			a[y][x]=0;
			dem--;
		}
	}
	}
}
int main(){
	int n=8,m=8;
	int a[8][8];
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			a[i][j]=0;
		}
	}
	int dem=1;
	madituan(0,0,a,dem);

}
