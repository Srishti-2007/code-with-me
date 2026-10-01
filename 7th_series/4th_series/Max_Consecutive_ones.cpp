#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int arr[]={1,1,0,1,1,1};
    int size=6;
    int curr_count=0;
    int max_count=0;
    for(int i=0;i<size;i++){
        if(arr[i]==1){
            curr_count++;
        }
        else{
            max_count=max(curr_count,max_count);
            curr_count=0;
        }
    }
    cout<<max(curr_count,max_count);
}