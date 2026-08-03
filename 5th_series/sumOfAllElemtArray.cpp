#include<iostream>
using namespace std;
int sum(int n , int arr[]){
    if(n==0) return arr[0];
    return arr[n]+sum(n-1,arr);
}
int main(){
    int arr[]={1,4,7,9};
    int n=3;
    cout<<sum(n,arr);
}