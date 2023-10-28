#include<bits/stdc++.h>
using namespace std;
void hienthi(int a[],int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
void sinh(int n,int a[]){
	for(int i=0;i<n;i++){
		a[i]=i+1;
		cout<<a[i]<<" ";
	}
	cout<<endl;
	int i=n-1;
	while(i>0){
		if(a[i]>a[i-1]){
			int temp = a[i-1];
			for(int j=n-1;j>=i;j--){
				if(a[j]>a[i-1]){
					a[i-1]=a[j];
					a[j]=temp;
					break;
				}
			}
			for(int j=i;j<=(i+(n-1))/2 ;j++){
				swap(a[j],a[(n-1)-(j-i)]);
			}
			i=n-1;
			hienthi(a,n);
		}else{
			i--;
		}
	}
}

int main()
{
	int n;
	cout<<"Nhap n : ";
	cin>>n;
	int a[n+1];
	sinh(n,a);
}
