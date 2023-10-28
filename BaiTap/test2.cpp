#include<bits/stdc++.h>
using namespace std;
struct congviec{
	char macv[10];
	int tgbd;
	int tgkt;
};
congviec a[]={
	{"cv01",7,10},
	{"cv02",6,9},
		{"cv03",3,6},
	{"cv04",10,12},
	{"cv05",13,16},
	{"cv06",8,10},
};
int n = sizeof a/sizeof a[0];
void sapxep(congviec a[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1 ; j<n;j++){
			if(a[i].tgkt>a[j].tgkt){
				swap(a[i],a[j]);
			}
		}
	}
}
void laplich(congviec a[],int n){
	sapxep(a,n);
	int i=0;
	int last=0,count=0;
	while(i<n){
		if(a[i].tgbd>=last){
			last = a[i].tgkt;
			cout<<"ma cv:"<<a[i].macv<<endl;
			cout<<"thoi bd:"<<a[i].tgbd<<endl;
			cout<<"thoi gian kt : "<<a[i].tgkt<<endl;
			count++;
		}
		i++;
	}
	cout<<"mot nguoi thuc hien nhieu nhat "<< count << " cong viec "<<endl;

}
int tongtg(congviec a[],int k){
	if(k<0){
		return 0;
	}
	return (a[k].tgkt-a[k].tgbd) + tongtg(a,k-1);
}
void hienthi(congviec a[],int b[]){
	for(int i=0;i<=4;i++){
		cout<<"ma cong viec: "<<a[b[i]].macv<<endl;
	}
}
void laycongviec(congviec a[],int n){
	int k=4,b[5];
	for(int i=0;i<5;i++){
		b[i]=i;
	}
	int j=b[4];
	while(k>=0){
		b[k]=j;
		j++;
		if(j>=n-(4-k)){
			k--;
			j=b[k]+1;
		}else if(k<4){
			for(int l=k+1;l<=4;l++){
				b[l]=b[l-1]+1;
			}
			k=4;
			j=b[k]+1;
		}
		cout<<"------------"<<endl;
		hienthi(a,b);
	}
}
int main(){
	cout<<"tong thoi gian thuc hien cong viec: "<<tongtg(a,n-1);

	laycongviec(a,n);
	laplich(a,n);
}
