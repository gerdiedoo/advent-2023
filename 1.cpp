#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

int solution(string str) { 
    char first,last;
    for(char ch : str){
        if(isdigit(ch)) {
            first = ch;
            break;
        }
    }
    for(int i=str.length();i>=0;i--){
        if(isdigit(str[i])){
            last=str[i];
            break;
        }
    }
    string temp = {first, last};

    return stoi(temp);
}

int main(){
    string str;
    int sum=0;
    while(cin >> str){
        sum+=solution(str);
    }
    cout << sum <<endl;
    return 0;
}
