#include<bits/stdc++.h>
using namespace std;
int tongdequy(int n){
	if(n<=0){
		return 0;
	}
	return n%10 + tongdequy(n/10);
}
int main(){
	int n;
	cin>>n;
	cout<<tongdequy(n);
}
