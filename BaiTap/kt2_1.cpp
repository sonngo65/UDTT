#include<bits/stdc++.h>
using namespace std;
char s[][100]={"you","i go child you  to school you ","the computer  you run slowly","arificia youl intelligent","it is rain you to day"};
int saunhonhat(int l,int r){
	int m= (l+r)/2;
	if(l==r){
		return l;
	}
	return strlen(s[saunhonhat(l,m)]) > strlen(s[saunhonhat(m+1,r)]) ? saunhonhat(l,m) : saunhonhat(m+1,r);
}

int tongchieudai(int l,int r){
	int m= (l+r)/2;
	if(l==r){
		return strlen(s[l]);
	}
	return tongchieudai(l,m) + tongchieudai(m+1,r);
}
void sapxeptron(char b[][100],int l,int r){
	int m=(l+r)/2;
	if(l>=r){
		return ;
	}
	sapxeptron(b,l,m);
	sapxeptron(b,m+1,r);
	for(int i=l;i<=m;i++){
		strcpy(b[i],s[i]);
	}
	for(int i=m+1;i<=r;i++){
		strcpy(b[i],s[r + m+1 - i]);
	}
	int i=l,j=r;
	for(int k=l;k<=r;k++){
		if(strcmp(b[j],b[i])<0){
			strcpy(s[k],b[j]);
			j--;
		}else{
			strcpy(s[k],b[i]);
			i++;
		}
	}
}
int timkitu(int l,int r,char st[]){
	int m=(l+r)/2;
	if(l<=r){
		if(strcmp(s[m],st)>0){
			return timkitu(l,m-1,st);
		}else if(strcmp(s[m],st)<0){
			return timkitu(m+1,r,st);
		}else{
			return m;
		}
	}
	return -1;
}
void BMHtimtu(char ch[],char a[],int &dem){
	int h=strlen(ch),i=strlen(ch)-1,len=strlen(a);

	while(i<len){
		int x=h-1,j=i;
		
		while(a[j]==ch[x] && x>=0){
			j--;
			x--;
		}
		if(x<0){
			dem++;
			i=i+h;
		}else{
			while(a[j]!=ch[x] && x>=0){
				x--;
			}
			if(x<0){
				i=i+h;
			}else{
				i=i+(h-x)-1;
			}
		}
	
	}
}
void xaucon(char a[],char v[]){
	char h[100];
	strcpy(h,a);
	strcat(h,"&");
	strcat(h,v);
	int l=0,r=0;
	int z[strlen(h)+1];

	z[0]=0;
	int n=strlen(h);
	for(int i=1;i<n;i++){
		if(i>r){
			l=r=i;
			while(h[r-l] == h[r] && r<n)  r++;
			z[i]=r-l;dfre4opi uy6t p[-\]p[-i9p-09=0987907o[]
			'']0uy67rt54g]\
			'= ghrt']
			r--;
		}else if(z[i-l]<r-i+1){
			
			z[i]=z[i-l];
		}else{
			l=i;
			while(h[r-l] == h[r] && r<n) r++;
			z[i]=r-l;
			r--;		
		}
		
	}
	int count=0;
	for(int i=1;i<n;i++){
		if(z[i]==strlen(a)){
			count++;
		}
	}
	if(count){
		cout<<a<<" xuat hien trong "<<v<<" so lan xuat hien "<<count<<endl;
	}
}
int main(){
	int dem=0;
	int n=sizeof s/sizeof s[0];
		char b[n+1][100];
	cout<<"sau cho chieu dai nhat la : "<<s[saunhonhat(0,n-1)]<<endl;
	cout<<"tong chieu dai cac sau ky tu la: "<<tongchieudai(0,n-1)<<endl;
//	sapxeptron(b,0,n-1);
//	for(int i=0;i<n;i++){
//		cout<<s[i]<<endl;
//	}
//	char st[100];
//	gets(st);
//	fflush(stdin);
//
//	cout<<"xuat hien vi tri "<<timkitu(0,n-1,st)+1<<endl;
//	char ch[]="child";
//	int count =0;
//	for(int i=0;i<n;i++){
//		dem=0;
//		
//		BMHtimtu(ch,s[i],dem);
//		if(dem>0){
//			cout<<s[i]<<endl;
//			count++;
//		}
//	}

	for(int i=1;i<n;i++){
		xaucon(s[0],s[i]);
	}
}
