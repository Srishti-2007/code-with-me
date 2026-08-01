#include<iostream>
using namespace std;
int check(int arr[],int n){
    int min=arr[0];
    int maxProfit=0;
    for(int i=1;i<n;i++){
        if(arr[i-1]<=min){
            min=arr[i-1];
        }
        if((arr[i]-min)>maxProfit){
        maxProfit=arr[i]-min;
     }   
    }
    return maxProfit;
}
int main(){
    int arr[]={7,6,4,3,1};
    int n=5;
    cout<<"maxProfit is "<<check(arr,n);
}