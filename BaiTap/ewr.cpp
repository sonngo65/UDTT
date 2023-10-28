#include<bits/stdc++.h>
using namespace std;
int arr[]={37, 10, 36, 16, 17, 10, 28, 42, 3, 27, 36, 16, 32, 35, 1, 1, 27, 29, 48, 37, 33, 18, 11, 36, 41, 35, 22, 40, 15, 3, 38, 42, 9, 45, 12, 24, 25, 20, 5, 35, 29, 48, 38, 29, 25, 47, 18, 24, 23, 36};
int n=sizeof arr/sizeof arr[0];
void strace(int arr[],int b[],int bl[],int n,int index){
    int k=arr[n]-1;
   if(b[k] == 0){
       b[k]=index;
       cout<<b[k]<<" k:"<<k<<" ";
	   strace(arr,b,bl,k,index+1);
       b[k]=0;
       
   }else{
       cout<<b[k]<<" k:"<<k<<" ";
          if(index-b[k]>2){
          	bl[0]=1;
		  }
      
   }

}
bool triangleFriendship(int arr[])
{   
    int b[n],bl[1];
    for(int i=0;i<n;i++){
       b[i]=0;
    }
    bl[0]=1;
    for(int i=0;i<n;i++){
        strace(arr,b,bl,i,1);
        if(bl[0]==1){
        	return 1;
		}
    }
	return 0;
}

int main(){

	cout<<triangleFriendship(arr);
}
