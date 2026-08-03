#include<iostream>
using namespace std;
int sum(int n , int arr[]){
    int odd= arr[n]%2!=0;
    if(n==0) {
        return odd ? arr[n]: 0;
    }
    return odd ? arr[n]+sum(n-1,arr): 0+sum(n-1,arr);
}
int main(){
    int arr[]={1,4,2,9};
    int n=3;
    cout<<sum(n,arr);
}