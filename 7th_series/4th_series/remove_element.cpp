#include<iostream>
using namespace std;
int main() {
    int arr[]={0,1,2,2,3,0,4,2};
    int size=8;
    int x=0;
    int val=2;
    for(int i=0;i<size;i++){
        if(arr[i]!=val){
            arr[x]=arr[i];
              x=x+1;
        }
    }
    cout<<x;
}