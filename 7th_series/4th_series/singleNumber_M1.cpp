#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int arr[] = {2, 2, 3, 4, 5, 4, 5,3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int flag=0;
    sort(arr, arr + n); 
    
    for(int i = 0; i < n; i += 2){ 
        // If it's the last element or doesn't match the next one
        if(i == n - 1 || arr[i] != arr[i + 1]){
            cout << "Single number: " << arr[i];
             flag=1;
            break;
        }
    }
    if(flag==0)
     cout<<"No single value found";
    return 0;
}
