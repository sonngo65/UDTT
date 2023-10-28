#include<bits/stdc++.h>
using namespace std;
int arr[]={1, 1, 1, 1, 6, 7, 4, 9, 8, 5, 1, 2, 2, 3, 1};

int n=sizeof arr/sizeof arr[0];
vector<int> b;
void hienthi(vector<int> b){
	for(int i=0;i<b.size();i++){
	  cout<<b[i]<<" ";
	}
}
void strace(int arr[], int a,int &count,int k,int &tong){

    for(int i=a+1;i<n;i++){
        tong = tong + arr[i];
        b.push_back(arr[i]);
        if(tong == k){
            count ++ ;
            cout<<endl;
            hienthi(b);
        }
        strace(arr,i,count,k,tong);
        tong = tong - arr[i];
        b.pop_back();
        while(arr[i+1]==arr[i]){
            i++;
        }
    }
}

int combinationSum(int arr[], int k)
{
    int count =0, tong =0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
    	cout<<arr[i]<<" ";
	}
	cout<<endl;
    for(int i=0;i<n;i++){
        tong = tong+arr[i];
        b.push_back(arr[i]);
        if(tong==k){
            count++;
                cout<<endl;
            hienthi(b);
        }
        strace(arr,i,count,k,tong);
        tong = tong - arr[i];
         b.pop_back();
         while(arr[i+1]==arr[i]){
            i++;
        }
        
     }
    return count;
}
int main(){
	cout<<combinationSum(arr,9);
}
