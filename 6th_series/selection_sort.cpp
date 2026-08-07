#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int arr[]={5,2,3,8,1};
    int n=5;
    cout<<"before Sorting"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    int min=0;
    for(int i=0;i<n-1;i++){
        min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
         if(min!=i){
        swap(arr[min],arr[i]);
    }
    }
   
     cout<<endl<<"after Sorting"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}