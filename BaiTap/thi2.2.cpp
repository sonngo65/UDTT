#include <bits/stdc++.h>
using namespace std;
struct sanpham{
	char masp[10];
	char tensp[30];
	int kl;
	int soluong;
};
sanpham d[] = {
	{"sp01","Iphone",4,6},
	{"sp02","sualnhsaubbnmmgfack",5,8},
	{"sp03","galaxy",8,14},
	{"SP0088","Tulanhabbnmmfackl",10,14},
	{"sp05","MtauylGainatblmkmfackl",5,7},
	{"sp06","SaPhong",2,5},
	{"sp07","Ntiviuoc",1,4},
	{"sp08","Com",6,9},
};
void sapxep(int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(strcmp(d[i].tensp,d[j].tensp)>0){
				swap(d[i],d[j]);
			}
		}
	}
}
int chiaDeTri(int l,int r,sanpham newD){
	int m= (l+r)/2;
	if(l==r){
		if(strcmp(newD.tensp,d[l].tensp)>0){
			return l+1;
		}else{
			return l;
		}
	}
	if(strcmp(newD.tensp,d[m].tensp)>0){
		return chiaDeTri(m+1,r,newD);
	}else{
		return chiaDeTri(l,m,newD);
	}
}
void QuyHoachDong(char *a,char *b,int l[][100]){
	for(int i=0;i<=strlen(a);i++){
		for(int j=0;j<=strlen(b);j++){
			l[i][j]=0;
		}		
	}
	for(int i=1;i<=strlen(a);i++){
		for(int j=1;j<=strlen(b);j++){
			if(a[i-1] == b[j-1]){
				l[i][j] = l[i-1][j-1] + 1;
			}
			else{
				if(l[i-1][j]>l[i][j-1]){
					l[i][j]=l[i-1][j];
				}else{
					l[i][j]=l[i][j-1];
				}
			}
		}
	}
}
void xuLyXau(char *s,char *a,int &dem){
	int u=strlen(s),v=strlen(a);
	int i=u-1;
	while(i<v){
		int j=i;
		int x=strlen(s)-1;
		while(a[j]==s[x] && x>=0){
			j--;
			x--;
			
		}
		if(x<0){
			dem++;
			i=i+u;
		}else{
			while(a[j]!=s[x] && x>=0) {
				x--;
			}
			if(x<0){
				i=i+u;
			}else{
				i=i+u-x-1;
			}
		}
	}
	
}
int main(){
	int n = sizeof d/sizeof d[0];
	sanpham newD ={
		"sp09","Baytinh",11,14
	} ;

	sapxep(n);
	cout<<d[0].tensp<<endl;
	int l[100][100];
	cout<<chiaDeTri(0,n-1,newD)<<endl;
	char c[100];
	for(int i=0;i<n;i++){
		if(strcmp(d[i].masp,"SP0088")==0){
			strcpy(c,d[i].tensp);	
		}
	}
	cout<<c<<endl;
	for(int i=0;i<n;i++){
		QuyHoachDong(d[i].tensp,c,l);
		if(l[strlen(d[i].tensp)][strlen(c)]>=10){
			cout<<"San pham : "<<d[i].masp<<endl;
		}
	}
	char s[] = "tivi";
	cout<<"ten Tivi : "<<endl;
	for(int i=0;i<n;i++){
		int dem=0;
		xuLyXau(s,d[i].tensp,dem);
		if(dem > 0){
			cout<<"san pham : "<<d[i].masp<<endl;
		}
	}
}
