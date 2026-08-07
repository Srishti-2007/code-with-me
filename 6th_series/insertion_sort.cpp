#include<iostream>
using namespace std;
int main(){
    int arr[]={5,2,3,8,1};
    int n=5;
    cout<<"before Sorting"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    for(int i=1;i<n;i++){
        int curr=arr[i];
        int p=i-1;
        while(arr[p]>curr && p>=0){
            arr[p+1]=arr[p];
            p--;
        }
        arr[p+1]=curr;
    }
    cout<<endl<<"after Sorting"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}