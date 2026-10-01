#include<iostream>
#include<string>
using namespace std;
int main(){
    string s = "srishti";
    int n = s.size();

    for(int i = 0; i < n/2; i++){
        char temp = s[i];
        s[i] = s[n-1-i];
        s[n-1-i] = temp;
    }

    cout << s;
}