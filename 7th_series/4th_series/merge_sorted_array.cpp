#include <bits/stdc++.h>
using namespace std;

void mergeArray(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int p1 = m - 1;
    int p2 = n - 1;
    int i = m + n - 1;

    while(p2 >= 0){
        if(p1 >= 0 && nums1[p1] > nums2[p2]){
            nums1[i] = nums1[p1];
            p1--;
        }
        else{
            nums1[i] = nums2[p2];
            p2--;
        }
        i--;
    }
}

int main() {
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    int m = 3;
    int n = 3;

    mergeArray(nums1, m, nums2, n);

    for(int x : nums1)
        cout << x << " ";

    return 0;
}