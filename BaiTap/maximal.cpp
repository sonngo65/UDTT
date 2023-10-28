#include<bits/stdc++.h>
using namespace std;

void strace(vector<int> arr,int n,int &phantu,int tong,int &max){
    int b=phantu;
    for(int i=1;i<arr.size()-n;i++){
        phantu= phantu+arr[n];
        max =( max > (phantu * (tong - phantu)) ) ? max : (phantu * (tong - phantu));
        cout<<max<< " "<<n<<endl;
	    strace(arr,n+i,phantu,tong,max);
     
	    phantu=b;
    }
}
int maximalMultiple(vector<int> arr)
{   int max=0;
    int phantu =0;
    int tong=0;
    for(int i=0;i< arr.size();i++){
        tong += arr[i];
    }

        
    for(int i=0;i<arr.size();i++){
        phantu = arr[i];
        if(i==0){
        	max =arr[0] * (tong - arr[0]); 
		}else{
		
 			max =(max>arr[i]* (tong - phantu)) ? max : arr[i]* (tong - phantu); 
    	}
		strace(arr,i+1,phantu,tong,max);
    }
    return max;
}
int main(){
	vector<int> arr;
	int a,b;
	cin>>a;
	for(int i=0;i<a;i++ ){
		cin>>b;
		arr.push_back(b);
	}
	cout<<maximalMultiple(arr);
}
