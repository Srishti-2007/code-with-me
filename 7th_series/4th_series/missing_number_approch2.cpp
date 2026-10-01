#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int arr[] = {3, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Formula approach
    int totalsum = n * (n + 1) / 2;
    int partialsum = 0;

    for(int i = 0; i < n; i++){
        partialsum = partialsum + arr[i];
    }

    cout << "Missing Number: " << totalsum - partialsum;

    return 0;
}
