#include <algorithm>
#include <cctype>
#include <iostream>
#include <iterator>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;


int solution(string str) {
  string first, last;
  vector<string> alpha_map = {
      "one", "1",   "two", "2",   "three", "3",
      "four", "4",  "five", "5",  "six", "6",
      "seven", "7", "eight", "8", "nine", "9"};
  int temp=9999999;
  for(auto elem : alpha_map) {
    int loc = str.find(elem);
    // cout << "loc " << loc << " elem " << elem << endl;
    if(loc<temp && loc!=-1){
      first = elem;
      temp = loc;
    }
  }
  temp=-1;
  for(auto elem : alpha_map) {
    int loc = str.rfind(elem);
    // cout << "loc " << loc << " elem " << elem << endl;
    if(loc>temp && loc!=-1){
      last = elem;
      temp = loc;
    }
  }
  // cout << first << last << endl;
  if(!isdigit(first[0])) {
    auto it = find(alpha_map.begin(), alpha_map.end(), first);
    int loc =  distance(alpha_map.begin(), it);
    first = alpha_map[loc+=1];
  }
  if(!isdigit(last[0])) {
    auto it = find(alpha_map.begin(), alpha_map.end(), last);
    int loc = distance(alpha_map.begin(), it);
    last = alpha_map[loc+=1];
  }
  
  return stoi(first+last);
}

int main() {
  string str;
  int sum = 0;
  while (cin >> str) {
    sum += solution(str);
    // cout << solution(str)<<endl;
  }
  cout << sum << endl;
  return 0;
}
