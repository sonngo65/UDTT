#include<bits/stdc++.h>
using namespace std;
struct lich{
	float bd;
	float kt;
};
lich a[]={
	{5.1,9.7},
	{6.1,7.7},
	{5.2,10.7},
	{1.1,7.9},
	{2.1,4.7},
	{7.1,13},
	{11.1,14.7},
	{14.1,19.7}
};
void sapxep(int n){
	
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i].kt>a[j].kt){
				swap(a[i],a[j]);
			}
		}
	}
}
void thamlam(int n){
	sapxep(n);
	float rekt=0;
	int i=0;
	while(i<n){
		
		if(a[i].bd > rekt || i==0){
			cout<<"viec bat dau: "<<a[i].bd<<endl;
			cout<<"viec ket thuc: "<<a[i].kt<<endl;
			cout<<"-------------------------"<<endl;
			rekt = a[i].kt;
		}
		i++;
	}
}
int main(){
	int n= sizeof a/sizeof a[0];
	thamlam(n);
}
