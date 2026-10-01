#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int arr[] = {0, 1,3};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    sort(arr, arr + n);
    
    for(int i = 0; i < n ; i++){
        if(arr[i] + 1 != arr[i+1]){   // gap found → number is missing
            cout << "Missing number: " << arr[i] + 1;
        }
    }
}