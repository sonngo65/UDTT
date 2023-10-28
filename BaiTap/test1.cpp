#include<bits/stdc++.h>
using namespace std;
struct maytinh{
	char nhanhieu[30];
	float gianhap;
	float giaban;
};
maytinh a[]={
		{"acer",1.4,2.6},
		{ "asus",4.6,5.7},
		{ "microsoft",3.6,5.7},
		{ "mac",5.6,7.7},
		{ "asus",6.6,8.2},
		{ "dev",5.2,8.5}
	};
	
int n=sizeof a/sizeof a[0];
void hienthidequy(maytinh a[],int m){
	if(m>=n){
		return;
	}
	cout<<"may tinh thu "<< m+1<<endl;
	cout<<"nhan hieu: "<<a[m].nhanhieu<<endl;
	cout<<"gia nhap: "<<a[m].gianhap<<endl;
	cout<<"gia ban: "<<a[m].giaban<<endl;
	hienthidequy(a,m+1);
}
void sapxep(maytinh a[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i].giaban-a[i].gianhap < a[j].giaban - a[j].gianhap){
				swap(a[i],a[j]);
			}
		}
	}
}
void tienlai(maytinh a[],int n,float q){
		int i=0;
		int count=0;
		sapxep(a,n);
		while(q>0 && i<n){
			q=q-(a[i].giaban-a[i].gianhap);
			count++;
			i++;
		}
		if(q>0){
			cout<<"khong ban du tien lai !"<<endl;
		
		}else{
			for(int j=0;j<i;j++){
					cout<<"may tinh:"<<endl;
				cout<<"tien lai: " <<a[j].giaban-a[j].gianhap<<endl;
				cout<<"nhan hieu: "<<a[j].nhanhieu<<endl;
			}
			cout<<"can it nhat: "<<count<<endl;
		}
}	
void hienthi(maytinh a[],int b[]){
	for(int i=0;i<n;i++){
		cout<<"may tinh thu "<< b[i]<<endl;
		cout<<"nhan hieu: "<<a[b[i]].nhanhieu<<endl;
	}
}
void xepmay(maytinh a[],int n){
	int b[n];
	for(int k=0;k<n;k++){
		b[k]=k;
	}
		cout<<"--------------"<<endl;
		hienthi(a,b);
	int i=n-1;
	while(i>0){
		if(b[i]>b[i-1]){
		
			for(int j=n-1;j>=i;j--){
				if(b[i-1]<b[j]){
					swap(b[i-1],b[j]);
					break;
				}
				
			}
			for(int j=i;j<n-1;j++){
				for(int k=j+1;k<n;k++){
					if(b[j]>b[k]){
						swap(b[j],b[k]);
						i=n-1;
					}
				}
			}
					cout<<"--------------"<<endl;
			hienthi(a,b);
		}
		else{
			i--;
		}

	}
}
int main(){
 	hienthidequy(a,0);
 	float q;
	cout<<"nhap tien lai mong muon: "<<endl;
 	cin>>q;
 	tienlai(a,n,q);
 	xepmay(a,n);
 	
}
