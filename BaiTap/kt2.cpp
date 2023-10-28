#include<bits/stdc++.h>
using namespace std;
struct dienthoai{
	char nhan[10];
	int kt;
	long long  gia;
};
dienthoai a[]={
	{"samsung",10,4000000},
	{"iphone",5,300},
	{"galaxy",4,5000000},
	{"xiaomi",3,23},
	{"iphonex",11,103},
	{"samsung2",9,89},
	{"iphone7",14,193}
};
void antrom(dienthoai a[],int f[],int k[],int n,int s){
	f[0]=0;
	int max=0;
	for(int i=1;i<=s;i++){
			for(int j=0;j<n;j++){
				if(a[j].kt<=i){
				
					if(f[i-a[j].kt] + a[j].gia >max ){
						max = f[i-a[j].kt] + a[j].gia;
						k[i]=j;
					}
				
				}
			}
			
			if(k[i]<0 && i>1){
				k[i]=k[i-1];
			}
			f[i]=max;
	}
}
int soluongdt(int l,int r){
	int m=(l+r)/2;
	if(l==r){
		return (a[l].gia > 3000000 && a[l].gia<6000000) ? 1 : 0 ; 
	}
	return soluongdt(l,m) + soluongdt(m+1,r);
}

int main(){
	int n = sizeof a/sizeof a[0];
	int s;
	cout<<"Nhap tui an trom : ";
	cin>>s;
	
	int f[n+1],k[s+1];
	int m=s;
	for(int i=1;i<=s;i++){
		k[i]=-1;
	
	}

	antrom(a,f,k,n,s);
	int soluong=0;
	cout<<"Lay dien thoai:"<<endl;
	while(f[m]>0){
		
		cout<<a[k[m]].nhan<<endl;
		cout<<a[k[m]].gia<<endl;
		soluong++;
		m=m-a[k[m]].kt;
	}
	cout<<"Tong so luong dien thoai da lay la: "<<soluong<<endl;
	cout<<"So luong dien thoai : "<<soluongdt(0,n-1);
	
}
