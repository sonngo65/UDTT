#include<bits/stdc++.h>
using namespace std;
int tien[] = {1,2,5,10,20,50,100,500};
void sapxep(int len){
	for(int i=0;i<len-1;i++){
		for(int j=i+1;j<len;j++){
			if(tien[i]<tien[j]){
				swap(tien[i],tien[j]);
			}
		}
	}
}
void thamlam(int len , int n){
	sapxep(len);
	int i=0;
	while(n>0 && i<len){
	
		if(n>=tien[i]){
			cout<<"menh gia: "<<tien[i]<<endl;
			n=n-tien[i];
		}
		else{
			i++;
		}
	}
}
int main(){
	int len=sizeof tien/sizeof tien[0];
	int n;
	cin>>n;
	thamlam(len,n);
	
}
