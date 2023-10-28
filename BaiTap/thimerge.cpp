#include<bits/stdc++.h>
using namespace std;
struct hocsinh {
	char ten[20];
	char hodem[20];
	int namsinh;
	char diachi[10];

};
hocsinh a[] = {
	{"ngo","tat son",2002,"lao cai"},
	{"nguyen","thi thom",2001,"ha noi"},
	{"dao","le nguyen",2002,"yen bai"},
	{"anh","nguyen van",2001,"hung yen"},
	{"tung","vu quang",2004,"vung tau"},
	{"linh","le thi",2003,"dien bien"},
	{"hang","nhu thi",2001,"ha giang"},
	
};
void sapxep(int l,int r,hocsinh b[]){
	int m= (l+r)/2;
	if(l<r){
		sapxep(l,m,b);
		sapxep(m+1,r,b);
		for(int i=l;i<=m;i++){
			b[i]=a[i];
		}
		for(int i=m+1;i<=r;i++){
			b[i]=a[r  + m + 1-i];
		}
		int i=l,j=r;
		for(int k=l;k<=r;k++){
			if(strcmp(b[i].ten,b[j].ten)>0){
				a[k]=b[j];
				j--;
			}else{
				a[k]=b[i];
				i++;
			}
		}
	}

}
int timten(int l,int r,char ten[]){
	int m=(l+r)/2;
	if(l==r){
		if(strcmp(a[l].ten,ten)==0){
			return l;
		}else{
			return -1;
		}
	}
		if(strcmp(a[m].ten,ten)>0){
			return timten(l,m,ten);
		}
		else if(strcmp(a[m].ten,ten)<0){
			return timten(m+1,r,ten);
		}else{
			return m;
		}


}
int main(){
	int n = sizeof a/ sizeof a[0];
	hocsinh b[n+1];
	sapxep(0,n-1,b);
	for(int i=0;i<n;i++){
		cout<<a[i].ten<<endl;
	}
	char *ten;
	gets(ten);
	fflush(stdin);
	if(timten(0,n-1,ten)>=0){
		cout<<"tim thay vi tri "<< timten(0,n-1,ten)+1<<endl;
	}
}
