#include<bits/stdc++.h>
using namespace std;
#define MAX 1000;
struct lophoc{
	char malop[10];
	int sohs;
	int sohsnu;
};

lophoc a[]={
	{"lop01",23,13},
	{"it02",33,11}, 
	{"lop03",49,8},
	{"lop0it4",32,21},
	{"lop05",38,16},
	{"lop06it",28,17},
	{"lop07",45,20},
	{"lop08",37,21},	
};
void sapxep(int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i].sohs < a[j].sohs){
				swap(a[i],a[j]);
			}
		}
	}
}
void thamLam(int len,int n){
	int i=0;
	while(n>0){
		n= n - a[i].sohs;
		i++;
	}
	cout<<"can lay it nhat "<< i << " lop hoc phan "<<endl;
}
void QuyHoachDong(int len,int k,int	f[][1000],int z[][1000]){

	for(int i=0;i<len;i++){
		f[i][0]= 0;
	}	
	for(int j=0;j<=k;j++){
		f[0][j]=0;
	}
	for(int i=0;i<len;i++){
		for(int j=1;j<=k;j++){
			f[i][j]=f[i-1][j];
			z[i][j]=i-1;
			if(j >= a[i].sohs && (f[i-1][j - a[i].sohs] +  a[i].sohsnu > f[i-1][j])){
				f[i][j]=f[i-1][j - a[i].sohs] + a[i].sohsnu;
				z[i][j]=i;
			}
		}
	}
}
void timKiTu(char *a,char *b,int &dem){
	int u=strlen(a);
	int v=strlen(b);
	int i=v-1;
	while(i<u){
		int j=i;
		int x=v-1;
		while(a[j]==b[x] && x>=0){
			j--;
			x--;
		}
		if(x<0){
			dem ++;
			i=i+v;
		}
		else{
			while(a[j]!=b[x] && x>=0){
				x--;
			}
			if(x>=0){
				i=i+v-x-1;
			}else{
				i=i+v;
			}
		}
	}
}
int main (){
	int len= sizeof a/ sizeof a[0];
//	sapxep(len);
//	int n ;
//	 cout << " nhap so nguye n : ";
//	 cin>>n;
//	thamLam(len,n);
//	 int k ;
//	 cout<<" Nhap so nguyen k : ";
//	 cin>>k;
//	int z[len+1][1000];
//	int f[len+1][1000];
//
//
//	QuyHoachDong(len,k,f,z);
//	int i= len-1;
//	int j= k;
//
//	while(i>=0 && j>0){
//		if(i == z[i][j]){
//			cout<<a[i].malop<<endl;
//			j=j - a[i].sohs;
//			i=i-1;
//		}else{
//			i=z[i][j];
//		}
//		cout<<i<<" "<<j<<endl;
//	}

	char s[] = "it";
	int dem=0;
	for(int i=0;i<len;i++){
		dem =0;
		timKiTu(a[i].malop,s,dem);
		if(dem > 0){
			cout<< " ma lop : "<< a[i].malop<<endl;
		}
	}

}
