#include<bits/stdc++.h>
using namespace std;
float tai[] = {4.5,6.4,7.1,2.1,1.8,3.4,5.1,3.2,5.1,2.4,1.4,1.7};

void sapxep(int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(tai[i]<tai[j]){
				swap(tai[i],tai[j]);
			}
		}
	}
}
void thamlam(int n,float m){
	sapxep(n);
	int i=0;
	while(m>0 && i<n){
		
		m=m-tai[i];
		i++;
	}
	if(m>0){
		cout<<"khong du xe"<<endl;
	
	}else{
		for(int j=0;j<i;j++){
			cout<<"xe : "<<tai[j]<<endl;
		}
	}
}
int main(){
	int n=sizeof tai/sizeof tai[0];
	int m;
	cin>>m;
	thamlam(n,m);
}
