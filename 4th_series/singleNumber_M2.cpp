#include<iostream>
using namespace std;
int main(){
     int arr[] = {2, 7,2, 3, 4, 5, 7,4, 5};
     int n=9;
     int res=0;
     for(int i=0;i<n;i++){
        res=res^arr[i];
     }
     cout<<res;
}