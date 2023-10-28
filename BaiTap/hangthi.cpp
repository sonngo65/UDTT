#include<bits/stdc++.h>
using namespace std;
struct hang{
	float m;
	float k;
	
};
hang a[]={
	{4.5,5.2},
	{3.5,4.2},
	{5.1,6.2},
	{4,3.2},
	{5.2,5},
	{3,1.0},
	{0.8 , 0.8},
	{0.7 , 0.8},
	{4,4},
	{3.2,2.2}
};
void sapxep(int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i].m/a[i].k  < a[j].m/a[j].k){
				swap(a[i],a[j]);
			}
		}
	}
}
void thamlam(int n,float k){
	sapxep(n);
	int i=0;
	while(k>0 && i<n){

		if(k >= a[i].k){
			cout<<"kien hang khoi luong  : "<<a[i].m<<endl;
			cout<<"kien hang kich thuoc : "<<a[i].k<<endl;
			k = k-a[i].k;
		}
		i++;
	}
}
int main(){
	int n= sizeof a/sizeof a[0];
	float k;
	cin>>k;
	thamlam(n,k);
}
