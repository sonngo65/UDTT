#include<bits/stdc++.h>
using namespace std;
// cho n hoc phan trong danh sach m , hoc phan bao gom: ten hoc phan, so tin chi , hoc ky
//cau 1: khoi tao danh sach n hoc phan (6<=n <=10) (khong nhap tu ban phim)
struct hocphan{
	char tenhp[20];
	float sotc;
	int hk;
};
hocphan a[]={
	{"triet",1.5,1},
	{"toan cc",2.5,2},
	{"vat ly",3,3},
	{"udtt",3,5},
	{"tieng anh",5,4},
	{"mang may tinh",3,4}
};
int n=sizeof a/sizeof a[0];

//cau1: tinh tong tin chi bang phuong phap de quy
int tongTC(hocphan a[],int k){
	if(k<0){
		return 0;
	}
	return a[k].sotc + tongTC(a,k-1);
}
//cau 2:- cho so thuc q can dang ky it nhat bao nhieu hoc phan de co tong so tin chi dung bang q
void sapxep(hocphan a[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i].sotc<a[j].sotc){
				swap(a[i],a[j]);
			}
		}
	}
}
void tinChiQ(hocphan a[],float q,int n){
	int i=0;
	sapxep(a,n);
	while(q>0 && i<n){
		q=q-a[i].sotc;
		i++;
	}
	if(q>0){
		cout<<"khong co cach dang ky du tin chi!"<<endl;
	}else{
		cout<<"dang ky it nhat "<<i<<" tin chi"<<endl;
		for(int j=0;j<i;j++){
			cout<<"------------"<<endl;
			cout<<"ten hoc phan: "<<a[j].tenhp<<endl;
			cout<<"so tin cho: "<<a[j].sotc<<endl;
		}
	}
}
//- sap xep danh sach n hoc phan m vao n vi tri khac ngau tu 1->n 


void hienthi(hocphan a[],int b[]){
	for(int i=0;i<n;i++){
			cout<<"so thu "<<b[i]+1<<endl;
			cout<<"ten hoc phan :"<<a[b[i]].tenhp<<endl;
			cout<<"so tin chi : "<<a[b[i]].sotc<<endl;
	}
}
void sapvitri(int k,int c[],int b[]){
	
	for(int i=0;i<n;i++){
		if(c[i]==0){
			c[i]=1;
			b[k]=i;		
			if(k==n-1){
				cout<<"-----------------"<<endl;
				hienthi(a,b);
			}else{
				sapvitri(k+1,c,b);
			}
			c[i]=0;
		}
	}
	
}
int main(){
	cout<<"Tong tin chi : "<<tongTC(a,n-1)<<endl;
	float q;
	cout<<"nhap so tin chi muon dang ky ";
	cin>>q;
	tinChiQ(a,q,n);

	int c[n]={0};
	int b[n]={0};
	sapvitri(0,c,b);
	
}

