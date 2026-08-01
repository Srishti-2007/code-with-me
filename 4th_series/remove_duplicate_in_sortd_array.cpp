#include<iostream>
using namespace std;
int removeDuplicate(int arr[], int n){
    int x=0;
    for(int i=1;i<n;i++){
        if(arr[i]>arr[x]){
            x++;
            arr[x]=arr[i];
        }
    }
    return x+1;

}
int main(){
    int arr[]={0,0,1,1,1,2,2,3,3,4};
    int n=10;
    int result=removeDuplicate(arr,n);
    cout<<"after removing "<<result;
}