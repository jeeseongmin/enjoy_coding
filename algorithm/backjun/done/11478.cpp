#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;
int main() {
  string str, temp;
  cin >> str;
  int N;
  N = str.size();
  vector<int> cnt(N, 0);
  map<string, int> all;
  for(int i=1; i<=N; i++) {
    for(int j=0; j<=N-i; j++) {
      temp = str.substr(j,i);
      all.insert({temp,i});
    }
  }
  cout << all.size();
}
