#include<iostream>
using namespace std;
int main(){
    int arr[]={0,1,0,3,12};
    int size=5;
    int x=0;
    for(int i=0;i<size;i++){
        if(arr[i]!=0){
            arr[x]=arr[i];
            x++;
        }
    }
    for(int i=x;i<size;i++){
        arr[i]=0;
    }
    // for printing purpous
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}